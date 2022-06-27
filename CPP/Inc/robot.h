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
#include "map.h"
#include "main.h"

class robot {
public:
	robot(control*, motorControl*, motorControl*, map*);
	virtual ~robot();
	void NextState();
	float module(float);
	void RunningState(uint8_t);
	int GetPosition();
	void Calibrate(uint32_t*);
	void ChangeTrack();

private:
	control* ctr;
	motorControl* mdir;
	motorControl* mesq;
	map* circuit;

	uint8_t pos;
	float velDir;
	float velEsq;
	int velMax;
	int velBase;
	int velDirNew;
	int velEsqNew;

};

#endif /* ROBOT_H_ */
