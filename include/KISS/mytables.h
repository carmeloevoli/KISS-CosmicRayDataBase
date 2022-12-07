// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_MYTABLES_H_
#define KISS_INCLUDE_MYTABLES_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

class MyLeptonVeritas : public CrDataset {
   public:
    MyLeptonVeritas(EnergyModes mode) : CrDataset(veritas, totalEnergy, lepton, mode) {
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

class MyLightARGO : public CrDataset {
   public:
    MyLightARGO(EnergyModes mode) : CrDataset(argo, totalEnergy, light, mode) {
        setSource(mytables);
        setDOI("doi.org/10.1103/PhysRevD.91.112017");
        setADSbibcode("2015PhRvD..91k2017B");
    }

    void readfile(std::string filename);
};

class MyLightHAWC : public CrDataset {
   public:
    MyLightHAWC(EnergyModes mode) : CrDataset(argo, totalEnergy, light, mode) {
        setSource(mytables);
        setDOI("doi.org/10.1103/PhysRevD.105.063021");
        setADSbibcode("2022PhRvD.105f3021A");
    }

    void readfile(std::string filename);
};

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

// class MyHeliumDAMPE : public CrDataset {
//    public:
//     MyHeliumDAMPE(EnergyModes mode) : CrDataset(dampe, totalEnergy, He, mode) {
//         setSource(mytables);
//         setDOI("10.1103/PhysRevLett.126.201102");
//         setADSbibcode("2021PhRvL.126t1102A");
//     }

//     void readfile(std::string filename);
// };

// class MyHeavyCALET : public CrDataset {
//    public:
//     MyHeavyCALET(size_t A) : m_A(A) { set_experimentName("CALET"); }
//     void readfile(std::fstream& infile) override;

//    protected:
//     size_t m_A;
// };

}  // namespace KISS

#endif  // KISS_INCLUDE_MYTABLES_H_
