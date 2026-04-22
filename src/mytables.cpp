// Copyright 2020 Carmelo Evoli
#include "KISS/mytables.h"

#include <cmath>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

#include "KISS/utils.h"

namespace KISS {

namespace {

void skipHeaderLines(std::istream& infile, int count) {
    for (int i = 0; i < count; ++i) {
        infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

}  // namespace

namespace CALET {
// void MyLepton::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double E_min, E_max, E_mean, flux, errStatLo, errStatUp, errSysLo, errSysUp;
//     while (infile >> E_min >> E_max >> E_mean >> flux >> errStatLo >> errStatUp >> errSysLo >> errSysUp) {
//         const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
//         dataPoint data = {{E, flux}, {errStatLo, errStatUp}, {errSysLo, errSysUp}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }

// void MyHeavy::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double E_min, E_max, flux, errStat, syst_1, syst_2_do, syst_2_up;
//     while (infile >> E_min >> E_max >> flux >> errStat >> syst_1 >> syst_2_do >> syst_2_up) {
//         const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
//         const double syst_do = syst_1 + syst_2_do;
//         const double syst_up = syst_1 + syst_2_up;
//         dataPoint data = {{E, flux}, {errStat, errStat}, {syst_do, syst_up}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }
}  // namespace CALET

namespace DAMPE {
void MyBoron::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 1);

    double E_min, E_max, flux, errStat, syst_1, syst_2_do, syst_2_up;
    while (infile >> E_min >> E_max >> flux >> errStat >> syst_1 >> syst_2_do >> syst_2_up) {
        const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
        const double syst_do = Utils::quadrature(syst_1, syst_2_do);
        const double syst_up = Utils::quadrature(syst_1, syst_2_up);
        dataPoint data = {{E, flux}, {errStat, errStat}, {syst_do, syst_up}};
        m_dataTable.push_back(data);
    }
    infile.close();
}

void MyLight::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 1);

    double E_min, E_max, E_mean, flux, stat, syst_ana, syst_had;
    while (infile >> E_min >> E_max >> E_mean >> flux >> stat >> syst_ana >> syst_had) {
        const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
        const double syst = Utils::quadrature(syst_ana, syst_had);
        dataPoint data = {{E, flux}, {stat, stat}, {syst, syst}};
        m_dataTable.push_back(data);
    }
    infile.close();
}

void MyPrimary::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 1);

    double E_min, E_max, flux, stat, syst_ana, syst_had;
    while (infile >> E_min >> E_max >> flux >> stat >> syst_ana >> syst_had) {
        const double E = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
        const double syst = Utils::quadrature(syst_ana, syst_had);
        dataPoint data = {{E, flux}, {stat, stat}, {syst, syst}};
        m_dataTable.push_back(data);
    }
    infile.close();
}
}  // namespace DAMPE

namespace HAWC {
void MyLight::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 1);

    double E, flux, errStat, errSystUp, errSystLo;
    while (infile >> E >> flux >> errStat >> errSystUp >> errSystLo) {
        dataPoint data = {{E, flux}, {errStat, errStat}, {errSystLo, errSystUp}};
        m_dataTable.push_back(data);
    }
    infile.close();
}
}  // namespace HAWC

namespace GRAPES {
void MyProtons::readfile(std::string filename) {
    std::fstream infile(filename.c_str());
    skipHeaderLines(infile, 1);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream s(line);
        double E, flux, errStat, errSystUp, errSystLo;
        if (!(s >> E >> flux >> errStat >> errSystUp >> errSystLo)) {
            std::cerr << "Invalid line, skipping.\n";
            continue;
        }
        dataPoint data = {{E, flux}, {errStat, errStat}, {errSystLo, errSystUp}};
        m_dataTable.push_back(data);
    }
    infile.close();
}
}  // namespace GRAPES

namespace LHAASO {
// std::string MyNuclei::makeSourceFilename() const {
//     std::string quantity;
//     if (m_yQuantity == light) {
//         quantity = "light";
//     } else if (m_yQuantity == He) {
//         quantity = "helium";
//     } else if (m_yQuantity == H) {
//         quantity = "proton";
//     } else {
//         quantity = ToString(m_yQuantity);
//     }

//     return "source/" + ToString(m_source) + "/" + ToString(m_experiment) + "_" + quantity + "_" +
//            ToString(m_xQuantity) + ".txt";
//}

// void MyNuclei::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 4);

//     int offset = -1;
//     if (m_description == "QGSJET-II-04") {
//         offset = 2;
//     } else if (m_description == "EPOS-LHC") {
//         offset = 5;
//     } else if (m_description == "SIBYLL-2.3d") {
//         offset = 8;
//     } else {
//         throw std::invalid_argument("unsupported LHAASO hadronic interaction model");
//     }

//     std::string line;
//     while (std::getline(infile, line)) {
//         if (line.empty() || line[0] == '#') {
//             continue;
//         }

//         std::istringstream s(line);
//         double log10Emin, log10Emax;
//         double fluxQGS, statQGS, systQGS;
//         double fluxEPOS, statEPOS, systEPOS;
//         double fluxSIBYLL, statSIBYLL, systSIBYLL;
//         if (!(s >> log10Emin >> log10Emax >> fluxQGS >> statQGS >> systQGS >> fluxEPOS >> statEPOS >> systEPOS >>
//               fluxSIBYLL >> statSIBYLL >> systSIBYLL)) {
//             std::cerr << "Invalid line, skipping.\n";
//             continue;
//         }

//         const double values[] = {log10Emin, log10Emax, fluxQGS,    statQGS,    systQGS,   fluxEPOS,
//                                  statEPOS,  systEPOS,  fluxSIBYLL, statSIBYLL, systSIBYLL};

//         const double Elo = std::pow(10., values[0]);
//         const double Eup = std::pow(10., values[1]);
//         const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode) * 1e6;  // [PeV -> GeV]
//         const double flux = values[offset] / 1e6;                                 // [PeV-1 -> GeV-1]
//         const double errStat = values[offset + 1] / 1e6;                          // [PeV-1 -> GeV-1]
//         const double errSyst = values[offset + 2] / 1e6;                          // [PeV-1 -> GeV-1]

//         dataPoint data = {{E, flux}, {errStat, errStat}, {errSyst, errSyst}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }
}  // namespace LHAASO

// ARGO
// void MyLightARGO::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double E_min, E_max, E, flux, error;
//     while (infile >> E_min >> E_max >> E >> flux >> error) {
//         dataPoint data = {{E, flux}, {0., 0.}, {error, error}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }

// HESS
// void MyLeptonHESS::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     double E, flux, errStatLo, errStatUp, errSystLo, errSystUp;
//     while (infile >> E >> flux >> errStatLo >> errStatUp >> errSystLo >> errSystUp) {
//         dataPoint data = {{E, flux}, {errStatLo, errStatUp}, {errSystLo, errSystUp}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }

// VERITAS
// void MyLeptonVeritas::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double E, E_min, E_max, N_events, fraction, fraction_error, flux, stat_error;
//     while (infile >> E >> E_min >> E_max >> N_events >> fraction >> fraction_error >> flux >> stat_error) {
//         E_min *= 1e3;       // TeV -> GeV
//         E_max *= 1e3;       // TeV -> GeV
//         flux *= 1e4;        // cm-2 s-1 GeV-1 -> m-2 s-1 GeV-1
//         stat_error *= 1e4;  // cm-2 s-1 GeV-1 -> m-2 s-1 GeV-1
//         const double syst_error_low = 0.33 * flux;
//         const double syst_error_high = 0.64 * flux;
//         const double xMean = Utils::computeMeanEnergy(E_min, E_max, m_energyMode);
//         dataPoint data = {{xMean, flux}, {stat_error, stat_error}, {syst_error_low, syst_error_high}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }

// void MyAllAuger2021::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     const int num_of_header_lines = 1;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double log10E, errLog10E, J, sigma_stat_lo, sigma_stat_up, sigma_sys_lo, sigma_sys_up;
//         infile >> log10E >> errLog10E >> J >> sigma_stat_lo >> sigma_stat_up >> sigma_sys_lo >> sigma_sys_up;
//         if (!infile.eof()) {
//             const double E = std::pow(10., log10E) / 1e9;  // [eV -> GeV]
//             const double y = J / 3.1e4;                    // [km-2 sr-1 yr-1 eV-1 -> m-2 sr-1 s-1 GeV-1]
//             const double yerr_stat_lo = sigma_stat_lo / 3.1e4;
//             const double yerr_stat_up = sigma_stat_up / 3.1e4;
//             const double yerr_sys_lo = sigma_sys_lo / 3.1e4;
//             const double yerr_sys_up = sigma_sys_up / 3.1e4;
//             dataPoint data = {{E, y}, {yerr_stat_lo, yerr_stat_up}, {yerr_sys_lo, yerr_sys_up}};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// void MyAllAuger2019::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     const int num_of_header_lines = 4;
//     for (int i = 0; i < num_of_header_lines; ++i) infile.ignore(MAX_NUM_OF_CHAIR_IN_A_LINE, '\n');
//     while (infile.good()) {
//         double log10E, EJ, Err_up, Err_low;
//         infile >> log10E >> EJ >> Err_up >> Err_low;
//         if (!infile.eof()) {
//             const double E = std::pow(10., log10E) / 1e9;  // [eV -> GeV]
//             const double y = EJ / E;
//             const double err_tot_lo = Err_low / E;
//             const double err_tot_up = Err_up / E;
//             dataPoint data = {{E, y}, {0., 0.}, {err_tot_lo, err_tot_up}};
//             m_dataTable.push_back(data);
//         }
//     }
//     infile.close();
// }

// void MyAllTale::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double log10Emin, log10Emax, numEvents, E3J, sigma_stat, sigma_sys_up, sigma_sys_lo;
//     while (infile >> log10Emin >> log10Emax >> numEvents >> E3J >> sigma_stat >> sigma_sys_up >> sigma_sys_lo) {
//         const double Elo = std::pow(10., log10Emin);
//         const double Eup = std::pow(10., log10Emax);
//         const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode) / 1e9;
//         const double y = E3J / std::pow(E, 3.) / 1e18;
//         const double yerr_stat = sigma_stat / std::pow(E, 3.) / 1e18;
//         const double yerr_sys_lo = sigma_sys_lo / std::pow(E, 3.) / 1e18;
//         const double yerr_sys_up = sigma_sys_up / std::pow(E, 3.) / 1e18;
//         dataPoint data = {{E, y}, {yerr_stat, yerr_stat}, {yerr_sys_lo, yerr_sys_up}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
// }

// void MyAllTibet::readfile(std::string filename) {
//     std::fstream infile(filename.c_str());
//     skipHeaderLines(infile, 1);

//     double E, dJdE, dJdE_err;
//     while (infile >> E >> dJdE >> dJdE_err) {
//         dataPoint data = {{E, dJdE}, {0, 0}, {dJdE_err, dJdE_err}};
//         m_dataTable.push_back(data);
//     }
//     infile.close();
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

// MyAllTIBET::MyAllTIBET(std::string hadmod) {
//     set_experimentName("TIBET");
//     if (hadmod == "QGSJET+HD")
//         m_hadmod = QGSJETHD;
//     else if (hadmod == "QGSJET+PD")
//         m_hadmod = QGSJETPD;
//     else if (hadmod == "SIBYLL+HD")
//         m_hadmod = SIBYLLHD;
// }

}  // namespace KISS
