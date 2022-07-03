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
	sum = 0;
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

void robot::Running() {
	velDir = velBase + ctr->PIDValue();
	velEsq = velBase - ctr->PIDValue();
	if(velDir > velMax) {
		velDir = velMax;
	}
	if(velEsq > velMax) {
		velEsq = velMax;
	}
	mdir->Speed(velDir);
	mesq->Speed(velEsq);
}

void robot::Finish(uint32_t* z) {
	*z = 0;
	while(*z < 1000) {
		mdir->Speed(70);
		mesq->Speed(70);
	}
	*z = 60000;
	mdir->Break();
	mesq->Break();
}

void robot::Calibrate(uint32_t* z) {
	ctr->p->InitCalibration();
	*z = 0;
	while(*z < 3000) {
		mdir->Speed(75);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 8000) {
		mdir->Speed(-75);
		mesq->Speed(0);
		ctr->p->CalibrateSensors();
	}
	mdir->Break();
	mesq->Break();
	while(*z < 12000) {
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
	return pos;
}

void robot::NextState() {
	pos++;
	ChangeTrack();
}

void robot::ChangeTrack() {
	if(pos != 0) {
		circuit->SetTrackRotations((pos-1), mdir->GetRotations(), mesq->GetRotations());
	}
	//velMax = 150;
	velBase = 55 + sum;
	velMax = 150;
	//velBase = circuit->baseSpeed + sum;
	ctr->setConsts(13, 130);
	//velBase = circuit->GetBaseSpeed() + sum;
	//ctr->setConsts(circuit->GetKp(pos), circuit->GetKd(pos));
	//ctr->setKD(circuit->GetKd(pos));
}

void robot::CompareRotations(){
	/*if((mdir->GetRotations() > (circuit->GetWaitChangeInit(pos)*circuit->GetRotationsDir(pos))) || (mesq->GetRotations() > circuit->GetWaitChangeInit(pos)*circuit->GetRotationsEsq(pos))) {
		velBase = circuit->GetHighSpeed(pos) + sum;
	}

	//if((mdir->GetRotations() > ((circuit->GetWaitChangeFinish(pos)  / 10)*circuit->GetRotationsDir(pos))) || (mesq->GetRotations() > ((circuit->GetWaitChangeFinish(pos)  / 10)*circuit->GetRotationsEsq(pos)))) {
	if((mdir->GetRotations() > (circuit->GetWaitChangeFinish(pos)*circuit->GetRotationsDir(pos))) || (mesq->GetRotations() > circuit->GetWaitChangeFinish(pos)*circuit->GetRotationsEsq(pos))) {
		velBase = circuit->GetBaseSpeed() + sum;
	}

	/*if (mdir->GetRotations() > 3*circuit->GetRotationsDir(pos) || mesq->GetRotations() > 3*circuit->GetRotationsEsq(pos)) {
		pos++;
	}*/

	if(((mdir->GetRotations() + mesq->GetRotations()) / 2) > (circuit->GetWaitChangeInit(pos)*circuit->GetRotations(pos))) {
		velBase = circuit->GetHighSpeed(pos) + sum;
	}

	if(((mdir->GetRotations() + mesq->GetRotations()) / 2) > (circuit->GetWaitChangeFinish(pos)*circuit->GetRotations(pos))) {
		velBase = circuit->GetBaseSpeed() + sum;
	}
}

void robot::sumPlus() {
	sum++;
}

void robot::sumLess() {
	sum--;
}
