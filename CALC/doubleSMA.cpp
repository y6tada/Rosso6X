//
//  doubleSMA.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/17.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "doubleSMA.hpp"

doubleSMA::doubleSMA(uint8_t reading) {
	/*
	 移動平均の平均数nを決定
	 */
	n = reading;
	
	/*
	 配列の初期化
	 */
	for (int i = 0; i < 50; i++) {
		sma_array[i] = 0;
	}
}

double doubleSMA::aveDouble(double reading) {
	
	if (cnt >= n) {
		cnt = 0;
	} cnt++;		// 配列のアクセスポイントを0~nまで回す
	
	sma_array[cnt] = reading;
	
	sum = 0;
	for (int i = 0; i < 50; i++) {
		sum += sma_array[i];
	}
	
	return sum / (double)n;
}