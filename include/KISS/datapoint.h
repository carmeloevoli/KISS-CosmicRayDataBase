// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_DATAPOINT_H_
#define KISS_INCLUDE_DATAPOINT_H_

namespace KISS {

class dataPoint {
   public:
    dataPoint(std::pair<double, double> point, std::pair<double, double> errStat, std::pair<double, double> errTotal)
        : m_point(point), m_errStat(errStat), m_errTotal(errTotal) {}

    friend std::ostream& operator<<(std::ostream& os, const dataPoint& data) {
        os << std::setprecision(3) << std::scientific;
        os << data.m_point.first << " " << data.m_point.second << " ";
        os << data.m_errTotal.first << " " << data.m_errTotal.second << " ";
        os << data.m_errStat.first << " " << data.m_errStat.second << " ";
        return os;
    }

   protected:
    std::pair<double, double> m_point;
    std::pair<double, double> m_errStat;
    std::pair<double, double> m_errTotal;
};

}  // namespace KISS

#endif  // KISS_INCLUDE_DATAPOINT_H