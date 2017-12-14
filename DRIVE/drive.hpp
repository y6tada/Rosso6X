//
//  drive.hpp
//  Rosso6x_main
//
//  Created by K-Taro on 7/10/16.
//	Edited by y6tada on 8/11/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#ifndef drive_hpp
#define drive_hpp

#include "mbed.h"
#include "motorCtrl.hpp"

void kickFlip(void);
void kickReady(void);

class DRIVE {
	
	int map_func(int, int, int, int, int);
	const float kick_nextRady_delay = 0.8;
	
public:
	DRIVE();
	void setMotorPwmPeriod(unsigned int period_us);
	void Drb_ON(void);
	void Drb_OFF(void);
	void Solenoid(int opentime);
	
	void enableRunDribler(uint8_t, uint8_t, int8_t, int8_t);
	void disableRunDribler(void);
	
	void kick(void);
	float int8x2_to_rad(int reading1, int reading2);
	void movePolar(float pwr, int int8deg, float turn);
	void moveComp(float VecX, float VecY, float turn);
};

#endif /* drive_hpp */