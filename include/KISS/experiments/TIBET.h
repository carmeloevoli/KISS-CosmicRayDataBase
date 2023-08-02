#ifndef KISS_EXPERIMENTS_TIBET_H_
#define KISS_EXPERIMENTS_TIBET_H_

#include "KISS/mytables.h"

namespace TIBET {

void run() {
    {
        KISS::MyAllTibet data(KISS::geometrical, "QGSJET+HD");
        data.run();
    }
    {
        KISS::MyAllTibet data(KISS::geometrical, "QGSJET+PD");
        data.run();
    }
    {
        KISS::MyAllTibet data(KISS::geometrical, "SIBYLL+HD");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tibet, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.run();
    }
}

}  // namespace TIBET

#endif