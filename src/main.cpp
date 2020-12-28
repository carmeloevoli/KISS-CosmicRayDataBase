// Copyright 2020 Carmelo Evoli
#include <iostream>

#include "include/allparticle.h"
#include "include/antiprotons.h"
#include "include/leptons.h"
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
        NUCLEI::AMS02();
        NUCLEI::ARGO();
        NUCLEI::ATIC02();
        NUCLEI::BESS();
        NUCLEI::CALET();
        NUCLEI::CREAM_II();
        NUCLEI::CREAM_III();
        NUCLEI::DAMPE();
        NUCLEI::ICECUBE_ICETOP();
        NUCLEI::KASCADE();
        NUCLEI::KASCADEGrande();
        NUCLEI::NUCLEON();
        NUCLEI::PAMELA();

        // antiprotons
        ANTIPROTONS::AMS02();
        ANTIPROTONS::BESS();
        ANTIPROTONS::PAMELA();

        // leptons
        LEPTONS::AMS02();
        LEPTONS::CALET();
        LEPTONS::DAMPE();
        LEPTONS::FERMI();
        LEPTONS::PAMELA();
        LEPTONS::VERITAS();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
