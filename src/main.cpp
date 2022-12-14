// Copyright 2020 Carmelo Evoli - MIT License
#include <iostream>

#include "include/kiss.h"

int main() {
    try {
        AMS02::run();
        ARGO::run();
        ATIC02::run();
        AUGER::run();
        BESS::run();
        CALET::run();
        CREAM::run();
        DAMPE::run();
        FERMI::run();
        HAWC::run();
        HESS::run();
        ICECUBE::run();
        KASCADE_Grande::run();
        KASCADE::run();
        NUCLEON::run();
        PAMELA::run();
        TALE::run();
        TIBET::run();
        TRACER::run();
        TUNKA::run();
        VERITAS::run();
    } catch (std::exception& e) {
        std::cout << "!Fatal Error: " << e.what() << '\n';
    }
    return 0;
}
