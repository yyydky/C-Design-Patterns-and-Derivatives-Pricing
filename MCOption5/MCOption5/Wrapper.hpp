//
//  Wrapper.hpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-05.
//

#ifndef Wrapper_hpp
#define Wrapper_hpp

template<class T>
class Wrapper{
public:
    Wrapper(){
        DataPtr=0;
    }
    Wrapper(const T& inner){
        DataPtr = inner.clone();
    }
    ~Wrapper(){
        if(DataPtr != 0)
            delete DataPtr;
    }
    Wrapper(const Wrapper<T>& original){
        DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone(): 0;
    }
    Wrapper& operator=(const Wrapper<T>& original){
        if(this != &original){
            if(DataPtr != 0) delete DataPtr;
            DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone(): 0;
            return *this;
        }
    }
    T& operator*(){
        return *DataPtr;
    }
    const T& operator*() const{
        return *DataPtr;
    }
    const T* operator->() const{
        return DataPtr;
    }
    T* operator->() {
        return DataPtr;
    }
    T* clone() const{
        return this->clone();
    }
private:
    T* DataPtr;
};

#endif /* Wrapper_hpp */
