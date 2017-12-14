//
//  CoordTrans.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/15.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "CoordTrans.hpp"

doubleSMA sma_real(20);
doubleSMA sma_imag(30);

compDouble makeCompFromRT(double radius, int8_t theta) {
	
	compDouble rslt;
	rslt.real = radius * sin((double)theta / -127.0 * M_PI);
	rslt.imag = radius * cos((double)theta / -127.0 * M_PI);
	
	return rslt;
}

compDouble makeComp(double real, double imag) {

	compDouble rslt;
	rslt.real = real;
	rslt.imag = imag;
	
	return rslt;
}

compDouble compSMA(compDouble *reading) {
	
	compDouble rslt;
	rslt.real = sma_real.aveDouble(reading->real);
	rslt.imag = sma_imag.aveDouble(reading->imag);
	
	return rslt;
}
