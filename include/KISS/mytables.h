// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_MYTABLES_H_
#define KISS_INCLUDE_MYTABLES_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

namespace CALET {
class MyLepton : public CrDataset {
   public:
    MyLepton(EnergyModes mode) : CrDataset(calet, totalEnergy, lepton, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevLett.131.191001");
        setADSbibcode("2023PhRvL.131s1001A");
    }

    void readfile(std::string filename) override;
};

class MyHeavy : public CrDataset {
   public:
    MyHeavy(YQuantities Y, EnergyModes mode) : CrDataset(calet, kEnergyPerNucleon, Y, mode) {
        setSource(mytables);
        setDOI("10.1103/py17-74rk");
        setADSbibcode("2025PhRvL.135b1002A");
    }

    void readfile(std::string filename) override;
};
}  // namespace CALET

namespace DAMPE {
class MyBoron : public CrDataset {
   public:
    MyBoron(EnergyModes mode) : CrDataset(dampe, kEnergyPerNucleon, B, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevLett.134.191001");
        setADSbibcode("2025PhRvL.134s1001A");
    }

    void readfile(std::string filename);
};

class MyLight : public CrDataset {
   public:
    MyLight(EnergyModes mode) : CrDataset(dampe, totalEnergy, light, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevD.109.L121101");
        setADSbibcode("2024PhRvD.109l1101A");
    }

    void readfile(std::string filename);
};
}  // namespace DAMPE

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

class MyProtonGRAPES : public CrDataset {
   public:
    MyProtonGRAPES(EnergyModes mode) : CrDataset(grapes, totalEnergy, H, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevLett.132.051002");
        setADSbibcode("2024PhRvL.132e1002V");
    }

    void readfile(std::string filename) override;
};

class MyProtonLHAASO : public CrDataset {
   public:
    MyProtonLHAASO(EnergyModes mode, std::string description) : CrDataset(lhaaso, totalEnergy, H, mode) {
        setSource(mytables);
        setDOI("unpublished");
        setADSbibcode("2025arXiv250514447T");
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

}  // namespace KISS

#endif  // KISS_INCLUDE_MYTABLES_H_
