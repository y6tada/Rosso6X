//
//  doubleSMA.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/17.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef doubleSMA_hpp
#define doubleSMA_hpp

#include "mbed.h"
#include "CoordTrans.hpp"

class doubleSMA {
	
	uint8_t cnt = 0;
	uint8_t n;
	double sma_array[50];
	double sum;
	
public:
	doubleSMA(uint8_t reading);
	double aveDouble(double reading);
};


#endif /* doubleSMA_hpp */
