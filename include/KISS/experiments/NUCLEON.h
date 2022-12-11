#ifndef KISS_EXPERIMENTS_NUCLEON_H_
#define KISS_EXPERIMENTS_NUCLEON_H_

#include "KISS/CRDB.h"

namespace NUCLEON {

void run() {
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::allParticle, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::H, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::He, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::C, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::O, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::Ne, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::Mg, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::Si, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
    {
        KISS::CRDB data(KISS::nucleon, KISS::totalEnergy, KISS::Fe, KISS::geometrical);
        data.setDOI("10.1016/j.asr.2019.10.004");
        data.setADSbibcode("2019AdSpR..64.2546G");
        data.setComments("From Table 2");
        data.run();
    }
}

}  // namespace NUCLEON

#endif