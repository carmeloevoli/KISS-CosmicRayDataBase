// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_NUCLEI_H_
#define INCLUDE_NUCLEI_H_

#include "CRDB.h"
#include "KCDC.h"
#include "SSDC.h"
#include "mydb.h"

namespace NUCLEI {

void AMS02() {
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.114.171103");
        dataSet.set_ADSbibcode("2015PhRvL.114q1103A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("H");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_H_AMS-02_Ek+.txt");
        dataSet.save("output/H_AMS-02_Ek.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_He_AMS-02_Etot+.txt");
        dataSet.save("output/He_AMS-02_Etot.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("C");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_C_AMS-02_Etot+.txt");
        dataSet.save("output/C_AMS-02_Etot.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("O");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_O_AMS-02_Etot+.txt");
        dataSet.save("output/O_AMS-02_Etot.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("Mg");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_Ne_AMS-02_Etot+.txt");
        dataSet.save("output/Ne_AMS-02_Etot.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("Mg");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_Mg_AMS-02_Etot+.txt");
        dataSet.save("output/Mg_AMS-02_Etot.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("Si");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_Si_AMS-02_Etot+.txt");
        dataSet.save("output/Si_AMS-02_Etot.txt");
    }
    {
        MyIronAMS02totalenergy dataSet;
        dataSet.set_doi("10.1103/PhysRevLett.126.041104");
        dataSet.set_ADSbibcode("2021PhRvL.126d1104A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("total energy(converted)");
        dataSet.set_yType("Fe");
        dataSet.set_comments("table read from Supp.Material");
        dataSet.loadDataset("source/nuclei/myFe_AMS02_rig.txt");
        dataSet.save("output/Fe_AMS-02_Etot.txt");
    }
}

void ARGO() {
    MyLightARGO dataSet;
    dataSet.set_doi("10.1051/epjconf/201714505003");
    dataSet.set_ADSbibcode("2017EPJWC.14505003D");
    dataSet.set_xUnits("total energy");
    dataSet.set_yType("light");
    dataSet.set_comments("Table provided by G. Di Sciascio");
    dataSet.loadDataset("source/nuclei/mysource_light_ARGO_Etot.txt");
    dataSet.save("output/light_ARGO_Etot.txt");
}

void ATIC02() {
    CRDB dataSet("ATIC02");
    dataSet.set_doi("Panov et al., Bull. Russian Acad. Sci. 73, 564 (2009)");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("H");
    dataSet.set_comments("");
    dataSet.loadDataset("source/nuclei/CRDB_H_ATIC02_Etot.txt");
    dataSet.save("output/H_ATIC02_Etot.txt");
}

void AUGER() {}

void BESS() {
    CRDB dataSet("BESS");
    dataSet.set_doi("10.1016/j.astropartphys.2007.05.001");
    dataSet.set_ADSbibcode("2007APh....28..154S");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic Energy");
    dataSet.set_yType("H");
    dataSet.set_comments("converted from original table");
    dataSet.loadDataset("source/nuclei/CRDB_H_BESS-TeV_Ek.txt");
    dataSet.save("output/H_BESS-TeV_Ek.txt");
}

void CALET() {
    {
        SSDC dataSet("CALET");
        dataSet.set_doi("10.1103/PhysRevLett.122.181102");
        dataSet.set_ADSbibcode("2019PhRvL.122r1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_H_CALET_Ek.txt");
        dataSet.save("output/H_CALET_Ek.txt");
    }
    {
        MyHeavyCALET dataSet(12);
        dataSet.set_doi("110.1103/PhysRevLett.125.251102");
        dataSet.set_ADSbibcode("2020PhRvL.125y1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/myC_CALET_Ekn.txt");
        dataSet.save("output/C_CALET_Etot.txt");
    }
    {
        MyHeavyCALET dataSet(16);
        dataSet.set_doi("110.1103/PhysRevLett.125.251102");
        dataSet.set_ADSbibcode("2020PhRvL.125y1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/myO_CALET_Ekn.txt");
        dataSet.save("output/O_CALET_Etot.txt");
    }
}

void CREAM_II() {
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_C_CREAM-II_Ekn.txt");
        dataSet.save("output/C_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_C_CREAM-II_Etot+.txt");
        dataSet.save("output/C_CREAM-II_Etot.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_O_CREAM-II_Ekn.txt");
        dataSet.save("output/O_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_O_CREAM-II_Etot+.txt");
        dataSet.save("output/O_CREAM-II_Etot.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("Ne");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Ne_CREAM-II_Ekn.txt");
        dataSet.save("output/Ne_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("Ne");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Ne_CREAM-II_Etot+.txt");
        dataSet.save("output/Ne_CREAM-II_Etot.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Mg_CREAM-II_Ekn.txt");
        dataSet.save("output/Mg_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Mg_CREAM-II_Etot+.txt");
        dataSet.save("output/Mg_CREAM-II_Etot.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("Si");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Si_CREAM-II_Ekn.txt");
        dataSet.save("output/Si_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("Si");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Si_CREAM-II_Etot+.txt");
        dataSet.save("output/Si_CREAM-II_Etot.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("Fe");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Fe_CREAM-II_Ekn.txt");
        dataSet.save("output/Fe_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_doi("10.1088/0004-637X/707/1/593");
        dataSet.set_ADSbibcode("2009ApJ...707..593A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("Fe");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Fe_CREAM-II_Etot+.txt");
        dataSet.save("output/Fe_CREAM-II_Etot.txt");
    }
}

void CREAM_III() {
    {
        CRDB dataSet("CREAM-III");
        dataSet.set_doi("10.3847/1538-4357/aa68e4");
        dataSet.set_ADSbibcode("2017ApJ...839....5Y");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Table 3");
        dataSet.loadDataset("source/nuclei/CRDB_H_CREAM-I+III_Ek.txt");
        dataSet.save("output/H_CREAM-III_Ek.txt");
    }
    {
        CRDB dataSet("CREAM-III");
        dataSet.set_doi("10.3847/1538-4357/aa68e4");
        dataSet.set_ADSbibcode("2017ApJ...839....5Y");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon (original)");
        dataSet.set_yType("He");
        dataSet.set_comments("Table 3");
        dataSet.loadDataset("source/nuclei/CRDB_He_CREAM-I+III_Ekn.txt");
        dataSet.save("output/He_CREAM-III_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-III");
        dataSet.set_doi("10.3847/1538-4357/aa68e4");
        dataSet.set_ADSbibcode("2017ApJ...839....5Y");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("Table 3");
        dataSet.loadDataset("source/nuclei/CRDB_He_CREAM-I+III_Etot+.txt");
        dataSet.save("output/He_CREAM-III_Etot.txt");
    }
}

void DAMPE() {
    SSDC dataSet("DAMPE");
    dataSet.set_doi("10.1126/sciadv.aax3793");
    dataSet.set_ADSbibcode("2019SciA....5.3793A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic Energy");
    dataSet.set_yType("H");
    dataSet.set_comments("");
    dataSet.loadDataset("source/nuclei/SSDC_H_DAMPE_Ek.txt");
    dataSet.save("output/H_DAMPE_Ek.txt");
}

void HESS() {
    SSDC dataSet("HESS");
    dataSet.set_doi("10.1103/PhysRevD.75.042004");
    dataSet.set_ADSbibcode("2007PhRvD..75d2004A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("Fe");
    dataSet.set_comments("");
    dataSet.loadDataset("source/nuclei/SSDC_Fe_HESS_Ek.txt");
    dataSet.save("output/Fe_HESS_Etot.txt");
}

void ICECUBE_ICETOP() {
    {
        KCDC dataSet("ICECUBE-ICETOP");
        dataSet.set_doi("10.1103/PhysRevD.100.082002");
        dataSet.set_ADSbibcode("2019PhRvD.100h2002A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Sibyll-2.1 only");
        dataSet.loadDataset("source/nuclei/KCDC_H_ICECUBE-ICETOP_Etot.txt");
        dataSet.save("output/H_ICECUBE-ICETOP_Etot.txt");
    }
    {
        KCDC dataSet("ICECUBE-ICETOP");
        dataSet.set_doi("10.1103/PhysRevD.100.082002");
        dataSet.set_ADSbibcode("2019PhRvD.100h2002A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("Sibyll-2.1 only");
        dataSet.loadDataset("source/nuclei/KCDC_He_ICECUBE-ICETOP_Etot.txt");
        dataSet.save("output/He_ICECUBE-ICETOP_Etot.txt");
    }
}

void KASCADE() {
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("10.1016/j.astropartphys.2005.04.001");
        dataSet.set_ADSbibcode("2005APh....24....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2005_QGSJET-01_Etot.txt");
        dataSet.save("output/H_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("10.1016/j.astropartphys.2005.04.001");
        dataSet.set_ADSbibcode("2005APh....24....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2005_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/H_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-II-02_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_QGSJET-II-02_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-01_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("10.1016/j.astropartphys.2005.04.001");
        dataSet.set_ADSbibcode("2005APh....24....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_He_KASCADE_2005_QGSJET-01_Etot.txt");
        dataSet.save("output/He_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_doi("10.1016/j.astropartphys.2005.04.001");
        dataSet.set_ADSbibcode("2005APh....24....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_He_KASCADE_2005_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/He_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
}

void KASCADEGrande() {
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_doi("doi.org/10.22323/1.301.0316");
        dataSet.set_ADSbibcode("2017ICRC...35..316A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KG_SIBYLL-2.3_Etot.txt");
        dataSet.save("output/H_KASCADEGrande_SIBYLL-2.3_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_doi("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_EPOS-LHC_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_EPOS-LHC_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_doi("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_QGSJET-II-04_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_QGSJET-II-04_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_doi("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_SIBYLL-2.1_Etot.txt");
    }
}

void NUCLEON() {
    {
        CRDB dataSet("NUCLEON");
        dataSet.set_doi("10.1016/j.asr.2019.10.004");
        dataSet.set_ADSbibcode("2019AdSpR..64.2546G");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Table 2");
        dataSet.loadDataset("source/nuclei/CRDB_H_NUCLEON_Etot.txt");
        dataSet.save("output/H_NUCLEON_Etot.txt");
    }
    {
        CRDB dataSet("NUCLEON");
        dataSet.set_doi("10.1016/j.asr.2019.10.004");
        dataSet.set_ADSbibcode("2019AdSpR..64.2546G");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("Table 2");
        dataSet.loadDataset("source/nuclei/CRDB_He_NUCLEON_Etot.txt");
        dataSet.save("output/He_NUCLEON_Etot.txt");
    }
}

void PAMELA() {
    {
        CRDB dataSet("PAMELA");
        dataSet.set_doi("10.1126/science.1199172");
        dataSet.set_ADSbibcode("2011Sci...332...69A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("H");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_H_PAMELA_Ek.txt");
        dataSet.save("output/H_PAMELA_Ek.txt");
    }
    {
        CRDB dataSet("PAMELA");
        dataSet.set_doi("10.1126/science.1199172");
        dataSet.set_ADSbibcode("2011Sci...332...69A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_He_PAMELA_Etot.txt");
        dataSet.save("output/He_PAMELA_Etot.txt");
    }
    {
        CRDB dataSet("PAMELA-CALO");
        dataSet.set_doi("10.1016/j.asr.2012.09.029");
        dataSet.set_ADSbibcode("2013AdSpR..51..219A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_He_PAMELA-CALO_Etot.txt");
        dataSet.save("output/He_PAMELA-CALO_Etot.txt");
    }
    {
        CRDB dataSet("PAMELA");
        dataSet.set_doi("10.1088/0004-637X/791/2/93");
        dataSet.set_ADSbibcode("2014ApJ...791...93A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("C");
        dataSet.set_comments("converted from original table");
        dataSet.loadDataset("source/nuclei/CRDB_C_PAMELA_Etot.txt");
        dataSet.save("output/C_PAMELA_Etot.txt");
    }
}

}  // namespace NUCLEI

#endif  // INCLUDE_NUCLEI_H_
