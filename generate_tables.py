import read_table_ASI as ASI
import read_table_CRDB as CRDB
import write_table as wt

import numpy as np

credit_asi = "# credit: SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays \n"
credit_crdb = "# credit: CRDB Database lpsc.in2p3.fr/cosmic-rays-db \n"

def data_protons_AMS02(ssdc_filename, output_filename):
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table_H(ssdc_filename)
    wt.write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)

def data_nuclei_AMS02(ssdc_filename, output_filename):
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table_flux(ssdc_filename)
    wt.write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
def data_ratio_AMS02(ssdc_filename, output_filename):
    R, ratio, ratio_err_low, ratio_err_high = ASI.get_table_ratio(ssdc_filename)
    wt.write_rigidity_table(credit_asi, output_filename, R, ratio, ratio_err_low, ratio_err_high)

### DATABASE
data_protons_AMS02("ASI/p_AMS_PRL2015_000.xml", "kiss_tables/H_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/He_AMSPRL2017_rig_000.xml", "kiss_tables/He_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/C_AMSPRL2017_rig_000.xml", "kiss_tables/C_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/O_AMSPRL2017_rig_000.xml", "kiss_tables/O_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/Ne_AMS_PRL____2020_rig_000.xml", "kiss_tables/Ne_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/Mg_AMS_PRL____2020_rig_000.xml", "kiss_tables/Mg_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/Si_AMS_PRL____2020_rig_000.xml", "kiss_tables/Si_AMS02_rigidity.txt")

data_ratio_AMS02("ASI/C_O_ratio_AMS_PRL2017_rig_000.xml", "kiss_tables/CO_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/B_C_ratio_AMS_PRL2018_rig_000.xml", "kiss_tables/BC_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/Si_O_ratio_AMS_PRL____2020_rig_000.xml", "kiss_tables/SiO_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/Si_Mg_ratio_AMS_PRL____2020_rig_000.xml", "kiss_tables/SiMg_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/Ne_O_ratio_AMS_PRL____2020_rig_000.xml", "kiss_tables/NeO_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/Ne_Mg_ratio_AMS_PRL____2020_rig_000.xml", "kiss_tables/NeMg_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/Mg_O_ratio_AMS_PRL____2020_rig_000.xml", "kiss_tables/MgO_ratio_AMS02_rigidity.txt")

