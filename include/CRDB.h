// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_CRDB_H_
#define INCLUDE_CRDB_H_

#include <string>

#include "include/CrDataset.h"

class CRDB : public CrDataset {
   public:
    explicit CRDB(std::string experimentName) {
        set_source("CRDB");
        set_url("https://lpsc.in2p3.fr/crdb");
        set_experimentName(experimentName);
    }

    void readfile(std::fstream& infile);
};

#endif  // INCLUDE_CRDB_H_
