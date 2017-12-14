//
//  mainLoop.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/11.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef mainLoop_hpp
#define mainLoop_hpp

#include "mbed.h"

#include "DRIVE/drive.hpp"

#include "SENSORS/imuCtrl.hpp"
#include "SENSORS/IR.hpp"
#include "SENSORS/US.hpp"

#include "CALC/CoordTrans.hpp"
#include "CALC/intSMA.hpp"
#include "CALC/doubleSMA.hpp"

#include "motion.hpp"
#include "lineDetect.hpp"
#include "motionRevision.hpp"

extern mbed::Serial	pc;
extern IMU		imu;
extern IR		i2cIR;
extern US		i2cUS;
extern DRIVE	drive;
extern void mainLoop(void);
void ballTrack(void);

const double moveSpeed		= 0.82;
const double moveRealRatio	= 1.25;
const double moveFrontRatio	= 0.80;

const double PD_P = 4.8;
const double PD_D = 2.2;



#endif /* mainLoop_hpp */
