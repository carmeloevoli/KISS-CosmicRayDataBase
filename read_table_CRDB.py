import numpy as np

def compute_mean_rigidity(R_min, R_max, slope):
    """ Compute the mean rigidity in the bin 
    assuming a spectrum R^-slope 
    """
    rig_mean = (slope - 1.) / (slope - 2.);
    rig_mean *= (R_max**(-slope + 2) - R_min**(-slope + 2)) / (R_max**(-slope + 1) - R_min**(-slope + 1)) 
    return (rig_mean)

def compute_total_error(stat_err, syst_err):
    """ Returns total error given statistycal and systematic errors
        Args:
          stat_err (float): 
          syst_err (float):
        Returns:
          (float): total error :math:`\\sqrt(stat^2 + syst^2)`
    """
    return np.sqrt(syst_err * syst_err + stat_err * stat_err)

def get_table(filename):
    R_low, R_up, y, y_stat_lo, y_stat_up, y_syst_lo, y_syst_up = np.loadtxt(filename,skiprows=2,usecols=(1,2,3,4,5,6,7),unpack=True)
    
    print ("read " + filename + " with data size : ", len(y))
    
    rig = compute_mean_rigidity(R_low, R_up, 2.7)
    f = y

    f_err_low = compute_total_error(y_stat_lo, y_syst_lo)
    f_err_high = compute_total_error(y_stat_up, y_syst_up)

    return rig, f, f_err_low, f_err_high
