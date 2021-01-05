//
//  PayOff3.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-04.
//

#ifndef PayOff3_hpp
#define PayOff3_hpp

#include<algorithm>
using namespace std;
 
class PayOff{
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const = 0;
private:
};

class PayOffCall: public PayOff{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffPut: public PayOff{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffDoubleDigital: public PayOff{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    virtual PayOff* clone() const;
    
private:
    double LowerLevel;
    double UpperLevel;
};

#endif /* PayOff3_hpp */
