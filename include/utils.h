// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include <string>

double compute_x_mean_Lafferty1995(double x_min, double x_max, double slope);
double compute_x_mean_powerlaw(double x_min, double x_max, double slope);
double compute_x_mean_geometrical(double x_min, double x_max);
double compute_x_mean(double x_min, double x_max, std::string mode);
double quadrature(double x, double y);

#endif  // INCLUDE_UTILS_H_
