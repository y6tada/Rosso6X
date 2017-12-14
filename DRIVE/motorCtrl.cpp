//
//  motorCtrl.cpp
//  Rosso6x_yunit_v1
//
//  Created by y6tada_mac on 2016/07/18.
//  Copyright © 2016年 y6tada. All rights reserved.
//

#include "motorCtrl.hpp"

mbed::DigitalOut M1A(PB_3);
mbed::DigitalOut M2A(PB_14);
mbed::DigitalOut M3A(PB_1);
mbed::DigitalOut M4A(PA_9);

mbed::DigitalOut M1DIR(PB_13);
mbed::DigitalOut M2DIR(PB_15);
mbed::DigitalOut M3DIR(PB_2);
mbed::DigitalOut M4DIR(PA_12);

mbed::PwmOut PWM1(PA_10);
mbed::PwmOut PWM2(PB_5);
mbed::PwmOut PWM3(PA_11);
mbed::PwmOut PWM4(PA_7);

MOTOR::MOTOR() {
	
}

void MOTOR::setPeriod_us(unsigned int us) {
	PWM1.period_us(us);
	PWM2.period_us(us);
	PWM3.period_us(us);
	PWM4.period_us(us);
}

void MOTOR::setRF(float pwr) {
	
	if (pwr > 0) {
		M1A = 1;
		PWM1 = pwr;
	}
	else if(pwr < 0) {
		M1A = 0;
		PWM1 = -pwr;
	}
	else {
		PWM1 = 0;
	}
}

void MOTOR::setLF(float pwr) {
	
	if (pwr > 0) {
		M2A = 1;
		PWM2 = pwr;
	}
	else if(pwr < 0) {
		M2A = 0;
		PWM2 = -pwr;
	}
	else {
		PWM2 = 0;
	}
}

void MOTOR::setLB(float pwr) {
	
	if (pwr > 0) {
		M3A = 1;
		PWM3 = pwr;
	}
	else if(pwr < 0) {
		M3A = 0;
		PWM3 = -pwr;
	}
	else {
		PWM3 = 0;
	}
}

void MOTOR::setRB(float pwr) {
	
	if (pwr > 0) {
		M4A = 1;
		PWM4 = pwr;
	}
	else if(pwr < 0) {
		M4A = 0;
		PWM4 = -pwr;
	}
	else {
		PWM4 = 0;
	}
}
