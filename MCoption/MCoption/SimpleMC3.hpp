//
//  SimpleMC3.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef SimpleMC3_hpp
#define SimpleMC3_hpp

#include "Vanilla1.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);
#endif /* SimpleMC3_hpp */
