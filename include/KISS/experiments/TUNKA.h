#ifndef KISS_EXPERIMENTS_TUNKA_H_
#define KISS_EXPERIMENTS_TUNKA_H_

#include "KISS/CRDB.h"
#include "KISS/KCDC.h"

namespace TUNKA {

void run() {
    {
        KISS::KCDC data(KISS::tunka133, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDOI("10.1016/j.astropartphys.2019.102406");
        data.setADSbibcode("2020APh...11702406B");
        data.run();
    }
    {
        KISS::KCDC data(KISS::tunkarex, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDOI("10.22323/1.358.0319");
        data.setADSbibcode("2019ICRC...36..319K");
        data.run();
    }
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P ");
        data.setComments("Model: QGSJet01");
        data.run();  // "source/nuclei/CRDB_H_TUNKA-133_Etot.txt");
    }
    {
        KISS::CRDB data(KISS::tunka133, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDOI("10.1016/j.nima.2013.09.018");
        data.setADSbibcode("2014NIMPA.756...94P ");
        data.setComments("Model: QGSJet01");
        data.run();  // loadDataset("source/nuclei/CRDB_He_TUNKA-133_Etot.txt");
    }
}

}  // namespace TUNKA

#endif