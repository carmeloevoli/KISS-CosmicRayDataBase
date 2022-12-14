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
}

}  // namespace TIBET

#endif