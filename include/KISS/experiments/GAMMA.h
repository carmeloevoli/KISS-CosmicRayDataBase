#ifndef KISS_EXPERIMENTS_GAMMA_H_
#define KISS_EXPERIMENTS_GAMMA_H_

#include "KISS/KCDC.h"

namespace GAMMA {

void run() {
    {
        KISS::CRDB data(KISS::gamma, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("");
        data.setDOI("10.1103/PhysRevD.89.123003");
        data.setADSbibcode("2014PhRvD..89l3003T");
        data.run();
    }
}

}  // namespace GAMMA

#endif
