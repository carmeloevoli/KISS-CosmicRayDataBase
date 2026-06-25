# CRDB source tables

This folder contains cosmic-ray measurement tables retrieved from the **Cosmic-Ray Data Base
(CRDB)** and used as input by KISS. These are upstream source files: KISS reads them and converts
them into the uniform output tables written to `build/output/` (and curated in `kiss_tables/`).

CRDB is the authoritative upstream source for these data. All credit for the original data,
curation, and database infrastructure belongs to CRDB and to the experimental collaborations that
produced the measurements.

- CRDB: https://lpsc.in2p3.fr/crdb
- Reference: Maurin et al., *A cosmic-ray database update: CRDB v4.1*,
  [2023EPJC...83..971M](https://ui.adsabs.harvard.edu/abs/2023EPJC...83..971M/abstract)

Please cite CRDB and the original publication of each dataset (see the `#ads:` line of each file)
when using these data.

## File format

Each `.txt` file has two comment header lines followed by the data:

```
#ads: 2021PhRvL.127b1101A
#E_lo - E_up - y - errSta_lo - errSta_up - errSys_lo - errSys_up
2.15000e+00 2.40000e+00 4.78800e-02 5.50000e-04 5.50000e-04 4.25000e-03 4.25000e-03
...
```

- **Line 1 — `#ads:`** the ADS bibcode of the scientific publication the dataset comes from, so
  every table can be traced back to its original paper.
- **Line 2** the column legend.
- **Data rows** seven whitespace-separated columns:

  | Column | Meaning |
  | --- | --- |
  | `E_lo`, `E_up` | lower and upper edge of the energy/rigidity bin |
  | `y` | measured quantity (flux, ratio, …) |
  | `errSta_lo`, `errSta_up` | lower/upper statistical uncertainty |
  | `errSys_lo`, `errSys_up` | lower/upper systematic uncertainty |

The loader [`CRDB::readfile`](../../src/CRDB.cpp) skips the two header lines, reads the seven
columns, and collapses each bin to a single representative energy via
`Utils::computeMeanEnergy(E_lo, E_up, mode)`.

## File naming

File names follow the pattern produced by `CrDataset::makeSourceFilename()`:

```
<Experiment>[_<description>]_<yQuantity>_<xQuantity>.txt
```

for example `AMS-02_B_C_rigidity.txt` or `Auger_SD_allParticle_totalEnergy.txt`. Keeping this
convention lets KISS locate the source table for each dataset without extra glue code.

## Experiments currently included

AMS-02, Auger, BESS-TeV, CALET, CREAM, DAMPE, FERMI, HAWC, HESS, ISS-CREAM, IceTop, KASCADE,
KASCADE-Grande, NUCLEON, PAMELA, TA, TALE, Tibet, TRACER, TUNKA-133.
