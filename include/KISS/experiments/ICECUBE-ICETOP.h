#ifndef KISS_EXPERIMENTS_ICECUBE_ICETOP_H_
#define KISS_EXPERIMENTS_ICECUBE_ICETOP_H_

#include "KISS/KCDC.h"

namespace ICECUBE_ICETOP {

void run() {
    {
        KISS::KCDC data(KISS::icecube, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::icecube, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::icecube, KISS::totalEnergy, KISS::He, KISS::unknown);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
}

}  // namespace ICECUBE_ICETOP

#endif
