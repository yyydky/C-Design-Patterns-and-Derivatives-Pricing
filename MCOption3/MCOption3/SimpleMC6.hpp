//
//  SimpleMC6.hpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef SimpleMC6_hpp
#define SimpleMC6_hpp

#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include "Random1.hpp"
#include <cmath>
using namespace std;

double SimpleMonteCarlo5(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths);

#endif /* SimpleMC6_hpp */
