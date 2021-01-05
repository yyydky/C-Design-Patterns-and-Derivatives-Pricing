//
//  Vanilla2.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#ifndef Vanilla2_hpp
#define Vanilla2_hpp

#include "PayOff3.hpp"

class VanillaOption{
public:
    VanillaOption(const PayOff& ThePayOff_, double Expiry_);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption& original);
    ~VanillaOption();
    
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    PayOff* ThePayOffPtr;
};

#endif /* Vanilla2_hpp */
