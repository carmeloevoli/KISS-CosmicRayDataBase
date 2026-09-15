#ifndef KISS_EXPERIMENTS_DAMPE_H_
#define KISS_EXPERIMENTS_DAMPE_H_

#include "KISS/CRDB.h"

namespace DAMPE {

void run() {
    {
        KISS::CRDB data(KISS::dampe, KISS::totalEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1038/nature24475");
        data.setADSbibcode("2017Natur.552...63D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1038/s41586-026-10472-0");
        data.setADSbibcode("2026Natur.653...52D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1038/s41586-026-10472-0");
        data.setADSbibcode("2026Natur.653...52D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::light, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevD.109.L121101");
        data.setADSbibcode("2024PhRvD.109l1101A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergyPerNucleon, KISS::B, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.134.191001");
        data.setADSbibcode("2025PhRvL.134s1001A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergyPerNucleon, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1016/j.scib.2022.10.002");
        data.setADSbibcode("2022SciBu..67.2162D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergyPerNucleon, KISS::B_O, KISS::geometrical);
        data.setDOI("10.1016/j.scib.2022.10.002");
        data.setADSbibcode("2022SciBu..67.2162D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1038/s41586-026-10472-0");
        data.setADSbibcode("2026Natur.653...52D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::O, KISS::Laff2_7);
        data.setDOI("10.1038/s41586-026-10472-0");
        data.setADSbibcode("2026Natur.653...52D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergy, KISS::Fe, KISS::Laff2_7);
        data.setDOI("10.1038/s41586-026-10472-0");
        data.setADSbibcode("2026Natur.653...52D");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergyPerNucleon, KISS::Ni, KISS::Laff2_7);
        data.setDOI("10.1103/p9zs-g8ky");
        data.setADSbibcode("2026PhRvL.137e1001A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::dampe, KISS::kEnergyPerNucleon, KISS::Ni_Fe, KISS::geometrical);
        data.setDOI("10.1103/p9zs-g8ky");
        data.setADSbibcode("2026PhRvL.137e1001A");
        data.run();
    }
}

}  // namespace DAMPE

#endif
