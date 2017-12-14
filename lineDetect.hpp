//
//  lineMonitoringCtrl.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/15.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef anti_lineOut_h
#define anti_lineOut_h

#include "mbed.h"
#include "CALC/CoordTrans.hpp"
#include "CALC/doubleSMA.hpp"
#include "SENSORS/US.hpp"

extern mbed::Serial	pc;
extern void lineDetect(compDouble *moveComp, uint8_t IR_dist);
extern mbed::DigitalIn Line_ALL;

extern mbed::DigitalIn Line_F;
extern mbed::DigitalIn Line_B;
extern mbed::DigitalIn Line_L;
extern mbed::DigitalIn Line_R;
extern mbed::DigitalIn Line_ALL;

const double lineArea = 40.0;
const double lineKeepOutArea = lineArea - 20.0;

#endif /* anti_lineOut_h */
