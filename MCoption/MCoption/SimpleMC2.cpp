//
//  SimpleMC.cpp
//  MCoption
//
//  Created by 一帆朱 on 2021-01-03.
//

#include "SimpleMC2.hpp"
#include <memory>

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
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
        double thisPayoff = thePayOff(thisSpot);
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}
