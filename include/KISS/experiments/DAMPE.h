#ifndef KISS_EXPERIMENTS_DAMPE_H_
#define KISS_EXPERIMENTS_DAMPE_H_

#include "KISS/CRDB.h"
#include "KISS/mytables.h"

namespace DAMPE {

void run() {
    {
        KISS::CRDB data(KISS::dampe, KISS::totalEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1038/nature24475");
        data.setADSbibcode("2017Natur.552...63D");
        data.run();
    }
    // {
    //     KISS::DAMPE::MyBoron data(KISS::Laff2_7);
    //     data.run();
    // }
    // {
    //     KISS::DAMPE::MyLight data(KISS::Laff2_7);
    //     data.run();
    // }
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
    // 2025
    // {
    //     KISS::DAMPE::MyPrimary data(KISS::H, KISS::Laff2_7);
    //     data.run();
    // }
    // {
    //     KISS::DAMPE::MyPrimary data(KISS::He, KISS::Laff2_7);
    //     data.run();
    // }
    // {
    //     KISS::DAMPE::MyPrimary data(KISS::C, KISS::Laff2_7);
    //     data.run();
    // }
    // {
    //     KISS::DAMPE::MyPrimary data(KISS::O, KISS::Laff2_7);
    //     data.run();
    // }
    // {
    //     KISS::DAMPE::MyPrimary data(KISS::Fe, KISS::Laff2_7);
    //     data.run();
    // }
}

}  // namespace DAMPE

#endif
