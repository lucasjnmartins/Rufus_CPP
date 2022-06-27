/*
 * map.cpp
 *
 *  Created on: Jun 26, 2022
 *      Author: Lucas Martins
 */

#include "map.h"

map::map() {
	// TODO Auto-generated constructor stub
}

map::~map() {
	// TODO Auto-generated destructor stub
}

void map::InitTracks() {
	uint8_t auxBaseSpeed[TRACKS] = {
		65, 65, 65, 65, 65,
		65, 65, 65, 65, 65,
		65, 65, 65, 65, 65,
		65, 65, 65, 65, 65,
		65, 65, 65, 65
	};

	float auxKp[TRACKS] = {
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3
	};

	float auxKd[TRACKS] = {
		12, 12, 12, 12, 12,
		12, 12, 12, 12, 12,
		12, 12, 12, 12, 12,
		12, 12, 12, 12, 12,
		12, 12, 12, 12
	};

	for (int i=0; i<TRACKS; i++) {
		baseSpeed[i] = auxBaseSpeed[i];
		kp[i] = auxKp[i];
		kd[i] = auxKd[i];
	}
}

uint8_t map::GetBaseSpeed(uint8_t pos) {
	return baseSpeed[pos];
}

float map::GetKp(uint8_t pos) {
	return kp[pos];
}

float map::GetKd(uint8_t pos) {
	return kd[pos];
}

void map::SetTrackRotations(uint8_t pos, uint32_t rotDir, uint32_t rotEsq) {
	rotationsDir[pos] = rotDir;
	rotationsEsq[pos] = rotEsq;
}
