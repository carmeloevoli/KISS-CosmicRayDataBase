# KISS Cosmic Ray Database Converter

This repository is a converter for cosmic-ray measurement tables. Its purpose is to read datasets from public sources and rewrite them into a simple, uniform plain-text format used by KISS.

It is important to be clear that this repository is **not** the primary source of the scientific data. The measurements, metadata, and the main data curation work come from external databases and the original experimental publications.

## Data Credit

The main upstream sources used by this project are:

- CRDB: https://lpsc.in2p3.fr/cosmic-rays-db/
- KCDC: https://kcdc.iap.kit.edu

All credit for the original data, database infrastructure, curation effort, and long-term maintenance belongs to those projects and to the experimental collaborations that produced the measurements.

If a dataset is available in CRDB or KCDC, those websites should be considered the authoritative upstream source, and they should receive the credit.
The repository may still contain some support code for other sources, but CRDB and KCDC are the main upstream data providers for this project.

## What This Code Does

This codebase:

- reads measurement tables from supported upstream sources
- converts them into a consistent local text format
- writes the converted tables to `build/output/`

In other words, this repository is a formatting and conversion layer, not a replacement for CRDB or KCDC.

## About `source/mytables/`

Some newer results and supplementary tables are not yet available in CRDB or KCDC. In those cases, this repository includes local plain-text tables in `source/mytables/`.

These files are:

- manually transcribed from the original papers or supplementary material
- included only to cover gaps where upstream database entries are not yet available
- documented with provenance notes in [source/mytables/README.md](source/mytables/README.md)

The `mytables` directory is therefore a convenience layer for missing recent data, not a claim of ownership over those measurements.

## Repository Layout

- `source/CRDB/` stores source files retrieved from CRDB
- `source/KCDC/` stores source files retrieved from KCDC
- `source/mytables/` stores manually added tables for datasets not yet available upstream
- `build/output/` contains the converted plain-text tables produced by the executable

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

## Attribution Reminder

Please cite and acknowledge the original databases and experimental publications when using these data. This repository only helps convert and organize the tables into a uniform format for downstream use.
