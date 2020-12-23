// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_KCDC_H_
#define INCLUDE_KCDC_H_

#include <string>

#include "include/CrDataset.h"

class KCDC : public CrDataset {
   public:
    explicit KCDC(std::string experimentName) {
        set_source("KCDC");
        set_url("https://kcdc.ikp.kit.edu/spectra/");
        set_experimentName(experimentName);
    }

    void readfile(std::fstream& infile);
};

#endif  // INCLUDE_KCDC_H_
