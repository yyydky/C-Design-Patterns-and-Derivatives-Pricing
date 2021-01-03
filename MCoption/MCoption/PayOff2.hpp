//
//  PayOff2.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef PayOff2_hpp
#define PayOff2_hpp

#include <algorithm>
using namespace std;

class PayOff{
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
private:
};

class PayOffCall : public PayOff{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
private:
    double Strike;
};

class PayOffPut : public PayOff{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
private:
    double Strike;
};

#endif /* PayOff2_hpp */
