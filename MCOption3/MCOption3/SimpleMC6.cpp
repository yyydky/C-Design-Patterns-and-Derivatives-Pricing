//
//  SimpleMC6.cpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "SimpleMC6.hpp"

double SimpleMonteCarlo5(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths){
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance; // ito's lemma
    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    for(unsigned long i = 0; i < NumberOfPaths; i++){
        double thisGuassian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGuassian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r.Integral(0, Expiry));
    return mean;
}
