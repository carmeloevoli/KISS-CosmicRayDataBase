#ifndef KISS_EXPERIMENTS_ATIC02_H_
#define KISS_EXPERIMENTS_ATIC02_H_

#include "KISS/CRDB.h"

namespace ATIC02 {

void run() {
    KISS::CRDB data(KISS::atic02, KISS::totalEnergy, KISS::H, KISS::geometrical);
    data.setDOI("10.3103/S1062873809050098");
    data.setADSbibcode("2009BRASP..73..564P");
    data.run();
}

}  // namespace ATIC02

#endif