#ifndef KISS_EXPERIMENTS_LHAASO_H_
#define KISS_EXPERIMENTS_LHAASO_H_

#include "KISS/mytables.h"

namespace LHAASO {

void run() {
    {
        KISS::MyProtonLHAASO data(KISS::geometrical, "QGSJETII-04");
        data.run();
    }
    {
        KISS::MyProtonLHAASO data(KISS::geometrical, "EPOS-LHC");
        data.run();
    }
}

}  // namespace LHAASO

#endif