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
}

}  // namespace CALET

#endif