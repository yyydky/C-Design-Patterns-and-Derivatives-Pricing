//
//  SimpleMC.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef SimpleMC2_hpp
#define SimpleMC2_hpp
#include "PayOff2.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif /* SimpleMC_hpp */
