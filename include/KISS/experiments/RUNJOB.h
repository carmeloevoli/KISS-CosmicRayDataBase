#ifndef KISS_EXPERIMENTS_RUNJOB_H_
#define KISS_EXPERIMENTS_RUNJOB_H_

#include "KISS/KCDC.h"

namespace RUNJOB {

void run() {
    KISS::KCDC data(KISS::runjob, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
    data.setDOI("10.1016/S0927-6505(00)00163-8");
    data.setADSbibcode("2001APh....16...13A");
    data.run();
}

}  // namespace RUNJOB

#endif