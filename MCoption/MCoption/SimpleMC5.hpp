//
//  SimpleMC4.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#ifndef SimpleMC5_hpp
#define SimpleMC5_hpp

#include "Vanilla3.hpp"
#include "Random1.hpp"
#include "PayOffBridge.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo4(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif /* SimpleMC4_hpp */
