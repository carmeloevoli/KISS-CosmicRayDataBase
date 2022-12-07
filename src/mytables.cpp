// Copyright 2020 Carmelo Evoli
#include "KISS/mytables.h"

#include <cmath>
#include <fstream>
#include <string>

#include "KISS/utils.h"

#define MAX_NUM_OF_CHAIR_IN_A_LINE 512

namespace KISS {

void MyLeptonVeritas::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
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
            const double errTotLo = Utils::quadrature(syst_error_low, stat_error);
            const double errTotUp = Utils::quadrature(syst_error_high, stat_error);
            const double xMean = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
            dataPoint data = {{xMean, flux}, {0., 0.}, {errTotLo, errTotUp}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyLeptonHess::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    const int num_of_header_lines = 0;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, flux, errStatLo, errStatUp, errSystLo, errSystUp;
        infile >> E >> flux >> errStatLo >> errStatUp >> errSystLo >> errSystUp;
        if (!infile.eof()) {
            const double errTotLo = Utils::quadrature(errSystLo, errStatLo);
            const double errTotUp = Utils::quadrature(errSystUp, errStatUp);
            dataPoint data = {{E, flux}, {0., 0.}, {errTotLo, errTotUp}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyLightARGO::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E_min, E_max, E, flux, error;
        infile >> E_min >> E_max >> E >> flux >> error;
        if (!infile.eof()) {
            dataPoint data = {{E, flux}, {0., 0.}, {error, error}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

void MyLightHAWC::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    const int num_of_header_lines = 1;
    for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
    while (infile.good()) {
        double E, flux, errStat, errSystUp, errSystLo;
        infile >> E >> flux >> errStat >> errSystUp >> errSystLo;
        if (!infile.eof()) {
            const double errTotLo = Utils::quadrature(errStat, errSystLo);
            const double errTotUp = Utils::quadrature(errStat, errSystUp);
            dataPoint data = {{E, flux}, {errStat, errStat}, {errTotLo, errTotUp}};
            m_dataTable.push_back(data);
        }
    }
    infile.close();
}

// void MyHeliumDAMPE::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     const int num_of_header_lines = 0;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double E_min, E_max, E_mean, flux, stat, syst_ana, syst_had;
//         infile >> E_min >> E_max >> E_mean >> flux >> stat >> syst_ana >> syst_had;
//         if (!infile.eof()) {
//             E_min *= 1e3;  // TeV -> GeV
//             E_max *= 1e3;  // TeV -> GeV
//             const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
//             const double syst = Utils::quadrature(syst_ana, syst_had);
//             const double err_tot = Utils::quadrature(stat, syst);
//             dataPoint data = {{E, flux}, {stat, stat}, {err_tot, err_tot}};
//             m_dataTable.push_back(data);
//         }
//     }
// }

// void MyHeavyCALET::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 1;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double E_min, E_max, Flux, stat, syst_1_do, syst_1_up, syst_2_do, syst_2_up;
//         infile >> E_min >> E_max >> Flux >> stat >> syst_1_do >> syst_1_up >> syst_2_do >> syst_2_up;
//         if (!infile.eof()) {
//             const double E = compute_x_mean_geometrical(E_min, E_max) * (double)m_A;
//             const double syst_do = syst_1_do + syst_2_do;
//             const double syst_up = syst_1_up + syst_2_up;
//             const double err_tot_do = quadrature(stat, syst_do);
//             const double err_tot_up = quadrature(stat, syst_up);
//             dataPoint data = {E, Flux / m_A, stat / m_A, stat / m_A, err_tot_do / m_A, err_tot_up / m_A};
//             m_dataTable.push_back(data);
//         }
//     }
// }

// void MyAllARGO::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 1;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double logEmin, logEmax, flux, stat, syst;
//         infile >> logEmin >> logEmax >> flux >> stat >> syst;
//         if (!infile.eof()) {
//             const double E_min = std::pow(10., logEmin) * 1e3;  // TeV -> GeV
//             const double E_max = std::pow(10., logEmax) * 1e3;  // TeV -> GeV
//             const double x_mean = compute_x_mean(E_min, E_max, m_mode);
//             const double err_tot = quadrature(stat, syst);
//             dataPoint data = {x_mean, flux, stat, stat, err_tot, err_tot};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// void MyAllAUGER::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 4;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double log10E, EJ, Err_up, Err_low;
//         infile >> log10E >> EJ >> Err_up >> Err_low;
//         if (!infile.eof()) {
//             const double x_mean = std::pow(10., log10E) / 1e9;
//             const double y = EJ / x_mean;
//             const double err_tot_do = Err_low / x_mean;
//             const double err_tot_up = Err_up / x_mean;
//             dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// void MyAllTA::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 4;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double log10E, E3J, lowerUncertainty, upperUncertainty;
//         infile >> log10E >> E3J >> lowerUncertainty >> upperUncertainty;
//         if (!infile.eof()) {
//             const double x_mean = std::pow(10., log10E) / 1e9;
//             const double y = E3J / std::pow(10., 3. * log10E) / 3.15e4;
//             const double err_tot_do = lowerUncertainty / std::pow(10., 3. * log10E) / 3.15e4;
//             const double err_tot_up = upperUncertainty / std::pow(10., 3. * log10E) / 3.15e4;
//             dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// void MyAllHAWC::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 1;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double lgEmin, lgEmax, flux, stat, sys_MC, sys_up, sys_do;
//         infile >> lgEmin >> lgEmax >> flux >> stat >> sys_MC >> sys_up >> sys_do;
//         if (!infile.eof()) {
//             const double Elo = std::pow(10., lgEmin);
//             const double Eup = std::pow(10., lgEmax);
//             const double x_mean = compute_x_mean(Elo, Eup, m_mode);
//             const double y = flux;
//             const double sys_tot_up = sys_MC + sys_up;
//             const double sys_tot_do = sys_MC + sys_do;
//             const double err_tot_do = quadrature(sys_tot_do, stat);
//             const double err_tot_up = quadrature(sys_tot_up, stat);
//             dataPoint data = {x_mean, y, 0, 0, err_tot_do, err_tot_up};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// MyAllTIBET::MyAllTIBET(std::string hadmod) {
//     set_experimentName("TIBET");
//     if (hadmod == "QGSJET+HD")
//         m_hadmod = QGSJETHD;
//     else if (hadmod == "QGSJET+PD")
//         m_hadmod = QGSJETPD;
//     else if (hadmod == "SIBYLL+HD")
//         m_hadmod = SIBYLLHD;
// }

// void MyAllTIBET::readfile(std::fstream& infile) {
//     const int num_of_header_lines = 1;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double E, dJdE_1, dJdE_err_1, dJdE_2, dJdE_err_2, dJdE_3, dJdE_err_3;
//         infile >> E >> dJdE_1 >> dJdE_err_1 >> dJdE_2 >> dJdE_err_2 >> dJdE_3 >> dJdE_err_3;
//         if (!infile.eof()) {
//             double dJdE, dJdE_err;
//             if (m_hadmod == QGSJETHD) {
//                 dJdE = dJdE_1;
//                 dJdE_err = dJdE_err_1;
//             } else if (m_hadmod == QGSJETPD) {
//                 dJdE = dJdE_2;
//                 dJdE_err = dJdE_err_2;
//             } else if (m_hadmod == SIBYLLHD) {
//                 dJdE = dJdE_3;
//                 dJdE_err = dJdE_err_3;
//             }
//             dataPoint data = {E, dJdE, 0, 0, dJdE_err, dJdE_err};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

}  // namespace KISS