//
//  imuFunc.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/11.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "imuCtrl.hpp"

static imu_rawData imu;
static int8_t get_data_last;

IMU::IMU() {
	/*
	 コンストラクタ
	 何もしない
	 */
}

void IMU::calculate(int8_t get_data) {
	
	imu.deg		= get_data;
	imu.deg_dt	= get_data - get_data_last;
	
	get_data_last = get_data;
}

float IMU::getDeg(void) {
	return (float)(imu.deg / 127.0);
}

float IMU::getDeg_dt(void) {
	return (float)(imu.deg_dt / 12.7);
}

void IMU::setPD(double p, double d) {
	gain_p = p;
	gain_d = d;
}

float IMU::PD(float ofset) {
	return (float)(getDeg_dt() * gain_d + ((imu.deg - ofset) / 127.0) * gain_p);
}
