import numpy as np
import utils as u

def get_table_posfrac(filename):
    E_min, E_max, y, y_stat_lo, y_stat_up, y_syst_lo, y_syst_up = np.loadtxt(filename, skiprows=2, usecols=(2,3,4,5,6,7,8), unpack=True)
    size = len(E_min)
    print ("read " + filename + " with data size : ", size)

    ek = np.zeros(size)
    r = np.zeros(size)
    r_err_low = np.zeros(size)
    r_err_high = np.zeros(size)
    
    for i in range(size):
        ek[i] = u.compute_geometrical_mean(E_min[i], E_max[i])
        r[i] = y[i]
        r_err_low[i] = np.sqrt(y_syst_lo[i]**2 + y_stat_lo[i]**2)
        r_err_high[i] = np.sqrt(y_syst_up[i]**2 + y_stat_up[i]**2)

    return ek, r, r_err_low, r_err_high
