from xml.dom import minidom
import numpy as np

def get_value(item, name):
    elem = item.getElementsByTagName(name)[0]
    return float(elem.firstChild.data)

def compute_mean_rigidity(R_min, R_max, slope):
    """ Compute the mean rigidity in the bin 
    assuming a spectrum R^-slope 
    """
    rig_mean = (slope - 1.) / (slope - 2.);
    rig_mean *= (R_max**(-slope + 2) - R_min**(-slope + 2)) / (R_max**(-slope + 1) - R_min**(-slope + 1)) 
    return (rig_mean)

def compute_total_error(stat_err, syst_err):
    """ Compute total error given a statistycal error 
    and a vector of systematic errors
    """
    total_systematical_error_squared = 0.
    for s in syst_err:
        total_systematical_error_squared += s * s;
    return np.sqrt(total_systematical_error_squared + stat_err * stat_err)

def get_table_flux(filename):
    tree = minidom.parse(filename)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    print ("read " + filename + " with data size : ", size)

    rig = np.zeros(size)
    f = np.zeros(size)
    f_err_low = np.zeros(size)
    f_err_high = np.zeros(size)

    counter = 0
    for item in items:
        rigidity_min = get_value(item, "rigidity_min")
        rigidity_max = get_value(item, "rigidity_max")
        rig[counter] = compute_mean_rigidity(rigidity_min, rigidity_max, 2.7)
        
        flux = get_value(item, "flux")
        f[counter] = flux
        
        statistical_error_low = get_value(item, "flux_statistical_error_low")
        statistical_error_high = get_value(item, "flux_statistical_error_high")

        systematical_error_low = get_value(item, "flux_systematical_error_low")
        systematical_error_high = get_value(item, "flux_systematical_error_high")

        acc_error_low = get_value(item, "flux_acc_error_low")
        acc_error_high = get_value(item, "flux_acc_error_high")

        scale_error_low = get_value(item, "flux_scale_error_low")
        scale_error_high = get_value(item, "flux_scale_error_high")

        unf_error_low = get_value(item, "flux_unf_error_low")
        unf_error_high = get_value(item, "flux_unf_error_high")

        systematical_errors = np.array([systematical_error_low, acc_error_low, scale_error_low, unf_error_low]) 
        f_err_low[counter] = compute_total_error(statistical_error_low, systematical_errors)

        systematical_errors = np.array([systematical_error_high, acc_error_high, scale_error_high, unf_error_high]) 
        f_err_high[counter] = compute_total_error(statistical_error_high, systematical_errors)
        
        counter = counter + 1

    return rig, f, f_err_low, f_err_high

def get_table_ratio(filename):
    tree = minidom.parse(filename)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    print ("read " + filename + " with data size : ", size)

    rig = np.zeros(size)
    r = np.zeros(size)
    r_err_low = np.zeros(size)
    r_err_high = np.zeros(size)

    counter = 0
    for item in items:
        rigidity_min = get_value(item, "rigidity_min")
        rigidity_max = get_value(item, "rigidity_max")
        rig[counter] = compute_mean_rigidity(rigidity_min, rigidity_max, 0.)
    
        ratio = get_value(item, "fluxratio")
        r[counter] = ratio
    
        statistical_error_low = get_value(item, "fluxratio_statistical_error_low")
        statistical_error_high = get_value(item, "fluxratio_statistical_error_high")

        systematical_error_low = get_value(item, "fluxratio_systematical_error_low")
        systematical_error_high = get_value(item, "fluxratio_systematical_error_high")

        acc_error_low = get_value(item, "fluxratio_acc_error_low")
        acc_error_high = get_value(item, "fluxratio_acc_error_high")

        scale_error_low = get_value(item, "fluxratio_scale_error_low")
        scale_error_high = get_value(item, "fluxratio_scale_error_high")

        unf_error_low = get_value(item, "fluxratio_unf_error_low")
        unf_error_high = get_value(item, "fluxratio_unf_error_high")

        systematical_errors = np.array([systematical_error_low, acc_error_low, scale_error_low, unf_error_low])
        r_err_low[counter] = compute_total_error(statistical_error_low, systematical_errors)

        systematical_errors = np.array([systematical_error_high, acc_error_high, scale_error_high, unf_error_high])
        r_err_high[counter] = compute_total_error(statistical_error_high, systematical_errors)
    
        counter = counter + 1

    return rig, r, r_err_low, r_err_high

