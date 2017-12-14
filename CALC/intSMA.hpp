//
//  SMA.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/17.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef intSMA_hpp
#define intSMA_hpp

#include "mbed.h"
#include "CoordTrans.hpp"

class intSMA {
	
	uint8_t cnt = 0;
	uint8_t n;
	int sma_array[50];
	int sum;

public:
	intSMA(uint8_t reading);
	int aveInt(int reading);
	
};

#endif /* intSMA_hpp */
