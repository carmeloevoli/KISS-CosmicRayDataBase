#ifndef KISS_EXPERIMENTS_TALE_H_
#define KISS_EXPERIMENTS_TALE_H_

#include "KISS/KCDC.h"

namespace TALE {

void run() {
    KISS::KCDC data(KISS::tale, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
    data.setDOI("10.3847/1538-4357/aada05");
    data.setADSbibcode("2018ApJ...865...74A");
    data.run();
}

}  // namespace TALE

#endif