//
//  SimpleMC8.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-06.
//

#ifndef SimpleMC8_hpp
#define SimpleMC8_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "Random2.hpp"
#include "MCStatistics.hpp"
#include "Arrays.hpp"
#include <cmath>
using namespace std;

void SimpleMonteCarlo7(
                       const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator);

#endif /* SimpleMC8_hpp */

