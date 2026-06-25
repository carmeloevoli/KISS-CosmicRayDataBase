// Copyright 2020 Carmelo Evoli - MIT License
#include "KISS/CrDataset.h"

#include <filesystem>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>

#include "KISS/config.h"

namespace KISS {

namespace {

int g_missingInputCount = 0;

}  // namespace

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

int CrDataset::missingInputCount() { return g_missingInputCount; }

void CrDataset::printMissingInputSummary() {
    std::cout << "\033[1;33m> missing input files: " << missingInputCount() << "\033[0m\n";
}

std::string CrDataset::buildSourcePath(const std::string& yLabel, bool withDescription,
                                       const std::string& extension) const {
    std::string s = kDataDir;
    s += ToString(m_source) + "/" + ToString(m_experiment);
    if (withDescription && m_description != "") s += "_" + m_description;
    s += "_" + yLabel + "_" + ToString(m_xQuantity) + extension;
    return s;
}

std::string CrDataset::makeSourceFilename() const {
    return buildSourcePath(ToString(m_yQuantity), /*withDescription=*/true);
}

std::string CrDataset::makeOutputFilename() const {
    std::string s = kOutputDir;
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
    if (!infile) {
        ++g_missingInputCount;
        std::cerr << "\033[1;33m> missing input file " << filename << ", skipping dataset\033[0m\n";
        return false;
    }

    m_dataTable.clear();
    infile.close();
    readfile(filename);
    return true;
}

void CrDataset::save() const {
    const auto filename = makeOutputFilename();
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
    std::cout << "\033[1;32m> saving data on file " << filename << "\033[0m\n";
    std::ofstream asciiFile(filename.c_str());
    if (!asciiFile) {
        throw std::runtime_error("cannot open output file for writing: " + filename);
    }
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
    asciiFile << "#Columns: x, y, y statistical errors, y systematic errors\n";
    for (auto data : m_dataTable) {
        asciiFile << data << "\n";
    }
    asciiFile.close();
}

}  // namespace KISS
