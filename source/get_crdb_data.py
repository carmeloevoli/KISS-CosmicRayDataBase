#!/usr/bin/env python

from __future__ import print_function

import argparse
import json
import os
from collections import OrderedDict

from utils import DEFAULT_OUTPUT_DIR, CrdbDependencyError, CrdbExportError, DatasetRequest, export_dataset

try:
    basestring
except NameError:  # pragma: no cover - Python 3
    basestring = str


DATASETS_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "crdb_datasets.json")
REQUIRED_DATASET_KEYS = frozenset(("quantity", "energy_type", "experiment", "sub_experiment", "filename"))
OPTIONAL_DATASET_KEYS = frozenset(("combo_level",))
_REGISTRY_CACHE = None


class DatasetRegistryError(ValueError):
    """Raised when the dataset registry file is missing or malformed."""


def _coerce_str(value, field_name, context):
    if not isinstance(value, basestring) or not value.strip():
        raise DatasetRegistryError("{0}: field {1!r} must be a non-empty string.".format(context, field_name))
    return value


def _parse_dataset_entry(experiment_name, index, entry):
    context = "experiment {0!r} dataset #{1}".format(experiment_name, index + 1)
    if not isinstance(entry, dict):
        raise DatasetRegistryError("{0}: each dataset entry must be an object.".format(context))

    keys = set(entry)
    missing = REQUIRED_DATASET_KEYS - keys
    if missing:
        raise DatasetRegistryError("{0}: missing required fields: {1}.".format(context, ", ".join(sorted(missing))))

    unknown = keys - REQUIRED_DATASET_KEYS - OPTIONAL_DATASET_KEYS
    if unknown:
        raise DatasetRegistryError("{0}: unknown fields: {1}.".format(context, ", ".join(sorted(unknown))))

    filename = _coerce_str(entry["filename"], "filename", context)
    if os.path.basename(filename) != filename:
        raise DatasetRegistryError("{0}: filename must not contain directory components.".format(context))

    combo_level = entry.get("combo_level", 0)
    if not isinstance(combo_level, int) or combo_level < 0:
        raise DatasetRegistryError("{0}: combo_level must be a non-negative integer.".format(context))

    return DatasetRequest(
        quantity=_coerce_str(entry["quantity"], "quantity", context),
        energy_type=_coerce_str(entry["energy_type"], "energy_type", context),
        experiment=_coerce_str(entry["experiment"], "experiment", context),
        sub_experiment=_coerce_str(entry["sub_experiment"], "sub_experiment", context),
        filename=filename,
        combo_level=combo_level,
    )


def load_registry():
    global _REGISTRY_CACHE
    if _REGISTRY_CACHE is not None:
        return _REGISTRY_CACHE

    if not os.path.isfile(DATASETS_FILE):
        raise DatasetRegistryError("dataset registry file not found: {0}".format(DATASETS_FILE))

    try:
        with open(DATASETS_FILE, "r") as handle:
            raw_registry = json.load(handle, object_pairs_hook=OrderedDict)
    except ValueError as exc:
        raise DatasetRegistryError("invalid JSON in {0}: {1}".format(DATASETS_FILE, exc))

    if not isinstance(raw_registry, dict):
        raise DatasetRegistryError("dataset registry root must be a JSON object.")

    experiments_raw = raw_registry.get("experiments")
    if not isinstance(experiments_raw, dict) or not experiments_raw:
        raise DatasetRegistryError("dataset registry must define a non-empty 'experiments' object.")

    registry = OrderedDict()
    seen_filenames = {}
    for experiment_name, entries in experiments_raw.items():
        if not isinstance(experiment_name, basestring) or not experiment_name.strip():
            raise DatasetRegistryError("experiment names must be non-empty strings.")
        if not isinstance(entries, list) or not entries:
            raise DatasetRegistryError(
                "experiment {0!r} must contain a non-empty dataset list.".format(experiment_name)
            )

        requests = [_parse_dataset_entry(experiment_name, index, entry) for index, entry in enumerate(entries)]
        for request in requests:
            owner = seen_filenames.get(request.filename)
            if owner is not None:
                raise DatasetRegistryError(
                    "duplicate output filename {0!r} in experiments {1!r} and {2!r}.".format(
                        request.filename,
                        owner,
                        experiment_name,
                    )
                )
            seen_filenames[request.filename] = experiment_name

        registry[experiment_name] = requests

    default_experiments_raw = raw_registry.get("default_experiments", [])
    if not isinstance(default_experiments_raw, list):
        raise DatasetRegistryError("'default_experiments' must be a list if provided.")

    default_experiments = tuple(default_experiments_raw)
    for name in default_experiments:
        if name not in registry:
            raise DatasetRegistryError(
                "default experiment {0!r} is not defined in the 'experiments' section.".format(name)
            )

    _REGISTRY_CACHE = (registry, default_experiments)
    return _REGISTRY_CACHE


def get_requests(experiment_name):
    registry, _ = load_registry()
    try:
        return registry[experiment_name]
    except KeyError:
        available = ", ".join(registry)
        raise ValueError("unknown experiment {0!r}. Available: {1}".format(experiment_name, available))


def run_experiment(experiment_name, output_dir=None, fail_fast=False):
    requests = get_requests(experiment_name)
    print("== {0}: {1} dataset(s) ==".format(experiment_name, len(requests)))

    exported = 0
    failed = 0
    for request in requests:
        try:
            export_dataset(request, output_dir=output_dir)
            exported += 1
        except CrdbDependencyError as exc:
            print("error: {0}\n".format(exc))
            raise
        except CrdbExportError as exc:
            failed += 1
            print("error: {0}\n".format(exc))
            if fail_fast:
                raise

    return exported, failed


def run_many(experiment_names, output_dir=None, fail_fast=False):
    total_exported = 0
    total_failed = 0

    for experiment_name in experiment_names:
        exported, failed = run_experiment(experiment_name, output_dir=output_dir, fail_fast=fail_fast)
        total_exported += exported
        total_failed += failed

    return total_exported, total_failed


def AUGER(**kwargs):
    return run_experiment("AUGER", **kwargs)


def AMS02(**kwargs):
    return run_experiment("AMS02", **kwargs)


def BESS(**kwargs):
    return run_experiment("BESS", **kwargs)


def CALET(**kwargs):
    return run_experiment("CALET", **kwargs)


def CREAM(**kwargs):
    return run_experiment("CREAM", **kwargs)


def DAMPE(**kwargs):
    return run_experiment("DAMPE", **kwargs)


def FERMI(**kwargs):
    return run_experiment("FERMI", **kwargs)


def HAWC(**kwargs):
    return run_experiment("HAWC", **kwargs)


def HESS(**kwargs):
    return run_experiment("HESS", **kwargs)


def ICETOP(**kwargs):
    return run_experiment("ICETOP", **kwargs)


def ISS_CREAM(**kwargs):
    return run_experiment("ISS_CREAM", **kwargs)


def NUCLEON(**kwargs):
    return run_experiment("NUCLEON", **kwargs)


def PAMELA(**kwargs):
    return run_experiment("PAMELA", **kwargs)


def TA(**kwargs):
    return run_experiment("TA", **kwargs)


def TIBET(**kwargs):
    return run_experiment("TIBET", **kwargs)


def TRACER(**kwargs):
    return run_experiment("TRACER", **kwargs)


def TUNKA(**kwargs):
    return run_experiment("TUNKA", **kwargs)


def parse_args(argv=None):
    parser = argparse.ArgumentParser(
        description="Query CRDB and export selected datasets into source/CRDB.",
    )
    parser.add_argument(
        "experiments",
        nargs="*",
        help="Optional experiment names to export. Defaults to the historical batch.",
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="Run every configured experiment, including ones outside the default batch.",
    )
    parser.add_argument(
        "--list",
        action="store_true",
        help="List available experiments and exit.",
    )
    parser.add_argument(
        "--output-dir",
        default=DEFAULT_OUTPUT_DIR,
        help="Directory where CRDB text tables are written (default: {0}).".format(DEFAULT_OUTPUT_DIR),
    )
    parser.add_argument(
        "--fail-fast",
        action="store_true",
        help="Stop immediately on the first export error.",
    )
    return parser.parse_args(argv)


def resolve_experiments(args):
    registry, default_experiments = load_registry()

    if args.all and args.experiments:
        raise SystemExit("Use either --all or an explicit experiment list, not both.")

    if args.all:
        selected = tuple(registry.keys())
    elif args.experiments:
        selected = tuple(args.experiments)
    else:
        selected = default_experiments

    unknown = [name for name in selected if name not in registry]
    if unknown:
        available = ", ".join(registry.keys())
        raise SystemExit("Unknown experiments: {0}. Available: {1}".format(", ".join(unknown), available))

    return selected


def print_available_experiments():
    registry, default_experiments = load_registry()
    print("Available experiments:")
    for name, requests in registry.items():
        default_mark = " [default]" if name in default_experiments else ""
        print("  {0:10s} {1:3d} dataset(s){2}".format(name, len(requests), default_mark))


def main(argv=None):
    args = parse_args(argv)

    try:
        if args.list:
            print_available_experiments()
            return 0

        experiment_names = resolve_experiments(args)
    except DatasetRegistryError as exc:
        print("configuration error: {0}".format(exc))
        return 1

    print("KISS Cosmic Ray Data Base - Data Extraction")
    print("registry file: {0}".format(DATASETS_FILE))
    print("output directory: {0}".format(args.output_dir))
    print("experiments: {0}\n".format(", ".join(experiment_names)))

    try:
        exported, failed = run_many(
            experiment_names,
            output_dir=args.output_dir,
            fail_fast=args.fail_fast,
        )
    except CrdbExportError:
        print("Summary: export aborted after the first failure.")
        return 1

    print("Summary: exported {0} dataset(s), failed {1} dataset(s).".format(exported, failed))
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
