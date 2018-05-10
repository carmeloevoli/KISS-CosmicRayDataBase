import read_table_ASI as ASI
import read_table_CRDB as CRDB

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

credit_asi = "credit: SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays \n"
credit_crdb = "credit: CRDB Database lpsc.in2p3.fr/cosmic-rays-db \n"
    
#  C Rigidity File
ssdc_filename = "data/C_AMSPRL2017_rig_000.xml"
output_filename = "kiss_tables/C_AMS02_rigidity.txt"

R, f, f_err_low, f_err_high = ASI.get_table(ssdc_filename)

write_rigidity_table(credit_asi, output_filename, R, f, f_err_low, f_err_high)

# O Rigidity file
ssdc_filename = "data/O_AMSPRL2017_rig_000.xml"
output_filename = "kiss_tables/O_AMS02_rigidity.txt"

R, f, f_err_low, f_err_high = ASI.get_table(ssdc_filename)

write_rigidity_table(credit_asi, output_filename, R, f, f_err_low, f_err_high)

# He Rigidity file
ssdc_filename = "data/He_AMSPRL2017_rig_000.xml"
output_filename = "kiss_tables/He_AMS02_rigidity.txt"

R, f, f_err_low, f_err_high = ASI.get_table(ssdc_filename)

write_rigidity_table(credit_asi, output_filename, R, f, f_err_low, f_err_high)

# H Rigidity file
crdb_filename = "data/H_AMS02_CRDB.txt"
output_filename = "kiss_tables/H_AMS02_rigidity.txt"

R, f, f_err_low, f_err_high = CRDB.get_table(crdb_filename)

write_rigidity_table(credit_crdb, output_filename, R, f, f_err_low, f_err_high)

