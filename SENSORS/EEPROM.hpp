//
//  EEPROM.hpp
//  20160426_main
//
//  Created by K-Taro on 2016/04/29.
//  Copyright © 2016年 K-Taro. All rights reserved.
//

#ifndef EEPROM_hpp
#define EEPROM_hpp

#include "mbed.h"

#define US_address 0x50

class EEPROM{

	mbed::I2C* i2c;
    char rwdata[3];
    
public:
    EEPROM(PinName sda, PinName scl);
    int read(int address);
    void write(int address,int data);

};

#endif /* EEPROM_hpp */
