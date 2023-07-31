#ifndef KISS_EXPERIMENTS_ICECUBE_H_
#define KISS_EXPERIMENTS_ICECUBE_H_

#include "KISS/KCDC.h"

namespace ICECUBE {

void run() {
    {
        KISS::CRDB data(KISS::icecube, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icecube, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icecube, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
}

}  // namespace ICECUBE

#endif
