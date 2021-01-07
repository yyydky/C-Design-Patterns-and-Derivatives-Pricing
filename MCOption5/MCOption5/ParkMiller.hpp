//
//  ParkMiller.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-06.
//

#ifndef ParkMiller_hpp
#define ParkMiller_hpp

#include "Random2.hpp"
#include "Arrays.hpp"

class ParkMiller{
public:
    ParkMiller(long seed = 1);
    long GetOneRandomInteger();
    void SetSeed(long Seed);
    static unsigned long Max();
    static unsigned long Min();
private:
    long Seed;
};

class  RandomParkMiller: public RandomBase{
public:
    RandomParkMiller(unsigned long Dimensionality, unsigned long seed=1);
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality);
private:
    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal;
};

#endif /* ParkMiller_hpp */
