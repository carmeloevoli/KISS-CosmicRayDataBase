#ifndef KISS_EXPERIMENTS_HESS_H_
#define KISS_EXPERIMENTS_HESS_H_

#include "KISS/CRDB.h"

namespace HESS {

void run() {
    {
        KISS::CRDB data(KISS::hess, KISS::totalEnergy, KISS::Fe, KISS::geometrical);
        data.setDOI("10.1103/PhysRevD.75.042004");
        data.setADSbibcode("2007PhRvD..75d2004A");
        data.run();  // loadDataset("source/nuclei/SSDC_Fe_HESS_Ek.txt");
    }
}

}  // namespace HESS

#endif