# MyTables

This folder contains plain-text tables manually converted from figures, tables, or supplementary material in original publications when the data are not retrieved through CRDB or another automated source.

## Conventions

- Each dataset should have a short provenance note in this README when it is added.
- The `old/` subfolder keeps superseded drafts or previous local versions; files in the top-level `data/mytables/` directory are the current versions used by KISS.
- File naming should follow the same pattern used by `CrDataset::makeSourceFilename()`, so the text tables can be loaded without extra glue code.

## Current Entries

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
