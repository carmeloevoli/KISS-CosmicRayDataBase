// Copyright 2020 Carmelo Evoli
#include "include/KCDC.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512

std::vector<double> splitline(const std::string& line) {
    const std::string delimiter = ";";
    std::string s = line;
    std::string token;
    size_t pos = 0;
    std::vector<double> values;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        values.push_back(std::stod(token));
        s.erase(0, pos + delimiter.length());
    }
    values.push_back(stod(s));
    return values;
}

void KCDC::readfile(std::fstream& infile) {
    const int num_of_header_lines = 6;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        std::string s;
        infile >> s;
        if (s.size() > 1) {
            auto values = splitline(s);
            double E = values[0], Flux = values[1], UncertLow = values[2], UncertHigh = values[3];
            dataPoint data = {E, Flux, 0, 0, UncertLow, UncertHigh};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}
