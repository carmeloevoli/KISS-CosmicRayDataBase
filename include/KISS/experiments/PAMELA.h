#ifndef KISS_EXPERIMENTS_PAMELA_H_
#define KISS_EXPERIMENTS_PAMELA_H_

#include "KISS/CRDB.h"

namespace PAMELA {

void run() {
    {
        KISS::CRDB data(KISS::pamela, KISS::rigidity, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::rigidity, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::rigidity, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/791/2/93");
        data.setADSbibcode("2014ApJ...791...93A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::totalEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.setComments("converted from original table in rigidity");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::totalEnergy, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.setComments("converted from original table in rigidity");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::totalEnergy, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1088/0004-637X/791/2/93");
        data.setADSbibcode("2014ApJ...791...93A");
        data.setComments("converted from original table in rigidity");
        data.run();
    }
}

}  // namespace PAMELA

#endif