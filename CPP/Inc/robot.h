/*
 * robot.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Lucas Martins
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "control.h"
#include "motorControl.h"
#include "main.h"

class robot {
public:
	robot(control*, motorControl*, motorControl*);
	virtual ~robot();
	void NextState();
	float module(float);
	void RunningState(uint8_t);
	int GetPosition();
	void Calibrate(int*);

private:
	control* ctr;
	motorControl* mdir;
	motorControl* mesq;

	float velDir;
	float velEsq;
	int velMax;
	int velBase;
	int velDirNew;
	int velEsqNew;

};

#endif /* ROBOT_H_ */
