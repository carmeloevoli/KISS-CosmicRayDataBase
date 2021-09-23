#ifndef KISS_EXPERIMENTS_FERMI_H_
#define KISS_EXPERIMENTS_FERMI_H_

#include "KISS/SSDC.h"

namespace FERMI {

void run() {
    {
        KISS::SSDC data(KISS::fermi, KISS::kEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevD.95.082007");
        data.setADSbibcode("2017PhRvD..95h2007A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::fermi, KISS::kEnergy, KISS::positronfraction, KISS::geometrical);
        data.setDOI("10.1103/PhysRevD.95.082007");
        data.setADSbibcode("2017PhRvD..95h2007A");
        data.run();
    }
}

}  // namespace FERMI

#endif
