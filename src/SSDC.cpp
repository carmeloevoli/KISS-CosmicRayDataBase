// Copyright 2020 Carmelo Evoli
#include "include/SSDC.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512

void SSDC::readfile(std::fstream& infile) {
    const int num_of_header_lines = 3;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double Elo, Eup, y, ystat_lo, ystat_up, ysyst_lo, ysyst_up;
        infile >> Elo >> Eup >> y >> ystat_lo >> ystat_up >> ysyst_lo >> ysyst_up;
        if (!infile.eof()) {
            const double x_mean = compute_x_mean(Elo, Eup, m_mode);
            const double err_tot_do = std::sqrt(ystat_lo * ystat_lo + ysyst_lo * ysyst_lo);
            const double err_tot_up = std::sqrt(ystat_up * ystat_up + ysyst_up * ysyst_up);
            dataPoint data = {x_mean, y, ystat_lo, ystat_up, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}
