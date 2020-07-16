import numpy as np
from xml.dom import minidom

credit_asi = "SSDC Cosmic Ray Database tools.asdc.asi.it/CosmicRays"
credit_crdb = "CRDB Database lpsc.in2p3.fr/cosmic-rays-db"

def write_raw(raw, credit, ads, data, xtype, ytype):
    raw = "raw_tables/" + raw
    file = open(raw, "w")
    file.write(credit + "\n")
    file.write(ads + "\n")
    file.write(xtype + "\n")
    file.write(ytype + "\n")
    size = len(data[0])
    for i in range(size):
        line = '{0:1.5e}'.format(data[0][i]) + " "
        line += '{0:1.5e}'.format(data[1][i]) + " "
        line += '{0:1.5e}'.format(data[2][i]) + " "
        line += '{0:1.5e}'.format(data[3][i]) + " "
        line += '{0:1.5e}'.format(data[4][i]) + " "
        line += '{0:1.5e}'.format(data[5][i]) + " "
        line += '{0:1.5e}'.format(data[6][i]) + " "
        line += "\n"
        file.write(line)
    file.close()

def convert_VERITAS_leptons(original, raw, ads):
    original = "original_tables/" + original
    E_min, E_max, flux, stat_error = np.loadtxt(original, skiprows=1, usecols=(1,2,6,7), unpack=True)
    E_min *= 1e3 # TeV -> GeV
    E_max *= 1e3 # TeV -> GeV
    flux *= 1e4 # cm-2 s-1 TeV-1 -> m-2 s-1 GeV-1
    stat_error *= 1e4 #
    syst_error_low = 0.33 * flux
    syst_error_high = 0.64 * flux
    
    print ("read " + original + " with data size : ", len(E_min))
    
    data = [E_min, E_max, flux, stat_error, stat_error, syst_error_low, syst_error_high]
    write_raw(raw, "arXiv:1808.10028", ads, data, "kineticEnergy", "flux")

def get_value(item, name):
    elem = item.getElementsByTagName(name)[0]
    return float(elem.firstChild.data)

def convert_ASI_kE_flux(original, raw, ads):
    original = "original_tables/" + original
    tree = minidom.parse(original)
    items = tree.getElementsByTagName('DATA')
    size = len(items)
    
    E_min, E_max = [], []
    flux = []
    stat_error_low, stat_error_high = [], []
    syst_error_low, syst_error_high = [], []

    for item in items:
        E_min.append(get_value(item, "kinetic_energy_min"))
        E_max.append(get_value(item, "kinetic_energy_max"))
        flux.append(get_value(item, "flux"))
        stat_error_low.append(get_value(item, "flux_statistical_error_low"))
        stat_error_high.append(get_value(item, "flux_statistical_error_high"))
        syst_error_low.append(get_value(item, "flux_systematical_error_low"))
        syst_error_high.append(get_value(item, "flux_systematical_error_high"))
        
    print ("read " + original + " with data size : ", size)

    data = [E_min, E_max, flux, stat_error_low, stat_error_high, syst_error_low, syst_error_high]
    write_raw(raw, credit_asi, ads, data, "kineticEnergy", "flux")

def convert_ASI_kE_ratio(original, raw, ads):
    original = "original_tables/" + original
    tree = minidom.parse(original)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    E_min, E_max = [], []
    ratio = []
    stat_error_low, stat_error_high = [], []
    syst_error_low, syst_error_high = [], []

    for item in items:
        E_min.append(get_value(item, "kinetic_energy_min"))
        E_max.append(get_value(item, "kinetic_energy_max"))
        ratio.append(get_value(item, "fluxratio"))
        stat_error_low.append(get_value(item, "fluxratio_statistical_error_low"))
        stat_error_high.append(get_value(item, "fluxratio_statistical_error_high"))
        syst_error_low.append(get_value(item, "fluxratio_systematical_error_low"))
        syst_error_high.append(get_value(item, "fluxratio_systematical_error_high"))
        
    print ("read " + original + " with data size : ", size)

    data = [E_min, E_max, ratio, stat_error_low, stat_error_high, syst_error_low, syst_error_high]
    write_raw(raw, credit_asi, ads, data, "kineticEnergy", "ratio")

def convert_PAMELA_posfrac(original, raw, ads):
    original = "original_tables/" + original
    tree = minidom.parse(original)
    items = tree.getElementsByTagName('DATA')
    size = len(items)

    E_min, E_max = [], []
    ratio = []
    stat_error_low, stat_error_high = [], []
    syst_error_low, syst_error_high = [], []

    for item in items:
        E_min.append(get_value(item, "kinetic_energy_min"))
        E_max.append(get_value(item, "kinetic_energy_max"))
        ratio.append(get_value(item, "fluxratio"))
        stat_error_low.append(get_value(item, "fluxratio_statistical_error_low"))
        stat_error_high.append(get_value(item, "fluxratio_statistical_error_high"))
        syst_error_low.append(0.)
        syst_error_high.append(0.)
        
    print ("read " + original + " with data size : ", size)

    data = [E_min, E_max, ratio, stat_error_low, stat_error_high, syst_error_low, syst_error_high]
    write_raw(raw, credit_asi, ads, data, "kineticEnergy", "ratio")

### Electrons + Positrons
convert_VERITAS_leptons("VERITAS_1808_10028.txt", "leptons_VERITAS_kE.raw", "2018PhRvD..98f2004A")
convert_ASI_kE_flux("e+e-_AMS_PRL2019_ekin_000.xml", "leptons_AMS02_kE.raw", "2019PhRvL.122j1101A")
convert_ASI_kE_flux("e+e-_CALET_PRL2018_binningDAMPE_ekin_000.xml", "leptons_CALET_kE.raw", "2018PhRvL.120z1102A")
convert_ASI_kE_flux("e+e-_DAMPE_NATURE2017_000.xml", "leptons_DAMPE_kE.raw", "2017Natur.552...63D")
convert_ASI_kE_flux("e+e-_FERMI_PRD2017_HE_000.xml", "leptons_FERMI_kE.raw", "2017PhRvD..95h2007A")

### Positrons
convert_ASI_kE_flux("pos_PAM_PRL2013_000.xml", "positrons_PAMELA_kE.raw", "2013PhRvL.111h1102A")
convert_ASI_kE_flux("pos_FER_PRL2012_000.xml", "positrons_FERMI_kE.raw", "2012PhRvL.108a1103A")
convert_ASI_kE_flux("e+_AMS_PRL2019_ekin_000.xml", "positrons_AMS02_kE.raw", "2019PhRvL.122d1102A")

### Electrons
convert_ASI_kE_flux("ele_PAM_PRL2011_000.xml", "electrons_PAMELA_kE.raw", "2011PhRvL.106t1101A")
convert_ASI_kE_flux("ele_FER_PRL2012_000.xml", "electrons_FERMI_kE.raw", "2012PhRvL.108a1103A")
convert_ASI_kE_flux("e-_AMS_PRL2019_ekin_000.xml", "electrons_AMS02_kE.raw", "2019PhRvL.122j1101A")

### Positron fraction
convert_ASI_kE_ratio("posfrac_AMS_PRL2019_ekin_000.xml", "posfrac_AMS02_kE.raw", "2019PhRvL.122j1101A")
convert_ASI_kE_ratio("posfrac_FER_PRL2012_000.xml", "posfrac_FERMI_kE.raw", "2012PhRvL.108a1103A")
convert_PAMELA_posfrac("posfrac_PAM_PRL2013_000.xml", "posfrac_PAMELA_kE.raw", "2013PhRvL.111h1102A")

