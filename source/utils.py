import crdb

def print_column_names(tab):
    for icol, col_name in enumerate(tab.dtype.fields):
        print("%2i" % icol, col_name)

def dump_datafile(quantity, energyType, expName, subExpName, filename, combo_level=0):
    filename = 'CRDB/' + filename
    print(f"search for {quantity} as a function of {energyType} measured by {expName}")
    
    tab = crdb.query(quantity, energy_type=energyType, combo_level=combo_level, energy_convert_level=0, exp_dates=expName)
 
    subExpNames = set(tab["sub_exp"])
    print("number of datasets found : ", len(subExpNames))
    print(subExpNames)

    adsCodes = set(tab["ads"])
    print(adsCodes)

    items = [i for i in range(len(tab["sub_exp"])) if tab["sub_exp"][i] == subExpName]
    print("number of data : ", len(items))
    assert(len(items) > 0)

    print(f"dump on {filename}")
    with open(filename, 'w') as f:
#        f.write(f"#source: CRDB\n")
#        f.write(f"#Quantity: {quantity}\n")
#        f.write(f"#EnergyType: {energyType}\n")
#        f.write(f"#Experiment: {expName}\n")
        f.write(f"#ads: {tab['ads'][items[0]]}\n")
        f.write(f"#E_lo - E_up - y - errSta_lo - errSta_up - errSys_lo - errSys_up\n")
        for eBin, value, errSta, errSys in zip(tab["e_bin"][items], tab["value"][items], tab["err_sta"][items], tab["err_sys"][items]):
            f.write(f"{eBin[0]:10.5e} {eBin[1]:10.5e} {value:10.5e} {errSta[0]:10.5e} {errSta[1]:10.5e} {errSys[0]:10.5e} {errSys[1]:10.5e}\n")
    print("")