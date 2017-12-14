//
//  US.cpp
//  Rosso6x_main
//
//  Created by K-Taro on 8/5/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#include "US.hpp"

US::US(PinName sda, PinName scl){
	i2c = new mbed::I2C(sda, scl);
//        i2c->frequency(400000);
}

void US::read(bool orange){
	
    if(orange == true){
        i2c->read(US_address, reading, 7);
        reading[7] = 0;
    }else{
        i2c->read(US_address, reading, 8);
    }
    
    L = reading[0]+reading[1];
    R = reading[2]+reading[3];
    B = reading[4]+reading[5];
    Goal = reading[6];
    Ball = reading[7];
}

void US::readPos(bool enableOrange, posSensor *posp) {
	if(enableOrange){
		i2c->read(US_address, reading, 7);
		reading[7] = 0;
	}else{
		i2c->read(US_address, reading, 8);
	}
	
	posp->left   = reading[0] + reading[1];
	posp->right  = reading[2] + reading[3];
	posp->back   = reading[4] + reading[5];
	posp->goal   = reading[6];
	posp->orange = reading[7];
}


int US::usL(void){
    return L;
}

int US::usR(void){
    return R;
}

int US::usB(void){
    return B;
}

int US::Pixy_Goal(void){
    return Goal;
}

int US::Pixy_Ball(void){
    return Ball;
}
