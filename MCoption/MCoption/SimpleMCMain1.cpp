//
//  main.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-02.
//

#include <iostream>
#include "Random1.hpp"
//#include "SimpleMC.hpp"
#include "SimpleMC2.hpp"
#include "DoubleDigital.hpp"
#include <cmath>
using namespace std;
//https://zhuanlan.zhihu.com/p/134759744
//https://zhuanlan.zhihu.com/p/125633858

double SimpleMonteCarlo(double Expiry,
                         double Strike,
                         double Spot,
                         double Vol,
                         double r, // a riskless bond, B, grows at a continuously compounding rate r
                         unsigned long NumberOfPaths){
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance; // ito's lemma
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    for(unsigned long i = 0; i < NumberOfPaths; i++){
        double thisGuassian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGuassian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}

int main(int argc, const char * argv[]) {
    //call
    double Expiry = 0.15890411;
    double Strike = 230;
    double Spot = 276.10;
    double Vol = 0.407530933;
    double r = 0.0016;
    unsigned long NumberOfPaths = 1000000;
    double Low = 220;
    double Up = 240;
    //version 1
//    double result = SimpleMonteCarlo1(Expiry,
//                                      Strike,
//                                      Spot,
//                                      Vol,
//                                      r,
//                                      NumberOfPaths);
    
    //version 2
//    PayOff callPayOff(Strike, PayOff::call);
//    PayOff putPayOff(Strike, PayOff::put);
//
//    double resultCall = SimpleMonteCarlo2(callPayOff,
//                                          Expiry,
//                                          Spot,
//                                          Vol,
//                                          r,
//                                          NumberOfPaths);
//    double resultPut = SimpleMonteCarlo2(putPayOff,
//                                         Expiry,
//                                         Spot,
//                                         Vol,
//                                         r,
//                                         NumberOfPaths);
//    cout << "the call price is " << resultCall << endl;
//    cout << "the put price is " << resultPut << endl;
    
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);
    PayOffDoubleDigital thePayOff(Low, Up);
    
    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);
    double resultDD = SimpleMonteCarlo2(thePayOff,
                                        Expiry,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);
    cout << "the call price is " << resultCall << endl;
    cout << "the put price is " << resultPut << endl;
    cout << "the double digit price is " << resultDD << endl;
    
}
