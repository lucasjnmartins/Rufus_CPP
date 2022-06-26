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

void control::setKP(float KP) {
	kp = KP;
}

void control::setKD(float KD) {
	kd = KD;
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

