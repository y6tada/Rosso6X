//
//  motorCtrl.hpp
//  Rosso6x_yunit_v1
//
//  Created by y6tada_mac on 2016/07/18.
//  Copyright © 2016年 y6tada. All rights reserved.
//

#ifndef motorCtrl_hpp
#define motorCtrl_hpp

#include "mbed.h"

class MOTOR {
	
public:
	MOTOR();
	void setPeriod_us(unsigned int us);
	void setRF(float pwr);
	void setRB(float pwr);
	void setLF(float pwr);
	void setLB(float pwr);
	
};

#endif /* motorCtrl_hpp */
