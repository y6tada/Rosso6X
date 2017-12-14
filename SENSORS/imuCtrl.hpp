//
//  imu_dataFunc.hpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/11.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#ifndef imuCtrl_hpp
#define imuCtrl_hpp

#include "mbed.h"

typedef struct {
	int8_t  deg;
	int8_t  deg_dt;
} imu_rawData;

class IMU {
	
	double gain_p = 0;
	double gain_d = 0;
	
public:
	IMU();
	void calculate(int8_t get_data);
	float getDeg(void);
	float getDeg_dt(void);
	void setPD(double p, double d);
	float PD(float ofset);
};

#endif /* imuCtrl_hpp */
