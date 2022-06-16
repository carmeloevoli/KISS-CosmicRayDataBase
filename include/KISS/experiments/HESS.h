#ifndef KISS_EXPERIMENTS_HESS_H_
#define KISS_EXPERIMENTS_HESS_H_

#include "KISS/CRDB.h"
#include "KISS/mytables.h"

namespace HESS {

void run() {
    {
        KISS::CRDB data(KISS::hess, KISS::totalEnergy, KISS::Fe, KISS::geometrical);
        data.setDOI("10.1103/PhysRevD.75.042004");
        data.setADSbibcode("2007PhRvD..75d2004A");
        data.run();  // loadDataset("source/nuclei/SSDC_Fe_HESS_Ek.txt");
    }
    {
        KISS::MyLeptonHess data(KISS::geometrical);
        data.setDOI("10.1051/0004-6361/200913323");
        data.setADSbibcode("2009A&A...508..561A");
        data.setUrl("https://www.mpi-hd.mpg.de/hfm/HESS/pages/publications/auxiliary/auxinfo_electrons2.html");
        data.setComments("systematic errors not official, derived from URL");
        data.run();
    }
}

}  // namespace HESS

#endif