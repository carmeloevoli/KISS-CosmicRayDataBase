#ifndef KISS_EXPERIMENTS_KASCADE_GRANDE_H_
#define KISS_EXPERIMENTS_KASCADE_GRANDE_H_

#include "KISS/KCDC.h"

namespace KASCADE_Grande {

void run() {
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("SIBYLL-2.3");
        data.setDOI("10.22323/1.301.0316");
        data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("QGSJet-II-04");
        data.setDOI("10.22323/1.236.0263");
        data.setADSbibcode("2015ICRC...34..263S");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDescription("QGSJET-II-04");
        data.setDOI("10.22323/1.236.0263");
        data.setADSbibcode("2015ICRC...34..263S");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("QGSJET-II-2");
        data.setDOI("10.48550/arXiv.0906.4007");
        data.setADSbibcode("2009arXiv0906.4007K");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDescription("SIBYLL-2.3");
        data.setDOI("10.22323/1.301.0316");
        data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
}

}  // namespace KASCADE_Grande

#endif