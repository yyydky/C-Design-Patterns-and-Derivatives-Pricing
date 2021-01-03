//
//  SimpleMC.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef SimpleMC_hpp
#define SimpleMC_hpp
#include "PayOff1.hpp"
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
