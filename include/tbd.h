// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_ALLPARTICLE_H_
#define INCLUDE_ALLPARTICLE_H_

#include "include/CRDB.h"
#include "include/KCDC.h"
#include "include/mydb.h"

namespace ALLPARTICLE {

void ARGO() {
    MyAllARGO dataSet;
    dataSet.set_doi("unpublished");
    dataSet.set_ADSbibcode("unpublished");
    dataSet.set_source("");
    dataSet.set_url("");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/mysource_ARGO_Etot.txt");
    dataSet.save("output/allparticle_ARGO_Etot.txt");
}

void AUGER() {
    MyAllAUGER dataSet;
    dataSet.set_doi("https://pos.sissa.it/358/450/");
    dataSet.set_ADSbibcode("2019ICRC...36..450V");
    dataSet.set_source("");
    dataSet.set_url("https://www.auger.org/index.php/science/data");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/mysource_AUGER_Etot.txt");
    dataSet.save("output/allparticle_AUGER_Etot.txt");
}

void HAWC() {
    MyAllHAWC dataSet;
    dataSet.set_doi("10.1103/PhysRevD.96.122001");
    dataSet.set_ADSbibcode("2017PhRvD..96l2001A");
    dataSet.set_source("");
    dataSet.set_url("");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("from their TABLE IV");
    dataSet.loadDataset("source/allparticle/mysource_HAWC_Etot.txt");
    dataSet.save("output/allparticle_HAWC_Etot.txt");
}

void TELESCOPEARRAY() {
    MyAllTA dataSet;
    dataSet.set_doi("10.22323/1.301.1096");
    dataSet.set_ADSbibcode("2017ICRC...35.1096M");
    dataSet.set_source("");
    dataSet.set_url("https://pos.sissa.it/301/1096");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/mysource_TA_Etot.txt");
    dataSet.save("output/allparticle_TA_Etot.txt");
}

void TIBET() {
    {
        MyAllTIBET dataSet("QGSJET+HD");
        dataSet.set_doi("10.1086/529514");
        dataSet.set_ADSbibcode("2008ApJ...678.1165A");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_QGSJET+HD_Etot.txt");
    }
    {
        MyAllTIBET dataSet("QGSJET+PD");
        dataSet.set_doi("10.1086/529514");
        dataSet.set_ADSbibcode("2008ApJ...678.1165A");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_QGSJET+PD_Etot.txt");
    }
    {
        MyAllTIBET dataSet("SIBYLL+HD");
        dataSet.set_doi("10.1086/529514");
        dataSet.set_ADSbibcode("2008ApJ...678.1165A");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_SIBYLL+HD_Etot.txt");
    }
}

}  // namespace ALLPARTICLE

namespace ANTIPROTONS {

void AMS02() {
    CRDB dataSet("AMS-02");
    dataSet.set_doi("10.1103/PhysRevLett.117.091103");
    dataSet.set_ADSbibcode("2016PhRvL.117i1103A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic energy");
    dataSet.set_yType("H-bar");
    dataSet.set_comments("converted from original table");
    dataSet.loadDataset("source/antiprotons/CRDB_H-bar_AMS-02_Ek.txt");
    dataSet.save("output/H-bar_AMS-02_Ek.txt");
}

void BESS() {
    CRDB dataSet("BESS-PolarII");
    dataSet.set_doi("10.1103/PhysRevLett.108.051102");
    dataSet.set_ADSbibcode("2012PhRvL.108e1102A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic energy");
    dataSet.set_yType("H-bar");
    dataSet.set_comments("");
    dataSet.loadDataset("source/antiprotons/CRDB_H-bar_BESS-PolarII_Ek.txt");
    dataSet.save("output/H-bar_BESS_Ek.txt");
}

void PAMELA() {
    CRDB dataSet("PAMELA");
    dataSet.set_doi("10.1134/S002136401222002X");
    dataSet.set_ADSbibcode("2013JETPL..96..621A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic energy");
    dataSet.set_yType("H-bar");
    dataSet.set_comments("");
    dataSet.loadDataset("source/antiprotons/CRDB_H-bar_PAMELA_Ek.txt");
    dataSet.save("output/H-bar_PAMELA_Ek.txt");
}

}  // namespace ANTIPROTONS

void AMS02() {
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.122.041102");
        dataSet.set_ADSbibcode("2019PhRvL.122d1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e+");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e+_AMS-02_Ek.txt");
        dataSet.save("output/e+_AMS-02_Ek.txt");
    }
    {
        CRDB dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.122.101101");
        dataSet.set_ADSbibcode("2019PhRvL.122j1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e-");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e-_AMS-02_Ek.txt");
        dataSet.save("output/e-_AMS-02_Ek.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.122.101101");
        dataSet.set_ADSbibcode("2019PhRvL.122j1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("leptons");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/SSDC_leptons_AMS-02_Ek.txt");
        dataSet.save("output/leptons_AMS-02_Ek.txt");
    }
}

void CALET() {
    SSDC dataSet("CALET");
    dataSet.set_doi("10.1103/PhysRevLett.120.261102");
    dataSet.set_ADSbibcode("2018PhRvL.120z1102A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic energy");
    dataSet.set_yType("leptons");
    dataSet.set_comments("");
    dataSet.loadDataset("source/leptons/SSDC_leptons_CALET_Etot.txt");
    dataSet.save("output/leptons_CALET_Etot.txt");
}

void FERMI() {
    {
        CRDB dataSet("FERMI");
        dataSet.set_doi("10.1103/PhysRevLett.108.011103");
        dataSet.set_ADSbibcode("2012PhRvL.108a1103A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e+");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e+_FERMI_Ek.txt");
        dataSet.save("output/e+_FERMI_Ek.txt");
    }
    {
        CRDB dataSet("FERMI");
        dataSet.set_doi("10.1103/PhysRevLett.108.011103");
        dataSet.set_ADSbibcode("2012PhRvL.108a1103A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e-");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e-_FERMI_Ek.txt");
        dataSet.save("output/e-_FERMI_Ek.txt");
    }
    {
        CRDB dataSet("FERMI");
        dataSet.set_doi("10.1103/PhysRevD.95.082007");
        dataSet.set_ADSbibcode("2017PhRvD..95h2007A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("leptons");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_leptons_FERMI_Etot.txt");
        dataSet.save("output/leptons_FERMI_Etot.txt");
    }
}

void PAMELA() {
    {
        CRDB dataSet("PAMELA");
        dataSet.set_doi("10.1103/PhysRevLett.111.081102");
        dataSet.set_ADSbibcode("2013PhRvL.111h1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e+");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e+_PAMELA_Ek.txt");
        dataSet.save("output/e+_PAMELA_Ek.txt");
    }
    {
        CRDB dataSet("PAMELA");
        dataSet.set_doi("10.1103/PhysRevLett.106.201101");
        dataSet.set_ADSbibcode("2011PhRvL.106t1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic energy");
        dataSet.set_yType("e-");
        dataSet.set_comments("");
        dataSet.loadDataset("source/leptons/CRDB_e-_PAMELA_Ek.txt");
        dataSet.save("output/e-_PAMELA_Ek.txt");
    }
}

void VERITAS() {
    MyLeptonVERITAS dataSet;
    dataSet.set_doi("10.1103/PhysRevD.98.062004");
    dataSet.set_ADSbibcode("2018PhRvD..98f2004A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total energy");
    dataSet.set_yType("leptons");
    dataSet.set_comments("possible error in Table I: the flux is in GeV^-1");
    dataSet.loadDataset("source/leptons/mysource_leptons_VERITAS_Etot.txt");
    dataSet.save("output/leptons_VERITAS_Etot.txt");
}

void HESS() {
    MyLeptonHESS dataSet;
    dataSet.set_doi("10.1051/0004-6361/200913323");
    dataSet.set_ADSbibcode("2009A&A...508..561A");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total energy");
    dataSet.set_yType("leptons");
    dataSet.set_comments(
        "systematic errors not official, derived from "
        "https://www.mpi-hd.mpg.de/hfm/HESS/pages/publications/auxiliary/auxinfo_electrons2.html");
    dataSet.loadDataset("source/leptons/mysource_leptons_HESS_Etot.txt");
    dataSet.save("output/leptons_HESS_Etot.txt");
}

}  // namespace LEPTONS

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
        dataSet.set_yType("O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/myO_CALET_Ekn.txt");
        dataSet.save("output/O_CALET_Etot.txt");
    }
    {
        MyHeavyCALET dataSet(56);
        dataSet.set_doi("10.1103/PhysRevLett.126.241101");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("Fe");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/myFe_CALET_Ekn.txt");
        dataSet.save("output/Fe_CALET_Etot.txt");
    }
}

}  // namespace NUCLEI

#endif  // INCLUDE_ALLPARTICLE_H_
