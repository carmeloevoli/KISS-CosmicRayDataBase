#ifndef KISS_EXPERIMENTS_TIBET_H_
#define KISS_EXPERIMENTS_TIBET_H_

#include "KISS/mytables.h"

namespace TIBET {

void run() {
    {
        KISS::KCDC data(KISS::tibet, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("QGSJET+HD");
        data.setADSbibcode("");
        data.setDOI("");
        data.run();
    }
    {
        KISS::KCDC data(KISS::tibet, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("QGSJET+PD");
        data.setADSbibcode("");
        data.setDOI("");
        data.run();
    }
    {
        KISS::KCDC data(KISS::tibet, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("SIBYLL+HD");
        data.setADSbibcode("");
        data.setDOI("");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tibet, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.run();
    }
}

}  // namespace TIBET

#endif