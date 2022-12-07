#ifndef KISS_EXPERIMENTS_HAWC_H_
#define KISS_EXPERIMENTS_HAWC_H_

#include "KISS/mytables.h"

namespace HAWC {

void run() {
    KISS::MyLightHAWC data(KISS::geometrical);
    data.run();
}

}  // namespace HAWC

#endif