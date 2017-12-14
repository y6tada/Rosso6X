//
//  motionFunc.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/13.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef motion_hpp
#define motion_hpp

#include "mbed.h"
#include "DRIVE/drive.hpp"
#include "SENSORS/IR.hpp"


extern int8_t getMotion(BallSensor *ball);

extern mbed::Serial pc;
extern DRIVE	drive;

const double ratioA = 80.0;
const double ratioB_far = 1.4;
const double ratioB_close = 1.8;

const int8_t DISTANCE_LEVEL_1 = 14;
const int8_t DISTANCE_LEVEL_2 = 22;
const int8_t DISTANCE_LEVEL_3 = 26;

#endif /* motion_hpp */
