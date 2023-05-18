#ifndef KISS_EXPERIMENTS_BESS_H_
#define KISS_EXPERIMENTS_BESS_H_

#include "KISS/CRDB.h"

namespace BESS {

void run() {
    {
        KISS::CRDB data(KISS::bess, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1016/j.astropartphys.2007.05.001");
        data.setADSbibcode("2007APh....28..154S");
        data.run();
    }
    {
        KISS::CRDB data(KISS::bess, KISS::kEnergyPerNucleon, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1016/j.astropartphys.2007.05.001");
        data.setADSbibcode("2007APh....28..154S");
        data.run();
    }
    {
        KISS::CRDB data(KISS::besspolar, KISS::kEnergy, KISS::antiproton, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.108.051102");
        data.setADSbibcode("2012PhRvL.108e1102A");
        data.run();
    }
}

}  // namespace BESS

#endif