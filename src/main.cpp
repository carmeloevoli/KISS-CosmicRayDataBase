// Copyright 2020 Carmelo Evoli - MIT License
#include <iostream>

#include "include/kiss.h"

int main() {
    try {
        CALET::run();
        DAMPE::run();
        HAWC::run();
        PAMELA::run();

        // DIRECT MEASUREMENTS
        // AMS02::run();
        // BESS::run();
        // CREAM::run();
        // FERMI::run();
        // NUCLEON::run();
        // TRACER::run();
        // INDIRECT MEASUREMENTS
        // ARGO::run();
        // AUGER::run();
        // GAMMA::run();
        // GRAPES::run();
        // HESS::run();
        // ICETOP::run();
        // KASCADE_Grande::run();
        // KASCADE::run();
        // LHAASO::run();
        // TALE::run();
        // TIBET::run();
        // TUNKA::run();
        // VERITAS::run();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
