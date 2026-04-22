#ifndef KISS_EXPERIMENTS_GRAPES_H_
#define KISS_EXPERIMENTS_GRAPES_H_

#include "KISS/mytables.h"

namespace GRAPES {

void run() {
    {
        KISS::GRAPES::MyProtons data(KISS::geometrical);
        data.run();
    }
}

}  // namespace GRAPES

#endif
