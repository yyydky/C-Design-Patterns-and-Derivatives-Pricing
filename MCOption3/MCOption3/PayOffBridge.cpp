//
//  PayOffBridge.cpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-04.
//

#include "PayOffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original){
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff){
    ThePayOffPtr = innerPayOff.clone();
}

//inline double operator()(double Spot) const;
PayOffBridge::~PayOffBridge(){
    delete ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original){
    if(this != &original){
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}
