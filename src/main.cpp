// Copyright 2020 Carmelo Evoli
#include <iostream>

#include "include/allparticle.h"
#include "include/nuclei.h"

int main() {
    try {
        // all particle spectrum
        ALLPARTICLE::AUGER();
        ALLPARTICLE::HAWC();
        ALLPARTICLE::ICECUBE_ICETOP();
        ALLPARTICLE::KASCADE();
        ALLPARTICLE::KASCADEGrande();
        ALLPARTICLE::NUCLEON();
        ALLPARTICLE::RUNJOB();
        ALLPARTICLE::TALE();
        ALLPARTICLE::TELESCOPEARRAY();
        ALLPARTICLE::TIBET();
        ALLPARTICLE::TUNKA();

        // nuclei
        NUCLEI::ARGO();
        NUCLEI::ATIC02();
        NUCLEI::CREAM_II();
        NUCLEI::CREAM_III();
        NUCLEI::DAMPE();
        NUCLEI::ICECUBE_ICETOP();
        NUCLEI::KASCADE();
        NUCLEI::KASCADEGrande();
        NUCLEI::NUCLEON();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
