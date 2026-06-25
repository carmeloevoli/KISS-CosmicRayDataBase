# MyTables

This folder contains plain-text tables manually converted from figures, tables, or supplementary material in original publications when the data are not retrieved through CRDB or another automated source.

## Conventions

- Each dataset should have a short provenance note in this README when it is added.
- The `old/` subfolder keeps superseded drafts or previous local versions; files in the top-level `data/mytables/` directory are the current versions used by KISS.
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

### LHAASO 2024 all-particle spectrum and mean logarithmic mass

- Source paper: LHAASO Collaboration, "All-particle energy spectrum and mean logarithmic mass of cosmic rays with LHAASO"
- DOI: `10.1103/PhysRevLett.132.131002`
- Local source: `data/mytables/pdfs/SuppMaterial_PhysRevLett.132.131002.pdf`
- Added on: April 29, 2026
- Provenance: manually transcribed from Supplementary Tables `S5` and `S6`
- Quantities: differential all-particle flux and mean logarithmic mass `lnA` as functions of total energy
- Units: the first two columns store `log10(E/GeV)` bin edges
- Table `S5` stored columns: `log10E_min log10E_max` followed by `flux stat syst` triplets for `QGSJET-II-04`, `EPOS-LHC`, and `SIBYLL-2.3d`
- Table `S6` stored columns: `log10E_min log10E_max` followed by `lnA stat syst` triplets for `QGSJET-II-04`, `EPOS-LHC`, and `SIBYLL-2.3d`
- Note: the quoted systematic uncertainties explicitly exclude the hadronic-interaction-model uncertainty

Files:

- `LHAASO_allParticle_totalEnergy.txt` from Table `S5`
- `LHAASO_lnA_totalEnergy.txt` from Table `S6`

### KASCADE 2024 Kuznetsov component spectra, all-particle spectrum, and mean mass

- Source paper: Kuznetsova et al., "Energy spectra of elemental groups of cosmic rays with the KASCADE experiment data and machine learning", arXiv:2312.08279
- PDF: `https://arxiv.org/pdf/2312.08279`
- Added on: April 27, 2026
- Provenance: manually extracted from Tables `1`, `2`, and `3` in the paper appendix
- Quantities: mean logarithmic mass `lnA`, elemental-group differential fluxes, and all-particle differential flux as functions of total energy
- Units: the first two columns store `log10(E/GeV)` bin edges; fluxes are in `m^-2 s^-1 sr^-1 GeV^-1`
- Table `1` stored columns: `log10E_min log10E_max lnA stat sys_basic th_unc_lo th_unc_up`
- Table `2` stored columns: `log10E_min log10E_max flux stat sys_basic`
- Table `3` stored columns: `log10E_min log10E_max flux stat sys_basic th_unc_lo th_unc_up`
- Note: Table `2` tabulates `p`, `He`, `C`, `Si`, and `Fe`; it does not provide an oxygen table

Files:

- `KASCADE_Kuznetsov2024_lnA_totalEnergy.txt` from Table `1`
- `KASCADE_Kuznetsov2024_H_totalEnergy.txt` from Table `2` (`p`)
- `KASCADE_Kuznetsov2024_He_totalEnergy.txt` from Table `2`
- `KASCADE_Kuznetsov2024_C_totalEnergy.txt` from Table `2`
- `KASCADE_Kuznetsov2024_Si_totalEnergy.txt` from Table `2`
- `KASCADE_Kuznetsov2024_Fe_totalEnergy.txt` from Table `2`
- `KASCADE_Kuznetsov2024_allParticle_totalEnergy.txt` from Table `3`

### Tibet-III 2008 all-particle spectrum

- Source paper: Tibet AS-gamma Collaboration, "The all-particle spectrum of primary cosmic rays in the wide energy range from 10^14 eV to 10^17 eV observed with the Tibet-III air-shower array", arXiv:0801.1803
- PDF: `https://arxiv.org/pdf/0801.1803`
- Added on: April 23, 2026
- Provenance: manually transcribed from Table `5`
- Quantities: differential all-particle flux as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E`, then `flux stat` triplets for `QGSJET+HD`, `QGSJET+PD`, and `SIBYLL+HD`
- Note: the archived per-model drafts in `data/mytables/old/` were checked against Table `5` and match the published values

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
- Provenance: local text export previously stored under `data/KCDC/`; moved to `mytables` because the file stores separate statistical and systematic uncertainties and needs a dedicated reader
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
- Provenance: manually transcribed from Table `I`; promoted from `data/mytables/old/` to the active directory so it can be loaded directly by KISS
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
- Added on: April 28, 2026
- Provenance: manually transcribed from Table `S5` of the supplemental material
- Local source: `data/mytables/pdfs/SuppMaterial_PhysRevLett.132.051002.pdf`
- Quantities: differential proton flux as a function of total energy
- Units: energy in `GeV`; flux in `m^-2 s^-1 sr^-1 GeV^-1`
- Stored columns: `E flux stat syst_up syst_lo`

Files:

- `GRAPES-3_H_totalEnergy.txt`

### TALE 2026 composition moments and mean logarithmic mass

- Source paper: Telescope Array Collaboration, "Cosmic ray mass composition measurement in the energy range from 10^16.5 eV to 10^18.5 eV observed with the TALE hybrid detector", arXiv:2603.14804
- PDF: `https://arxiv.org/pdf/2603.14804`
- Added on: April 29, 2026
- Provenance: manually transcribed from Appendix Table `A.1`
- Quantities: first two moments of the `Xmax` distributions together with mean logarithmic mass `lnA` as functions of total energy
- Units: the first two columns store published `log10(E/eV)` bin edges; `Xmax` and `sigmaXmax` are in `g/cm^2`; `lnA` is dimensionless
- Stored columns: `log10E_min_eV log10E_max_eV N Xmax Xmax_stat Xmax_sys_lo Xmax_sys_up sigmaXmax sigmaXmax_stat sigmaXmax_sys_lo sigmaXmax_sys_up lnA lnA_stat lnA_sys_lo lnA_sys_up`
- Note: this file keeps all columns from Table `A.1`; the last four columns are the `lnA` observable and its uncertainties

Files:

- `TALE_lnA_totalEnergy.txt` from Table `A.1`

### Yakutsk 2019 mean logarithmic mass and shower-maximum moments

- Source paper: Knurenko and Petrov, "Mass composition of cosmic rays above 0.1 EeV by the Yakutsk array data"
- Journal DOI: `10.1016/j.asr.2019.07.019`
- Fallback PDF used for extraction: `https://arxiv.org/pdf/1908.01508.pdf`
- Added on: April 29, 2026
- Provenance: manually transcribed from Tables `II` and `III`
- Quantities: `Xmax`, `sigma(Xmax)`, and mean logarithmic mass `lnA` as functions of total energy
- Units: `E0` is stored exactly as published in `eV`; `Xmax` and `sigma(Xmax)` are in `g/cm^2`; `lnA` is dimensionless
- Stored columns: `E0_eV N_events Xmax Xmax_stat sigmaXmax sigmaXmax_stat lnA lnA_stat`
- Note: the first two rows in Table `II` do not report `N` or `sigma(Xmax)` and therefore keep `-` placeholders; the published `0,64` decimal comma in Table `III` was normalized to `0.64`

Files:

- `Yakutsk_lnA_totalEnergy.txt` from Tables `II` and `III`
