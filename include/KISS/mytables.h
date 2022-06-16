// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_MYTABLES_H_
#define KISS_INCLUDE_MYTABLES_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

// class MyAllARGO : public CrDataset {
//    public:
//     MyAllARGO() { set_experimentName("ARGO"); }
//     void readfile(std::fstream& infile) override;
// };

// class MyAllAUGER : public CrDataset {
//    public:
//     MyAllAUGER() { set_experimentName("AUGER"); }
//     void readfile(std::fstream& infile) override;
// };

// class MyAllTA : public CrDataset {
//    public:
//     MyAllTA() { set_experimentName("Telescope Array"); }
//     void readfile(std::fstream& infile) override;
// };

// class MyAllHAWC : public CrDataset {
//    public:
//     MyAllHAWC() { set_experimentName("HAWC"); }
//     void readfile(std::fstream& infile) override;
// };

// class MyAllTIBET : public CrDataset {
//    public:
//     explicit MyAllTIBET(std::string hadmod);
//     void readfile(std::fstream& infile) override;

//    private:
//     enum HADMOD { QGSJETHD, QGSJETPD, SIBYLLHD };
//     HADMOD m_hadmod;
// };

// class MyLightARGO : public CrDataset {
//    public:
//     MyLightARGO() { set_experimentName("ARGO"); }
//     void readfile(std::fstream& infile) override;
// };

class MyLeptonVeritas : public CrDataset {
   public:
    explicit MyLeptonVeritas(EnergyModes mode) : CrDataset(veritas, totalEnergy, lepton, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevD.98.062004");
        setADSbibcode("2018PhRvD..98f2004A");
    }

    void readfile(std::string filename);
};

class MyLeptonHess : public CrDataset {
   public:
    MyLeptonHess(EnergyModes mode) : CrDataset(hess, totalEnergy, lepton, mode) {
        setSource(mytables);
        setDOI("");
        setADSbibcode("");
    }

    void readfile(std::string filename);
};

// class MyHeavyCALET : public CrDataset {
//    public:
//     MyHeavyCALET(size_t A) : m_A(A) { set_experimentName("CALET"); }
//     void readfile(std::fstream& infile) override;

//    protected:
//     size_t m_A;
// };

// class MyHeliumDAMPE : public CrDataset {
//    public:
//     MyHeliumDAMPE() { set_experimentName("DAMPE"); }
//     void readfile(std::fstream& infile) override;
// };

}  // namespace KISS

#endif  // KISS_INCLUDE_MYTABLES_H_
