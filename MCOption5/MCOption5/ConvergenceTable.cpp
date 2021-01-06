//
//  ConvergenceTable.cpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "ConvergenceTable.hpp"

//ConvergenceTable(const Wrapper<StatisticsMC> & Inner_);
//virtual StatisticsMC* clone() const;
//virtual void DumpOneResult(double result);
//virtual vector<vector<double>> GetResultsSoFar() const;

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC> & Inner_):
Inner(Inner_), StoppingPoint(2), PathsDone(0){}

//need to implement all base class' pure virtual methods
StatisticsMC* ConvergenceTable::clone() const{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result){
    Inner->DumpOneResult(result);
    ++PathsDone;
    if(PathsDone == StoppingPoint){
        StoppingPoint*=2;
        vector<vector<double>> thisResult(Inner->GetResultSoFar());
        for(unsigned long i = 0; i < thisResult.size(); i++){
            thisResult[i].push_back(PathsDone);
            ResultsSoFar.push_back(thisResult[i]);
        }
    }
    return;
}

vector<vector<double>> ConvergenceTable::GetResultSoFar() const{
    vector<vector<double>>tmp(ResultsSoFar);
    if(PathsDone != StoppingPoint){
        vector<vector<double>> thisResult(Inner->GetResultSoFar());
        for(unsigned long i = 0; i < thisResult.size(); i++){
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }
    }
    return tmp;
}
