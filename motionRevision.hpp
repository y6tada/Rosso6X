//
//  anti_ collision.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/18.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef anti_collision_hpp
#define anti_collision_hpp

#include "mbed.h"
#include "CALC/CoordTrans.hpp"
#include "SENSORS/US.hpp"
#include "SENSORS/IR.hpp"
#include "SENSORS/US.hpp"

extern US i2cUS;
extern IR i2cIR;
extern mbed::Serial pc;
extern void movingRevision(compDouble *moveComp, posSensor *langep);

#endif /* anti_collision_hpp */
