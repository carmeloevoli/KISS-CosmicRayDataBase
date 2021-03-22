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
            const double err_tot_do = quadrature(sys_1, stat);
            const double err_tot_up = quadrature(sys_2, stat);
            dataPoint data = {E, flux, stat, stat, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyLeptonVERITAS::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, E_min, E_max, N_events, fraction, fraction_error, flux, stat_error;
        infile >> E >> E_min >> E_max >> N_events >> fraction >> fraction_error >> flux >> stat_error;
        if (!infile.eof()) {
            E_min *= 1e3;       // TeV -> GeV
            E_max *= 1e3;       // TeV -> GeV
            flux *= 1e4;        // cm-2 s-1 GeV-1 -> m-2 s-1 GeV-1
            stat_error *= 1e4;  // cm-2 s-1 GeV-1 -> m-2 s-1 GeV-1
            const double syst_error_low = 0.33 * flux;
            const double syst_error_high = 0.64 * flux;
            const double err_tot_do = quadrature(syst_error_low, stat_error);
            const double err_tot_up = quadrature(syst_error_high, stat_error);
            const double x_mean = compute_x_mean(E_min, E_max, m_mode);
            dataPoint data = {x_mean, flux, stat_error, stat_error, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
}

void MyLeptonHESS::readfile(std::fstream& infile) {
    const int num_of_header_lines = 0;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, flux, stat_error_low, stat_error_high, syst_error_low, syst_error_high;
        infile >> E >> flux >> stat_error_low >> stat_error_high >> syst_error_low >> syst_error_high;
        if (!infile.eof()) {
            const double err_tot_do = quadrature(syst_error_low, stat_error_low);
            const double err_tot_up = quadrature(syst_error_high, stat_error_high);
            dataPoint data = {E, flux, stat_error_low, stat_error_high, err_tot_do, err_tot_up};
            m_dataTable.push_back(data);
        }
    }
}

void MyIronAMS02rigidity::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double R_min, R_max, flux, Stat, Acc, Unf, Scale, Syst;
        infile >> R_min >> R_max >> flux >> Stat >> Acc >> Unf >> Scale >> Syst;
        if (!infile.eof()) {
            const double R = compute_x_mean_Lafferty1995(R_min, R_max, 2.7);
            const double err_tot = quadrature(Stat, Syst);
            dataPoint data = {R, flux, Stat, Stat, err_tot, err_tot};
            m_dataTable.push_back(data);
        }
    }
}

void MyIronAMS02totalenergy::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    const double Z = 26;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double R_min, R_max, flux, Stat, Acc, Unf, Scale, Syst;
        infile >> R_min >> R_max >> flux >> Stat >> Acc >> Unf >> Scale >> Syst;
        if (!infile.eof()) {
            const double R = compute_x_mean_geometrical(R_min, R_max);
            const double E = R * Z;
            const double err_tot = quadrature(Stat, Syst);
            dataPoint data = {E, flux / Z, Stat / Z, Stat / Z, err_tot / Z, err_tot / Z};
            m_dataTable.push_back(data);
        }
    }
}

void MyHeavyCALET::readfile(std::fstream& infile) {
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E_min, E_max, Flux, stat, syst_1_do, syst_1_up, syst_2_do, syst_2_up;
        infile >> E_min >> E_max >> Flux >> stat >> syst_1_do >> syst_1_up >> syst_2_do >> syst_2_up;
        if (!infile.eof()) {
            const double E = compute_x_mean_geometrical(E_min, E_max) * (double)m_A;
            const double syst_do = syst_1_do + syst_2_do;
            const double syst_up = syst_1_up + syst_2_up;
            const double err_tot_do = quadrature(stat, syst_do);
            const double err_tot_up = quadrature(stat, syst_up);
            dataPoint data = {E, Flux / m_A, stat / m_A, stat / m_A, err_tot_do / m_A, err_tot_up / m_A};
            m_dataTable.push_back(data);
        }
    }
}
