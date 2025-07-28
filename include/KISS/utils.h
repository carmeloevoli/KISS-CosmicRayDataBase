// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_UTILS_H_
#define KISS_INCLUDE_UTILS_H_

#include <cmath>
#include <string>
#include <vector>

#include "KISS/CrDataset.h"

namespace Utils {

// inline double quadrature(double a, double b) { return std::sqrt(a * a + b * b); }

double computeMeanEnergy(double x_min, double x_max, KISS::EnergyModes mode);

std::vector<double> splitline(const std::string& line, const std::string& delimiter = ";");

}  // namespace Utils

#endif  // INCLUDE_UTILS_H_
