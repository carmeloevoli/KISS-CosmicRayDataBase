#ifndef KISS_EXPERIMENTS_TALE_H_
#define KISS_EXPERIMENTS_TALE_H_

#include "KISS/KCDC.h"

namespace TA {

void run() {
    {
        KISS::CRDB data(KISS::tale, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.3847/1538-4357/aada05");
        data.setADSbibcode("2018ApJ...865...74A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::ta, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.22323/1.236.0349");
        data.setADSbibcode("2015ICRC...34..349I");
        data.run();
    }
}

}  // namespace TA

#endif