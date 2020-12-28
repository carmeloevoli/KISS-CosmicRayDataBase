// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_ANTIPROTONS_H_
#define INCLUDE_ANTIPROTONS_H_

#include "CRDB.h"
#include "KCDC.h"
#include "SSDC.h"

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

#endif  // INCLUDE_ANTIPROTONS_H_
