// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/CRDB.h"

#include <fstream>
#include <limits>

#include "KISS/utils.h"

namespace KISS {

namespace {

void skipHeaderLines(std::istream& infile, int count) {
    for (int i = 0; i < count; ++i) {
        infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

}  // namespace

void CRDB::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 2);

    double Elo, Eup, y, statLo, statUp, systLo, systUp;
    while (infile >> Elo >> Eup >> y >> statLo >> statUp >> systLo >> systUp) {
        const double xMean = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
        dataPoint data = {{xMean, y}, {statLo, statUp}, {systLo, systUp}};
        m_dataTable.push_back(data);
    }
    infile.close();
}

}  // namespace KISS
