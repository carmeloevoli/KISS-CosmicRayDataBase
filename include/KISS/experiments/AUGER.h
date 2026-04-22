#ifndef KISS_EXPERIMENTS_AUGER_H_
#define KISS_EXPERIMENTS_AUGER_H_

#include "KISS/KCDC.h"

namespace AUGER {

void run() {
    {
        KISS::CRDB data(KISS::auger, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.22323/1.301.0486");
        data.setADSbibcode("2017ICRC...35..486F");
        data.setDescription("hybrid");
        data.run();
    }
    {
        KISS::CRDB data(KISS::auger, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1140/epjc/s10052-021-09700-w");
        data.setADSbibcode("2021EPJC...81..966A");
        data.setDescription("SD");
        data.run();
    }
}

}  // namespace AUGER

#endif