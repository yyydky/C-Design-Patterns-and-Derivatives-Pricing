//
//  SimpleMC7.cpp
//  MCOption3
//
//  Created by 一帆朱 on 2021-01-05.
//

#include "SimpleMC7.hpp"

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer){
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance; // ito's lemma
    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));
    for(unsigned long i = 0; i < NumberOfPaths; i++){
        double thisGuassian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGuassian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff*discounting);
    }
    return ;
}
