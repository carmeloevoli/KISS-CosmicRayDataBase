#ifndef KISS_EXPERIMENTS_CALET_H_
#define KISS_EXPERIMENTS_CALET_H_

#include "KISS/SSDC.h"

namespace CALET {

void run() {
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.120.261102");
        data.setADSbibcode("2017Natur.552...63D");
        data.run();
    }
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1126/sciadv.aax3793");
        data.setADSbibcode("2019SciA....5.3793A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.125.251102");
        data.setADSbibcode("2020PhRvL.125y1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::O, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.125.251102");
        data.setADSbibcode("2020PhRvL.125y1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::Fe, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.126.241101");
        data.setADSbibcode("2021PhRvL.126x1101A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::calet, KISS::kEnergy, KISS::Ni, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.128.131103");
        data.setADSbibcode("2022PhRvL.128m1103A");
        data.run();
    }
}

}  // namespace CALET

#endif