#ifndef KISS_EXPERIMENTS_TALE_H_
#define KISS_EXPERIMENTS_TALE_H_

#include "KISS/KCDC.h"

namespace TALE {

void run() {
    {
        KISS::MyAllTale data(KISS::geometrical);
        data.run();
    }
    {
        KISS::CRDB data(KISS::ta, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.22323/1.236.0349");
        data.setADSbibcode("2015ICRC...34..349I");
        data.run();
    }
}

}  // namespace TALE

#endif