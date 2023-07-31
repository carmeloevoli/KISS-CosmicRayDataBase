#ifndef KISS_EXPERIMENTS_HAWC_H_
#define KISS_EXPERIMENTS_HAWC_H_

#include "KISS/mytables.h"

namespace HAWC {

void run() {
    {
        KISS::MyLightHAWC data(KISS::geometrical);
        data.run();
    }
    {
        KISS::CRDB data(KISS::hawc, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1103/PhysRevD.96.122001");
        data.setADSbibcode("2017PhRvD..96l2001A");
        data.run();
    }
}

}  // namespace HAWC

#endif