/*
 * sensorSide.h
 *
 *  Created on: Jun 26, 2022
 *      Author: Lucas Martins
 */

#ifndef SENSORSIDE_H_
#define SENSORSIDE_H_

#include "main.h"

class sensorSide {
public:
	sensorSide(GPIO_TypeDef*, uint16_t);
	virtual ~sensorSide();
	void InitTrack();
	void NextTrack();
	uint8_t CurrentTrack();
	uint16_t GetPin();
	GPIO_PinState State();

private:
	uint8_t track;
	uint16_t pin;
	GPIO_TypeDef* port;

};

#endif /* SENSORSIDE_H_ */
