// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/CrDataset.h"

#include <fstream>
#include <regex>
#include <string>

namespace KISS {

void CrDataset::setDOI(std::string str) { m_doi = str; }  // TODO use regex

void CrDataset::setADSbibcode(std::string str) { m_ads = str; }  // TODO use regex

void CrDataset::setUrl(std::string url) {
    std::string pattern = "^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$";
    std::regex url_regex(pattern);
    if (std::regex_match(url, url_regex)) {
        m_url = url;
    } else {
        throw std::invalid_argument("url not valid");
    }
}

void CrDataset::setComments(std::string str) { m_comments = str; }

void CrDataset::setDescription(std::string str) { m_description = str; }

std::string CrDataset::makeSourceFilename() const {
    std::string s = "source/";
    s += ToString(m_source) + "/" + ToString(m_experiment);
    if (m_description != "") s += "_" + m_description;
    s += "_" + ToString(m_yQuantity) + "_" + ToString(m_xQuantity);
    s += ".txt";
    return s;
}

std::string CrDataset::makeOutputFilename() const {
    std::string s = "output/";
    s += ToString(m_experiment);
    if (m_description != "") s += "_" + m_description;
    s += "_" + ToString(m_yQuantity) + "_" + ToString(m_xQuantity);
    s += ".txt";
    return s;
}

bool CrDataset::load() {
    const auto filename = makeSourceFilename();
    std::cout << "\033[1;31m> loading data from file " << filename << "\033[0m\n";
    std::fstream infile(filename.c_str());
    bool success = false;
    if (infile) {
        readfile(filename);
        success = true;
        infile.close();
    } else
        throw std::runtime_error("file not found!");
    return success;
}

void CrDataset::save() const {
    const auto filename = makeOutputFilename();
    std::cout << "\033[1;32m> saving data on file " << filename << "\033[0m\n";
    std::ofstream asciiFile(filename.c_str());
    asciiFile << "#Source: " << ToString(m_source) << "\n";
    asciiFile << "#Ref: " << m_doi << " (" << m_ads << ")\n";
    asciiFile << "#Experiment: " << ToString(m_experiment);
    if (m_description != "")
        asciiFile << " (" << m_description << ")\n";
    else
        asciiFile << "\n";
    asciiFile << "#Y Quantity: " << ToString(m_yQuantity) << "\n";
    asciiFile << "#X Quantity: " << ToString(m_xQuantity) << "\n";
    asciiFile << "#Url: " << m_url << "\n";
    asciiFile << "#Comments: " << m_comments << "\n";
    asciiFile << "#Colums: x, y, y statistical errors, y systematic errors\n";
    for (auto data : m_dataTable) {
        asciiFile << data << "\n";
    }
    asciiFile.close();
}

}  // namespace KISS