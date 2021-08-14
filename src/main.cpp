// Copyright 2020 Carmelo Evoli - MIT License
#include <iostream>

#include "include/kiss.h"

int main() {
    try {
        AMS02::run();
        exit(1);
        ATIC02::run();
        BESS::run();
        CREAM::run();
        HESS::run();
        ICECUBE_ICETOP::run();
        KASCADE_Grande::run();
        KASCADE::run();
        NUCLEON::run();
        PAMELA::run();
        RUNJOB::run();
        TALE::run();
        TUNKA::run();

        // all original AMS-02
        // ALLAMS02::ratios();
        // ALLAMS02::fluxes();

        // all particle spectrum
        // ALLPARTICLE::ARGO();
        // ALLPARTICLE::AUGER();
        // ALLPARTICLE::HAWC();
        // ALLPARTICLE::ICECUBE_ICETOP();
        // ALLPARTICLE::KASCADE();
        // ALLPARTICLE::KASCADEGrande();
        // ALLPARTICLE::NUCLEON();
        // ALLPARTICLE::RUNJOB();
        // ALLPARTICLE::TALE();
        // ALLPARTICLE::TELESCOPEARRAY();
        // ALLPARTICLE::TIBET();
        // ALLPARTICLE::TUNKA();

        // nuclei
        // NUCLEI::AMS02();
        // NUCLEI::ARGO();
        // NUCLEI::ATIC02();
        // NUCLEI::BESS();
        // NUCLEI::CALET();
        // NUCLEI::CREAM_II();
        // NUCLEI::CREAM_III();
        // NUCLEI::DAMPE();
        // NUCLEI::HESS();
        // NUCLEI::ICECUBE_ICETOP();
        // NUCLEI::KASCADE();
        // NUCLEI::KASCADEGrande();
        // NUCLEI::NUCLEON();
        // NUCLEI::PAMELA();
        // NUCLEI::TUNKA();

        // antiprotons
        // ANTIPROTONS::AMS02();
        // ANTIPROTONS::BESS();
        // ANTIPROTONS::PAMELA();

        // leptons
        // LEPTONS::AMS02();
        // LEPTONS::CALET();
        // LEPTONS::DAMPE();
        // LEPTONS::FERMI();
        // LEPTONS::PAMELA();
        // LEPTONS::VERITAS();
        // LEPTONS::HESS();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
