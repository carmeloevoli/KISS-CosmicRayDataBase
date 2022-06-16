#ifndef KISS_EXPERIMENTS_VERITAS_H_
#define KISS_EXPERIMENTS_VERITAS_H_

#include "KISS/mytables.h"

namespace VERITAS {

void run() {
    KISS::MyLeptonVeritas data(KISS::geometrical);
    data.run();
}

}  // namespace VERITAS

#endif
