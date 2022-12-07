#ifndef KISS_EXPERIMENTS_ARGO_H_
#define KISS_EXPERIMENTS_ARGO_H_

#include "KISS/mytables.h"

namespace ARGO {

void run() {
    KISS::MyLightARGO data(KISS::geometrical);
    data.run();
}

}  // namespace ARGO

#endif