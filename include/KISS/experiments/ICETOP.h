#ifndef KISS_EXPERIMENTS_ICETOP_H_
#define KISS_EXPERIMENTS_ICETOP_H_

#include "KISS/KCDC.h"

namespace ICETOP {

void run() {
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("IceCube_SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("IceCube_SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDescription("IceCube_SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.100.082002");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("");
        data.setDOI("10.1103/PhysRevD.100.082002 ");
        data.setADSbibcode("2019PhRvD.100h2002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1103/PhysRevD.102.122001");
        data.setADSbibcode("2020PhRvD.102l2001A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::icetop, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("QGSJet-II-04");
        data.setDOI("10.1103/PhysRevD.102.122001");
        data.setADSbibcode("2020PhRvD.102l2001A");
        data.run();
    }
}

}  // namespace ICETOP

#endif
