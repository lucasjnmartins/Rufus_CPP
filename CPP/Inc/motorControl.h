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

class motorControl {
public:
	motorControl(motor*);
	virtual ~motorControl();
	void Break();
	void Speed(int);
private:
	motor* m;
	int der;
};

#endif /* INC_MOTORCONTROL_H_ */
