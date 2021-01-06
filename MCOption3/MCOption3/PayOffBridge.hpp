//
//  PayOffBridge.hpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-04.
//

#ifndef PayOffBridge_hpp
#define PayOffBridge_hpp

#include "PayOff3.hpp"
class PayOffBridge{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const{
    return ThePayOffPtr->operator ()(Spot);
}

#endif /* PayOffBridge_hpp */
