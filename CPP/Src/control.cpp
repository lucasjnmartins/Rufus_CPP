/*
 * control.cpp
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#include "control.h"

control::control(position* P) {
	// TODO Auto-generated constructor stub
	p = P;
	kp = 0;
	kd = 0;
	der = 0;
}

control::~control() {
	// TODO Auto-generated destructor stub
}

void control::setConsts(uint8_t KP, uint8_t KD) {
	kp = float(KP) / 10;
	kd = float(KD) / 10;
}


float control::PIDValue() {
	oldPos = pos;
	pos = p->DefinePosition();
	der = pos - oldPos;
	oldPID = PID;
	PID = (kp*pos + kd*oldPos);
	return PID;
}

int control::GetPosition() {
	return pos;
}

