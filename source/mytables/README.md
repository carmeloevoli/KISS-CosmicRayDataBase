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

### Tibet-III 2008 all-particle spectrum

- Source paper: Tibet AS-gamma Collaboration, "The all-particle spectrum of primary cosmic rays in the wide energy range from 10^14 eV to 10^17 eV observed with the Tibet-III air-shower array", arXiv:0801.1803
- PDF: `https://arxiv.org/pdf/0801.1803`
- Added on: April 23, 2026
- Provenance: manually transcribed from Table `5`
- Quantities: differential all-particle flux as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E`, then `flux stat` triplets for `QGSJET+HD`, `QGSJET+PD`, and `SIBYLL+HD`
- Note: the archived per-model drafts in `source/mytables/old/` were checked against Table `5` and match the published values

Files:

- `Tibet-III_allParticle_totalEnergy.txt` from Table `5`

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

### TUNKA-133 2020 all-particle spectrum

- Source paper: Tunka-133 Collaboration, "Cosmic ray energy spectrum and mass composition from \(2\cdot10^{15}\) to \(3\cdot10^{18}\) eV by data of the Tunka-133 array"
- DOI: `10.1016/j.astropartphys.2019.102406`
- Added on: April 23, 2026
- Provenance: local text export previously stored under `source/KCDC/`; moved to `mytables` because the file stores separate statistical and systematic uncertainties and needs a dedicated reader
- Quantities: differential all-particle flux as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E Flux UncertLow UncertHigh SysUncertLow SysUncertHigh`
- Note: the file keeps the original six-column semicolon-separated structure rather than collapsing the uncertainties

Files:

- `TUNKA-133_allParticle_totalEnergy.txt`

### CALET 2023 all-electron spectrum

- Source paper: CALET Collaboration, "Extended Measurement of the Cosmic-Ray Electron and Positron Spectrum from 11 GeV to 4.8 TeV with the Calorimetric Electron Telescope on the International Space Station"
- DOI: `10.1103/PhysRevLett.131.191001`
- Added on: April 23, 2026
- Provenance: manually transcribed from Table `I`; promoted from `source/mytables/old/` to the active directory so it can be loaded directly by KISS
- Quantities: differential all-electron (`e+ + e-`) flux as a function of total energy
- Units: energy in `GeV`; flux in `GeV^-1 m^-2 s^-1 sr^-1`
- Stored columns: `E_min E_max E_mean flux stat_lo stat_up syst_lo syst_up`

Files:

- `CALET_e+e-_totalEnergy.txt` from Table `I`

### CALET 2025 chromium, titanium, and sub-iron to iron ratios

- Source paper: CALET Collaboration, "Precision spectral measurements of Chromium and Titanium from 10 to 250 GeV/n and sub-Iron to Iron ratio with the Calorimetric Electron Telescope on the ISS", arXiv:2507.08643
- PDF: `https://arxiv.org/pdf/2507.08643`
- Added on: April 23, 2026
- Provenance: manually transcribed from Tables `1`, `2`, `4`, and `5`
- Quantities: differential chromium and titanium fluxes, plus `Ti/Fe` and `Cr/Fe` ratios, as functions of kinetic energy per nucleon
- Flux-table units: energy in `GeV/n`; flux in `(GeV/n)^-1 m^-2 s^-1 sr^-1`
- Flux-table stored columns: `E_min E_max flux stat syst_norm syst_dep_lo syst_dep_up`
- Ratio-table units: energy in `GeV/n`; ratio is dimensionless
- Ratio-table stored columns: `E_min E_max ratio stat syst_lo syst_up`
- Note: the flux tables quote statistical, normalization-systematic, and energy-dependent systematic components; the ratio tables quote statistical and total systematic uncertainties

Files:

- `CALET_Ti_kineticEnergyPerNucleon.txt` from Table `1`
- `CALET_Cr_kineticEnergyPerNucleon.txt` from Table `2`
- `CALET_Ti_Fe_kineticEnergyPerNucleon.txt` from Table `4`
- `CALET_Cr_Fe_kineticEnergyPerNucleon.txt` from Table `5`

### VERITAS 2018 CRE spectrum

- Source paper: VERITAS Collaboration, "Measurement of cosmic-ray electrons at TeV energies by VERITAS", arXiv:1808.10028
- PDF: `https://arxiv.org/pdf/1808.10028`
- DOI: `10.1103/PhysRevD.98.062004`
- Added on: April 23, 2026
- Provenance: manually transcribed from Table `1`
- Quantities: differential CRE (`e+ + e-`) flux as a function of total energy
- Units: energy columns in `TeV`; flux in `cm^-2 s^-1 TeV^-1`
- Stored columns: `E E_min E_max N_events electron_fraction electron_fraction_err flux stat`
- Note: Table `1` reports statistical uncertainties for the flux; broader systematic uncertainties are discussed in the paper text

Files:

- `VERITAS_e+e-_totalEnergy.txt` from Table `1`

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
