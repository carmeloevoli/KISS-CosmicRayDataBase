import numpy as np

def compute_mean_rigidity_Lafferty1995(R_min, R_max, slope):
    """ Compute the mean rigidity in the bin
    assuming a spectrum R^-slope a in
    Lafferty and Wyatt, 1995, NIMPR A 335
    """
    R_ratio = R_min / (R_max - R_min)
    R_tilde = R_min
    R_tilde *= np.power(R_ratio / (slope - 1.) * (1. - np.power(R_max / R_min, -slope + 1.)), -1. / slope)
    return (R_tilde)

def compute_mean_rigidity_powerlaw(R_min, R_max, slope):
    """ Compute the mean rigidity in the bin
    assuming a spectrum R^-slope
    """
    rig_mean = (slope - 1.) / (slope - 2.);
    rig_mean *= (R_max**(-slope + 2) - R_min**(-slope + 2)) / (R_max**(-slope + 1) - R_min**(-slope + 1))
    return (rig_mean)
    
def compute_mean_rigidity(R_min, R_max, slope):
    """ Compute the mean rigidity in the bin
    assuming a spectrum R^-slope
    """
    #return compute_mean_rigidity_powerlaw(R_min, R_max, slope)
    return compute_mean_rigidity_Lafferty1995(R_min, R_max, slope)
    
def compute_geometrical_mean(R_min, R_max):
    """
    Compute the mean geometrical mean in the bin
    """
    return np.sqrt(R_min * R_max)
    
def compute_total_error(stat_err, syst_err):
    """ Compute total error given a statistycal error
    and a vector of systematic errors
    """
    total_systematical_error_squared = 0.
    for s in syst_err:
        total_systematical_error_squared += s * s;
    return np.sqrt(total_systematical_error_squared + stat_err * stat_err)

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

def write_kE_table(credit, filename, E, f, f_err_low, f_err_high):
    file = open(filename, "w")
    file.write("# credit: " + credit + "\n")
    file.write("# kE [GeV] - flux [] - flux_error_low [] - flux_error_high [] \n")
    for i in range(len(E)):
        line = '{0:1.5e}'.format(E[i]) + "   "
        line += '{0:1.5e}'.format(f[i]) + "   "
        line += '{0:1.5e}'.format(f_err_low[i]) + "   "
        line += '{0:1.5e}'.format(f_err_high[i]) + "   "
        line += "\n"
        file.write(line)
    file.close()
