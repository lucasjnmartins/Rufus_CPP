/*
 * control.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "position.h"
#include "main.h"

class control {
public:
	control(position*);
	position* p;
	virtual ~control();
	void setKP(float);
	void setKD(float);
	float PIDValue();
	int GetPosition();

private:
	float kp;
	float kd;
	int der;
	float PID;
	float oldPID;
	int pos;
	int oldPos;

};

#endif /* CONTROL_H_ */
