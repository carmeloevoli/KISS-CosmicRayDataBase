#ifndef KISS_EXPERIMENTS_ICECUBE_H_
#define KISS_EXPERIMENTS_ICECUBE_H_

#include "KISS/KCDC.h"

namespace ICECUBE {

void run() {
    {
        KISS::MyIceCube data(KISS::geometrical, KISS::allParticle);
        data.run();
    }
    {
        KISS::MyIceCube data(KISS::geometrical, KISS::H);
        data.run();
    }
    {
        KISS::MyIceCube data(KISS::geometrical, KISS::He);
        data.run();
    }
    {
        KISS::MyIceCube data(KISS::geometrical, KISS::O);
        data.run();
    }
    {
        KISS::MyIceCube data(KISS::geometrical, KISS::Fe);
        data.run();
    }
}

}  // namespace ICECUBE

#endif
