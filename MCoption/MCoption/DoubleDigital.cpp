//
//  DoubleDigital.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#include "DoubleDigital.hpp"

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double UpperLevel_):
LowerLevel(LowerLevel_), UpperLevel(UpperLevel_){}


double PayOffDoubleDigital::operator()(double Spot) const{
    if ((Spot <= LowerLevel) || (Spot >= UpperLevel)) return 0;
    return 1;
}

