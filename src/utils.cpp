// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/utils.h"

#include <cmath>

namespace Utils {

double computeMeanEnergyLafferty1995(double Emin, double Emax, double slope) {
    /*
     * Compute the mean rigidity in the bin
     * assuming a spectrum R^-slope as in
     * Lafferty and Wyatt, 1995, NIMPR A 335
     */
    const double x_ratio = Emin / (Emax - Emin);
    double x_tilde = Emin;
    x_tilde *= std::pow(x_ratio / (slope - 1.) * (1. - std::pow(Emax / Emin, -slope + 1.)), -1. / slope);
    return x_tilde;
}

double computeMeanEnergyPowerLaw(double Emin, double Emax, double slope) {
    /*
     * Compute the mean rigidity in the bin
     * assuming a spectrum R^-slope
     */
    double x_mean = (slope - 1.) / (slope - 2.);
    x_mean *= (std::pow(Emax, -slope + 2) - std::pow(Emin, -slope + 2)) /
              (std::pow(Emax, -slope + 1) - std::pow(Emin, -slope + 1));
    return x_mean;
}

double computeMeanEnergyGeometrical(double Emin, double Emax) {
    /*
     * Compute the mean geometrical mean in the bin
     */
    return std::sqrt(Emin * Emax);
}

double computeMeanEnergy(double Emin, double Emax, KISS::EnergyModes mode) {
    if (Emax <= Emin) return Emin;
    if (mode == KISS::geometrical) {
        return computeMeanEnergyGeometrical(Emin, Emax);
    } else if (mode == KISS::PL2_7) {
        return computeMeanEnergyPowerLaw(Emin, Emax, 2.7);
    } else if (mode == KISS::PL3_0) {
        return computeMeanEnergyPowerLaw(Emin, Emax, 3.0);
    } else if (mode == KISS::Laff2_7) {
        return computeMeanEnergyLafferty1995(Emin, Emax, 2.7);
    } else if (mode == KISS::Laff3_0) {
        return computeMeanEnergyLafferty1995(Emin, Emax, 3.0);
    } else {
        throw std::invalid_argument("mean energy mode not implemented");
        return -1;
    }
}

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

}  // namespace Utils