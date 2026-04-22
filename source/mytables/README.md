# MyTables

This folder contains plain-text tables manually converted from figures, tables, or supplementary material in original publications when the data are not retrieved through CRDB or another automated source.

## Conventions

- Each dataset should have a short provenance note in this README when it is added.
- The `old/` subfolder keeps superseded drafts or previous local versions; files in the top-level `source/mytables/` directory are the current versions used by KISS.
- File naming should follow the same pattern used by `CrDataset::makeSourceFilename()`, so the text tables can be loaded without extra glue code.

## Current Entries

### DAMPE 2024 light component spectrum

- Source paper: DAMPE Collaboration, "Measurement of the cosmic p+He energy spectrum from 50 GeV to 0.5 PeV with the DAMPE space mission", arXiv:2304.00137
- PDF: `https://arxiv.org/pdf/2304.00137`
- Added on: April 22, 2026
- Provenance: manually transcribed from Supplementary Table `S1`
- Quantities: differential light-component (`p+He`) flux as a function of total energy
- Units: energy in `GeV`; flux in `GeV^-1 m^-2 s^-1 sr^-1`
- Stored columns: `E E_min E_max flux stat sys_ana sys_had`

Files:

- `DAMPE_light_totalEnergy.txt` from Table `S1`

### DAMPE 2024 boron spectrum

- Source paper: DAMPE Collaboration, "Observation of a spectral hardening in cosmic ray boron spectrum with the DAMPE space mission", arXiv:2412.11460
- PDF: `https://arxiv.org/pdf/2412.11460`
- Added on: April 22, 2026
- Provenance: manually transcribed from Supplementary Table `S1`
- Quantities: differential boron flux as a function of kinetic energy per nucleon
- Units: kinetic energy per nucleon in `GeV/n`; flux in `(GeV/n)^-1 m^-2 s^-1 sr^-1`
- Stored columns: `E E_min E_max flux stat sys_ana sys_had`
- Note: the paper states that the average mass number used to compute kinetic energy per nucleon is `A = 10.7`

Files:

- `DAMPE_B_kineticEnergyPerNucleon.txt` from Table `S1`

### DAMPE 2025 primary nuclei spectra

- Source paper: DAMPE Collaboration, "Charge-dependent spectral softenings of primary cosmic-rays from proton to iron below the knee", arXiv:2511.05409
- PDF: `https://arxiv.org/pdf/2511.05409`
- Added on: April 21, 2026
- Provenance: manually transcribed from Supplementary Tables `S1` to `S5`
- Quantities: differential fluxes as a function of kinetic energy
- Units: kinetic energy in `GeV`; flux in `GeV^-1 m^-2 s^-1 sr^-1`
- Stored columns: `E_min E_max flux stat sys_ana sys_had`

Files:

- `DAMPE_2025_H_kineticEnergy.txt` from Table `S1` (proton)
- `DAMPE_2025_He_kineticEnergy.txt` from Table `S2` (helium)
- `DAMPE_2025_C_kineticEnergy.txt` from Table `S3` (carbon)
- `DAMPE_2025_O_kineticEnergy.txt` from Table `S4` (oxygen)
- `DAMPE_2025_Fe_kineticEnergy.txt` from Table `S5` (iron)

### LHAASO 2025 light, helium, and proton spectra

- Source paper: LHAASO Collaboration, "Precise Measurement of the Cosmic Ray Helium Spectrum above 0.1 PeV", arXiv:2511.05013
- PDF: `https://arxiv.org/pdf/2511.05013`
- Added on: April 21, 2026
- Provenance: manually transcribed from Supplementary Tables `S1`, `S3`, and `S5`
- Quantities: differential fluxes as a function of total energy
- Units: `log10(E/PeV)` bin edges in the first two columns; fluxes in `PeV^-1 m^-2 s^-1 sr^-1`
- Stored columns: `log10E_min log10E_max` followed by `flux stat syst` triplets for `QGSJET-II-04`, `EPOS-LHC`, and `SIBYLL-2.3d`

Files:

- `LHAASO_light_totalEnergy.txt` from Table `S1`
- `LHAASO_helium_totalEnergy.txt` from Table `S3`
- `LHAASO_proton_totalEnergy.txt` from Table `S5`

### HAWC 2022 light spectrum

- Source paper: HAWC Collaboration, "Measurement of the light component spectrum of cosmic rays with HAWC", arXiv:2204.06662
- PDF: `https://arxiv.org/pdf/2204.06662`
- Added on: April 21, 2026
- Provenance: manually transcribed from Table `2`
- Quantities: differential flux of the light component as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E flux stat syst_up syst_lo`

Files:

- `HAWC_light_totalEnergy.txt` from Table `2`

### GRAPES-3 2024 proton spectrum

- Source paper: GRAPES-3 Collaboration, "Evidence of a Hardening in the Cosmic Ray Proton Spectrum at around 166 TeV Observed by the GRAPES-3 Experiment"
- DOI: `10.1103/PhysRevLett.132.051002`
- Added on: April 21, 2026
- Provenance: manually transcribed from the table contained in the attached local PDF copy provided by the user; the attachment table is not public in the paper landing page
- Local source: `/Users/carmeloevoli/Documents/Papers Library/Varsi-Evidence of a Hardening in the Cosmic Ray Proton Spectrum at around 166 TeV Observed by the GRAPES-3 Experiment-2024-Physical Review Letters.pdf`
- Quantities: differential proton flux as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E flux stat syst_up syst_lo`

Files:

- `GRAPES_H_totalEnergy.txt`
