import read_table_ASI as ASI
import read_table_CRDB as CRDB
import numpy as np

proton_mass_GeV = 938.27231e-3

def write_rigidity_table(credit, filename, R, f, f_err_low, f_err_high):
    file = open(filename, "w") 
    file.write(credit)
    file.write("# rigidity [GV] - flux [] - flux_error_low [] - flux_error_high [] \n")
    for i in range(len(R)):
        line = '{0:1.5e}'.format(R[i]) + "   "
        line += '{0:1.5e}'.format(f[i]) + "   "
        line += '{0:1.5e}'.format(f_err_low[i]) + "   "
        line += '{0:1.5e}'.format(f_err_high[i]) + "   "
        line += "\n"
        file.write(line)
    file.close()     

def T_2_rigidity(T, A, Z):
    return float(A / Z) * np.sqrt(T * T + 2. * proton_mass_GeV * T)

def E_2_rigidity(E, Z):
    return float(1. / Z) * np.sqrt(E * E - proton_mass_GeV * proton_mass_GeV)

def dNdT_2_dNdR(dNdT, T, A, Z):
    dRdT = float(A / Z) * (T + proton_mass_GeV) / np.sqrt(T * T + 2. * proton_mass_GeV * T)
    return dNdT / dRdT

def dNdE_2_dNdR(dNdE, E, Z):
    dRdE = float(1. / Z) * E / np.sqrt(E * E - proton_mass_GeV * proton_mass_GeV)
    

credit_asi = "# credit: SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays \n"
credit_crdb = "# credit: CRDB Database lpsc.in2p3.fr/cosmic-rays-db \n"

def data_from_AMS02():
    #  C from AMS02 in rigidity 
    ssdc_filename = "data/C_AMSPRL2017_rig_000.xml"
    output_filename = "kiss_tables/C_AMS02_rigidity.txt"
    
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table(ssdc_filename)
    
    write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
    # O from AMS02 in rigidity
    ssdc_filename = "data/O_AMSPRL2017_rig_000.xml"
    output_filename = "kiss_tables/O_AMS02_rigidity.txt"
    
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table(ssdc_filename)
    
    write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
    # He from AMS02 in rigidity
    ssdc_filename = "data/He_AMSPRL2017_rig_000.xml"
    output_filename = "kiss_tables/He_AMS02_rigidity.txt"
    
    R, dNdR, dNdR_err_low, dNdR_err_high = ASI.get_table(ssdc_filename)
    
    write_rigidity_table(credit_asi, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
    # H from AMS02 in rigidity
    crdb_filename = "data/H_AMS02_rig_CRDB.txt"
    output_filename = "kiss_tables/H_AMS02_rigidity.txt"
    
    R, dNdR, dNdR_err_low, dNdR_err_high = CRDB.get_table(crdb_filename)
    
    write_rigidity_table(credit_crdb, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)

def data_from_CREAM():
    # H from CREAM-I in E
    crdb_filename = "data/H_CREAMI_ekn_CRDB.txt"
    output_filename = "kiss_tables/H_CREAMI_rigidity.txt"
    
    T, dNdT, dNdT_err_low, dNdT_err_high = CRDB.get_table(crdb_filename)

    R = T_2_rigidity(T, 1, 1)
    dNdR = dNdT_2_dNdR(dNdT, T, 1, 1)
    dNdR_err_low = dNdT_2_dNdR(dNdT_err_low, T, 1, 1)
    dNdR_err_high = dNdT_2_dNdR(dNdT_err_high, T, 1, 1)
    
    write_rigidity_table(credit_crdb, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)

    # He from CREAM-I in E/n
    crdb_filename = "data/He_CREAMI_ekn_CRDB.txt"
    output_filename = "kiss_tables/He_CREAMI_rigidity.txt"

    T, dNdT, dNdT_err_low, dNdT_err_high = CRDB.get_table(crdb_filename)

    R = T_2_rigidity(T, 4, 2)
    dNdR = dNdT_2_dNdR(dNdT, T, 4, 2)
    dNdR_err_low = dNdT_2_dNdR(dNdT_err_low, T, 4, 2)
    dNdR_err_high = dNdT_2_dNdR(dNdT_err_high, T, 4, 2)
    
    write_rigidity_table(credit_crdb, output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)

    # H from CREAM-III
    my_filename = "data/H_CREAMIII_ekn_mydata.txt"
    output_filename = "kiss_tables/H_CREAMIII_rigidity.txt"

    T_low, T_up, dNdT, dNdT_err_low, dNdT_err_high = np.loadtxt(my_filename, skiprows=2, usecols=(0,1,2,3,4), unpack=True)

    print "read " + my_filename + " with data size : ", len(dNdT)
    
    T = CRDB.compute_mean_rigidity(T_low, T_up, 2.7)

    R = T_2_rigidity(T, 1, 1)
    dNdR = dNdT_2_dNdR(dNdT, T, 1, 1)
    dNdR_err_low = dNdT_2_dNdR(dNdT_err_low, T, 1, 1)
    dNdR_err_high = dNdT_2_dNdR(dNdT_err_high, T, 1, 1)

    write_rigidity_table("# credit: Ref. Yoon et al., ApJ, 839:5, 2017", output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)

    # He from CREAM-III
    my_filename = "data/He_CREAMIII_ekn_mydata.txt"
    output_filename = "kiss_tables/He_CREAMIII_rigidity.txt"

    T_low, T_up, dNdT, dNdT_err_low, dNdT_err_high = np.loadtxt(my_filename, skiprows=2, usecols=(0,1,2,3,4), unpack=True)

    print "read " + my_filename + " with data size : ", len(dNdT)
    
    T = CRDB.compute_mean_rigidity(T_low, T_up, 2.7)

    R = T_2_rigidity(T, 4, 2)
    dNdR = dNdT_2_dNdR(dNdT, T, 4, 2)
    dNdR_err_low = dNdT_2_dNdR(dNdT_err_low, T, 4, 2)
    dNdR_err_high = dNdT_2_dNdR(dNdT_err_high, T, 4, 2)

    write_rigidity_table("# credit: Ref. Yoon et al., ApJ, 839:5, 2017", output_filename, R, dNdR, dNdR_err_low, dNdR_err_high)
    
### EXPERIMENT LIST

#data_from_AMS02()
data_from_CREAM()
