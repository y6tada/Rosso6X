//
//  lineMonitoringCtrl.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/15.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "lineDetect.hpp"

mbed::DigitalIn Line_F(PB_10);
mbed::DigitalIn Line_B(PA_6);
mbed::DigitalIn Line_L(PA_8);
mbed::DigitalIn Line_R(PB_4);
mbed::DigitalIn Line_ALL(PC_4);

static unsigned int LineAllCnt = 0;

double inLineArea_F;
double inLineArea_B;
double inLineArea_R;
double inLineArea_L;

void lineDetect(compDouble *move, uint8_t IR_dist) {

	if (Line_ALL) {
		
//		pc.printf("on_line\n");
		LineAllCnt++;
		
		if(LineAllCnt < 8) {
			/*
			 一定時間内でのライン処理
			 反応した方向への逆移動
			 最初の積分領域の設定
			 */
			move->real *= -1.20;
			move->imag *= -0.80;
			
			if (!Line_F) {
				if(inLineArea_F < lineArea) inLineArea_F = lineArea;
				if(move->imag > 0) {
//					move->imag = -0.65;
				}
			}
			
			if (!Line_B) {
				if(inLineArea_B < lineArea) inLineArea_B = lineArea;
				if(move->imag < 0) {
//					move->imag = 0.65;
				}
			}
			
			if (!Line_R) {
				if(inLineArea_R < lineArea) inLineArea_R = lineArea;
				if(move->real > 0) {
//					move->real = -0.4;
				}
			}
			
			if (!Line_L) {
				if(inLineArea_L < lineArea) inLineArea_L = lineArea;
				if(move->real < 0) {
//					move->real = 0.4;
				}
			}
		}
		else {
			if (LineAllCnt < 85) {
				/*
				 慣性減衰処理
				 惰性で移動するのをブレーキ
				 */
				move->real *= -0.80;
				move->imag *= -0.65;
			}
			
			/*	積分領域の残った方向に移動 */
			if(inLineArea_F > 0 && move->imag > 0) {
				move->imag = -0.65;
			}
			if(inLineArea_B > 0 && move->imag < 0) {
				move->imag = 0.65;
			}
			if(inLineArea_R > 0 && move->real > 0) {
				move->real = -0.7;
			}
			if(inLineArea_L > 0 && move->real < 0) {
				move->real = 0.7;
			}
		}
		
		if (LineAllCnt > 120) {
			inLineArea_F = 0;
			inLineArea_B = 0;
			inLineArea_R = 0;
			inLineArea_L = 0;
		}
	}
	else if (!Line_ALL) {	//ラインを検出しない
//		pc.printf("no_line\n");
		LineAllCnt = 0;
		
		/*	積分領域をホイールオドメトリによって減算 */
		if(inLineArea_F > 0 && move->imag < 0) {
			inLineArea_F -= move->imag * -1.2;
			move->real *= 0.4;
			move->imag *= 1.25;
		}
		if(inLineArea_B > 0 && move->imag > 0) {
			inLineArea_B -= move->imag * 1.2;
			move->real *= 0.4;
			move->imag *= 1.25;
		}
		if(inLineArea_R > 0 && move->real < 0) {
			inLineArea_R -= move->real * -0.7;
			move->imag *= 0.5;
			move->real *= 0.65;
		}
		if(inLineArea_L > 0 && move->real > 0) {
			inLineArea_L -= move->real * 0.7;
			move->imag *= 0.5;
			move->real *= 0.65;
		}
		
		/*  keepOut領域から無条件に抜け出す  */
		if(inLineArea_F > lineKeepOutArea) {
			move->imag += -0.5;
		}
		if(inLineArea_B > lineKeepOutArea) {
			move->imag += 0.5;
		}
		if(inLineArea_R > lineKeepOutArea) {
			move->real += 0.6;
		}
		if(inLineArea_L > lineKeepOutArea) {
			move->real += -0.6;
		}
		
//		pc.printf("F:%lf\tB:%lf\tR:%lf\tL:%lf\n",
//				  inLineArea_F,
//				  inLineArea_B,
//				  inLineArea_R,
//				  inLineArea_L
//		);
		
		/*	領域を抜けるまではライン方向への移動をキャンセル */
		if (inLineArea_F > lineKeepOutArea) {
			move->imag = 0;
		}
		if (inLineArea_B > lineKeepOutArea) {
			move->imag = 0;
		}
		if (inLineArea_R > lineKeepOutArea) {
			move->real = 0;
		}
		if (inLineArea_L > lineKeepOutArea) {
			move->real = 0;
		}
		
		if (IR_dist < 11) {
			inLineArea_F = 0;
			inLineArea_B = 0;
			inLineArea_R = 0;
			inLineArea_L = 0;
		}
		
		if(inLineArea_L < 0) inLineArea_L = 0;
		if(inLineArea_R < 0) inLineArea_R = 0;
		if(inLineArea_F < 0) inLineArea_F = 0;
		if(inLineArea_B < 0) inLineArea_B = 0;
	}
	
	/*	現在ラインを検出中であるか否かに依存しない処理 */
}
