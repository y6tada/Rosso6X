//
//  EEPROM.cpp
//  20160426_main
//
//  Created by K-Taro on 2016/04/29.
//  Copyright © 2016年 K-Taro. All rights reserved.
//

#include "EEPROM.hpp"

EEPROM::EEPROM(PinName sda, PinName scl){
	i2c = new mbed::I2C(sda, scl);
//    i2c->frequency(100000);
}

int EEPROM::read(int address){
    
    rwdata[0] = 2;
    rwdata[1] = address;
    rwdata[2] = 0;
    i2c->write(US_address, rwdata, 3);
    wait(0.001);
    
    i2c->read(US_address, rwdata, 3);
    
    return rwdata[0];
    
}

void EEPROM::write(int address, int data){
    
    rwdata[0] = 1;
    rwdata[1] = address;
    rwdata[2] = data;
    i2c->write(US_address, rwdata, 3);
    wait(0.01);
    
}
