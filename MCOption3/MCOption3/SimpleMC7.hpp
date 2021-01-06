//
//  SimpleMC7.hpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef SimpleMC7_hpp
#define SimpleMC7_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "MCStatistics.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer);

#endif /* SimpleMC7_hpp */
