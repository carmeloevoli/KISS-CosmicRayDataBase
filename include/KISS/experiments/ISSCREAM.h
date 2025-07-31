#ifndef KISS_EXPERIMENTS_ISSCREAM_H_
#define KISS_EXPERIMENTS_ISSCREAM_H_

#include "KISS/CRDB.h"

namespace ISSCREAM {

void run() {
    KISS::CRDB data(KISS::isscream, KISS::kEnergy, KISS::H, KISS::Laff2_7);
    data.setDOI("10.3847/1538-4357/ac9d2c");
    data.setADSbibcode("2022ApJ...940..107C");
    data.run();
}

}  // namespace ISSCREAM

#endif