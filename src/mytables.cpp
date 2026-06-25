// Copyright 2020 Carmelo Evoli
#include "KISS/mytables.h"

#include <cmath>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "KISS/utils.h"

namespace KISS {

namespace {

std::fstream openInputFile(const std::string& filename) {
    std::fstream infile(filename.c_str());
    if (!infile) {
        throw std::runtime_error("could not open input file " + filename);
    }
    return infile;
}

void skipHeaderLines(std::istream& infile, int count, const std::string& filename) {
    std::string header;
    for (int i = 0; i < count; ++i) {
        if (!std::getline(infile, header)) {
            throw std::runtime_error("missing expected header lines in " + filename);
        }
    }
}

std::vector<double> parseWhitespaceRow(const std::string& line, std::size_t expectedColumns) {
    std::istringstream s(line);
    std::vector<double> values;
    double value = 0.;

    while (s >> value) {
        values.push_back(value);
    }

    if (!s.eof()) {
        throw std::runtime_error("encountered a non-numeric token");
    }
    if (values.size() != expectedColumns) {
        throw std::runtime_error("unexpected number of columns");
    }

    return values;
}

std::vector<double> parseDelimitedRow(const std::string& line, const std::string& delimiter, std::size_t expectedColumns) {
    auto values = Utils::splitline(line, delimiter);
    if (values.size() != expectedColumns) {
        throw std::runtime_error("unexpected number of columns");
    }
    return values;
}

std::vector<std::string> parseWhitespaceTokens(const std::string& line, std::size_t expectedColumns) {
    std::istringstream s(line);
    std::vector<std::string> values;
    std::string value;

    while (s >> value) {
        values.push_back(value);
    }

    if (values.size() != expectedColumns) {
        throw std::runtime_error("unexpected number of columns");
    }

    return values;
}

void reportInvalidRow(const std::string& datasetName, const std::string& filename, int lineNumber, const std::string& reason) {
    std::cerr << "Invalid " << datasetName << " row in " << filename << ":" << lineNumber << " (" << reason
              << "), skipping.\n";
}

int lhaasoModelOffset(const std::string& him) {
    if (him == "QGSJET-II-04") {
        return 2;
    }
    if (him == "EPOS-LHC") {
        return 5;
    }
    if (him == "SIBYLL-2.3d") {
        return 8;
    }
    throw std::invalid_argument("unsupported LHAASO hadronic interaction model");
}

}  // namespace

namespace CALET {
void MyLeptons::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 8);
            const double E = Utils::computeMeanEnergy(values[0], values[1], m_energyMode);
            dataPoint data = {{E, values[3]}, {values[4], values[5]}, {values[6], values[7]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("CALET leptons", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}

void MyHeavy::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 7);
            const double E = Utils::computeMeanEnergy(values[0], values[1], m_energyMode);
            const double syst_do = Utils::quadrature(values[4], values[5]);
            const double syst_up = Utils::quadrature(values[4], values[6]);
            dataPoint data = {{E, values[2]}, {values[3], values[3]}, {syst_do, syst_up}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("CALET heavy nuclei", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace CALET

namespace DAMPE {
void MyBoron::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 7);
            const double E = Utils::computeMeanEnergy(values[0], values[1], m_energyMode);
            const double syst_do = Utils::quadrature(values[4], values[5]);
            const double syst_up = Utils::quadrature(values[4], values[6]);
            dataPoint data = {{E, values[2]}, {values[3], values[3]}, {syst_do, syst_up}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("DAMPE boron", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}

void MyLight::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 7);
            const double E = Utils::computeMeanEnergy(values[0], values[1], m_energyMode);
            const double syst = Utils::quadrature(values[5], values[6]);
            dataPoint data = {{E, values[3]}, {values[4], values[4]}, {syst, syst}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("DAMPE light", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}

void MyPrimary::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 6);
            const double E = Utils::computeMeanEnergy(values[0], values[1], m_energyMode);
            const double syst = Utils::quadrature(values[4], values[5]);
            dataPoint data = {{E, values[2]}, {values[3], values[3]}, {syst, syst}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("DAMPE primary nuclei", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace DAMPE

namespace GRAPES {
void MyProtons::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 5);
            dataPoint data = {{values[0], values[1]}, {values[2], values[2]}, {values[4], values[3]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("GRAPES proton", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace GRAPES

namespace HAWC {
void MyLight::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 5);
            dataPoint data = {{values[0], values[1]}, {values[2], values[2]}, {values[4], values[3]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("HAWC light", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace HAWC

namespace KASCADE {
void MyKuznetsov2024::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 2, filename);

    const auto expectedColumns = (m_yQuantity == allParticle || m_yQuantity == lnA) ? 7 : 5;

    std::string line;
    int lineNumber = 2;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, expectedColumns);
            const double Elo = std::pow(10., values[0]);
            const double Eup = std::pow(10., values[1]);
            const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
            const double errStat = values[3];

            double errSystLow = values[4];
            double errSystHigh = values[4];
            if (expectedColumns == 7) {
                errSystLow = Utils::quadrature(values[4], values[5]);
                errSystHigh = Utils::quadrature(values[4], values[6]);
            }

            dataPoint data = {{E, values[2]}, {errStat, errStat}, {errSystLow, errSystHigh}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("KASCADE Kuznetsov 2024", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace KASCADE

namespace LHAASO {
std::string MyNuclei::makeSourceFilename() const {
    std::string quantity;
    if (m_yQuantity == light) {
        quantity = "light";
    } else if (m_yQuantity == He) {
        quantity = "helium";
    } else if (m_yQuantity == H) {
        quantity = "proton";
    } else {
        quantity = ToString(m_yQuantity);
    }

    return "data/" + ToString(m_source) + "/" + ToString(m_experiment) + "_" + quantity + "_" +
           ToString(m_xQuantity) + ".txt";
}

void MyNuclei::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 4, filename);

    const int offset = lhaasoModelOffset(m_description);

    std::string line;
    int lineNumber = 4;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 11);

            const double Elo = std::pow(10., values[0]);
            const double Eup = std::pow(10., values[1]);
            const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode) * 1e6;  // [PeV -> GeV]
            const double flux = values[offset] / 1e6;                                 // [PeV^-1 -> GeV^-1]
            const double errStat = values[offset + 1] / 1e6;                          // [PeV^-1 -> GeV^-1]
            const double errSyst = values[offset + 2] / 1e6;                          // [PeV^-1 -> GeV^-1]

            dataPoint data = {{E, flux}, {errStat, errStat}, {errSyst, errSyst}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("LHAASO nuclei", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}

std::string MyAllParticle::makeSourceFilename() const {
    return "data/" + ToString(m_source) + "/" + ToString(m_experiment) + "_" + ToString(m_yQuantity) + "_" +
           ToString(m_xQuantity) + ".txt";
}

void MyAllParticle::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 4, filename);

    const int offset = lhaasoModelOffset(m_description);

    std::string line;
    int lineNumber = 4;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 11);
            const double Elo = std::pow(10., values[0]);
            const double Eup = std::pow(10., values[1]);
            const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
            dataPoint data = {{E, values[offset]}, {values[offset + 1], values[offset + 1]}, {values[offset + 2], values[offset + 2]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("LHAASO all-particle", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}

std::string MyLnA::makeSourceFilename() const {
    return "data/" + ToString(m_source) + "/" + ToString(m_experiment) + "_" + ToString(m_yQuantity) + "_" +
           ToString(m_xQuantity) + ".txt";
}

void MyLnA::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 4, filename);

    const int offset = lhaasoModelOffset(m_description);

    std::string line;
    int lineNumber = 4;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 11);
            const double Elo = std::pow(10., values[0]);
            const double Eup = std::pow(10., values[1]);
            const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
            dataPoint data = {{E, values[offset]}, {values[offset + 1], values[offset + 1]}, {values[offset + 2], values[offset + 2]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("LHAASO lnA", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace LHAASO

namespace TUNKA {
void MyAllParticle::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 6, filename);

    std::string line;
    int lineNumber = 6;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            const auto values = parseDelimitedRow(line, ";", 6);
            dataPoint data = {{values[0], values[1]}, {values[2], values[3]}, {values[4], values[5]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("TUNKA", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace TUNKA

namespace TALE {
void MyLnA::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 4, filename);

    std::string line;
    int lineNumber = 4;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceRow(line, 15);
            const double Elo = std::pow(10., values[0]) / 1e9;  // [eV -> GeV]
            const double Eup = std::pow(10., values[1]) / 1e9;  // [eV -> GeV]
            const double E = Utils::computeMeanEnergy(Elo, Eup, m_energyMode);
            dataPoint data = {{E, values[11]}, {values[12], values[12]}, {values[13], values[14]}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("TALE lnA", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace TALE

namespace YAKUTSK {
void MyLnA::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 5, filename);

    std::string line;
    int lineNumber = 5;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        try {
            const auto values = parseWhitespaceTokens(line, 8);
            const double E = std::stod(values[0]) / 1e9;  // [eV -> GeV]
            const double lnAValue = std::stod(values[6]);
            const double errStat = std::stod(values[7]);
            dataPoint data = {{E, lnAValue}, {errStat, errStat}, {0., 0.}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("Yakutsk lnA", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace YAKUTSK

namespace VERITAS {
void MyLeptons::readfile(std::string filename) {
    std::fstream infile = openInputFile(filename);
    skipHeaderLines(infile, 1, filename);

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        try {
            auto values = parseWhitespaceRow(line, 8);
            values[1] *= 1e3;     // TeV -> GeV
            values[2] *= 1e3;     // TeV -> GeV
            values[6] *= 1e4;     // cm^-2 s^-1 GeV^-1 -> m^-2 s^-1 GeV^-1
            values[7] *= 1e4;     // cm^-2 s^-1 GeV^-1 -> m^-2 s^-1 GeV^-1

            const double syst_error_low = 0.33 * values[6];
            const double syst_error_high = 0.64 * values[6];
            const double xMean = Utils::computeMeanEnergy(values[1], values[2], m_energyMode);
            dataPoint data = {{xMean, values[6]}, {values[7], values[7]}, {syst_error_low, syst_error_high}};
            m_dataTable.push_back(data);
        } catch (const std::exception& e) {
            reportInvalidRow("VERITAS leptons", filename, lineNumber, e.what());
        }
    }

    if (infile.bad()) {
        throw std::runtime_error("I/O error while reading " + filename);
    }
}
}  // namespace VERITAS

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
