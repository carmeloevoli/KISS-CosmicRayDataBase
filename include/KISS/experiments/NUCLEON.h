#ifndef KISS_EXPERIMENTS_NUCLEON_H_
#define KISS_EXPERIMENTS_NUCLEON_H_

#include "KISS/CRDB.h"

namespace NUCLEON {

void run() {
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.run();  // ("source/allparticle/CRDB_NUCLEON_Etot.txt");
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();  // ("source/nuclei/CRDB_H_NUCLEON_Etot.txt");
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();  // ("source/nuclei/CRDB_He_NUCLEON_Etot.txt");
    }
}

}  // namespace NUCLEON

#endif