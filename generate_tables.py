import read_table_ASI as ASI
import read_table_CRDB as CRDB
import write_table as wt

import numpy as np

credit_asi = "# credit: SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays \n"
credit_crdb = "# credit: CRDB Database lpsc.in2p3.fr/cosmic-rays-db \n"

def data_nuclei_AMS02(ssdc_filename, output_filename):
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table_flux(ssdc_filename)
    wt.write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
def data_ratio_AMS02(ssdc_filename, output_filename):
    R, ratio, ratio_err_low, ratio_err_high = ASI.get_table_ratio(ssdc_filename)
    wt.write_rigidity_table(credit_asi, output_filename, R, ratio, ratio_err_low, ratio_err_high)

### DATABASE
data_nuclei_AMS02("ASI/p_AMS_PRL2015_000.xml", "kiss_tables/H_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/He_AMSPRL2017_rig_000.xml", "kiss_tables/He_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/C_AMSPRL2017_rig_000.xml", "kiss_tables/C_AMS02_rigidity.txt")
data_nuclei_AMS02("ASI/O_AMSPRL2017_rig_000.xml", "kiss_tables/O_AMS02_rigidity.txt")

data_ratio_AMS02("ASI/C_O_ratio_AMS_PRL2017_rig_000.xml", "kiss_tables/CO_ratio_AMS02_rigidity.txt")
data_ratio_AMS02("ASI/B_C_ratio_AMS_PRL2018_rig_000.xml", "kiss_tables/BC_ratio_AMS02_rigidity.txt")
