//
//  mainLoop.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/11.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "mainLoop.hpp"

mbed::DigitalIn Encoder(PB_12);
mbed::DigitalIn OptoHold(PC_5);
mbed::DigitalIn UI_SW(PC_12);

doubleSMA	ballSMA_double(8);

static BallSensor ball;
static posSensor  lange;
static uint8_t	  ofset = 0;

MOTOR testMotor;

void mainLoop(void) {
	
	if(UI_SW) {
		i2cIR.read(&ball);
		i2cUS.readPos(false, &lange);
		
		if (ball.distance > 25 && abs(ball.degree) < 24) {
			drive.kick();
		}
		
		drive.moveComp(0, 0, 0);	// 何もしない
		
//		pc.printf("dist:%d\tdegr:%d\t%d\n",
//			ball.distance,
//			ball.degree,
//			ball.d_degree
//		);
		
//		pc.printf("F:%d\tB:%d\tR:%d\tL:%dtAll:%d\n",
//			(int)Line_F,
//			(int)Line_B,
//			(int)Line_R,
//			(int)Line_L,
//			(int)Line_ALL
//		);
		
//		pc.printf("r:%d\tL:%d\tB:%d\n", lange.right, lange.left, lange.back);
		
//		pc.printf("pixy:%d\n", lange.);
	}
	else {
		ballTrack();
	}
	
}

void ballTrack(void) {

	i2cIR.read(&ball);
	i2cUS.readPos(false, &lange);
	
	compDouble move = makeCompFromRT(moveSpeed, getMotion(&ball));
	
	move.real *= moveRealRatio;
	if(abs(ball.degree) < 20) {
		/*
		 ball.d_degree : ボールを指し示すベクトルの角速度
		 微分制御により回り込みのオーバーランを解消
		 */
		move.real += ballSMA_double.aveDouble((double)(ball.d_degree / -4.0));
	}
	
	if (move.imag > 0) {
		move.imag *= moveFrontRatio;
	}
	
	lineDetect(&move, ball.distance);
	movingRevision(&move, &lange);

	if (ball.distance) {
		drive.enableRunDribler(ball.distance, 25, ball.degree, 24);

		if(!Line_ALL) {
			if(ball.distance > 29 && abs(ball.degree) < 24) {
				
				if(lange.goal != 0)  {
					
					move.imag = 1.4;
					if(OptoHold && lange.goal == 3) drive.kick();
					
					if ((lange.right - lange.left) > 25) {
						move.real += 0.6;
						if(lange.goal == 1) {
							move.real *= 1.2;
						}
					}
					if ((lange.right - lange.left) < -25) {
						move.real -= 0.6;
						if(lange.goal == 2) {
							move.real *= 1.2;
						}
					}
				}
				else {
					move.imag = -0.55;
					
					if ((lange.right - lange.left) > 15) {
						move.real += 1.1;
					}
					if ((lange.right - lange.left) < -15) {
						move.real -= 1.1;
					}
				}
			}
		}
		
		move = compSMA(&move);
		drive.moveComp(move.real, move.imag, imu.PD(ofset));
	}
	else {
		/*
		 ボールを見ていない場合の処理
		 ・自陣復帰/何もしない
		 ・ドリブラー無効化
		 */
		move.real = 0;
		move.imag = 0;
		
		if(abs(lange.right - lange.left) > 20) {
			move.real = (double)((lange.right - lange.left) / 40.0);
		}
		move.imag = (double)((lange.back - 35) / -80.0);
	
		drive.moveComp(move.real, move.imag, imu.PD(0));
		drive.disableRunDribler();
	}

}
