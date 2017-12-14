//
//  motionFunc.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/13.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "motion.hpp"

int8_t getMotion(BallSensor *ball) {
	
	int8_t ball_16D = abs(ball->degree) / 15;
	int8_t rslt_16D = 0;
	
	if (ball->distance < DISTANCE_LEVEL_1) {
		
		switch (ball_16D) {
			case 1:
				rslt_16D = 2;
				break;
				
			case 2:
				rslt_16D = 3;
				break;
				
			case 3:
				rslt_16D = 4;
				break;
				
			case 4:
				rslt_16D = 5;
				break;
				
			case 5:
				rslt_16D = 6;
				break;
				
			case 6:
				rslt_16D = 7;
				break;
				
			case 7:
				rslt_16D = 7;
				break;
				
			case 8:
				rslt_16D = 8;
				break;
		}
	}
	else if(ball->distance < DISTANCE_LEVEL_2) {
		
		switch (ball_16D) {
			case 0:
				rslt_16D = 3;
				break;
			case 1:
				rslt_16D = 4;
				break;
				
			case 2:
				rslt_16D = 4;
				break;
				
			case 3:
				rslt_16D = 5;
				break;
				
			case 4:
				rslt_16D = 6;
				break;
				
			case 5:
				rslt_16D = 7;
				break;
				
			case 6:
				rslt_16D = 8;
				break;
				
			case 7:
				rslt_16D = 9;
				break;
				
			case 8:
				rslt_16D = 10;
				break;
		}
	}
	else if(ball->distance < DISTANCE_LEVEL_3) {
		
		switch (ball_16D) {
			case 0:
				if (abs(ball->degree) > 7) {
					rslt_16D = 3;
				}
				break;
			case 1:
				rslt_16D = 3;
				break;
				
			case 2:
				rslt_16D = 4;
				break;
				
			case 3:
				rslt_16D = 5;
				break;
				
			case 4:
				rslt_16D = 7;
				break;
				
			case 5:
				rslt_16D = 8;
				break;
				
			case 6:
				rslt_16D = 10;
				break;
				
			case 7:
				rslt_16D = 11;
				break;
				
			case 8:
				rslt_16D = 12;
				break;
		}
	}
	else {

		switch (ball_16D) {
			case 0:
				rslt_16D = 1;
				break;
			case 1:
				rslt_16D = 3;
				break;
				
			case 2:
				rslt_16D = 5;
				break;
				
			case 3:
				rslt_16D = 6;
				break;
				
			case 4:
				rslt_16D = 7;
				break;
				
			case 5:
				rslt_16D = 8;
				break;
				
			case 6:
				rslt_16D = 10;
				break;
				
			case 7:
				rslt_16D = 11;
				break;
				
			case 8:
				rslt_16D = 12;
				break;
		}
	}
	
	
	int rslt = rslt_16D * 15;
	if(rslt > 127) {
		rslt -= 255;
	} else if(rslt < -127) {
		rslt += 255;
	}
	
	return (ball->degree > 0) ? rslt : -1 * rslt;
}

