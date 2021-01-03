//
//  DoubleDigital.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef DoubleDigital_hpp
#define DoubleDigital_hpp
#include "PayOff2.hpp"

class PayOffDoubleDigital: public PayOff{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    
private:
    double LowerLevel;
    double UpperLevel;
};

#endif /* DoubleDigital_hpp */
