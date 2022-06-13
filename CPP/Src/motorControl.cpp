/*
 * motorControl.cpp
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#include <motorControl.h>

motorControl::motorControl(motor* M) {
	// TODO Auto-generated constructor stub
	m = M;
}

motorControl::~motorControl() {
	// TODO Auto-generated destructor stub
}

void motorControl::Speed(int speed) {
	if(speed >= 0) {
		m->CW();
		speed = speed;
	} else {
		m->CCW();
		speed = -speed;
	}
	m->PWM(speed);
}

void motorControl::Break() {
	m->MotorBreak();
}
