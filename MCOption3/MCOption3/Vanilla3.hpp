//
//  Vanilla2.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#ifndef Vanilla2_hpp
#define Vanilla2_hpp

#include "PayOffBridge.hpp"

class VanillaOption{
public:
    VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    PayOffBridge ThePayOffPtr;
};

#endif /* Vanilla2_hpp */
