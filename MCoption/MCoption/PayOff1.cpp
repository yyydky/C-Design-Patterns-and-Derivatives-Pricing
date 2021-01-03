//
//  PayOff1.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#include "PayOff1.hpp"

PayOff::PayOff(double Strike_, OptionType TheOptionsType_):
Strike(Strike_), TheOptionsType(TheOptionsType_){}

double PayOff::operator()(double Spot) const{
    switch(TheOptionsType){
        case call:
            return max(Spot-Strike, 0.0);
        case put:
            return max(Strike-Spot, 0.0);
        case digital:
            return Strike-Spot > 0 ? 1 : 0;
        default:
            throw("unknown option type found.");
    }
}
