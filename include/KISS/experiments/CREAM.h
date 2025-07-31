#ifndef KISS_EXPERIMENTS_CREAM_H_
#define KISS_EXPERIMENTS_CREAM_H_

#include "KISS/CRDB.h"

namespace CREAM {

void run() {
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.3847/1538-4357/aa68e4");
        data.setADSbibcode("2017ApJ...839....5Y");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::He, KISS::Laff2_7);
        data.setDOI("10.3847/1538-4357/aa68e4");
        data.setADSbibcode("2017ApJ...839....5Y");
        data.run();
    }

    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::N, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::O, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::Ne, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::Mg, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::Si, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::Fe, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/707/1/593");
        data.setADSbibcode("2009ApJ...707..593A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1016/j.astropartphys.2008.07.010 ");
        data.setADSbibcode("2008APh....30..133A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::N_O, KISS::geometrical);
        data.setDOI("10.1016/j.astropartphys.2008.07.010 ");
        data.setADSbibcode("2008APh....30..133A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::cream, KISS::kEnergyPerNucleon, KISS::C_O, KISS::geometrical);
        data.setDOI("10.1016/j.astropartphys.2008.07.010 ");
        data.setADSbibcode("2008APh....30..133A");
        data.run();
    }
}

}  // namespace CREAM

#endif
