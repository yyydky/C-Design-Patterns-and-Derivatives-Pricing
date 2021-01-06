//
//  Vanilla2.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#include "Vanilla3.hpp"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_): ThePayOffPtr(ThePayOff_), Expiry(Expiry_){
//    Expiry = Expiry_;
//    ThePayOffPtr = ThePayOff_.clone();
}


double VanillaOption::GetExpiry() const{
    return Expiry;
}
double VanillaOption::OptionPayOff(double Spot) const{
    return (ThePayOffPtr)(Spot);
}
