// Copyright 2020 Carmelo Evoli - MIT License
#include <cstdlib>
#include <iostream>

#include "include/kiss.h"

int main() {
    try {
        AMS02::run();
        AUGER::run();
        BESS::run();
        CALET::run();
        CREAM::run();
        DAMPE::run();
        FERMI::run();
        GRAPES::run();
        HAWC::run();
        HESS::run();
        KASCADE_Grande::run();
        KASCADE::run();
        ICETOP::run();
        ISSCREAM::run();
        NUCLEON::run();
        PAMELA::run();
        LHAASO::run();
        TRACER::run();
        TA::run();
        TIBET::run();
        TUNKA::run();
        VERITAS::run();
        YAKUTSK::run();
    } catch (std::exception& e) {
        std::cerr << "!Fatal Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    KISS::CrDataset::printMissingInputSummary();
    return EXIT_SUCCESS;
}
