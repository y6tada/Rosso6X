//
//  IR.hpp
//  Rosso6x_main
//
//  Created by K-Taro on 8/5/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#ifndef IR_hpp
#define IR_hpp

#include "mbed.h"

#define IR_address 0x64

typedef struct {
	int8_t degree;
	uint8_t distance;
	int8_t d_degree;
} BallSensor;

class IR{

    mbed::I2C *i2c_i;
	int8_t x(void);
	int8_t y(void);
	
public:
    IR(PinName sda, PinName scl);
    void read(void);
	void read(BallSensor *ir);
	int8_t getDegr(void);
	uint8_t getDist(void);
	void getBall(BallSensor *ir);
};

#endif /* IR_hpp */
