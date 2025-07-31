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
        KISS::CRDB data(KISS::pamela, KISS::rigidity, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/791/2/93");
        data.setADSbibcode("2014ApJ...791...93A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::kEnergyPerNucleon, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1088/0004-637X/791/2/93");
        data.setADSbibcode("2014ApJ...791...93A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::kEnergy, KISS::antiproton, KISS::Laff2_7);
        data.setDOI("10.1134/S002136401222002X");
        data.setADSbibcode("2013JETPL..96..621A");
        data.setComments("");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::kEnergy, KISS::electron, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.111.081102");
        data.setADSbibcode("2013PhRvL.111h1102A");
        data.setComments("");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::kEnergy, KISS::positron, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.111.081102");
        data.setADSbibcode("2013PhRvL.111h1102A");
        data.setComments("");
        data.run();
    }
    {
        KISS::CRDB data(KISS::pamela, KISS::kEnergy, KISS::positronfraction, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.111.081102");
        data.setADSbibcode("2013PhRvL.111h1102A");
        data.setComments("");
        data.run();
    }
}

}  // namespace PAMELA

#endif