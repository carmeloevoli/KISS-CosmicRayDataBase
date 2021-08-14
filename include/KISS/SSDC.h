// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_SSDC_H_
#define KISS_INCLUDE_SSDC_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

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
    const std::vector<YQuantities> fluxes{H, He, Li, Be, B, C, N, O, F, Ne, Mg, Si, Fe};
    const std::vector<YQuantities> ratios{B_C,  B_O,  Be_B, Be_C, Be_O, C_O, F_B, F_Si,  Fe_He, Fe_O,  Fe_Si, H_He,
                                          He_O, Li_B, Li_C, Li_O, Mg_O, N_B, N_O, Ne_Mg, Ne_O,  Si_Mg, Si_O};
};

}  // namespace KISS

#endif  // KISS_INCLUDE_SSDC_H_
