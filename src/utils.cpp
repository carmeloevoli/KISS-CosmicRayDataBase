// Copyright 2020 Carmelo Evoli
#include "include/utils.h"

#include <cmath>
#include <iostream>
#include <string>

double compute_x_mean_Lafferty1995(double x_min, double x_max, double slope) {
    /*
     * Compute the mean rigidity in the bin
     * assuming a spectrum R^-slope as in
     * Lafferty and Wyatt, 1995, NIMPR A 335
     */
    const double x_ratio = x_min / (x_max - x_min);
    double x_tilde = x_min;
    x_tilde *=
        std::pow(x_ratio / (slope - 1.) * (1. - std::pow(x_max / x_min, -slope + 1.)), -1. / slope);
    return x_tilde;
}

double compute_x_mean_powerlaw(double x_min, double x_max, double slope) {
    /*
     * Compute the mean rigidity in the bin
     * assuming a spectrum R^-slope
     */
    double x_mean = (slope - 1.) / (slope - 2.);
    x_mean *= (std::pow(x_max, -slope + 2) - std::pow(x_min, -slope + 2)) /
              (std::pow(x_max, -slope + 1) - std::pow(x_min, -slope + 1));
    return x_mean;
}

double compute_x_mean_geometrical(double x_min, double x_max) {
    /*
     * Compute the mean geometrical mean in the bin
     */
    return std::sqrt(x_min * x_max);
}

double compute_x_mean(double x_min, double x_max, std::string mode) {
    if (mode == "geometrical") {
        return compute_x_mean_geometrical(x_min, x_max);
    } else if (mode == "pl2.7") {
        return compute_x_mean_powerlaw(x_min, x_max, 2.7);
    } else if (mode == "pl3,0") {
        return compute_x_mean_powerlaw(x_min, x_max, 3.0);
    } else if (mode == "Lafferty2.7") {
        return compute_x_mean_Lafferty1995(x_min, x_max, 2.7);
    } else if (mode == "Lafferty3.0") {
        return compute_x_mean_Lafferty1995(x_min, x_max, 3.0);
    } else {
        throw std::runtime_error("problem with mean energy or mode not implemented");
        return -1;
    }
}

double quadrature(double x, double y) { return std::sqrt(x * x + y * y); }
