#ifndef KISS_EXPERIMENTS_AUGER_H_
#define KISS_EXPERIMENTS_AUGER_H_

#include "KISS/KCDC.h"

namespace AUGER {

void run() {
    {
        KISS::MyAllAuger2021 data(KISS::geometrical);
        data.run();
    }
    {
        KISS::MyAllAuger2019 data(KISS::geometrical);
        data.run();
    }
}

}  // namespace AUGER

#endif