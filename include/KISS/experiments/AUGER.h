#ifndef KISS_EXPERIMENTS_AUGER_H_
#define KISS_EXPERIMENTS_AUGER_H_

#include "KISS/KCDC.h"

namespace AUGER {

void run() {
    {
        KISS::CRDB data(KISS::auger, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("");
        data.setADSbibcode("");
        data.setDescription("hybrid");
        data.run();
    }
    {
        KISS::CRDB data(KISS::auger, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("");
        data.setADSbibcode("");
        data.setDescription("SD");
    }
}

}  // namespace AUGER

#endif