#ifndef KISS_EXPERIMENTS_CALET_H_
#define KISS_EXPERIMENTS_CALET_H_

#include "KISS/CRDB.h"

namespace CALET {

void run() {
    {
        KISS::CRDB data(KISS::calet, KISS::totalEnergy, KISS::lepton, KISS::Laff3_0);
        data.setDOI("10.1103/PhysRevLett.120.261102");
        data.setADSbibcode("2018PhRvL.120z1102A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergy, KISS::H, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.129.101102");
        data.setADSbibcode("2022PhRvL.129j1102A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergy, KISS::He, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.130.171002");
        data.setADSbibcode("2023PhRvL.130q1002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::B, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.129.251103");
        data.setADSbibcode("2022PhRvL.129y1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::C, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.129.251103");
        data.setADSbibcode("2022PhRvL.129y1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::O, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.125.251102");
        data.setADSbibcode("2020PhRvL.125y1102A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::Fe, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.126.241101");
        data.setADSbibcode("2021PhRvL.126x1101A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::Ni, KISS::Laff2_7);
        data.setDOI("10.1103/PhysRevLett.128.131103");
        data.setADSbibcode("2022PhRvL.128m1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::rigidity, KISS::H_He, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.130.171002");
        data.setADSbibcode("2023PhRvL.130q1002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::H_He, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.130.171002");
        data.setADSbibcode("2023PhRvL.130q1002A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::B_C, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.129.251103");
        data.setADSbibcode("2022PhRvL.129y1103A");
        data.run();
    }
    {
        KISS::CRDB data(KISS::calet, KISS::kEnergyPerNucleon, KISS::C_O, KISS::geometrical);
        data.setDOI("10.1103/PhysRevLett.125.251102");
        data.setADSbibcode("2020PhRvL.125y1102A");
        data.run();
    }
}

}  // namespace CALET

#endif