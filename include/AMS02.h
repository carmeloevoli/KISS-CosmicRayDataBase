#ifndef INCLUDE_AMS02_H_
#define INCLUDE_AMS02_H_

#include "SSDC.h"
#include "mydb.h"

namespace ALLAMS02 {

void ratios() {
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("He/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_HeO_AMS-02_R.txt");
        dataSet.save("output/HeO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Li/B");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_LiB_AMS-02_R.txt");
        dataSet.save("output/LiB_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Li/C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_LiC_AMS-02_R.txt");
        dataSet.save("output/LiC_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Li/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_LiO_AMS-02_R.txt");
        dataSet.save("output/LiO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Be/B");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BeB_AMS-02_R.txt");
        dataSet.save("output/BeB_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Be/C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BeC_AMS-02_R.txt");
        dataSet.save("output/BeC_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Be/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BeO_AMS-02_R.txt");
        dataSet.save("output/BeO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B/C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BC_AMS-02_R.txt");
        dataSet.save("output/BC_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BO_AMS-02_R.txt");
        dataSet.save("output/BO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("C/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_CO_AMS-02_R.txt");
        dataSet.save("output/CO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("N/B");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_NB_AMS-02_R.txt");
        dataSet.save("output/NB_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("N/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_NO_AMS-02_R.txt");
        dataSet.save("output/NO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.081102");
        dataSet.set_ADSbibcode(" ");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("F/B");
        dataSet.set_comments("2021PhRvL.126h1102A");
        dataSet.loadDataset("source/nuclei/SSDC_FB_AMS-02_R.txt");
        dataSet.save("output/FB_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.081102");
        dataSet.set_ADSbibcode(" ");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("F/Si");
        dataSet.set_comments("2021PhRvL.126h1102A");
        dataSet.loadDataset("source/nuclei/SSDC_FSi_AMS-02_R.txt");
        dataSet.save("output/FSi_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Ne/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_NeO_AMS-02_R.txt");
        dataSet.save("output/NeO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Ne/Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_NeMg_AMS-02_R.txt");
        dataSet.save("output/NeMG_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Mg/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_MgO_AMS-02_R.txt");
        dataSet.save("output/MgO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Si/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_SiO_AMS-02_R.txt");
        dataSet.save("output/SiO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Si/Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_SiMg_AMS-02_R.txt");
        dataSet.save("output/SiMg_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.041104");
        dataSet.set_ADSbibcode("2021PhRvL.126d1104A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Fe/He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_FeHe_AMS-02_R.txt");
        dataSet.save("output/FeHe_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.041104");
        dataSet.set_ADSbibcode("2021PhRvL.126d1104A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Fe/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_FeO_AMS-02_R.txt");
        dataSet.save("output/FeO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.041104");
        dataSet.set_ADSbibcode("2021PhRvL.126d1104A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Fe/Si");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_FeSi_AMS-02_R.txt");
        dataSet.save("output/FeSi_AMS-02_R.txt");
    }
}

void fluxes() {
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("H");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_H_AMS-02_R.txt");
        dataSet.save("output/H_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("He");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_He_AMS-02_R.txt");
        dataSet.save("output/He_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Li");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Li_AMS-02_R.txt");
        dataSet.save("output/Li_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Be");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Be_AMS-02_R.txt");
        dataSet.save("output/Be_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_B_AMS-02_R.txt");
        dataSet.save("output/B_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_C_AMS-02_R.txt");
        dataSet.save("output/C_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("N");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_N_AMS-02_R.txt");
        dataSet.save("output/N_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1016/j.physrep.2020.09.003");
        dataSet.set_ADSbibcode("2021PhR...894....1A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_O_AMS-02_R.txt");
        dataSet.save("output/O_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.081102");
        dataSet.set_ADSbibcode("2021PhRvL.126h1102A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("F");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_F_AMS-02_R.txt");
        dataSet.save("output/F_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("110.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Ne");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Ne_AMS-02_R.txt");
        dataSet.save("output/Ne_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("110.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Mg");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Mg_AMS-02_R.txt");
        dataSet.save("output/Mg_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("110.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Si");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Si_AMS-02_R.txt");
        dataSet.save("output/Si_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.126.041104");
        dataSet.set_ADSbibcode("2021PhRvL.126d1104A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Fe");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_Fe_AMS-02_R.txt");
        dataSet.save("output/Fe_AMS-02_R.txt");
    }
}

}  // namespace ALLAMS02

#endif
