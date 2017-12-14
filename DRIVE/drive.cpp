//
//  drive.cpp
//  Rosso6x_main
//
//  Created by K-Taro on 7/10/16.
//	Edited by y6tada on 8/11/16.
//  Copyright © 2016 K-Taro. All rights reserved.
//

#include "drive.hpp"

mbed::DigitalOut SD(PA_5);
mbed::DigitalOut Drb_one(PB_0);

MOTOR Motor;

mbed::Timeout kick_disableOmeShot;
mbed::Timeout kick_readyOneShot;


DRIVE::DRIVE(){
	/*
	 コンストラクタ
	 何もしない
	 */
}

void DRIVE::setMotorPwmPeriod(unsigned int period_us) {
	Motor.setPeriod_us(period_us);
}

int DRIVE::map_func(int x, int in_min, int in_max, int out_min, int out_max){
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void DRIVE::Drb_ON(void){
	Drb_one = 1;
}

void DRIVE::Drb_OFF(void){
	Drb_one = 0;
}

void DRIVE::Solenoid(int opentime){
	if(opentime > 0){  //open_timeが0でない（0=打たない）
		SD = 1;
		wait(opentime/1000.0);
		SD = 0;
	}
}

// ========================= yunit_tech ここから =================================== //
static bool kickReadyStatus = 1;

void kickFlip(void) {
	SD = 0;
}

void kickReady(void) {
	kickReadyStatus = 1;
}


void DRIVE::kick(void) {
	
	if (kickReadyStatus) {
		
		/*
		 ソレノイド通電
		 40ms後にソレノイド遮断の処理を行うワンショットタイマーを立ち上げ
		 */
		SD = 1;
		kick_disableOmeShot.attach_us(&kickFlip, 40000);
		
		/*
		 キックすると同時にRaedyステータスを0(Not ready)へ変更
		 指定秒後のワンショットで再び1(Ready)へ戻す
		 */
		kickReadyStatus	= 0;
		kick_readyOneShot.attach(&kickReady, kick_nextRady_delay);
	}
}

void DRIVE::enableRunDribler(uint8_t readDist, uint8_t distMin, int8_t readDeg, int8_t degrMin) {
	
	if (readDist > distMin && abs(readDeg) < degrMin) {
		Drb_ON();
	}
	else {
		Drb_OFF();
	}
}

void DRIVE::disableRunDribler(void) {
	Drb_OFF();
}

float DRIVE::int8x2_to_rad(int reading1, int reading2) {
	return (float)(reading1 + reading2) * M_PI / 127.0;
}

void DRIVE::movePolar(float pwr, int int8deg, float turn) {
	
	Motor.setRF( pwr * cos(int8x2_to_rad(-30, int8deg)) + turn);
	Motor.setRB( pwr * cos(int8x2_to_rad(45, int8deg)) + turn);
	Motor.setLB( pwr * cos(int8x2_to_rad(135, int8deg)) + turn);
	Motor.setLF( pwr * cos(int8x2_to_rad(-120, int8deg)) + turn);
}

void DRIVE::moveComp(float VecX, float VecY, float turn) {
	
	Motor.setRF(VecX * -0.500 + VecY * 0.866 + turn);
	Motor.setLF(VecX * -0.500 + VecY * -0.866 + turn);
	Motor.setLB(VecX *  0.707 + VecY * -0.707 + turn);
	Motor.setRB(VecX *  0.707 + VecY *  0.707 + turn);
}
// ========================= yunit_tech ここまで =================================== //
