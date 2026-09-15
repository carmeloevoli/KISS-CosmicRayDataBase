#ifndef KISS_EXPERIMENTS_TUNKA_H_
#define KISS_EXPERIMENTS_TUNKA_H_

#include "KISS/CRDB.h"

namespace TUNKA {

void run() {
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDescription("QGSJet01");
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1016/j.astropartphys.2019.102406");
        data.setADSbibcode("2020APh...11702406B");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tunkahiscore, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setADSbibcode("2025icrc.confE.206B");
        data.run();
    }
}

}  // namespace TUNKA

#endif
