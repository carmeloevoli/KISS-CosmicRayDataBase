#ifndef KISS_EXPERIMENTS_GRAPES_H_
#define KISS_EXPERIMENTS_GRAPES_H_

#include "KISS/mytables.h"

namespace GRAPES {

void run() {
    {
        KISS::GRAPES::MyProtons data(KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.132.051002");
        data.setADSbibcode("2024PhRvL.132e1002V");
        data.run();
    }
}

}  // namespace GRAPES

#endif
