//
//  Vanilla1.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#include "Vanilla1.hpp"

VanillaOption::VanillaOption(PayOff& ThePayOff_, double Expiry_):
ThePayOff(ThePayOff_), Expiry(Expiry_){}

double VanillaOption::GetExpiry() const{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const{
    return ThePayOff(Spot);
}
