//
//  Vanilla1.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef Vanilla1_hpp
#define Vanilla1_hpp

#include "PayOff2.hpp"

class VanillaOption{
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
    
private:
    double Expiry;
    PayOff& ThePayOff;
};

#endif /* Vanilla1_hpp */
