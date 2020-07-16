import read_table_ASI as ASI
import read_table_CRDB as CRDB
import write_table as wt

import numpy as np

credit_asi = "SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays"
credit_crdb = "CRDB Database lpsc.in2p3.fr/cosmic-rays-db"

def data_posfraction_ASI(ssdc_filename, output_filename):
    E, ratio, ratio_err_low, ratio_err_high = ASI.get_table_posfrac(ssdc_filename)
    wt.write_kE_table(credit_asi, output_filename, E, ratio, ratio_err_low, ratio_err_high)

def data_posfraction_CRDB(crdb_filename, output_filename):
    E, ratio, ratio_err_low, ratio_err_high = CRDB.get_table_posfrac(crdb_filename)
    wt.write_kE_table(credit_crdb, output_filename, E, ratio, ratio_err_low, ratio_err_high)

def data_flux_ASI(ssdc_filename, output_filename):
    E, ratio, ratio_err_low, ratio_err_high = ASI.get_table_lepton_flux(ssdc_filename)
    wt.write_kE_table(credit_asi, output_filename, E, ratio, ratio_err_low, ratio_err_high)

def data_flux_VERITAS(txt_filename, output_filename):
    E, ratio, ratio_err_low, ratio_err_high = ASI.get_table_VERITAS(txt_filename)
    wt.write_kE_table("arXiv:1808.10028 - Table I", output_filename, E, ratio, ratio_err_low, ratio_err_high)

### Positron fraction
data_posfraction_ASI("ASI/posfrac_AMS_PRL2019_ekin_000.xml", "kiss_tables/posfrac_AMS02_kenergy.txt")
data_posfraction_ASI("ASI/posfrac_FER_PRL2012_000.xml", "kiss_tables/posfrac_FERMI_kenergy.txt")
data_posfraction_CRDB("CRDB/PAMELA_posfraction_PRL2013.txt", "kiss_tables/posfrac_PAMELA_kenergy.txt")

### Positrons
data_flux_ASI("ASI/pos_PAM_PRL2013_000.xml", "kiss_tables/positrons_PAMELA_kenergy.txt")
data_flux_ASI("ASI/pos_FER_PRL2012_000.xml", "kiss_tables/positrons_FERMI_kenergy.txt")
data_flux_ASI("ASI/e+_AMS_PRL2019_ekin_000.xml", "kiss_tables/positrons_AMS02_kenergy.txt")

### Electrons
data_flux_ASI("ASI/ele_PAM_PRL2011_000.xml", "kiss_tables/electrons_PAMELA_kenergy.txt")
data_flux_ASI("ASI/ele_FER_PRL2012_000.xml", "kiss_tables/electrons_FERMI_kenergy.txt")
data_flux_ASI("ASI/e-_AMS_PRL2019_ekin_000.xml", "kiss_tables/electrons_AMS02_kenergy.txt")

### Electrons + Positrons
data_flux_ASI("ASI/e+e-_AMS_PRL2019_ekin_000.xml", "kiss_tables/leptons_AMS02_kenergy.txt")
data_flux_ASI("ASI/e+e-_CALET_PRL2018_binningDAMPE_ekin_000.xml", "kiss_tables/leptons_CALET_kenergy.txt")
data_flux_ASI("ASI/e+e-_DAMPE_NATURE2017_000.xml", "kiss_tables/leptons_DAMPE_kenergy.txt")
data_flux_ASI("ASI/e+e-_FERMI_PRD2017_HE_000.xml", "kiss_tables/leptons_FERMI_kenergy.txt")
data_flux_VERITAS("tables_txt/VERITAS_1808_10028.txt", "kiss_tables/leptons_VERITAS_kenergy.txt")
