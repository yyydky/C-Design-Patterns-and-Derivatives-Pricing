//
//  Random2.cpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "Random2.hpp"

void RandomBase::GetGaussians(MJArray& variates){
    GetUniforms(variates);
    for(unsigned long i = 0; i < Dimensionality; i++){
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality){
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_): Dimensionality(Dimensionality_){}

