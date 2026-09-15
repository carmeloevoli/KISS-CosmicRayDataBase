// Copyright 2020 Carmelo Evoli
#ifndef KISS_INCLUDE_MYTABLES_H_
#define KISS_INCLUDE_MYTABLES_H_

#include <string>

#include "KISS/CrDataset.h"

namespace KISS {

namespace KASCADE {
class MyKuznetsov2024 : public CrDataset {
   public:
    MyKuznetsov2024(YQuantities primary, EnergyModes mode) : CrDataset(kascade, totalEnergy, primary, mode) {
        setSource(mytables);
        setDescription("Kuznetsov2024");
        setDOI("10.48550/arXiv.2312.08279");
        setADSbibcode("2023arXiv231208279K");
        setUrl("https://arxiv.org/pdf/2312.08279");
        setComments(
            "Tables 1 and 3 include theoretical uncertainties; reader combines them with basic systematic "
            "uncertainties in quadrature.");
    }

    void readfile(const std::string& filename) override;
};
}  // namespace KASCADE

namespace TALE {
class MyLnA : public CrDataset {
   public:
    MyLnA(EnergyModes mode) : CrDataset(tale, totalEnergy, lnA, mode) {
        setSource(mytables);
        setDOI("10.48550/arXiv.2603.14804");
        setADSbibcode("2026arXiv260314804A");
        setUrl("https://arxiv.org/pdf/2603.14804");
        setComments("Source file preserves Xmax and sigma(Xmax) columns; reader uses the final lnA block.");
    }

    void readfile(const std::string& filename) override;
};
}  // namespace TALE

namespace YAKUTSK {
class MyLnA : public CrDataset {
   public:
    MyLnA(EnergyModes mode) : CrDataset(yakutsk, totalEnergy, lnA, mode) {
        setSource(mytables);
        setDOI("10.1016/j.asr.2019.07.019");
        setADSbibcode("2019AdSpR..64.2570K");
        setUrl("https://arxiv.org/pdf/1908.01508.pdf");
        setComments(
            "Source file preserves Xmax and sigma(Xmax) columns; tables report only statistical uncertainties for "
            "lnA.");
    }

    void readfile(const std::string& filename) override;
};
}  // namespace YAKUTSK

namespace LHAASO {
class MyNuclei : public CrDataset {
   public:
    MyNuclei(YQuantities primary, std::string HIM, EnergyModes mode) : CrDataset(lhaaso, totalEnergy, primary, mode) {
        setSource(mytables);
        setDOI("arXiv:2511.05013");
        setADSbibcode("none");
        setDescription(HIM);
        setUrl("https://arxiv.org/pdf/2511.05013");
    }

    void readfile(const std::string& filename) override;

   protected:
    std::string makeSourceFilename() const override;
};

class MyAllParticle : public CrDataset {
   public:
    MyAllParticle(std::string HIM, EnergyModes mode) : CrDataset(lhaaso, totalEnergy, allParticle, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevLett.132.131002");
        setADSbibcode("none");
        setDescription(HIM);
        setUrl("https://arxiv.org/pdf/2403.10010");
        setComments("Systematic uncertainties exclude hadronic interaction model uncertainty.");
    }

    void readfile(const std::string& filename) override;

   protected:
    std::string makeSourceFilename() const override;
};

class MyLnA : public CrDataset {
   public:
    MyLnA(std::string HIM, EnergyModes mode) : CrDataset(lhaaso, totalEnergy, lnA, mode) {
        setSource(mytables);
        setDOI("10.1103/PhysRevLett.132.131002");
        setADSbibcode("none");
        setDescription(HIM);
        setUrl("https://arxiv.org/pdf/2403.10010");
        setComments("Systematic uncertainties exclude hadronic interaction model uncertainty.");
    }

    void readfile(const std::string& filename) override;

   protected:
    std::string makeSourceFilename() const override;
};
}  // namespace LHAASO

// OLD DATASETS

// class MyLeptonHESS : public CrDataset {
//    public:
//     MyLeptonHESS(EnergyModes mode) : CrDataset(hess, totalEnergy, lepton, mode) {
//         setSource(mytables);
//         setDOI("");
//         setADSbibcode("");
//     }

//     void readfile(const std::string& filename) override;
// };

// class MyLightARGO : public CrDataset {
//    public:
//     MyLightARGO(EnergyModes mode) : CrDataset(argo, totalEnergy, light, mode) {
//         setSource(mytables);
//         setDOI("doi.org/10.1103/PhysRevD.91.112017");
//         setADSbibcode("2015PhRvD..91k2017B");
//     }

//     void readfile(const std::string& filename) override;
// };

// class MyAllTale : public CrDataset {
//    public:
//     MyAllTale(EnergyModes mode) : CrDataset(tale, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.3847/1538-4357/aada05");
//         setADSbibcode("2018ApJ...865...74A");
//     }

//     void readfile(const std::string& filename) override;
// };

// class MyAllTibet : public CrDataset {
//    public:
//     MyAllTibet(EnergyModes mode, std::string description) : CrDataset(tibet, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.1086/529514");
//         setADSbibcode("2008ApJ...678.1165A");
//         setDescription(description);
//     }

//     void readfile(const std::string& filename) override;
// };

// TO BE DONE

// class MyAllRunjob : public CrDataset {
//    public:
//     MyAllRunjob(EnergyModes mode) : CrDataset(runjob, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.1016/S0927-6505(00)00163-8");
//         setADSbibcode("2001APh....16...13A");
//     }

//     void readfile(const std::string& filename) override{};
// };

// class MyAllTunka133 : public CrDataset {
//    public:
//     MyAllTunka133(EnergyModes mode) : CrDataset(tunka133, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.1016/j.astropartphys.2019.102406");
//         setADSbibcode("2020APh...11702406B");
//     }

//     void readfile(const std::string& filename) override{};
// };

// class MyAllTunkaRex : public CrDataset {
//    public:
//     MyAllTunkaRex(EnergyModes mode) : CrDataset(tunkarex, totalEnergy, allParticle, mode) {
//         setSource(mytables);
//         setDOI("10.22323/1.358.0319");
//         setADSbibcode("2019ICRC...36..319K");
//     }

//     void readfile(const std::string& filename) override{};
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
