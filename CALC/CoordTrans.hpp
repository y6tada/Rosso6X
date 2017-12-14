//
//  CoordTrans.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/15.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef CoordTrans_hpp
#define CoordTrans_hpp

#include "mbed.h"
#include "doubleSMA.hpp"

typedef struct {
	double real;
	double imag;
} compDouble;

extern compDouble makeCompFromRT(double radius, int8_t theta);
extern compDouble makeComp(double real, double imag);
extern compDouble compSMA(compDouble *reading);

#endif /* CoordTrans_hpp */
