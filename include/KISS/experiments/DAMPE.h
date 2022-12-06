#ifndef KISS_EXPERIMENTS_DAMPE_H_
#define KISS_EXPERIMENTS_DAMPE_H_

#include "KISS/SSDC.h"
#include "KISS/mytables.h"

namespace DAMPE {

void run() {
    {
        KISS::SSDC data(KISS::dampe, KISS::kEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1038/nature24475");
        data.setADSbibcode("2017Natur.552...63D");
        data.run();
    }
    {
        KISS::SSDC data(KISS::dampe, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1126/sciadv.aax3793");
        data.setADSbibcode("2019SciA....5.3793A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::dampe, KISS::kEnergy, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.126.201102");
        data.setADSbibcode("2021PhRvL.126t1102A");
        data.run();
    }
}

}  // namespace DAMPE

#endif
