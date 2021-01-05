// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_LEPTONS_H_
#define INCLUDE_LEPTONS_H_

#include "CRDB.h"
#include "KCDC.h"
#include "SSDC.h"
#include "include/mydb.h"

namespace LEPTONS {

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

void DAMPE() {
    SSDC dataSet("DAMPE");
    dataSet.set_doi("10.1038/nature24475");
    dataSet.set_ADSbibcode("2017Natur.552...63D");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("kinetic energy");
    dataSet.set_yType("leptons");
    dataSet.set_comments("");
    dataSet.loadDataset("source/leptons/SSDC_leptons_DAMPE_Etot.txt");
    dataSet.save("output/leptons_DAMPE_Etot.txt");
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

#endif  // INCLUDE_LEPTONS_H_
