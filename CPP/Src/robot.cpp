/*
 * robot.cpp
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#include "robot.h"

robot::robot(control* CTR, motorControl* MDIR, motorControl* MESQ, map* CIRCUIT) {
	// TODO Auto-generated constructor stub
	ctr = CTR;
	mdir = MDIR;
	mesq = MESQ;
	circuit = CIRCUIT;
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
		mdir->Break();
		mesq->Break();
	} if(state == 1) {
		velMax = 150;
		circuit->InitTracks();
		/*mdir->InitConsts(1040.93, 21.714);
		mesq->InitConsts(1040.93, 21.714);*/
	} else if (state == 3) {

		if(pos == TRACKS) {
			pos = 0;
		}

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
	while(*z < 5000) {
		mdir->Speed(75);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 13000) {
		mdir->Speed(-75);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 18000) {
		mdir->Speed(75);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}

	*z = 60000;
	mdir->Break();
	mesq->Break();
	pos = 0;
}

int robot::GetPosition() {
	return ctr->GetPosition();
}

void robot::NextState() {
	ChangeTrack();
	pos++;
}

void robot::ChangeTrack() {
	if(pos != 0) {
		circuit->SetTrackRotations(pos-1, mdir->GetRotations(), mesq->GetRotations());
	}
	velBase = circuit->GetBaseSpeed(pos);
	ctr->setKP(circuit->GetKp(pos));
	ctr->setKD(circuit->GetKd(pos));

}
