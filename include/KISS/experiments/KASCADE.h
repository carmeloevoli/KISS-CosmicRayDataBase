#ifndef KISS_EXPERIMENTS_KASCADE_H_
#define KISS_EXPERIMENTS_KASCADE_H_

#include "KISS/KCDC.h"

namespace KASCADE {

void run() {
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2005_QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2005_SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_EPOS-199");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_QGSJET-II-02");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_SIBYLL-2.1");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::allParticle, KISS::unknown);
        data.setDescription("2011_QGSJET-01");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2005_QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();  // ("source/nuclei/KCDC_H_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2005_SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();  // ("source/nuclei/KCDC_H_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_QGSJET-II-02");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();  // ("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-II-02_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_SIBYLL-2.1");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();  // ("source/nuclei/KCDC_H_KASCADE_2011_SIBYLL-2.1_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::H, KISS::unknown);
        data.setDescription("2011_QGSJET-01");
        data.setComments("From Marcel Finger PhD Thesis");
        data.run();  // ("source/nuclei/KCDC_H_KASCADE_2011_QGSJET-01_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::He, KISS::unknown);
        data.setDescription("2005_QGSJET-01");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();  // ("source/nuclei/KCDC_He_KASCADE_2005_QGSJET-01_Etot.txt");
    }
    {
        KISS::KCDC data(KISS::kascade, KISS::totalEnergy, KISS::He, KISS::unknown);
        data.setDescription("2005_SIBYLL-2.1");
        data.setDOI("10.1016/j.astropartphys.2005.04.001");
        data.setADSbibcode("2005APh....24....1A");
        data.run();  //  ("source/nuclei/KCDC_He_KASCADE_2005_SIBYLL-2.1_Etot.txt");
    }
}

}  // namespace KASCADE

#endif  // KISS_EXPERIMENTS_KASCADE_H_