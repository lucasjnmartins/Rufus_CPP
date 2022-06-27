/*
 * motorControl.cpp
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#include <motorControl.h>

motorControl::motorControl(motor* M, encoder* E) {
	// TODO Auto-generated constructor stub
	m = M;
	e = E;
}

motorControl::~motorControl() {
	// TODO Auto-generated destructor stub
}

/*void motorControl::Speed(int speed) {
	if(speed >= 0) {
		m->CW();
		speed = speed;
	} else {
		m->CCW();
		speed = -speed;
	}
	m->PWM(speed);
}*/

void motorControl::InitConsts(float KP, float KD) {
	kp = KP;
	kd = KD;
}

void motorControl::Speed(int speed)  {
	if(speed >= 0) {
		m->CW();
		sinal = speed;
	} else {
		m->CCW();
		sinal = -speed;
	}

	/*olderror = error;
	error = sinal - (e->GetRps() / 6.0262783);
	errorDer = error - olderror;

	pid = kp*error + kd*errorDer;
	sinal+=(pid);*/
	m->PWM(sinal);
}

void motorControl::Break() {
	m->MotorBreak();
}

uint32_t motorControl::GetRotations() {
	return e->GetRotation();
}

int motorControl::GetSpeed() {
	return sinal;
}
