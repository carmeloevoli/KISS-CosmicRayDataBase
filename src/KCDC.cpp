// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/KCDC.h"

#include <fstream>
#include <iostream>
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

void KCDC::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 6);

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) {
            continue;
        }

        try {
            auto values = Utils::splitline(line);
            if (values.size() != 4) {
                throw std::runtime_error("unexpected number of columns");
            }

            double E = values[0], Flux = values[1], UncertLow = values[2], UncertHigh = values[3];
            dataPoint data = {{E, Flux}, {0, 0}, {UncertLow, UncertHigh}};
            m_dataTable.push_back(data);
        } catch (const std::exception&) {
            std::cerr << "Invalid KCDC row in " << filename << ", skipping.\n";
        }
    }
    infile.close();
}

}  // namespace KISS
