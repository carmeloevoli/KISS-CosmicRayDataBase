// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/KCDC.h"

#include <fstream>

#include "KISS/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512
#define NUM_OF_HEADER_LINES 6

namespace KISS {

void KCDC::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    for (int i = 0; i < NUM_OF_HEADER_LINES; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        std::string s;
        infile >> s;
        if (s.size() > 1) {
            auto values = Utils::splitline(s);
            double E = values[0], Flux = values[1], UncertLow = values[2], UncertHigh = values[3];
            dataPoint data = {{E, Flux}, {0, 0}, {UncertLow, UncertHigh}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

}  // namespace KISS