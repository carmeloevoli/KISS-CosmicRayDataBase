#ifndef KISS_EXPERIMENTS_TUNKA_H_
#define KISS_EXPERIMENTS_TUNKA_H_

#include "KISS/CRDB.h"
#include "KISS/KCDC.h"

namespace TUNKA {

void run() {
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P");
        data.setComments("Model: QGSJet01");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P ");
        data.setComments("Model: QGSJet01");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P ");
        data.setComments("Model: QGSJet01");
        data.run();
    }
}

}  // namespace TUNKA

#endif