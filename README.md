# KISS Cosmic Ray Database Converter

This repository is a converter for cosmic-ray measurement tables. Its purpose is to read datasets from public sources and rewrite them into a simple, uniform plain-text format used by KISS.

It is important to be clear that this repository is **not** the primary source of the scientific data. The measurements, metadata, and the main data curation work come from external databases and the original experimental publications.

## Data Credit

The main upstream sources used by this project are:

- CRDB: https://lpsc.in2p3.fr/cosmic-rays-db/
- KCDC: https://kcdc.iap.kit.edu

All credit for the original data, database infrastructure, curation effort, and long-term maintenance belongs to those projects and to the experimental collaborations that produced the measurements.

If a dataset is available in [CRDB](https://ui.adsabs.harvard.edu/abs/2023EPJC...83..971M/abstract) or KCDC, those websites should be considered the authoritative upstream source, and they should receive the credit.
The repository may still contain some support code for other sources, but CRDB and KCDC are the main upstream data providers for this project.

## What This Code Does

This codebase:

- reads measurement tables from supported upstream sources
- converts them into a consistent local text format
- writes the converted tables to `build/output/`

In other words, this repository is a formatting and conversion layer, not a replacement for CRDB or KCDC.

## Table Format

Each converted table begins with a comment header (lines starting with `#`) that records the
provenance of the dataset. In particular, the `#Ref:` line tracks the scientific publication the
measurements come from, given as its DOI and ADS bibcode, so every table can be traced back to the
original paper:

```
#Source: CRDB
#Ref: 10.1016/j.physrep.2020.09.003 (2021PhR...894....1A)
#Experiment: AMS-02
#Y Quantity: B_C
#X Quantity: rigidity
#Url: https://lpsc.in2p3.fr/crdb
#Comments:
#Columns: x, y, y statistical errors, y systematic errors
```

Please cite the publication referenced in each table when using its data.

## About `data/mytables/`

Some newer results and supplementary tables are not yet available in CRDB or KCDC. In those cases, this repository includes local plain-text tables in `data/mytables/`.

These files are:

- manually transcribed from the original papers or supplementary material
- included only to cover gaps where upstream database entries are not yet available
- documented with provenance notes in [data/mytables/README.md](data/mytables/README.md)

The `mytables` directory is therefore a convenience layer for missing recent data, not a claim of ownership over those measurements.

## Repository Layout

- `src/` and `include/` contain the C++ converter source code
- `data/CRDB/` stores input files retrieved from CRDB
- `data/KCDC/` stores input files retrieved from KCDC
- `data/mytables/` stores manually added tables for datasets not yet available upstream
- `build/output/` contains the converted plain-text tables produced by the executable
- `kiss_tables/` holds the curated copy of the converted tables

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/KISS
```

Running the executable processes the enabled experiment loaders and writes the converted tables into `build/output/`.

## Regenerating and Packaging

The curated `kiss_tables/` directory and the distributable archive are produced in two stages.

**1. Regenerate `kiss_tables/`** — rebuilds, runs the converter, and mirrors the output into
`kiss_tables/`:

```bash
scripts/regenerate.sh
```

If the converter reports any missing input files, `kiss_tables/` is left untouched (an
incomplete run will not delete good tables). Fetch the missing source data first, e.g.
`python data/get_crdb_data.py` for the CRDB tables.

**2. Package a tarball** — after reviewing `git diff kiss_tables/` and committing, build a
provenance-stamped archive into `tarballs/`:

```bash
scripts/make_tarball.sh            # writes tarballs/kiss_tables_<UTCdate>_<gitshort>.tar.gz
scripts/make_tarball.sh /some/dir  # or to a directory of your choice
```

The archive contains a `MANIFEST.json` (generation date, git commit/branch, table count)
alongside the tables, so it records how and when it was generated. Archives built from an
uncommitted working tree are tagged with a `-dirty` suffix.

To run both stages at once (the tarball will be `-dirty` if `kiss_tables/` changed and was not
committed first):

```bash
scripts/regenerate.sh --tarball
```

## Attribution Reminder

Please cite and acknowledge the original databases and experimental publications when using these data. This repository only helps convert and organize the tables into a uniform format for downstream use.
