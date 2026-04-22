#ifndef KISS_EXPERIMENTS_HAWC_H_
#define KISS_EXPERIMENTS_HAWC_H_

#include "KISS/mytables.h"

namespace HAWC {

void run() {
    {
        KISS::HAWC::MyLight data(KISS::geometrical);
        data.run();
    }
    {
        KISS::CRDB data(KISS::hawc, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.22323/1.395.0330");
        data.setADSbibcode("2022icrc.confE.330M");
        data.run();
    }
}

}  // namespace HAWC

#endif