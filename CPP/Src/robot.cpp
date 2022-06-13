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
		velMax = 200;
		velBase = 90;
		ctr->setKP(10);
		ctr->setKD(10);
	} else if (state == 1) {
		velDir = velBase + ctr->PIDValue();;
		velEsq = velBase - ctr->PIDValue();;
		mdir->Speed(velDir);
		mesq->Speed(velEsq);
	}

}

void robot::Calibrate(int* z) {
	*z = 0;
	while(*z < 10) {
		mdir->Speed(90);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 30) {
		mdir->Speed(-90);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 40) {
		mdir->Speed(90);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
}

int robot::GetPosition() {
	return ctr->GetPosition();
}
