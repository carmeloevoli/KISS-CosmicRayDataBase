#ifndef KISS_EXPERIMENTS_LHAASO_H_
#define KISS_EXPERIMENTS_LHAASO_H_

#include "KISS/mytables.h"

namespace LHAASO {

void run() {
    {
        KISS::LHAASO::MyAllParticle data("QGSJET-II-04", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyAllParticle data("EPOS-LHC", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyAllParticle data("SIBYLL-2.3d", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyLnA data("QGSJET-II-04", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyLnA data("EPOS-LHC", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyLnA data("SIBYLL-2.3d", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::light, "QGSJET-II-04", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::light, "EPOS-LHC", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::light, "SIBYLL-2.3d", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::H, "QGSJET-II-04", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::H, "EPOS-LHC", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::H, "SIBYLL-2.3d", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::He, "QGSJET-II-04", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::He, "EPOS-LHC", KISS::geometrical);
        data.run();
    }
    {
        KISS::LHAASO::MyNuclei data(KISS::He, "SIBYLL-2.3d", KISS::geometrical);
        data.run();
    }
}

}  // namespace LHAASO

#endif
