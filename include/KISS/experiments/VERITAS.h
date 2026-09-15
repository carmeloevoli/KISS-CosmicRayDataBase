#ifndef KISS_EXPERIMENTS_VERITAS_H_
#define KISS_EXPERIMENTS_VERITAS_H_

#include "KISS/CRDB.h"

namespace VERITAS {

void run() {
    KISS::CRDB data(KISS::veritas, KISS::totalEnergy, KISS::lepton, KISS::geometrical);
    data.setDOI("10.1103/PhysRevD.98.062004");
    data.setADSbibcode("2018PhRvD..98f2004A");
    data.setComments("CRDB has no per-bin systematic errors; the paper reports an energy-scale systematic band. Table 1 may have a flux unit-label issue.");
    data.run();
}

}  // namespace VERITAS

#endif
