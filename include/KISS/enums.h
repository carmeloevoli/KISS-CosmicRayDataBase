// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_ENUMS_H_
#define KISS_INCLUDE_ENUMS_H_

namespace KISS {

enum Sources { crdb, kcdc, ssdc, mytables };

inline std::string ToString(Sources v) {
    switch (v) {
        case crdb:
            return "CRDB";
        case kcdc:
            return "KCDC";
        case ssdc:
            return "SSDC";
        default:
            return "mytables";
    }
}

enum CrExperiments {
    ams02,
    atic02,
    bess,
    calet,
    cream,
    dampe,
    hess,
    icecube,
    kascadeGrande,
    kascade,
    nucleon,
    pamela,
    runjob,
    tale,
    tunka133,
    tunkarex,
    veritas
};

inline std::string ToString(CrExperiments v) {
    switch (v) {
        case ams02:
            return "AMS-02";
        case atic02:
            return "ATIC-02";
        case bess:
            return "BESS-TeV";
        case calet:
            return "CALET";
        case cream:
            return "CREAM";
        case dampe:
            return "DAMPE";
        case hess:
            return "HESS";
        case icecube:
            return "ICECUBE-ICETOP";
        case kascadeGrande:
            return "KASCADE-Grande";
        case kascade:
            return "KASCADE";
        case nucleon:
            return "NUCLEON";
        case pamela:
            return "PAMELA";
        case runjob:
            return "RUNJOB";
        case tale:
            return "TALE";
        case tunka133:
            return "TUNKA-133";
        case tunkarex:
            return "TUNKA-Rex";
        default:
            throw std::invalid_argument("Experiment Name not found.");
    }
}

enum XQuantities { rigidity, totalEnergy, kEnergy, kEnergyPerNucleon };

inline std::string ToString(XQuantities v) {
    switch (v) {
        case rigidity:
            return "rigidity";
        case totalEnergy:
            return "totalEnergy";
        case kEnergy:
            return "kineticEnergy";
        case kEnergyPerNucleon:
            return "kineticEnergyPerNucleon";
        default:
            throw std::invalid_argument("X Quantity not found.");
    }
}

enum YQuantities {
    allParticle,
    electron,
    positron,
    lepton,
    positronfraction,
    light,
    H,
    He,
    Li,
    Be,
    B,
    C,
    N,
    O,
    F,
    Ne,
    Na,
    Mg,
    Al,
    Si,
    P,
    S,
    Cl,
    Ar,
    K,
    Ca,
    Sc,
    Ti,
    V,
    Cr,
    Mn,
    Fe,
    B_C,
    B_O,
    Be_B,
    Be_C,
    Be_O,
    C_O,
    F_B,
    F_Si,
    Fe_He,
    Fe_O,
    Fe_Si,
    H_He,
    He_O,
    Li_B,
    Li_C,
    Li_O,
    Mg_O,
    N_B,
    N_O,
    Ne_Mg,
    Ne_O,
    Si_Mg,
    Si_O
};

inline std::string ToString(YQuantities v) {
    switch (v) {
        case allParticle:
            return "allParticle";
        case electron:
            return "e-";
        case positron:
            return "e+";
        case lepton:
            return "e+e-";
        case positronfraction:
            return "posfraction";
        case light:
            return "light";
        case H:
            return "H";
        case He:
            return "He";
        case Li:
            return "Li";
        case Be:
            return "Be";
        case B:
            return "B";
        case C:
            return "C";
        case N:
            return "N";
        case O:
            return "O";
        case F:
            return "F";
        case Ne:
            return "Ne";
        case Na:
            return "Na";
        case Mg:
            return "Mg";
        case Al:
            return "Al";
        case Si:
            return "Si";
        case Fe:
            return "Fe";
        case B_C:
            return "B_C";
        case B_O:
            return "B_O";
        case Be_B:
            return "Be_B";
        case Be_C:
            return "Be_C";
        case Be_O:
            return "Be_O";
        case C_O:
            return "C_O";
        case F_B:
            return "F_B";
        case F_Si:
            return "F_Si";
        case Fe_He:
            return "Fe_He";
        case Fe_O:
            return "Fe_O";
        case Fe_Si:
            return "Fe_Si";
        case H_He:
            return "H_He";
        case He_O:
            return "He_O";
        case Li_B:
            return "Li_B";
        case Li_C:
            return "Li_C";
        case Li_O:
            return "Li_O";
        case Mg_O:
            return "Mg_O";
        case N_B:
            return "N_B";
        case N_O:
            return "N_O";
        case Ne_Mg:
            return "Ne_Mg";
        case Ne_O:
            return "Ne_O";
        case Si_Mg:
            return "Si_Mg";
        case Si_O:
            return "Si_O";
        default:
            throw std::invalid_argument("Y Quantity not found.");
    }
}

enum EnergyModes { geometrical, PL2_7, PL3_0, Laff2_7, Laff3_0, unknown };

inline std::string ToString(EnergyModes v) {
    switch (v) {
        case unknown:
            return "Unknown";
        case geometrical:
            return "Geometrical mean";
        case PL2_7:
            return "Power-law with slope 2.7";
        case PL3_0:
            return "Power-law with slope 3.0";
        case Laff2_7:
            return "Lafferty and Wyatt (1995) with slope 2.7";
        case Laff3_0:
            return "Lafferty and Wyatt (1995) with slope 3.0";
        default:
            throw std::invalid_argument("Energy mode not found.");
    }
}

}  // namespace KISS

#endif  // KISS_INCLUDE_ENUMS_H