/*
 * map.h
 *
 *  Created on: Jun 26, 2022
 *      Author: Lucas Martins
 */

#ifndef MAP_H_
#define MAP_H_

#include "main.h"

class map {
public:
	map();
	virtual ~map();
	void InitTracks();
	uint8_t GetBaseSpeed(uint8_t);
	float GetKp(uint8_t);
	float GetKd(uint8_t);
	void SetTrackRotations(uint8_t, uint32_t, uint32_t);

private:
	uint8_t baseSpeed[TRACKS];
	float kp[TRACKS];
	float kd[TRACKS];
	uint32_t rotationsDir[TRACKS];
	uint32_t rotationsEsq[TRACKS];

};

#endif /* MAP_H_ */
