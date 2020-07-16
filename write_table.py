def write_rigidity_table(credit, filename, R, f, f_err_low, f_err_high):
    file = open(filename, "w") 
    file.write("# credit: " + credit + "\n")
    file.write("# rigidity [GV] - flux [] - flux_error_low [] - flux_error_high [] \n")
    for i in range(len(R)):
        line = '{0:1.5e}'.format(R[i]) + "   "
        line += '{0:1.5e}'.format(f[i]) + "   "
        line += '{0:1.5e}'.format(f_err_low[i]) + "   "
        line += '{0:1.5e}'.format(f_err_high[i]) + "   "
        line += "\n"
        file.write(line)
    file.close()  

def write_kE_table(credit, filename, R, f, f_err_low, f_err_high):
    file = open(filename, "w")
    file.write("# credit: " + credit + "\n")
    file.write("# T [GeV] - flux [] - flux_error_low [] - flux_error_high [] \n")
    for i in range(len(R)):
        line = '{0:1.5e}'.format(R[i]) + "   "
        line += '{0:1.5e}'.format(f[i]) + "   "
        line += '{0:1.5e}'.format(f_err_low[i]) + "   "
        line += '{0:1.5e}'.format(f_err_high[i]) + "   "
        line += "\n"
        file.write(line)
    file.close()
