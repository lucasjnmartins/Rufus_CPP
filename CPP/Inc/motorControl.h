/*
 * motorControl.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#ifndef INC_MOTORCONTROL_H_
#define INC_MOTORCONTROL_H_

#include "main.h"
#include "motor.h"
#include "encoder.h"

class motorControl {
public:
	motorControl(motor*, encoder*);
	virtual ~motorControl();
	void Break();
	void Speed(int);
	void InitConsts(float, float);
private:
	motor* m;
	encoder* e;
	float kp, kd, pid;
	int error, errorDer, olderror, sinal;
	int der;
};

#endif /* INC_MOTORCONTROL_H_ */
