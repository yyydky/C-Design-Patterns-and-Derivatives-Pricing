//
//  Random2.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef Random2_hpp
#define Random2_hpp
#include "Arrays.hpp"
#include "Normals.hpp"
#include <cstdlib>

class RandomBase{
public:
    RandomBase(unsigned long Dimensionality_);
    inline unsigned long GetDimensionality() const;
    virtual RandomBase* clone() const=0;
    virtual void GetUniforms(MJArray& variates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed)=0;
    virtual void Reset()=0;
    virtual ~RandomBase(){}
    
    virtual void GetGaussians(MJArray& variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const{
    return Dimensionality;
}

#endif /* Random2_hpp */
