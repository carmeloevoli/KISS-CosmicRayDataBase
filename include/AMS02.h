#ifndef INCLUDE_AMS02_H_
#define INCLUDE_AMS02_H_

#include "SSDC.h"

namespace ALLAMS02 {

void ratios() {
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B/C");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BC_AMS-02_R.txt");
        dataSet.save("output/BC_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_BO_AMS-02_R.txt");
        dataSet.save("output/BO_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.119.251101");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("geometrical");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("C/O");
        dataSet.set_comments("");
        dataSet.loadDataset("source/nuclei/SSDC_CO_AMS-02_R.txt");
        dataSet.save("output/CO_AMS-02_R.txt");
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
}

void fluxes() {
     {
       SSDC dataSet("AMS-02");
       dataSet.set_doi("10.1103/PhysRevLett.114.171103");
       dataSet.set_ADSbibcode("2015PhRvL.114q1103A");
       dataSet.set_mode("Lafferty2.7");
       dataSet.set_xUnits("rigidity(original)");
       dataSet.set_yType("H");
       dataSet.set_comments("Z=1");
       dataSet.loadDataset("source/nuclei/SSDC_H_AMS-02_R.txt");
       dataSet.save("output/H_AMS-02_R.txt");
     }
     {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.119.251101");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("He");
        dataSet.set_comments("Z=2");
        dataSet.loadDataset("source/nuclei/SSDC_He_AMS-02_R.txt");
        dataSet.save("output/He_AMS-02_R.txt");
     }
     {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Li");
        dataSet.set_comments("Z=3");
        dataSet.loadDataset("source/nuclei/SSDC_Li_AMS-02_R.txt");
        dataSet.save("output/Li_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Be");
        dataSet.set_comments("Z=4");
        dataSet.loadDataset("source/nuclei/SSDC_Be_AMS-02_R.txt");
        dataSet.save("output/Be_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.120.021101");
        dataSet.set_ADSbibcode("2018PhRvL.120b1101A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("B");
        dataSet.set_comments("Z=5");
        dataSet.loadDataset("source/nuclei/SSDC_B_AMS-02_R.txt");
        dataSet.save("output/B_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.119.251101");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("C");
        dataSet.set_comments("Z=6");
        dataSet.loadDataset("source/nuclei/SSDC_C_AMS-02_R.txt");
        dataSet.save("output/C_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.121.051103");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("N");
        dataSet.set_comments("Z=7");
        dataSet.loadDataset("source/nuclei/SSDC_N_AMS-02_R.txt");
        dataSet.save("output/N_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("10.1103/PhysRevLett.119.251101");
        dataSet.set_ADSbibcode("");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("O");
        dataSet.set_comments("Z=8");
        dataSet.loadDataset("source/nuclei/SSDC_O_AMS-02_R.txt");
        dataSet.save("output/O_AMS-02_R.txt");
    }
    {
        SSDC dataSet("AMS-02");
        dataSet.set_doi("110.1103/PhysRevLett.124.211102");
        dataSet.set_ADSbibcode("2020PhRvL.124u1102A");
        dataSet.set_mode("Lafferty2.7");
        dataSet.set_xUnits("rigidity(original)");
        dataSet.set_yType("Ne");
        dataSet.set_comments("Z=10");
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
        dataSet.set_comments("Z=12");
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
        dataSet.set_comments("Z=14");
        dataSet.loadDataset("source/nuclei/SSDC_Si_AMS-02_R.txt");
        dataSet.save("output/Si_AMS-02_R.txt");
    }
}

}  // namespace ALLAMS02

#endif
