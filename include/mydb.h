// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_MYDB_H_
#define INCLUDE_MYDB_H_

#include <string>

#include "include/CrDataset.h"

class MyAllAUGER : public CrDataset {
   public:
    MyAllAUGER() { set_experimentName("AUGER"); }
    void readfile(std::fstream& infile) override;
};

class MyAllTA : public CrDataset {
   public:
    MyAllTA() { set_experimentName("Telescope Array"); }
    void readfile(std::fstream& infile) override;
};

class MyAllHAWC : public CrDataset {
   public:
    MyAllHAWC() { set_experimentName("HAWC"); }
    void readfile(std::fstream& infile) override;
};

class MyAllTIBET : public CrDataset {
   public:
    explicit MyAllTIBET(std::string hadmod);
    void readfile(std::fstream& infile) override;

   private:
    enum HADMOD { QGSJETHD, QGSJETPD, SIBYLLHD };
    HADMOD m_hadmod;
};

class MyLightARGO : public CrDataset {
   public:
    MyLightARGO() { set_experimentName("ARGO"); }
    void readfile(std::fstream& infile) override;
};

class MyLeptonVERITAS : public CrDataset {
   public:
    MyLeptonVERITAS() { set_experimentName("VERITAS"); }
    void readfile(std::fstream& infile) override;
};

class MyLeptonHESS : public CrDataset {
   public:
    MyLeptonHESS() { set_experimentName("HESS"); }
    void readfile(std::fstream& infile) override;
};

#endif  // INCLUDE_MYDB_H_
