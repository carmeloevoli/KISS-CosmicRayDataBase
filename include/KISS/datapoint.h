// Copyright 2020 Carmelo Evoli - MIT License
#ifndef KISS_INCLUDE_DATAPOINT_H_
#define KISS_INCLUDE_DATAPOINT_H_

namespace KISS {

using Pair = std::pair<double, double>;

class dataPoint {
   public:
    dataPoint(Pair point, Pair errStat, Pair errSys) : m_point(point), m_errStat(errStat), m_errSys(errSys) {}

    friend std::ostream& operator<<(std::ostream& os, const dataPoint& data) {
        os << std::setprecision(3) << std::scientific;
        os << data.m_point.first << " " << data.m_point.second << " ";
        os << data.m_errStat.first << " " << data.m_errStat.second << " ";
        os << data.m_errSys.first << " " << data.m_errSys.second << " ";
        return os;
    }

   protected:
    Pair m_point;
    Pair m_errStat;
    Pair m_errSys;
};

}  // namespace KISS

#endif  // KISS_INCLUDE_DATAPOINT_H