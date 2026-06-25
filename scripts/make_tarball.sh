#!/usr/bin/env bash
#
# make_tarball.sh - package kiss_tables/ into a provenance-stamped tarball.
#
# Produces  kiss_tables_<UTCdate>_<gitshort>.tar.gz  containing:
#   kiss_tables/        the converted tables
#   MANIFEST.json       generation date, git commit/branch, table count
#
# The manifest travels inside the archive so provenance survives renaming.
# The working tree is left untouched (staging happens in a temp dir).
#
# Usage: scripts/make_tarball.sh [output_dir]   (default: repository root)

set -euo pipefail

cd "$(git rev-parse --show-toplevel)"
out_dir="${1:-$PWD}"

if [ ! -d kiss_tables ]; then
    echo "error: kiss_tables/ not found in repository root" >&2
    exit 1
fi

short=$(git rev-parse --short HEAD)
full=$(git rev-parse HEAD)
branch=$(git rev-parse --abbrev-ref HEAD)
describe=$(git describe --tags --always --dirty)
date_utc=$(date -u +%Y-%m-%dT%H:%M:%SZ)
stamp=$(date -u +%Y%m%d)
ntables=$(find kiss_tables -maxdepth 1 -name '*.txt' | wc -l | tr -d ' ')

dirty=false
if [ -n "$(git status --porcelain)" ]; then
    dirty=true
    short="${short}-dirty"   # never mistake an uncommitted build for a release
    echo "warning: working tree is dirty; tagging archive as -dirty" >&2
fi

stage=$(mktemp -d)
trap 'rm -rf "$stage"' EXIT

cp -R kiss_tables "$stage/kiss_tables"

cat > "$stage/MANIFEST.json" <<EOF
{
  "generated_at": "${date_utc}",
  "git_commit":   "${full}",
  "git_short":    "${short}",
  "git_branch":   "${branch}",
  "git_describe": "${describe}",
  "dirty":        ${dirty},
  "n_tables":     ${ntables},
  "generator":    "KISS-CosmicRayDataBase"
}
EOF

out="${out_dir}/kiss_tables_${stamp}_${short}.tar.gz"
tar -czf "$out" -C "$stage" MANIFEST.json kiss_tables

echo "wrote ${out} (${ntables} tables, commit ${short})"
