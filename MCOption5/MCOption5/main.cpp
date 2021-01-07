//
//  StatsMain1.cpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "SimpleMC8.hpp"
#include "ParkMiller.hpp"
#include "Vanilla3.hpp"
#include "MCStatistics.hpp"
#include "ConvergenceTable.hpp"
#include "AntiThetic.hpp"
#include <iostream>
using namespace std;

int main(){
    double Expiry = 0.15890411;
    double Strike = 230;
    double Spot = 276.10;
    double Vol = 0.407530933;
    double r = 0.0016;
    unsigned long NumberOfPaths = 1000000;
    double Low = 220;
    double Up = 240;
    
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);
    PayOffDoubleDigital thePayOff(Low, Up);
    VanillaOption theOption(thePayOff, Expiry);
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    ConvergenceTable gethererTwo(gatherer);

    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);
    
    SimpleMonteCarlo7(theOption,
                      Spot,
                      VolParam,
                      rParam,
                      NumberOfPaths,
                      gethererTwo,
                      GenTwo);
    
    vector<vector<double>> result = gethererTwo.GetResultSoFar();
    cout << "For the call price the results are" << endl;
    for(unsigned long i=0; i < result.size(); i++){
        for(unsigned long j=0; j < result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}

