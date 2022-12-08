#ifndef KISS_EXPERIMENTS_AMS02_H_
#define KISS_EXPERIMENTS_AMS02_H_

#include "KISS/SSDC.h"

namespace AMS02 {

void leptons() {
    {
        KISS::SSDC data(KISS::ams02, KISS::kEnergy, KISS::positron, KISS::Laff3_0);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::kEnergy, KISS::electron, KISS::Laff3_0);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::kEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::kEnergy, KISS::positronfraction, KISS::Laff3_0);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
}

void antiprotons() {
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::antiproton, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
}

void fluxes() {
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Li, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Be, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::B, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::N, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::O, KISS::Laff2_7);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::F, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.126.081102");
        data.setADSbibcode("2021PhRvL.126h1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Ne, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Na, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.127.021101");
        data.setADSbibcode("2021PhRvL.127b1101A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Mg, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Al, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.127.021101");
        data.setADSbibcode("2021PhRvL.127b1101A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Si, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Fe, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.126.041104");
        data.setADSbibcode("2021PhRvL.126d1104A");
        data.run();
    }
}

void ratios() {
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::B_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Be_C, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Be_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::C_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::H_He, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::He_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Li_C, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Li_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::N_B, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::N_O, KISS::geometrical);
        data.setDOI("10.1016/j.physrep.2020.09.003");
        data.setADSbibcode("2021PhR...894....1A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Be_B, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.120.021101");
        data.setADSbibcode("2018PhRvL.120b1101A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Li_B, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.120.021101");
        data.setADSbibcode("2018PhRvL.120b1101A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Mg_O, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Ne_Mg, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Ne_O, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Si_Mg, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Si_O, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2020PhRvL.124u1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Fe_He, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2021PhRvL.126d1104A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Fe_O, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2021PhRvL.126d1104A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::Fe_Si, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.124.211102");
        data.setADSbibcode("2021PhRvL.126d1104A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::F_B, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.126.081102");
        data.setADSbibcode("2021PhRvL.126h1102A");
        data.run();
    }
    {
        KISS::SSDC data(KISS::ams02, KISS::rigidity, KISS::F_Si, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.126.081102");
        data.setADSbibcode("2021PhRvL.126h1102A");
        data.run();
    }
}

void run() {
    leptons();
    antiprotons();
    fluxes();
    ratios();
}

}  // namespace AMS02

#endif