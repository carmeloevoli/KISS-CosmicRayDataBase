// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_SSDC_H_
#define INCLUDE_SSDC_H_

#include <string>

#include "include/CrDataset.h"

class SSDC : public CrDataset {
   public:
    explicit SSDC(std::string experimentName) {
        set_source("SSDC");
        set_url("https://tools.ssdc.asi.it/CosmicRays/");
        set_experimentName(experimentName);
    }

    void readfile(std::fstream& infile);
};

#endif  // INCLUDE_SSDC_H_
