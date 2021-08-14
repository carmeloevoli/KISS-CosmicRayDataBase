// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_CRDB_H_
#define KISS_INCLUDE_CRDB_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

class CRDB : public CrDataset {
   public:
    explicit CRDB(CrExperiments crExperiment, XQuantities xQuantity, YQuantities yQuantity, EnergyModes mode)
        : CrDataset(crExperiment, xQuantity, yQuantity, mode) {
        setSource(crdb);
        setUrl("https://lpsc.in2p3.fr/crdb");
    }

    void readfile(std::string filename);
};

}  // namespace KISS

#endif  // KISS_INCLUDE_CRDB_H_
