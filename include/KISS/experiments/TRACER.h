#ifndef KISS_EXPERIMENTS_TRACER_H_
#define KISS_EXPERIMENTS_TRACER_H_

#include "KISS/CRDB.h"

namespace TRACER {

void run() {
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::C, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::O, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::Ne, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::Mg, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::Si, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tracer, KISS::kEnergyPerNucleon, KISS::Fe, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/742/1/14");
        data.setADSbibcode("2011ApJ...742...14O");
        data.run();
    }
}

}  // namespace TRACER

#endif