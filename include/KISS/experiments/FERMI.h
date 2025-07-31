#ifndef KISS_EXPERIMENTS_FERMI_H_
#define KISS_EXPERIMENTS_FERMI_H_

#include "KISS/CRDB.h"

namespace FERMI {

void run() {
    {
        KISS::CRDB data(KISS::fermi, KISS::totalEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevD.95.082007");
        data.setADSbibcode("2017PhRvD..95h2007A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::fermi, KISS::kEnergy, KISS::electron, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.108.011103");
        data.setADSbibcode("2012PhRvL.108a1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::fermi, KISS::kEnergy, KISS::positron, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.108.011103");
        data.setADSbibcode("2012PhRvL.108a1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::fermi, KISS::totalEnergy, KISS::positronfraction, KISS::geometrical);
        data.setDOI("10.1103/PhysRevD.95.082007");
        data.setADSbibcode("2017PhRvD..95h2007A");
        data.run();
    }
}

}  // namespace FERMI

#endif
