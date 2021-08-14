// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_KCDC_H_
#define KISS_INCLUDE_KCDC_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

class KCDC : public CrDataset {
   public:
    explicit KCDC(CrExperiments crExperiment, XQuantities xQuantity, YQuantities yQuantity, EnergyModes mode)
        : CrDataset(crExperiment, xQuantity, yQuantity, mode) {
        setSource(kcdc);
        setUrl("https://kcdc.ikp.kit.edu/spectra/");
    }

    void readfile(std::string filename);
};

}  // namespace KISS

#endif  // KISS_INCLUDE_KCDC_H
