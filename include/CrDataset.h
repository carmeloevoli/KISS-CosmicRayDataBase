// Copyright 2020 Carmelo Evoli
#ifndef INCLUDE_CRDATASET_H_
#define INCLUDE_CRDATASET_H_

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

class dataPoint {
   public:
    dataPoint(double x, double y, double err_stat_do, double err_stat_up, double err_tot_do,
              double err_tot_up)
        : m_x(x),
          m_y(y),
          m_err_stat_do(err_stat_do),
          m_err_stat_up(err_stat_up),
          m_err_tot_do(err_tot_do),
          m_err_tot_up(err_tot_up) {}

    friend std::ostream& operator<<(std::ostream& os, const dataPoint& data) {
        os << std::setprecision(5) << std::scientific;
        os << data.m_x << " " << data.m_y << " ";
        os << data.m_err_tot_do << " " << data.m_err_tot_up << " ";
        os << data.m_err_stat_do << " " << data.m_err_stat_up << " ";
        return os;
    }

   protected:
    double m_x = 0;
    double m_y = 0;
    double m_err_stat_do = 0;
    double m_err_stat_up = 0;
    double m_err_tot_do = 0;
    double m_err_tot_up = 0;
};

class CrDataset {
   public:
    CrDataset() {}
    virtual ~CrDataset() = default;

    void set_source(std::string str) { m_source = str; }
    void set_doi(std::string str) { m_doi = str; }
    void set_ADSbibcode(std::string str) { m_ads = str; }
    void set_xUnits(std::string str) { m_xUnits = str; }
    void set_yType(std::string str) { m_yType = str; }
    void set_comments(std::string str) { m_comments = str; }
    void set_experimentName(std::string str) { m_experimentName = str; }
    void set_url(std::string str) { m_url = str; }
    void set_mode(std::string str) { m_mode = str; }

    virtual void readfile(std::fstream& infile) = 0;

    void loadDataset(std::string filename);
    void save(std::string filename) const;
    void clean();

   protected:
    std::vector<dataPoint> m_dataTable;
    std::string m_experimentName;
    std::string m_doi;
    std::string m_ads;
    std::string m_source;
    std::string m_url;
    std::string m_mode;
    std::string m_xUnits;
    std::string m_yType;
    std::string m_comments;
};

#endif  // INCLUDE_CRDATASET_H_
