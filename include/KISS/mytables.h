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

    void readfile(std::string filename) override;
};

class MyLeptonHess : public CrDataset {
   public:
    MyLeptonHess(EnergyModes mode) : CrDataset(hess, totalEnergy, lepton, mode) {
        setSource(mytables);
        setDOI("");
        setADSbibcode("");
    }

    void readfile(std::string filename) override;
};

class MyLightARGO : public CrDataset {
   public:
    MyLightARGO(EnergyModes mode) : CrDataset(argo, totalEnergy, light, mode) {
        setSource(mytables);
        setDOI("doi.org/10.1103/PhysRevD.91.112017");
        setADSbibcode("2015PhRvD..91k2017B");
    }

    void readfile(std::string filename) override;
};

class MyLightHAWC : public CrDataset {
   public:
    MyLightHAWC(EnergyModes mode) : CrDataset(hawc, totalEnergy, light, mode) {
        setSource(mytables);
        setDOI("doi.org/10.1103/PhysRevD.105.063021");
        setADSbibcode("2022PhRvD.105f3021A");
    }

    void readfile(std::string filename) override;
};

class MyAllAuger2021 : public CrDataset {
   public:
    MyAllAuger2021(EnergyModes mode) : CrDataset(auger2021, totalEnergy, allParticle, mode) {
        setSource(mytables);
        setDOI("10.1140/epjc/s10052-021-09700-w");
        setADSbibcode("2021EPJC...81..966A");
    }

    void readfile(std::string filename) override;
};

class MyAllAuger2019 : public CrDataset {
   public:
    MyAllAuger2019(EnergyModes mode) : CrDataset(auger2019, totalEnergy, allParticle, mode) {
        setSource(mytables);
        setDOI("10.22323/1.358.0450");
        setADSbibcode("2019ICRC...36..450V");
    }

    void readfile(std::string filename) override;
};

class MyAllTale : public CrDataset {
   public:
    MyAllTale(EnergyModes mode) : CrDataset(tale, totalEnergy, allParticle, mode) {
        setSource(mytables);
        setDOI("10.3847/1538-4357/aada05");
        setADSbibcode("2018ApJ...865...74A");
    }

    void readfile(std::string filename) override;
};

class MyIceCube : public CrDataset {
   public:
    MyIceCube(EnergyModes mode, YQuantities yQuantity) : CrDataset(icecube, totalEnergy, yQuantity, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevD.100.082002");
        setADSbibcode("2019PhRvD.100h2002A");
        setDescription("SIBYLL-2.1");
    }

    void readfile(std::string filename) override;
};

class MyAllTibet : public CrDataset {
   public:
    MyAllTibet(EnergyModes mode, std::string description) : CrDataset(tibet, totalEnergy, allParticle, mode) {
        setSource(mytables);
        setDOI("10.1086/529514");
        setADSbibcode("2008ApJ...678.1165A");
        setDescription(description);
    }

    void readfile(std::string filename) override;
};

// TO BE DONE

// class MyAllRunjob : public CrDataset {
//    public:
//     MyAllRunjob(EnergyModes mode) : CrDataset(runjob, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.1016/S0927-6505(00)00163-8");
//         setADSbibcode("2001APh....16...13A");
//     }

//     void readfile(std::string filename) override{};
// };

// class MyAllTunka133 : public CrDataset {
//    public:
//     MyAllTunka133(EnergyModes mode) : CrDataset(tunka133, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.1016/j.astropartphys.2019.102406");
//         setADSbibcode("2020APh...11702406B");
//     }

//     void readfile(std::string filename) override{};
// };

// class MyAllTunkaRex : public CrDataset {
//    public:
//     MyAllTunkaRex(EnergyModes mode) : CrDataset(tunkarex, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.22323/1.358.0319");
//         setADSbibcode("2019ICRC...36..319K");
//     }

//     void readfile(std::string filename) override{};
// };

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

// class MyAllHAWC : public CrDataset {//    public:
//     MyAllHAWC() { set_experimentName("HAWC"); }
//     void readfile(std::fstream& infile) override;
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
