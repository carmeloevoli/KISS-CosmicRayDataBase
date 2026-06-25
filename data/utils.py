#!/usr/bin/env python

from __future__ import print_function

import csv
import difflib
import io
import math
import os
import re
import ssl
import sys

try:
    unicode
except NameError:  # pragma: no cover - Python 3
    unicode = str

try:
    from urllib import urlencode
    from urllib2 import HTTPSHandler
    from urllib2 import HTTPError
    from urllib2 import URLError
    from urllib2 import Request
    from urllib2 import build_opener
    from urllib2 import urlopen
except ImportError:  # pragma: no cover - Python 3
    from urllib.error import HTTPError
    from urllib.error import URLError
    from urllib.parse import urlencode
    from urllib.request import HTTPSHandler
    from urllib.request import Request
    from urllib.request import build_opener
    from urllib.request import urlopen


DEFAULT_OUTPUT_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "CRDB")
PY2 = sys.version_info[0] == 2
_SSL_RETRY_WARNING_SHOWN = False

CRDB_BASE_URL = "https://lpsc.in2p3.fr/crdb"
CRDB_DIALOG_URL = CRDB_BASE_URL + "/_dialog_result.php"
CRDB_CSV_EXPORT_URL = CRDB_BASE_URL + "/_getfile.php?id=22&extension={0}"
CRDB_USER_AGENT = "KISS-CosmicRayDataBase/1.0"
CRDB_EXPORT_LINK_RE = re.compile(r"_getfile\.php\?id=22&extension=([0-9]+)")
CRDB_HTML_MESSAGE_RE = re.compile(r"<p>(.*?)</p>", re.IGNORECASE | re.DOTALL)

CSV_COLUMNS = (
    "EXP-NAME",
    "EXP-TYPE",
    "EXP-HTML",
    "EXP-STARTYEAR",
    "SUBEXP-NAME",
    "SUBEXP-DESCRIPTION",
    "SUBEXP-ESCALE_RELERR",
    "SUBEXP-INFO",
    "SUBEXP-DISTANCE",
    "SUBEXP-DATES",
    "PUBLI-HTML",
    "PUBLI-DATAORIGIN",
    "DATA-QTY",
    "DATA-EAXIS",
    "DATA-E_MEAN",
    "DATA-E_BIN_L",
    "DATA-E_BIN_U",
    "DATA-VAL",
    "DATA-VAL_ERRSTAT_L",
    "DATA-VAL_ERRSTAT_U",
    "DATA-VAL_ERRSYST_L",
    "DATA-VAL_ERRSYST_U",
    "DATA-ISUPPERLIM",
    "phi [MV]",
)


class CrdbExportError(RuntimeError):
    """Base class for CRDB export failures."""


class CrdbDependencyError(CrdbExportError):
    """Kept for compatibility with the caller interface."""


class InvalidCrdbTableError(CrdbExportError):
    """Raised when CRDB returns data with an unexpected structure."""


class DatasetNotFoundError(CrdbExportError):
    """Raised when no CRDB rows match the requested dataset."""


class DatasetRequest(object):
    def __init__(self, quantity, energy_type, experiment, sub_experiment, filename, combo_level=0):
        self.quantity = quantity
        self.energy_type = energy_type
        self.experiment = experiment
        self.sub_experiment = sub_experiment
        self.filename = filename
        self.combo_level = combo_level

    def describe(self):
        return "{0} vs {1} for '{2}' / '{3}'".format(
            self.quantity,
            self.energy_type,
            self.experiment,
            self.sub_experiment,
        )

    def output_path(self, output_dir=None):
        base_dir = DEFAULT_OUTPUT_DIR if output_dir is None else output_dir
        return os.path.join(base_dir, self.filename)


def print_column_names(_tab=None):
    for icol, col_name in enumerate(CSV_COLUMNS):
        print("{0:2d} {1}".format(icol, col_name))


def dump_datafile(
    quantity,
    energyType,
    expName,
    subExpName,
    filename,
    combo_level=0,
    output_dir=None,
):
    request = DatasetRequest(
        quantity=quantity,
        energy_type=energyType,
        experiment=expName,
        sub_experiment=subExpName,
        filename=filename,
        combo_level=combo_level,
    )
    return export_dataset(request, output_dir=output_dir)


def export_dataset(request, output_dir=None):
    print("search for {0}".format(request.describe()))

    rows = query_crdb(request)
    selected_rows = select_rows(rows, request)
    formatted_rows, skipped_rows = collect_rows(selected_rows, request)
    output_path = request.output_path(output_dir)
    ads_codes = unique_values(row["PUBLI-HTML"] for row in selected_rows)

    if len(ads_codes) > 1:
        print("warning: multiple ADS codes found for {0}: {1}".format(request.filename, ads_codes))

    output_dirname = os.path.dirname(output_path)
    if output_dirname and not os.path.isdir(output_dirname):
        os.makedirs(output_dirname)

    tmp_path = output_path + ".tmp"
    with open(tmp_path, "w") as handle:
        ads_code = ads_codes[0] if ads_codes else "unknown"
        handle.write("#ads: {0}\n".format(ads_code))
        handle.write("#E_lo - E_up - y - errSta_lo - errSta_up - errSys_lo - errSys_up\n")
        for row in formatted_rows:
            handle.write(
                "{0:10.5e} {1:10.5e} {2:10.5e} {3:10.5e} {4:10.5e} {5:10.5e} {6:10.5e}\n".format(*row)
            )

    replace_file(tmp_path, output_path)

    print("number of data : {0}".format(len(formatted_rows)))
    if skipped_rows:
        print("warning: skipped {0} invalid rows while writing {1}".format(skipped_rows, request.filename))
    print("dump on {0}\n".format(output_path))
    return output_path


def query_crdb(request):
    params = build_query_params(request)
    html = fetch_text(CRDB_DIALOG_URL, params)
    extension = extract_export_extension(html)
    csv_text = fetch_text(CRDB_CSV_EXPORT_URL.format(extension), None)
    rows = parse_csv_rows(csv_text)

    if not rows:
        raise DatasetNotFoundError("CRDB returned no rows for {0}.".format(request.describe()))

    print("number of datasets found : {0}".format(len(unique_values(row["SUBEXP-NAME"] for row in rows))))
    print(unique_values(row["SUBEXP-NAME"] for row in rows))
    print(unique_values(row["PUBLI-HTML"] for row in rows))
    return rows


def build_query_params(request):
    numerator, denominator = split_quantity(request.quantity)
    params = [
        ("num", numerator),
        ("energy_type", request.energy_type),
        ("combo_level", str(request.combo_level)),
        ("energy_convert_level", "0"),
        ("exp_dates", request.experiment),
        ("format", "csv-asimport"),
    ]
    if denominator is not None:
        params.insert(1, ("den", denominator))
    return params


def split_quantity(quantity):
    if "/" not in quantity:
        return quantity, None
    return quantity.split("/", 1)


def fetch_text(url, params):
    global _SSL_RETRY_WARNING_SHOWN

    headers = {"User-Agent": CRDB_USER_AGENT}
    data = None
    if params is not None:
        data = urlencode(params)
        if not isinstance(data, bytes):
            data = data.encode("utf-8")
        headers["Content-Type"] = "application/x-www-form-urlencoded"

    try:
        payload = open_request(url, data, headers, verify_ssl=True)
    except HTTPError as exc:
        raise CrdbExportError("CRDB request failed with HTTP {0} for {1}".format(exc.code, url))
    except URLError as exc:
        if should_retry_without_ssl_verification(url, exc):
            if not _SSL_RETRY_WARNING_SHOWN:
                print("warning: SSL verification failed for CRDB; retrying without certificate checks.")
                _SSL_RETRY_WARNING_SHOWN = True
            try:
                payload = open_request(url, data, headers, verify_ssl=False)
            except HTTPError as retry_exc:
                raise CrdbExportError("CRDB request failed with HTTP {0} for {1}".format(retry_exc.code, url))
            except URLError as retry_exc:
                reason = getattr(retry_exc, "reason", retry_exc)
                raise CrdbExportError("CRDB request failed for {0}: {1}".format(url, reason))
        else:
            reason = getattr(exc, "reason", exc)
            raise CrdbExportError("CRDB request failed for {0}: {1}".format(url, reason))

    return decode_payload(payload)


def open_request(url, data, headers, verify_ssl=True):
    request = Request(url, data=data, headers=headers)

    if verify_ssl or not url.lower().startswith("https://"):
        response = urlopen(request, timeout=60)
    else:
        context_factory = getattr(ssl, "_create_unverified_context", None)
        if context_factory is None:
            response = urlopen(request, timeout=60)
        else:
            opener = build_opener(HTTPSHandler(context=context_factory()))
            response = opener.open(request, timeout=60)

    try:
        return response.read()
    finally:
        response.close()


def should_retry_without_ssl_verification(url, exc):
    if not url.lower().startswith("https://"):
        return False

    reason = getattr(exc, "reason", exc)
    message = str(reason)
    return "CERTIFICATE_VERIFY_FAILED" in message or "certificate verify failed" in message.lower()


def extract_export_extension(html):
    match = CRDB_EXPORT_LINK_RE.search(html)
    if match is not None:
        return match.group(1)

    error_message = extract_html_message(html)
    if error_message:
        raise CrdbExportError("CRDB query failed: {0}".format(error_message))

    raise CrdbExportError("could not find the CRDB CSV export link in the server response")


def extract_html_message(html):
    match = CRDB_HTML_MESSAGE_RE.search(html)
    if match is None:
        return None

    message = re.sub(r"<[^>]+>", " ", match.group(1))
    message = " ".join(message.replace("&nbsp;", " ").split())
    return message or None


def parse_csv_rows(csv_text):
    data_lines = []
    for line in csv_text.splitlines():
        stripped = line.strip()
        if not stripped or stripped.startswith("#"):
            continue
        data_lines.append(line)

    if not data_lines:
        return []

    payload = "\n".join(data_lines)
    if PY2:
        if isinstance(payload, unicode):
            payload = payload.encode("utf-8")
        reader = csv.reader(io.BytesIO(payload))
    else:
        if isinstance(payload, bytes):
            payload = payload.decode("utf-8", "replace")
        reader = csv.reader(io.StringIO(payload))
    rows = []
    for values in reader:
        values = [decode_payload(value) for value in values]
        if len(values) != len(CSV_COLUMNS):
            raise InvalidCrdbTableError(
                "unexpected number of columns in CRDB CSV export: expected {0}, got {1}".format(
                    len(CSV_COLUMNS), len(values)
                )
            )
        rows.append(dict(zip(CSV_COLUMNS, values)))
    return rows


def select_rows(rows, request):
    selected_rows = [row for row in rows if row["SUBEXP-NAME"] == request.sub_experiment]
    if selected_rows:
        return selected_rows

    available = unique_values(row["SUBEXP-NAME"] for row in rows)
    message = "sub-experiment {0!r} not found for {1}.".format(request.sub_experiment, request.describe())
    if available:
        suggestions = difflib.get_close_matches(request.sub_experiment, available, n=3)
        if suggestions:
            message += " Close matches: {0}.".format(", ".join(suggestions))
        else:
            message += " Available values: {0}.".format(", ".join(available))
    raise DatasetNotFoundError(message)


def collect_rows(rows, request):
    formatted_rows = []
    skipped_rows = 0

    for row in rows:
        try:
            formatted = (
                float(row["DATA-E_BIN_L"]),
                float(row["DATA-E_BIN_U"]),
                float(row["DATA-VAL"]),
                float_or_zero(row["DATA-VAL_ERRSTAT_L"]),
                float_or_zero(row["DATA-VAL_ERRSTAT_U"]),
                float_or_zero(row["DATA-VAL_ERRSYST_L"]),
                float_or_zero(row["DATA-VAL_ERRSYST_U"]),
            )
        except (TypeError, ValueError):
            skipped_rows += 1
            continue

        if not all(is_finite(item) for item in formatted):
            skipped_rows += 1
            continue

        formatted_rows.append(formatted)

    if not formatted_rows:
        raise InvalidCrdbTableError("All rows selected for {0} are invalid.".format(request.describe()))

    formatted_rows.sort(key=lambda row: (row[0], row[1]))
    return formatted_rows, skipped_rows


def unique_values(values):
    cleaned = set()
    for value in values:
        text = decode_payload(value).strip()
        if text:
            cleaned.add(text)
    return sorted(cleaned)


def float_or_zero(value):
    text = decode_payload(value).strip()
    if not text:
        return 0.0
    return float(text)


def decode_payload(payload):
    if isinstance(payload, bytes):
        return payload.decode("utf-8", "replace")
    return payload


def is_finite(value):
    if hasattr(math, "isfinite"):
        return math.isfinite(value)
    return not (math.isnan(value) or math.isinf(value))


def replace_file(source_path, target_path):
    if os.path.isfile(target_path):
        os.remove(target_path)
    os.rename(source_path, target_path)
