// Copyright 2020 Carmelo Evoli - MIT License
#include <iostream>

#include "include/kiss.h"

int main() {
    try {
        // DIRECT MEASUREMENTS
        AMS02::run();
        ATIC02::run();
        BESS::run();
        CALET::run();
        CREAM::run();
        DAMPE::run();
        FERMI::run();
        NUCLEON::run();
        PAMELA::run();
        TRACER::run();

        // INDIRECT MEASUREMENTS
        ARGO::run();
        AUGER::run();
        HAWC::run();
        HESS::run();
        ICECUBE::run();
        KASCADE_Grande::run();
        KASCADE::run();
        TALE::run();
        TIBET::run();
        TUNKA::run();
        VERITAS::run();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
