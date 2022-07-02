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
	//uint8_t GetBaseSpeed(uint8_t);
	uint8_t GetHighSpeed(uint8_t);
	float GetKp(uint8_t);
	float GetKd(uint8_t);
	uint16_t GetRotationsDir(uint8_t);
	uint16_t GetRotationsEsq(uint8_t);
	void SetTrackRotations(uint8_t, uint16_t, uint16_t);
	float GetWaitChangeInit(uint8_t);
	float GetWaitChangeFinish(uint8_t);
	uint8_t baseSpeed;

private:
	//uint8_t baseSpeed[TRACKS];
	uint8_t highSpeed[TRACKS];
	uint16_t kp[TRACKS];
	uint16_t kd[TRACKS];
	float waitChangeInit[TRACKS];
	float waitChangeFinish[TRACKS];
	uint16_t rotationsDir[TRACKS];
	uint16_t rotationsEsq[TRACKS];

};

#endif /* MAP_H_ */
