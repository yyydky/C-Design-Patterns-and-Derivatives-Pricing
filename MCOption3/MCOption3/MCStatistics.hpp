//
//  MCStatistics.hpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef MCStatistics_hpp
#define MCStatistics_hpp

#include <vector>
using namespace std;

class StatisticsMC{
public:
    StatisticsMC(){}
    virtual void DumpOneResult(double result) = 0;
    virtual vector<vector<double>> GetResultSoFar() const=0;
    virtual StatisticsMC* clone() const=0;
    virtual ~StatisticsMC(){}
private:
};

class StatisticsMean: public StatisticsMC{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual vector<vector<double>> GetResultSoFar() const;
    virtual StatisticsMC* clone() const;
private:
    double RunningSum;
    unsigned long PathsDone;
};

#endif /* MCStatistics_hpp */
