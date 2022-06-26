/*
 * position.cpp
 *
 *  Created on: Jun 9, 2022
 *      Author: Lucas Martins
 */

#include "position.h"

position::position() {
	// TODO Auto-generated constructor stub

}

position::~position() {
	// TODO Auto-generated destructor stub
}

void position::SetAnalog(uint8_t* array, int size) {
	uint32_t aux;
	for(int i=0; i<CHANNELS; i++) {
		aux = 0;
		for(int j=0; j<(size/CHANNELS); j++) {
			aux = aux + array[i+j*CHANNELS];
		}
		sensors_analog[i] = aux / (size/CHANNELS);
	}
	SetSensors();
}

void position::InitCalibration() {
	for(int i=0; i<CHANNELS; i++) {
		max[i] = 0;
		min[i] = 255;
		med[i] = 0;
	}
}

void position::CalibrateSensors() {
	for(int i=0; i<CHANNELS; i++) {
		if(sensors_analog[i] > max[i]){
			max[i] = sensors_analog[i];
		}
		if(sensors_analog[i] < min[i]) {
			min[i] = sensors_analog[i];
		}
		med[i] = (max[i] + min[i]) / 2;
	}
}

void position::SetSensors() {
	for(int i=0; i<CHANNELS; i++) {
		if(sensors_analog[i] < med[i]){
			sensors[i] = 1;
		} else {
			sensors[i] = 0;
		}
	}
}

int position::DefinePosition() {
	if(sensors[2] && sensors[3]) {
		oldPos = 0;
		return 0;
	} else if (sensors[3] && sensors[4]) {
		oldPos = 2;
		return 2;
	} else if (sensors[1] && sensors[2]) {
		oldPos = -2;
		return -2;
	} else if (sensors[4] && sensors[5]) {
		oldPos = 4;
		return 4;
	} else if (sensors[0] && sensors[1]) {
		oldPos = -4;
		return -4;
	} else if (sensors[3]) {
		oldPos = 1;
		return 1;
	} else if (sensors[2]) {
		oldPos = -1;
		return -1;
	} else if (sensors[4]) {
		oldPos = 3;
		return 3;
	} else if (sensors[1]) {
		oldPos = -3;
		return -3;
	} else if (sensors[5]) {
		return 5;
	} else if (sensors[0]) {
		oldPos = -5;
		return -5;
	}
	return oldPos;
}


