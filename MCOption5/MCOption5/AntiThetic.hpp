//
//  AntiThetic.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-06.
//

#ifndef AntiThetic_hpp
#define AntiThetic_hpp

#include "Random2.hpp"
#include "Wrapper.hpp"

class AntiThetic: public RandomBase{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator);
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long Newdimensionality);
    virtual void Reset();
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
};

#endif /* AntiThetic_hpp */
