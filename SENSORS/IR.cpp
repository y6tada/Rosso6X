//
//  IR.cpp
//  Rosso6x_main
//
//  Created by K-Taro on 8/5/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#include "IR.hpp"

static char reading[2];
static int8_t mem_degree;

IR::IR(PinName sda, PinName scl){
	i2c_i = new mbed::I2C(sda, scl);
//	i2c_i->frequency(400000);
}

void IR::read(void){
    i2c_i->read(IR_address, reading, 2);
}

void IR::read(BallSensor *ir){
	i2c_i->read(IR_address, reading, 2);
	int8_t x = (reading[0] - 127);
	int8_t y = (reading[1] - 127);
	
	ir->degree	 = (int8_t)(atan2(-x, y) / M_PI * 127.0);
	ir->distance = (uint8_t)(sqrt(x*x + y*y));
	ir->d_degree = (ir->degree - mem_degree) * 3.0;
	mem_degree = ir->degree;
}

int8_t IR::x(void){
    return (int8_t)(reading[0] - 127);
}

int8_t IR::y(void){
    return (int8_t)(reading[1] - 127);
}

int8_t IR::getDegr(void) {
	return (int8_t)(atan2(x() * -1, y()) / M_PI * 127.0);
}

uint8_t IR::getDist(void) {
	return (uint8_t)sqrt(x() * x() + y() * y());
}

void IR::getBall(BallSensor *ir) {
	ir->degree = getDegr();
	ir->distance = getDist();
}



