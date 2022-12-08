// Copyright 2020 Carmelo Evoli
#include "KISS/SSDC.h"

#include <algorithm>

#include "KISS/utils.h"
#include "pugixml/pugixml.hpp"

namespace KISS {

bool IsFlux(YQuantities yQuantity) {
    const std::vector<YQuantities> fluxes{H,  He, Li, Be, B,  C,  N,        O,        F,      Ne,
                                          Na, Mg, Al, Si, Fe, Ni, electron, positron, lepton, antiproton};
    return (std::find(fluxes.begin(), fluxes.end(), yQuantity) != fluxes.end());
}

bool IsRatio(YQuantities yQuantity) {
    const std::vector<YQuantities> ratios{positronfraction,
                                          B_C,
                                          B_O,
                                          Be_B,
                                          Be_C,
                                          Be_O,
                                          C_O,
                                          F_B,
                                          F_Si,
                                          Fe_He,
                                          Fe_O,
                                          Fe_Si,
                                          H_He,
                                          He_O,
                                          Li_B,
                                          Li_C,
                                          Li_O,
                                          Mg_O,
                                          N_B,
                                          N_O,
                                          Ne_Mg,
                                          Ne_O,
                                          Si_Mg,
                                          Si_O};
    return (std::find(ratios.begin(), ratios.end(), yQuantity) != ratios.end());
}

std::string SSDC::makeSourceFilename() const {
    std::string s = "source/";
    s += ToString(m_source) + "/" + ToString(m_experiment);
    if (m_description != "") s += "_" + m_description;
    s += "_" + ToString(m_yQuantity) + "_" + ToString(m_xQuantity);
    s += ".xml";
    return s;
}

void SSDC::readfile(std::string filename) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename.c_str());
    if (!result) throw std::runtime_error("error in loadig the XML file.");
    const auto tree = doc.child("XML");

    size_t n = std::distance(tree.children("DATA").begin(), tree.children("DATA").end());

    for (pugi::xml_node node : tree.children("DATA")) {
        double xMean = 0;

        if (m_xQuantity == rigidity) {
            double x_min = node.child("rigidity_min").first_child().text().as_double();
            double x_max = node.child("rigidity_max").first_child().text().as_double();
            xMean = Utils::computeMeanEnergy(x_min, x_max, m_energyMode);
        } else if (m_xQuantity == kEnergy || m_xQuantity == kEnergyPerNucleon) {
            double x_min = node.child("kinetic_energy_min").first_child().text().as_double();
            double x_max = node.child("kinetic_energy_max").first_child().text().as_double();
            xMean = Utils::computeMeanEnergy(x_min, x_max, m_energyMode);
        } else {
            throw std::runtime_error("energy value not valid");
        }

        double y = -1, statLo = 0, statUp = 0, systLo = 0, systUp = 0;

        if (IsFlux(m_yQuantity)) {
            y = node.child("flux").first_child().text().as_double();
            statLo = node.child("flux_statistical_error_low").first_child().text().as_double();
            statUp = node.child("flux_statistical_error_high").first_child().text().as_double();
            systLo = node.child("flux_systematical_error_low").first_child().text().as_double();
            systUp = node.child("flux_systematical_error_high").first_child().text().as_double();
        } else if (IsRatio(m_yQuantity)) {
            y = node.child("fluxratio").first_child().text().as_double();
            statLo = node.child("fluxratio_statistical_error_low").first_child().text().as_double();
            statUp = node.child("fluxratio_statistical_error_high").first_child().text().as_double();
            systLo = node.child("fluxratio_systematical_error_low").first_child().text().as_double();
            systUp = node.child("fluxratio_systematical_error_high").first_child().text().as_double();
        } else
            throw std::invalid_argument("y-quantity not valid");

        if (y > 0.) {
            dataPoint data = {{xMean, y}, {statLo, statUp}, {systLo, systUp}};
            m_dataTable.push_back(data);
        }
    }

    if (n != m_dataTable.size()) throw std::runtime_error("generic problem in reading the XML file");
}

}  // namespace KISS
