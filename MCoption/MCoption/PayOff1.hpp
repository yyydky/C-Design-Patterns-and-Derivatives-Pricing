//
//  PayOff1.hpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#ifndef PayOff1_hpp
#define PayOff1_hpp
#include <algorithm>
using namespace std;

class PayOff{
public:
    enum OptionType{call, put, digital};
    PayOff(double Strike_, OptionType TheOptionsType_);
    //given a value of spot, it returns the value of the payoff
    double operator()(double Spot) const;//can call on a const obj
    
private:
    double Strike;
    OptionType TheOptionsType;
};

#endif /* PayOff1_hpp */
