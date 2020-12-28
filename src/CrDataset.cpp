// Copyright 2020 Carmelo Evoli
#include "include/CrDataset.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

void CrDataset::save(std::string filename) const {
    std::cout << "\033[1;32m> saving data on file " << filename << "\033[0m\n";
    std::ofstream asciiFile(filename.c_str());
    asciiFile << "#Source: " << m_source << "\n";
    asciiFile << "#Ref: " << m_doi << " (" << m_ads << ")\n";
    asciiFile << "#Experiment: " << m_experimentName << "\n";
    asciiFile << "#Quantity: " << m_yType << "\n";
    asciiFile << "#Units: " << m_xUnits << "\n";
    asciiFile << "#Url: " << m_url << "\n";
    asciiFile << "#Comments: " << m_comments << "\n";
    for (auto data : m_dataTable) {
        asciiFile << data << "\n";
    }
    asciiFile.close();
}

void CrDataset::loadDataset(std::string filename) {
    std::cout << "\033[1;31m> loading data from file " << filename << "\033[0m\n";
    std::fstream infile(filename.c_str());
    if (infile)
        readfile(infile);
    else
        throw std::runtime_error("file not found!");
}
void CrDataset::clean() { m_dataTable.erase(m_dataTable.begin(), m_dataTable.end()); }
