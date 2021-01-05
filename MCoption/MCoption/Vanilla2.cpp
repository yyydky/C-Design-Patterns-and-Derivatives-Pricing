//
//  Vanilla2.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#include "Vanilla2.hpp"

VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_): ThePayOffPtr(ThePayOff_.clone()), Expiry(Expiry_){
//    Expiry = Expiry_;
//    ThePayOffPtr = ThePayOff_.clone();
}

VanillaOption::VanillaOption(const VanillaOption& original){
    Expiry = original.Expiry;
    ThePayOffPtr = original.ThePayOffPtr->clone();
}
VanillaOption& VanillaOption::operator=(const VanillaOption& original){
    if(this != & original){
        Expiry = original.Expiry;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}

VanillaOption::~VanillaOption(){
    delete ThePayOffPtr;
}

double VanillaOption::GetExpiry() const{
    return Expiry;
}
double VanillaOption::OptionPayOff(double Spot) const{
    return (*ThePayOffPtr)(Spot);
}
