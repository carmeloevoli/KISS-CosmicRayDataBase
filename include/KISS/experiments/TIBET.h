#ifndef KISS_EXPERIMENTS_TIBET_H_
#define KISS_EXPERIMENTS_TIBET_H_

#include "KISS/mytables.h"

namespace TIBET {

void run() {
    // {
    //     KISS::MyAllTibet data(KISS::geometrical, "QGSJET+HD");
    //     data.run();
    // }
    // {
    //     KISS::MyAllTibet data(KISS::geometrical, "QGSJET+PD");
    //     data.run();
    // }
    // {
    //     KISS::MyAllTibet data(KISS::geometrical, "SIBYLL+HD");
    //     data.run();
    // }
    {
        KISS::CRDB data(KISS::tibet, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDOI("10.1126/science.1199172");
        data.setADSbibcode("2011Sci...332...69A");
        data.run();
    }
}

}  // namespace TIBET

#endif