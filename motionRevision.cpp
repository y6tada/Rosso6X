//
//  anti_ collision.cpp
//  yunit_Rosso6Xmain
//
//  Created by y6tada_mac on 2016/08/18.
//  Copyright © 2016年 yunit_tech. All rights reserved.
//

#include "motionRevision.hpp"

void movingRevision(compDouble *moveComp, posSensor *langep) {
	
	if (langep->back < 15) {
		if(moveComp->imag < 0) moveComp->imag = 0;
		
		if(i2cIR.getDegr() > 0) {
			moveComp->real += 0.6;
		}
		else {
			moveComp->real -= 0.6;
		}
	}
	
	// 増速処理
	if(langep->right > 60 && moveComp->real > 0) {
		moveComp->real *= 1.25;
	}
	if(langep->left > 60 && moveComp->real < 0) {
		moveComp->real *= 1.25;
	}
	if(langep->back > 100 && moveComp->imag < 0) {
		moveComp->imag *= 1.25;
	}
}
