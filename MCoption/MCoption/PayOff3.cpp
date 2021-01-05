//
//  PayOff3.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#include "PayOff3.hpp"

PayOffCall::PayOffCall(double Strike_): Strike(Strike_){}

double PayOffCall::operator()(double Spot) const{
    return max(Spot-Strike, 0.0);
}

PayOff* PayOffCall::clone() const{
    return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double Strike_): Strike(Strike_){}

double PayOffPut::operator()(double Spot) const{
    return max(Strike-Spot, 0.0);
}

PayOff* PayOffPut::clone() const{
    return new PayOffPut(*this);
}

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double UpperLevel_):
LowerLevel(LowerLevel_), UpperLevel(UpperLevel_){}

double PayOffDoubleDigital::operator()(double Spot) const{
    if ((Spot <= LowerLevel) || (Spot >= UpperLevel)) return 0;
    return 1;
}

PayOff* PayOffDoubleDigital::clone() const{
    return new PayOffDoubleDigital(*this);
}
