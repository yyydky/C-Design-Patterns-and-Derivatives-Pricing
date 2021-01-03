//
//  PayOff2.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#include "PayOff2.hpp"

PayOffCall::PayOffCall(double Strike_): Strike(Strike_){}

PayOffPut::PayOffPut(double Strike_): Strike(Strike_){}

double PayOffCall::operator()(double Spot) const{
    return max(Spot-Strike, 0.0);
}

double PayOffPut::operator()(double Spot) const{
    return max(Strike-Spot, 0.0);
}

