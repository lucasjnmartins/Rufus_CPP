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
	void Running();
	int GetPosition();
	void Calibrate(uint32_t*);
	void ChangeTrack();
	void sumPlus();
	void sumLess();
	void CompareRotations();
	void Finish(uint32_t*);

private:
	control* ctr;
	motorControl* mdir;
	motorControl* mesq;
	map* circuit;
	uint8_t pos;

	int sum;
	float velDir;
	float velEsq;
	int velBase;
	int velMax;
	int relationDir, relationEsq;
	int velDirNew;
	int velEsqNew;

};

#endif /* ROBOT_H_ */
