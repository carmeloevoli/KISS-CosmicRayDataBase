#ifndef KISS_EXPERIMENTS_YAKUTSK_H_
#define KISS_EXPERIMENTS_YAKUTSK_H_

#include "KISS/mytables.h"

namespace YAKUTSK {

void run() {
    {
        KISS::YAKUTSK::MyLnA data(KISS::geometrical);
        data.run();
    }
}

}  // namespace YAKUTSK

#endif
