// Copyright 2020 Carmelo Evoli
#include "KISS/SSDC.h"

#include <algorithm>

#include "KISS/utils.h"
#include "pugixml/pugixml.hpp"
namespace KISS {

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

    for (pugi::xml_node node : tree.children("DATA")) {
        double xMean = 0;

        if (m_xQuantity == rigidity) {
            double x_min = node.child("rigidity_min").first_child().text().as_double();
            double x_max = node.child("rigidity_max").first_child().text().as_double();
            xMean = Utils::computeMeanEnergy(x_min, x_max, m_energyMode);
        }

        double y, statLo, statUp, errTotLo, errTotUp;

        if (std::find(fluxes.begin(), fluxes.end(), m_yQuantity) != fluxes.end()) {
            double systLo, systUp;
            y = node.child("flux").first_child().text().as_double();
            statLo = node.child("flux_statistical_error_low").first_child().text().as_double();
            statUp = node.child("flux_statistical_error_high").first_child().text().as_double();
            systLo = node.child("flux_systematical_error_low").first_child().text().as_double();
            systUp = node.child("flux_systematical_error_high").first_child().text().as_double();
            errTotLo = Utils::quadrature(statLo, systLo);
            errTotUp = Utils::quadrature(statUp, systUp);
        } else if (std::find(ratios.begin(), ratios.end(), m_yQuantity) != ratios.end()) {
            double systLo, systUp;
            y = node.child("fluxratio").first_child().text().as_double();
            statLo = node.child("fluxratio_statistical_error_low").first_child().text().as_double();
            statUp = node.child("fluxratio_statistical_error_high").first_child().text().as_double();
            systLo = node.child("fluxratio_systematical_error_low").first_child().text().as_double();
            systUp = node.child("fluxratio_systematical_error_high").first_child().text().as_double();
            errTotLo = Utils::quadrature(statLo, systLo);
            errTotUp = Utils::quadrature(statUp, systUp);
        }

        dataPoint data = {{xMean, y}, {statLo, statUp}, {errTotLo, errTotUp}};
        m_dataTable.push_back(data);
    }
}

}  // namespace KISS
