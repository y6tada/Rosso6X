//
//  US.hpp
//  Rosso6x_main
//
//  Created by K-Taro on 8/5/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#ifndef US_hpp
#define US_hpp

#include "mbed.h"

#define US_address 0x50

extern mbed::Serial pc;

typedef struct {
	uint8_t back;
	uint8_t left;
	uint8_t right;
	uint8_t goal;
	uint8_t orange;
} posSensor;

class US{
    
	mbed::I2C* i2c;
    char reading[8];
    int L = 0;
    int R = 0;
    int B = 0;
    int Goal = 0;
    int Ball = 0;

public:
    US(PinName sda, PinName scl);
	
    void read(bool orange);
	void readPos(bool, posSensor*);
	
    int usL(void);
    int usR(void);
    int usB(void);
    int Pixy_Goal(void);
    int Pixy_Ball(void);

};

#endif /* US_hpp */
