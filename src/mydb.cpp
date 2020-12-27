// Copyright 2020 Carmelo Evoli
#include "include/mydb.h"

#include <cmath>
#include <string>

#include "include/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512

void MyAllAUGER::readfile(std::fstream& infile) {
    const int num_of_header_lines = 4;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double log10E, EJ, Err_up, Err_low;
        infile >> log10E >> EJ >> Err_up >> Err_low;
        if (!infile.eof()) {
            const double x_mean = std::pow(10., log10E) / 1e9;
            const double y = EJ / x_mean;
            const double err_tot_do = Err_low / x_mean;
            const double err_tot_up = Err_up / x_mean;
            dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyAllTA::readfile(std::fstream& infile) {
    const int num_of_header_lines = 4;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double log10E, E3J, lowerUncertainty, upperUncertainty;
        infile >> log10E >> E3J >> lowerUncertainty >> upperUncertainty;
        if (!infile.eof()) {
            const double x_mean = std::pow(10., log10E) / 1e9;
            const double y = E3J / std::pow(10., 3. * log10E) / 3.15e4;
            const double err_tot_do = lowerUncertainty / std::pow(10., 3. * log10E) / 3.15e4;
            const double err_tot_up = upperUncertainty / std::pow(10., 3. * log10E) / 3.15e4;
            dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyAllHAWC::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double lgEmin, lgEmax, flux, stat, sys_MC, sys_up, sys_do;
        infile >> lgEmin >> lgEmax >> flux >> stat >> sys_MC >> sys_up >> sys_do;
        if (!infile.eof()) {
            const double Elo = std::pow(10., lgEmin);
            const double Eup = std::pow(10., lgEmax);
            const double x_mean = compute_x_mean(Elo, Eup, m_mode);
            const double y = flux;
            const double sys_tot_up = sys_MC + sys_up;
            const double sys_tot_do = sys_MC + sys_do;
            const double err_tot_do = quadrature(sys_tot_do, stat);
            const double err_tot_up = quadrature(sys_tot_up, stat);
            dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

MyAllTIBET::MyAllTIBET(std::string hadmod) {
    set_experimentName("TIBET");
    if (hadmod == "QGSJET+HD")
        m_hadmod = QGSJETHD;
    else if (hadmod == "QGSJET+PD")
        m_hadmod = QGSJETPD;
    else if (hadmod == "SIBYLL+HD")
        m_hadmod = SIBYLLHD;
}

void MyAllTIBET::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, dJdE_1, dJdE_err_1, dJdE_2, dJdE_err_2, dJdE_3, dJdE_err_3;
        infile >> E >> dJdE_1 >> dJdE_err_1 >> dJdE_2 >> dJdE_err_2 >> dJdE_3 >> dJdE_err_3;
        if (!infile.eof()) {
            double dJdE, dJdE_err;
            if (m_hadmod == QGSJETHD) {
                dJdE = dJdE_1;
                dJdE_err = dJdE_err_1;
            } else if (m_hadmod == QGSJETPD) {
                dJdE = dJdE_2;
                dJdE_err = dJdE_err_2;
            } else if (m_hadmod == SIBYLLHD) {
                dJdE = dJdE_3;
                dJdE_err = dJdE_err_3;
            }
            dataPoint data = {E, dJdE, 0, 0, dJdE_err, dJdE_err};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyLightARGO::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, flux, stat, sys_1, sys_2;
        infile >> E >> flux >> stat >> sys_1 >> sys_2;
        if (!infile.eof()) {
            E *= 1e3;  // TeV -> GeV
            dataPoint data = {E, flux, stat, stat, sys_1, sys_2};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}