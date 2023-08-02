#ifndef KISS_EXPERIMENTS_KASCADE_GRANDE_H_
#define KISS_EXPERIMENTS_KASCADE_GRANDE_H_

#include "KISS/KCDC.h"

namespace KASCADE_Grande {

void run() {
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("EPOS-LHC");
        data.setDOI("10.22323/1.236.0359");
        data.setADSbibcode("2015ICRC...34..359B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("QGSJET-II-04");
        data.setDOI("10.22323/1.236.0359");
        data.setADSbibcode("2015ICRC...34..359B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("QGSJET-II-02");
        data.setDOI("10.22323/1.236.0359");
        data.setADSbibcode("2015ICRC...34..359B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.22323/1.236.0359");
        data.setADSbibcode("2015ICRC...34..359B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("SIBYLL-2.3");
        data.setDOI("10.22323/1.236.0359/");
        data.setADSbibcode("2015ICRC...34..359B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("SIBYLL-2.3");
        data.setDOI("10.22323/1.301.0316");
        data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::unknown);
        data.setDescription("EPOS-LHC");
        data.setDOI("10.22323/1.301.0316");
        data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::unknown);
        data.setDescription("SIBYLL-2.1");
        data.setDOI("10.22323/1.301.0316");
        data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDescription("QGSJET-II-02");
        // data.setDOI("10.22323/1.301.0316");
        // data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDescription("QGSJET-II-03");
        // data.setDOI("10.22323/1.301.0316");
        // data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::kascadeGrande, KISS::totalEnergy, KISS::light, KISS::geometrical);
        data.setDescription("QGSJET-II-04");
        // data.setDOI("10.22323/1.301.0316");
        // data.setADSbibcode("2017ICRC...35..316A");
        data.run();
    }
}

}  // namespace KASCADE_Grande

#endif