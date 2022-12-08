// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/CRDB.h"

#include <fstream>

#include "KISS/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512
#define NUM_OF_HEADER_LINES 2

namespace KISS {

void CRDB::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    for (int i = 0; i < NUM_OF_HEADER_LINES; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        std::string Qty;
        double E, Elo, Eup, y, statLo, statUp, systLo, systUp, totLo, totUp;
        infile >> Qty >> E >> Elo >> Eup >> y >> statLo >> statUp >> systLo >> systUp >> totLo >> totUp;
        if (!infile.eof()) {
            const double xMean = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
            dataPoint data = {{xMean, y}, {statLo, statUp}, {systLo, systUp}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

}  // namespace KISS