//
//  MCStatistics.cpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "MCStatistics.hpp"

StatisticsMean::StatisticsMean(): RunningSum(0.0), PathsDone(0UL){}//unsigned long with value 0

void StatisticsMean::DumpOneResult(double result){
    PathsDone++;
    RunningSum += result;
}

vector<vector<double>> StatisticsMean::GetResultSoFar() const{
    vector<vector<double>> Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSum/PathsDone;
    return Results;
}

StatisticsMC* StatisticsMean::clone() const{
    return new StatisticsMean(*this);
}
