// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_ALLPARTICLE_H_
#define INCLUDE_ALLPARTICLE_H_

#include "include/CRDB.h"
#include "include/KCDC.h"
#include "include/mydb.h"

namespace ALLPARTICLE {

void AUGER() {
    MyAllAUGER dataSet;
    dataSet.set_reference("Pierre Auger collaboration, PoS ICRC2019 (2019) 450");
    dataSet.set_source("");
    dataSet.set_url("https://www.auger.org/index.php/science/data");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/mysource_AUGER_Etot.txt");
    dataSet.save("output/allparticle_AUGER_Etot.txt");
}

void HAWC() {
    MyAllHAWC dataSet;
    dataSet.set_reference("HAWC collaboration, Phys.Rev.D (2017) 96");
    dataSet.set_source("");
    dataSet.set_url("");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("from their TABLE IV");
    dataSet.loadDataset("source/allparticle/mysource_HAWC_Etot.txt");
    dataSet.save("output/allparticle_HAWC_Etot.txt");
}

void ICECUBE_ICETOP() {
    KCDC dataSet("ICECUBE-ICETOP");
    dataSet.set_reference("Aartsen et al., Physical Review D, 2019, Volume 100, Issue 8");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("Sibyll-2.1 only");
    dataSet.loadDataset("source/allparticle/KCDC_ICECUBE-ICETOP_SIBYLL-2.1_Etot.txt");
    dataSet.save("output/allparticle_ICECUBE-ICETOP_SIBYLL-2.1_Etot.txt");
}

void KASCADE() {
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Antoni et al., Astroparticle Physics, 24, Issues 1–2, 2005");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KASCADE_2005_QGSJET-01_Etot.txt");
        dataSet.save("output/allparticle_KASCADE_QGSJET-01_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Antoni et al., Astroparticle Physics, 24, Issues 1–2, 2005");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KASCADE_2005_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/allparticle_KASCADE_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Thesis M. Finger");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KASCADE_2011_EPOS-199_Etot.txt");
        dataSet.save("output/allparticle_KASCADE_EPOS-199_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Thesis M. Finger");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KASCADE_2011_QGSJET-II-02_Etot.txt");
        dataSet.save("output/allparticle_KASCADE_QGSJET-II-02_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE");
        dataSet.set_reference("Thesis M. Finger");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KASCADE_2011_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/allparticle_KASCADE_SIBYLL-2.1_Etot.txt");
    }
}

void KASCADEGrande() {
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("pos.sissa.it/236/359/");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KG_EPOS-LHC_Etot.txt");
        dataSet.save("output/allparticle_KASCADEGrande_EPOS-LHC_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("pos.sissa.it/236/359/");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KG_QGSJET-II-04_Etot.txt");
        dataSet.save("output/allparticle_KASCADEGrande_QGSJET-II-04_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("pos.sissa.it/236/359/");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KG_QGSJET-II-02_Etot.txt");
        dataSet.save("output/allparticle_KASCADEGrande_QGSJET-II-02_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("pos.sissa.it/236/359/");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KG_SIBYLL-2.1_Etot.txt");
        dataSet.save("output/allparticle_KASCADEGrande_SIBYLL-2.1_Etot.txt");
    }
    {
        KCDC dataSet("KASCADE-Grande");
        dataSet.set_reference("pos.sissa.it/236/359/");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_KG_SIBYLL-2.3_Etot.txt");
        dataSet.save("output/allparticle_KASCADEGrande_SIBYLL-2.3_Etot.txt");
    }
}

void NUCLEON() {
    CRDB dataSet("NUCLEON");
    dataSet.set_reference("2019AdSpR..64.2546G");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/CRDB_NUCLEON_Etot.txt");
    dataSet.save("output/allparticle_NUCLEON_Etot.txt");
}

void RUNJOB() {
    KCDC dataSet("RUNJOB");
    dataSet.set_reference(
        "RUNJOB Collaboration, APP, Volume 16, Issue 1, October 2001, Pages 13-46");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/KCDC_RUNJOB_Etot.txt");
    dataSet.save("output/allparticle_RUNJOB_Etot.txt");
}

void TALE() {
    KCDC dataSet("TALE");
    dataSet.set_reference("R. U. Abbasi et al 2018 ApJ 865 74");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/KCDC_TALE_Etot.txt");
    dataSet.save("output/allparticle_TALE_Etot.txt");
}

void TELESCOPEARRAY() {
    MyAllTA dataSet;
    dataSet.set_reference("Telescope Array Collaboration, PoS ICRC2017 (2018) 1096");
    dataSet.set_source("");
    dataSet.set_url("https://pos.sissa.it/301/1096");
    dataSet.set_mode("geometrical");
    dataSet.set_xUnits("total Energy");
    dataSet.set_yType("all particle");
    dataSet.set_comments("");
    dataSet.loadDataset("source/allparticle/mysource_TA_Etot.txt");
    dataSet.save("output/allparticle_TA_Etot.txt");
}

void TIBET() {
    {
        MyAllTIBET dataSet("QGSJET+HD");
        dataSet.set_reference("Amenomori et al., The Astrophysical Journal (2008) 678");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_QGSJET+HD_Etot.txt");
    }
    {
        MyAllTIBET dataSet("QGSJET+PD");
        dataSet.set_reference("Amenomori et al., The Astrophysical Journal (2008) 678");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_QGSJET+PD_Etot.txt");
    }
    {
        MyAllTIBET dataSet("SIBYLL+HD");
        dataSet.set_reference("Amenomori et al., The Astrophysical Journal (2008) 678");
        dataSet.set_source("");
        dataSet.set_url("https://iopscience.iop.org/article/10.1086/529514");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("using the column of QGSJET+HD from Table 4");
        dataSet.loadDataset("source/allparticle/mysource_TIBET_Etot.txt");
        dataSet.save("output/allparticle_TIBET_SIBYLL+HD_Etot.txt");
    }
}

void TUNKA() {
    {
        KCDC dataSet("TUNKA");
        dataSet.set_reference("Budnev et al., Astropart.Phys., 117 (2020) 102406");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_TUNKA-133_Etot.txt");
        dataSet.save("output/allparticle_TUNKA-133_Etot.txt");
    }
    {
        KCDC dataSet("TUNKARex");
        dataSet.set_reference("1908.10305");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("total Energy");
        dataSet.set_yType("all particle");
        dataSet.set_comments("");
        dataSet.loadDataset("source/allparticle/KCDC_TUNKARex_Etot.txt");
        dataSet.save("output/allparticle_TUNKA-REX_Etot.txt");
    }
}

}  // namespace ALLPARTICLE

#endif  // INCLUDE_ALLPARTICLE_H_
