//
//  Arrays.cpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-06.
//

#include "Arrays.hpp"
#include <algorithm>
#include <numeric>
using namespace std;

MJArray::MJArray(unsigned long size): Size(size), Capacity(size){
    if(Size>0){
        ValuesPtr = new double[size];
        EndPtr = ValuesPtr;
        EndPtr += size;
    }else{
        ValuesPtr=nullptr;
        EndPtr=nullptr;
    }
}

MJArray::MJArray(const MJArray& original): Size(original.Size), Capacity(original.Size){
    if(Size>0){
        ValuesPtr = new double[Size];
        EndPtr = ValuesPtr;
        EndPtr += Size;
        copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
    }else{
        ValuesPtr=EndPtr=nullptr;
    }
}

MJArray::~MJArray(){
    if(!ValuesPtr)
        delete [] ValuesPtr;
}

MJArray& MJArray::operator=(const MJArray& original){
    if(&original==this) return *this;
    if(original.Size>Capacity){
        if(Capacity>0) delete [] ValuesPtr;
        ValuesPtr=new double [original.Size];
        Capacity=original.Size;
    }
    Size=original.Size;
    EndPtr=ValuesPtr;
    EndPtr+=Size;
    copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
    return *this;
}

MJArray& MJArray::operator=(const double& val){
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i] = val;
    return *this;
}

void MJArray::resize(unsigned long newSize){
    if(newSize>Capacity){
        if(Capacity>0) delete [] ValuesPtr;
        ValuesPtr=new double [newSize];
        Capacity=newSize;
    }
    Size=newSize;
    EndPtr=ValuesPtr+Size;
}

MJArray& MJArray::operator+=(const MJArray& operand){
#ifdef RANGE_CHECKING
    if(Size!=operand.size()){
        throw("to apply += two arrays must be of same size");
    }
#endif
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]+=operand[i];
    return *this;
}

MJArray& MJArray::operator-=(const MJArray& operand){
#ifdef RANGE_CHECKING
    if(Size!=operand.size()){
        throw("to apply -= two arrays must be of same size");
    }
#endif
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]-=operand[i];
    return *this;
}

MJArray& MJArray::operator/=(const MJArray& operand){
#ifdef RANGE_CHECKING
    if(Size!=operand.size()){
        throw("to apply /= two arrays must be of same size");
    }
#endif
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]/=operand[i];
    return *this;
}

MJArray& MJArray::operator*=(const MJArray& operand){
#ifdef RANGE_CHECKING
    if(Size!=operand.size()){
        throw("to apply *= two arrays must be of same size");
    }
#endif
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]*=operand[i];
    return *this;
}

MJArray& MJArray::operator+=(const double& operand){
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]+=operand;
    return *this;
}

MJArray& MJArray::operator-=(const double& operand){
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]-=operand;
    return *this;
}

MJArray& MJArray::operator/=(const double& operand){
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]/=operand;
    return *this;
}

MJArray& MJArray::operator*=(const double& operand){
    for(unsigned long i = 0; i < Size; i++)
        ValuesPtr[i]*=operand;
    return *this;
}

double MJArray::sum() const{
    return accumulate(ValuesPtr, EndPtr, 0.0);
}

double MJArray::min() const{
#ifdef RANGE_CHECKING
    if(Size==0){
        throw("cannot take min of empty array");
    }
#endif
    double* tmp = ValuesPtr;
    double* endTmp = EndPtr;
    return *min_element(tmp, endTmp);
}

double MJArray::max() const{
#ifdef RANGE_CHECKING
    if(Size==0){
        throw("cannot take max of empty array");
    }
#endif
    double* tmp = ValuesPtr;
    double* endTmp = EndPtr;
    return *max_element(tmp, endTmp);
}

MJArray MJArray::apply(double f(double)) const{
    MJArray result(size());
    transform(ValuesPtr, EndPtr, result.ValuesPtr, f);
    return result;
}
