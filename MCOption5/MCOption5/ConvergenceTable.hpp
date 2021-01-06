//
//  ConvergenceTable.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef ConvergenceTable_hpp
#define ConvergenceTable_hpp

#include "Wrapper.hpp"
#include "MCStatistics.hpp"
#include <vector>
using namespace std;

class ConvergenceTable: public StatisticsMC{
public:
    ConvergenceTable(const Wrapper<StatisticsMC> & Inner_);
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual vector<vector<double>> GetResultSoFar() const;
private:
    Wrapper<StatisticsMC> Inner;
    vector<vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif /* ConvergenceTable_hpp */
