// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_NUCLEI_H_
#define INCLUDE_NUCLEI_H_

#include "CRDB.h"
#include "KCDC.h"
#include "SSDC.h"

namespace NUCLEI {

void ARGO() {
    MyLightARGO dataSet;
    dataSet.set_reference("Di Siascio, EPJ Conf. 145, 05003 (2017) ");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("light");
    dataSet.set_comments("Table provided by G. Di Sciascio");
    dataSet.loadDataset("source/nuclei/mysource_light_ARGO_Etot.txt");
    dataSet.save("output/light_ARGO_Etot.txt");
}

void ATIC02() {
    CRDB dataSet("ATIC02");
    dataSet.set_reference("Panov et al., Bull. Russian Acad. Sci. 73, 564 (2009)");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total energy");
    dataSet.set_yType("H");
    dataSet.set_comments("");
    dataSet.loadDataset("source/nuclei/CRDB_H_ATIC02_Etot.txt");
    dataSet.save("output/H_ATIC02_Etot.txt");
}

void CREAM_II() {
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_reference("Ahn et al., ApJ 707, 593 (2009)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_C_CREAM-II_Ekn.txt");
        dataSet.save("output/C_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_reference("Ahn et al., ApJ 707, 593 (2009)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_O_CREAM-II_Ekn.txt");
        dataSet.save("output/O_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_reference("Ahn et al., ApJ 707, 593 (2009)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Mg_CREAM-II_Ekn.txt");
        dataSet.save("output/Mg_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_reference("Ahn et al., ApJ 707, 593 (2009)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("Si");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Si_CREAM-II_Ekn.txt");
        dataSet.save("output/Si_CREAM-II_Ekn.txt");
    }
    {
        CRDB dataSet("CREAM-II");
        dataSet.set_reference("Ahn et al., ApJ 707, 593 (2009)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("Fe");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/CRDB_Fe_CREAM-II_Ekn.txt");
        dataSet.save("output/Fe_CREAM-II_Ekn.txt");
    }
}

void CREAM_III() {
    {
        CRDB dataSet("CREAM-III");
        dataSet.set_reference("Yoon et al., ApJ 839, 5 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Table 3");
        dataSet.loadDataset("source/nuclei/CRDB_H_CREAM-I+III_Ek.txt");
        dataSet.save("output/H_CREAM-III_Ek.txt");
    }
    {
        CRDB dataSet("CREAM-III");
        dataSet.set_reference("Yoon et al., ApJ 839, 5 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("kinetic Energy per nucleon");
        dataSet.set_yType("He");
        dataSet.set_comments("Table 3");
        dataSet.loadDataset("source/nuclei/CRDB_He_CREAM-I+III_Ekn.txt");
        dataSet.save("output/He_CREAM-III_Ekn.txt");
    }
}

void DAMPE() {
    SSDC dataSet("DAMPE");
    dataSet.set_reference(" ");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("H");
    dataSet.set_comments("");
    dataSet.loadDataset("source/nuclei/SSDC_H_DAMPE_Ek.txt");
    dataSet.save("output/H_DAMPE_Ek.txt");
}

void ICECUBE_ICETOP() {
    {
        KCDC dataSet("ICECUBE-ICETOP");
        dataSet.set_reference("Aartsen et al., Physical Review D 100, 082002 (2019)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Sibyll-2.1 only");
        dataSet.loadDataset("source/nuclei/KCDC_H_ICECUBE-ICETOP_Etot.txt");
        dataSet.save("output/H_ICECUBE-ICETOP_Etot.txt");
    }
    {
        KCDC dataSet("ICECUBE-ICETOP");
        dataSet.set_reference("Aartsen et al., Physical Review D 100, 082002 (2019)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("Sibyll-2.1 only");
        dataSet.loadDataset("source/nuclei/KCDC_He_ICECUBE-ICETOP_Etot.txt");
        dataSet.save("output/He_ICECUBE-ICETOP_Etot.txt");
    }
}

void KASCADE() {
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Antoni et al., Astroparticle Physics 24, 1 (2005)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2005_QGSJET-01_Etot.txt");
        dataSet.save("output/H_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Antoni et al., Astroparticle Physics 24, 1 (2005)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2005_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/H_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-II-02_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_QGSJET-II-02_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-01_Etot.txt");
        dataSet.save("output/H_KASCADE_2011_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_He_KASCADE_2005_QGSJET-01_Etot.txt");
        dataSet.save("output/He_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_He_KASCADE_2005_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/He_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
}

void KASCADEGrande() {
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_H_KG_SIBYLL-2.3_Etot.txt");
        dataSet.save("output/H_KASCADEGrande_SIBYLL-2.3_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_EPOS-LHC_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_EPOS-LHC_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_QGSJET-II-04_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_QGSJET-II-04_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("KASCADE-Grande Collaboration, ICRC Proc. 301, 316 (2017)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("light");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/KCDC_light_KG_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/light_KASCADEGrande_SIBYLL-2.1_Etot.txt");
    }
}

void NUCLEON() {
    {
        CRDB dataSet("NUCLEON");
        dataSet.set_reference("Grebenyuk et al., AdSpR 64, 2546 (2019)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("H");
        dataSet.set_comments("Table 2");
        dataSet.loadDataset("source/nuclei/CRDB_H_NUCLEON_Etot.txt");
        dataSet.save("output/H_NUCLEON_Etot.txt");
    }
    {
        CRDB dataSet("NUCLEON");
        dataSet.set_reference("Grebenyuk et al., AdSpR 64, 2546 (2019)");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total energy");
        dataSet.set_yType("He");
        dataSet.set_comments("Table 2");
        dataSet.loadDataset("source/nuclei/CRDB_He_NUCLEON_Etot.txt");
        dataSet.save("output/He_NUCLEON_Etot.txt");
    }
}

}  // namespace NUCLEI

#endif  // INCLUDE_NUCLEI_H_
