import numpy as np
import utils as utils

def make_header_data(raw_filename):
    file = open("raw_tables/" + raw_filename, "r")
    lines = file.readlines()
    xaxis_type = lines[2]
    xaxis_type = xaxis_type.replace("\n", "")
    yaxis_type = lines[3]
    yaxis_type = yaxis_type.replace("\n", "")
    header = "# "
    if (xaxis_type == "kineticEnergy"):
        if (yaxis_type == "flux"):
            header += "T [GeV] flux [m-2 s-1 sr-1 GeV-1]"
        elif (yaxis_type == "ratio"):
            header += "T [GeV] ratio []"
    if (xaxis_type == "rigidity"):
        if (yaxis_type == "flux"):
            header += "R [GV] flux [m-2 s-1 sr-1 GV-1]"
        elif (yaxis_type == "ratio"):
            header += "R [GV] ratio []"
    return header + " total_error_low total_error_high\n"

def make_credits(raw_filename):
    file = open("raw_tables/" + raw_filename, "r")
    lines = file.readlines()
    credit = "# " + lines[0]
    url = "# https://ui.adsabs.harvard.edu/abs/" + lines[1]
    return credit, url
    
def compute_mean_energy(x_min, x_max, xmode):
    size = len(x_min)
    x = []
    for i in range(size):
        if (xmode == "geometrical"):
            x.append(utils.compute_geometrical_mean(x_min[i], x_max[i]))
        elif (xmode == "pl2.7"):
            x.append(utils.compute_mean_rigidity_powerlaw(x_min[i], x_max[i], 2.7))
        elif (xmode == "pl3.0"):
            x.append(utils.compute_mean_rigidity_powerlaw(x_min[i], x_max[i], 3.0))
        elif (xmode == "Lafferty2.7"):
            x.append(utils.compute_mean_rigidity_Lafferty1995(x_min[i], x_max[i], 2.7))
        elif (xmode == "Lafferty3.0"):
            x.append(utils.compute_mean_rigidity_Lafferty1995(x_min[i], x_max[i], 3.0))
    assert (len(x) == size)
    return np.array(x)
    
def write_kiss_table(raw, kiss, xmode):
    header = make_header_data(raw)
    credit, url = make_credits(raw)
    
    file = open("kiss_crdata/" + kiss, "w")
    file.write(credit)
    file.write(url)
    file.write(header)

    x_min, x_max, y, stat_low, stat_high, syst_low, syst_high = np.loadtxt("raw_tables/" + raw,
        skiprows=4, usecols=(0,1,2,3,4,5,6), unpack=True)

    x = compute_mean_energy(x_min, x_max, xmode)
    err_low = np.sqrt(stat_low * stat_low + syst_low * syst_low)
    err_high = np.sqrt(stat_high * stat_high + syst_high * syst_high)
 
    for i in range(len(x_min)):
        line = '{0:1.5e}'.format(x[i]) + "   "
        line += '{0:1.5e}'.format(y[i]) + "   "
        line += '{0:1.5e}'.format(err_low[i]) + "   "
        line += '{0:1.5e}'.format(err_high[i]) + "   "
        line += "\n"
        file.write(line)
    file.close()
    
#### Positron fraction
write_kiss_table("posfrac_FERMI_kE.raw", "posfrac_FERMI_kenergy.txt", "geometrical")
write_kiss_table("posfrac_PAMELA_kE.raw", "posfrac_PAMELA_kenergy.txt", "geometrical")
write_kiss_table("posfrac_AMS02_kE.raw", "posfrac_AMS02_kenergy.txt", "geometrical")

#### Positrons
write_kiss_table("positrons_FERMI_kE.raw", "positrons_FERMI_kenergy.txt", "Lafferty3.0")
write_kiss_table("positrons_PAMELA_kE.raw", "positrons_PAMELA_kenergy.txt", "Lafferty3.0")
write_kiss_table("positrons_AMS02_kE.raw", "positrons_AMS02_kenergy.txt", "Lafferty3.0")

#### Electrons
write_kiss_table("electrons_FERMI_kE.raw", "electrons_FERMI_kenergy.txt", "Lafferty3.0")
write_kiss_table("electrons_PAMELA_kE.raw", "electrons_PAMELA_kenergy.txt", "Lafferty3.0")
write_kiss_table("electrons_AMS02_kE.raw", "electrons_AMS02_kenergy.txt", "Lafferty3.0")

#### Electrons + Positrons
write_kiss_table("leptons_FERMI_kE.raw", "leptons_FERMI_kenergy.txt", "Lafferty3.0")
write_kiss_table("leptons_AMS02_kE.raw", "leptons_AMS02_kenergy.txt", "Lafferty3.0")
write_kiss_table("leptons_CALET_kE.raw", "leptons_CALET_kenergy.txt", "Lafferty3.0")
write_kiss_table("leptons_DAMPE_kE.raw", "leptons_DAMPE_kenergy.txt", "Lafferty3.0")
write_kiss_table("leptons_VERITAS_kE.raw", "leptons_VERITAS_kenergy.txt", "Lafferty3.0")

### Nuclei
write_kiss_table("H_AMS02_rig.raw", "H_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("Li_AMS02_rig.raw", "Li_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("Be_AMS02_rig.raw", "Be_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("B_AMS02_rig.raw", "B_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("C_AMS02_rig.raw", "C_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("N_AMS02_rig.raw", "N_AMS02_rigidity.txt", "Lafferty2.7")
write_kiss_table("O_AMS02_rig.raw", "O_AMS02_rigidity.txt", "Lafferty2.7")

write_kiss_table("LiC_AMS02_rig.raw", "LiC_AMS02_rigidity.txt", "geometrical")
write_kiss_table("LiO_AMS02_rig.raw", "LiO_AMS02_rigidity.txt", "geometrical")
write_kiss_table("BeC_AMS02_rig.raw", "BeC_AMS02_rigidity.txt", "geometrical")
write_kiss_table("BeO_AMS02_rig.raw", "BeO_AMS02_rigidity.txt", "geometrical")
write_kiss_table("BC_AMS02_rig.raw", "BC_AMS02_rigidity.txt", "geometrical")
write_kiss_table("BO_AMS02_rig.raw", "BO_AMS02_rigidity.txt", "geometrical")
