
from xml.dom import minidom
import numpy as np
import utils as u

def get_value(item, name):
    elem = item.getElementsByTagName(name)[0]
    return float(elem.firstChild.data)

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
        rig[counter] = u.compute_mean_rigidity(rigidity_min, rigidity_max, 2.7)
        
        flux = get_value(item, "flux")
        f[counter] = flux
        
        statistical_error_low = get_value(item, "flux_statistical_error_low")
        statistical_error_high = get_value(item, "flux_statistical_error_high")

#        systematical_error_low = get_value(item, "flux_systematical_error_low")
#        systematical_error_high = get_value(item, "flux_systematical_error_high")

        acc_error_low = get_value(item, "flux_acc_error_low")
        acc_error_high = get_value(item, "flux_acc_error_high")

        scale_error_low = get_value(item, "flux_scale_error_low")
        scale_error_high = get_value(item, "flux_scale_error_high")

        unf_error_low = get_value(item, "flux_unf_error_low")
        unf_error_high = get_value(item, "flux_unf_error_high")
        
        systematical_errors = np.array([acc_error_low, scale_error_low, unf_error_low])
        f_err_low[counter] = u.compute_total_error(statistical_error_low, systematical_errors)

        systematical_errors = np.array([acc_error_high, scale_error_high, unf_error_high])
        f_err_high[counter] = u.compute_total_error(statistical_error_high, systematical_errors)
        
        counter = counter + 1

    return rig, f, f_err_low, f_err_high

def get_table_H(filename):
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
        rig[counter] = u.compute_mean_rigidity(rigidity_min, rigidity_max, 2.7)
        
        flux = get_value(item, "flux")
        f[counter] = flux
        
        statistical_error_low = get_value(item, "flux_statistical_error_low")
        statistical_error_high = get_value(item, "flux_statistical_error_high")

#        systematical_error_low = get_value(item, "flux_systematical_error_low")
#        systematical_error_high = get_value(item, "flux_systematical_error_high")

        acc_error_low = get_value(item, "flux_acc_error_low")
        acc_error_high = get_value(item, "flux_acc_error_high")

        scale_error_low = get_value(item, "flux_scale_error_low")
        scale_error_high = get_value(item, "flux_scale_error_high")

        unf_error_low = get_value(item, "flux_unf_error_low")
        unf_error_high = get_value(item, "flux_unf_error_high")
        
        trig_error_low = get_value(item, "flux_trig_error_low")
        trig_error_high = get_value(item, "flux_trig_error_high")

        systematical_errors = np.array([acc_error_low, scale_error_low, unf_error_low, trig_error_low])
        f_err_low[counter] = u.compute_total_error(statistical_error_low, systematical_errors)

        systematical_errors = np.array([acc_error_high, scale_error_high, unf_error_high, trig_error_high])
        f_err_high[counter] = u.compute_total_error(statistical_error_high, systematical_errors)
        
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
        rig[counter] = u.compute_geometrical_mean(rigidity_min, rigidity_max)
    
        ratio = get_value(item, "fluxratio")
        r[counter] = ratio
    
        statistical_error_low = get_value(item, "fluxratio_statistical_error_low")
        statistical_error_high = get_value(item, "fluxratio_statistical_error_high")

#        systematical_error_low = get_value(item, "fluxratio_systematical_error_low")
#        systematical_error_high = get_value(item, "fluxratio_systematical_error_high")

        acc_error_low = get_value(item, "fluxratio_acc_error_low")
        acc_error_high = get_value(item, "fluxratio_acc_error_high")

        scale_error_low = get_value(item, "fluxratio_scale_error_low")
        scale_error_high = get_value(item, "fluxratio_scale_error_high")

        unf_error_low = get_value(item, "fluxratio_unf_error_low")
        unf_error_high = get_value(item, "fluxratio_unf_error_high")

        systematical_errors = np.array([acc_error_low, scale_error_low, unf_error_low])
        r_err_low[counter] = u.compute_total_error(statistical_error_low, systematical_errors)

        systematical_errors = np.array([acc_error_high, scale_error_high, unf_error_high])
        r_err_high[counter] = u.compute_total_error(statistical_error_high, systematical_errors)
    
        counter = counter + 1

    return rig, r, r_err_low, r_err_high

def get_table_lepton_flux(filename):
    tree = minidom.parse(filename)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    print ("read " + filename + " with data size : ", size)

    ek = np.zeros(size)
    f = np.zeros(size)
    f_err_low = np.zeros(size)
    f_err_high = np.zeros(size)

    counter = 0
    for item in items:
        ek_min = get_value(item, "kinetic_energy_min")
        ek_max = get_value(item, "kinetic_energy_max")
        ek[counter] = u.compute_mean_rigidity(ek_min, ek_max, 3.0)
        
        flux = get_value(item, "flux")
        f[counter] = flux
        
        statistical_error_low = get_value(item, "flux_statistical_error_low")
        statistical_error_high = get_value(item, "flux_statistical_error_high")

        systematical_error_low = get_value(item, "flux_systematical_error_low")
        systematical_error_high = get_value(item, "flux_systematical_error_high")
        
        f_err_low[counter] = np.sqrt(statistical_error_low**2. + systematical_error_low**2.)
        f_err_high[counter] = np.sqrt(statistical_error_high**2. + systematical_error_high**2.)
        
        counter = counter + 1

    return ek, f, f_err_low, f_err_high

def get_table_posfrac(filename):
    tree = minidom.parse(filename)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    print ("read " + filename + " with data size : ", size)

    ek = np.zeros(size)
    f = np.zeros(size)
    f_err_low = np.zeros(size)
    f_err_high = np.zeros(size)

    counter = 0
    for item in items:
        ek_min = get_value(item, "kinetic_energy_min")
        ek_max = get_value(item, "kinetic_energy_max")
        ek[counter] = u.compute_geometrical_mean(ek_min, ek_max)
    
        fluxratio = get_value(item, "fluxratio")
        f[counter] = fluxratio
    
        statistical_error_low = get_value(item, "fluxratio_statistical_error_low")
        statistical_error_high = get_value(item, "fluxratio_statistical_error_high")

        systematical_error_low = get_value(item, "fluxratio_systematical_error_low")
        systematical_error_high = get_value(item, "fluxratio_systematical_error_high")
    
        f_err_low[counter] = np.sqrt(statistical_error_low**2. + systematical_error_low**2.)
        f_err_high[counter] = np.sqrt(statistical_error_high**2. + systematical_error_high**2.)
        
        counter = counter + 1

    return ek, f, f_err_low, f_err_high

def get_table_VERITAS(filename):
    E_min, E_max, flux, statistical_error = np.loadtxt(filename, skiprows=1, usecols=(1,2,6,7), unpack=True)
    
    size = len(E_min)
    
    ek = np.zeros(size)
    f = np.zeros(size)
    f_err_low = np.zeros(size)
    f_err_high = np.zeros(size)

    for i in range(size):
        ek[i] = u.compute_mean_rigidity(E_min[i], E_max[i], 3.0) * 1e3
        f[i] = flux[i] * 1e4
        
        systematical_error_low = 0.33 * flux[i]
        systematical_error_high = 0.64 * flux[i]

        f_err_low[i] = np.sqrt(systematical_error_low**2 + statistical_error[i]**2)
        f_err_low[i] *= 1e4
        
        f_err_high[i] = np.sqrt(systematical_error_high**2 + statistical_error[i]**2)
        f_err_high[i] *= 1e4

    return ek, f, f_err_low, f_err_high
