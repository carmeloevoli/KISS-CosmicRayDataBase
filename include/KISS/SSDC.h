// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_SSDC_H_
#define KISS_INCLUDE_SSDC_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

bool IsFlux(YQuantities yQuantity);
bool IsRatio(YQuantities yQuantity);

class SSDC : public CrDataset {
   public:
    explicit SSDC(CrExperiments crExperiment, XQuantities xQuantity, YQuantities yQuantity, EnergyModes mode)
        : CrDataset(crExperiment, xQuantity, yQuantity, mode) {
        setSource(ssdc);
        setUrl("https://tools.ssdc.asi.it/CosmicRays/");
    }

    void readfile(std::string filename);

   protected:
    std::string makeSourceFilename() const override;
};

}  // namespace KISS

#endif  // KISS_INCLUDE_SSDC_H_
