#ifndef KISS_EXPERIMENTS_KASCADE_H_
#define KISS_EXPERIMENTS_KASCADE_H_

#include "KISS/CRDB.h"
#include "KISS/KCDC.h"
#include "KISS/mytables.h"

namespace KASCADE {

void run() {
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2005_QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2005_SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_EPOS-199");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_QGSJET-II-02");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_SIBYLL-2.1");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_QGSJET-01");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_QGSJET-II-02");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_SIBYLL-2.1");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_QGSJET-01");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascade, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDescription("QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascade, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::allParticle, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::lnA, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::H, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::He, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::C, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::Si, KISS::geometrical);
        data.run();
    }
    {
        KISS::KASCADE::MyKuznetsov2024 data(KISS::Fe, KISS::geometrical);
        data.run();
    }
}

}  // namespace KASCADE

#endif  // KISS_EXPERIMENTS_KASCADE_H_
