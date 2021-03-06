//
//  DistanceComputer.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "DistanceComputer.h"

#define R 6371
#define TO_RAD (3.1415926536 / 180)

double DistanceComputer::operator()(double th1, double ph1, double th2, double ph2)
{    
    double dx, dy, dz;
    
    ph1 -= ph2;
    
    ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;
    
    dz = sin(th1) - sin(th2);
    
    dx = cos(ph1) * cos(th1) - cos(th2);
    
    dy = sin(ph1) * cos(th1);
    
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}