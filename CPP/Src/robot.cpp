/*
 * robot.cpp
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#include "robot.h"

robot::robot(control* CTR, motorControl* MDIR, motorControl* MESQ) {
	// TODO Auto-generated constructor stub
	ctr = CTR;
	mdir = MDIR;
	mesq = MESQ;
}

robot::~robot() {
	// TODO Auto-generated destructor stub
}

float robot::module(float val) {
	if(val > 0) {
		return val;
	} else {
		return -val;
	}
}

void robot::RunningState(uint8_t state) {
	if(state == 0) {

	} if(state == 1) {
		velMax = 120;
		velBase = 70;
		ctr->setKP(15);
		ctr->setKD(10);
		mdir->InitConsts(1040.93, 21.714);
		mesq->InitConsts(1040.93, 21.714);
	} else if (state == 3) {
		velDir = velBase + ctr->PIDValue();;
		velEsq = velBase - ctr->PIDValue();;
		if(velDir > velMax) {
			velDir = velMax;
		}
		if(velEsq > velMax) {
			velEsq = velMax;
		}
		mdir->Speed(velDir);
		mesq->Speed(velEsq);
	}

}

void robot::Calibrate(uint32_t* z) {
	ctr->p->InitCalibration();
	*z = 0;
	while(*z < 10000) {
		mdir->Speed(60);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 30000) {
		mdir->Speed(-60);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 40000) {
		mdir->Speed(60);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}

	*z = 60000;
	mdir->Break();
	mesq->Break();
}

int robot::GetPosition() {
	return ctr->GetPosition();
}
