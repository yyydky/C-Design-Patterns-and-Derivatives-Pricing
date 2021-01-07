//
//  SimpleMC8.cpp
//  MCOption5
//
//  Created by 一帆朱 on 2021-01-06.
//

#include "SimpleMC8.hpp"

void SimpleMonteCarlo7(
                       const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gatherer,
                       RandomBase& generator){
    generator.ResetDimensionality(1);
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance; // ito's lemma
    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));
    MJArray VariateArray(1);
    
    for(unsigned long i = 0; i < NumberOfPaths; i++){
        generator.GetGaussians(VariateArray);
        thisSpot = movedSpot * exp(rootVariance * VariateArray[0]);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff*discounting);
    }
    return ;
}
