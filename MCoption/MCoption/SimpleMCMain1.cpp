//
//  main.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-02.
//

#include <iostream>
#include "Random1.hpp"
#include <cmath>
using namespace std;
//https://zhuanlan.zhihu.com/p/134759744
//https://zhuanlan.zhihu.com/p/125633858

double SimpleMonteCarlo1(double Expiry,
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
    
    double result = SimpleMonteCarlo1(Expiry,
                                      Strike,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);
    cout << "the price is " << result << endl;
}
