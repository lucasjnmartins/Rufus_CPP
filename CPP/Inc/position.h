/*
 * position.h
 *
 *  Created on: Jun 9, 2022
 *      Author: Lucas Martins
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "main.h"
#define CHANNELS 6



class position {
public:
	position();
	virtual ~position();
	void SetAnalog(uint8_t*, int);
	void InitCalibration();
	void CalibrateSensors();
	int DefinePosition();

private:
	int oldPos;
	uint8_t med[CHANNELS], min[CHANNELS], max[CHANNELS];
	uint8_t sensors_analog[CHANNELS];
	bool sensors[CHANNELS];
	void SetSensors();

};

#endif /* POSITION_H_ */
