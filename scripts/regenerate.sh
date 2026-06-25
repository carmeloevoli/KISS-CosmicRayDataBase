#!/usr/bin/env bash
#
# regenerate.sh - rebuild KISS and refresh the curated kiss_tables/ directory
#                 from the converter output.
#
# Steps:
#   1. configure + build
#   2. run the converter (writes build/output/)
#   3. mirror build/output/ -> kiss_tables/  (only if no inputs were missing)
#
# Safety: if the converter reports missing input files, the curated kiss_tables/
# is left untouched -- otherwise an incomplete run (e.g. CRDB source data not yet
# fetched) would delete good tables via the mirror's --delete.
#
# Usage:
#   scripts/regenerate.sh            # refresh kiss_tables/ only
#   scripts/regenerate.sh --tarball  # also package tarballs/ via make_tarball.sh

set -euo pipefail

cd "$(git rev-parse --show-toplevel)"
build_dir="build"
do_tarball=0
[ "${1:-}" = "--tarball" ] && do_tarball=1

jobs=$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)

echo "==> [1/3] configuring & building"
cmake -S . -B "$build_dir" >/dev/null
cmake --build "$build_dir" -j"$jobs" >/dev/null
echo "    build OK"

echo "==> [2/3] running converter"
run_log=$(mktemp)
trap 'rm -f "$run_log"' EXIT
rm -rf "$build_dir/output"
if ! ( cd "$build_dir" && ./KISS ) >"$run_log" 2>&1; then
    echo "    converter failed:" >&2
    tail -n 20 "$run_log" >&2
    exit 1
fi
echo "    $(grep -aoE 'missing input files: [0-9]+' "$run_log" | tail -1)"

missing=$(grep -aoE 'missing input files: [0-9]+' "$run_log" | grep -oE '[0-9]+' | tail -1 || true)
: "${missing:=unknown}"
if [ "$missing" != "0" ]; then
    echo "==> refusing to refresh kiss_tables/: converter reported '${missing}' missing input(s)." >&2
    echo "    fetch the missing source data (e.g. 'python data/get_crdb_data.py') and retry." >&2
    exit 1
fi

ntables=$(find "$build_dir/output" -maxdepth 1 -name '*.txt' | wc -l | tr -d ' ')
echo "==> [3/3] mirroring ${build_dir}/output/ -> kiss_tables/ (${ntables} tables)"
rsync -a --delete "$build_dir/output/" kiss_tables/

changed=$(git status --porcelain -- kiss_tables | wc -l | tr -d ' ')
echo "    done. ${changed} file(s) changed in kiss_tables/ vs the committed copy."

if [ "$do_tarball" = "1" ]; then
    echo "==> packaging tarball"
    scripts/make_tarball.sh
else
    echo
    echo "Next: review 'git diff kiss_tables/', commit, then package a release with:"
    echo "    scripts/make_tarball.sh        # writes tarballs/kiss_tables_<date>_<hash>.tar.gz"
fi
