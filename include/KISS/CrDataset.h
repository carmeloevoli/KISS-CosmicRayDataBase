// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_CRDATASET_H_
#define KISS_INCLUDE_CRDATASET_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "KISS/datapoint.h"
#include "KISS/enums.h"

namespace KISS {

class CrDataset {
   public:
    CrDataset(CrExperiments crExperiment, XQuantities xQuantity, YQuantities yQuantity, EnergyModes mode)
        : m_experiment(crExperiment), m_xQuantity(xQuantity), m_yQuantity(yQuantity), m_energyMode(mode) {}

    virtual ~CrDataset() = default;

    inline void run() {
        if (load()) save();
    };

    inline void setSource(Sources source) { m_source = source; }
    inline void setExperiment(CrExperiments experiment) { m_experiment = experiment; }
    inline void setXQuantity(XQuantities x) { m_xQuantity = x; }
    inline void setYQuantity(YQuantities y) { m_yQuantity = y; }
    inline void setMeanEnergyMode(EnergyModes mode) { m_energyMode = mode; }

    void setDOI(const std::string& str);
    void setADSbibcode(const std::string& str);
    void setUrl(const std::string& str);
    void setComments(const std::string& str);
    void setDescription(const std::string& str);
    static int missingInputCount();
    static void printMissingInputSummary();

   protected:
    CrExperiments m_experiment;
    Sources m_source = unknownSource;
    XQuantities m_xQuantity;
    YQuantities m_yQuantity;
    EnergyModes m_energyMode;

    std::string m_doi = "not available";
    std::string m_ads = "none";
    std::string m_url = "";
    std::string m_comments = "";
    std::string m_description = "";

    std::vector<dataPoint> m_dataTable;

   protected:
    // Assembles "<kDataDir><source>/<experiment>[_<description>]_<yLabel>_<xQuantity><extension>".
    // Shared by the makeSourceFilename() overrides, which differ only in the y-label, whether the
    // description is appended, and the file extension.
    std::string buildSourcePath(const std::string& yLabel, bool withDescription,
                                const std::string& extension = ".txt") const;
    virtual std::string makeSourceFilename() const;
    virtual std::string makeOutputFilename() const;
    virtual void readfile(const std::string& filename) = 0;
    bool load();
    void save() const;
};

}  // namespace KISS

#endif  // KISS_INCLUDE_CRDATASET_H
