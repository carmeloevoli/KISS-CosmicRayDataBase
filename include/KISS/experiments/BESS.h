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
        KISS::CRDB data(KISS::bess, KISS::totalEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1016/j.astropartphys.2007.05.001");
        data.setADSbibcode("2007APh....28..154S");
        data.setComments("converted from original table in kinetic energy");
        data.run();
    }
    {
        KISS::CRDB data(KISS::bess, KISS::totalEnergy, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1016/j.astropartphys.2007.05.001");
        data.setADSbibcode("2007APh....28..154S");
        data.setComments("converted from original table in kinetic energy");
        data.run();
    }
}

}  // namespace BESS

#endif