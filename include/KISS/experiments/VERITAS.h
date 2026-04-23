#ifndef KISS_EXPERIMENTS_VERITAS_H_
#define KISS_EXPERIMENTS_VERITAS_H_

#include "KISS/mytables.h"

namespace VERITAS {

void run() {
    KISS::VERITAS::MyLeptons data(KISS::geometrical);
    data.run();
}

}  // namespace VERITAS

#endif
