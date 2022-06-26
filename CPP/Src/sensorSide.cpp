/*
 * sensorSide.cpp
 *
 *  Created on: Jun 26, 2022
 *      Author: Lucas Martins
 */

#include "sensorSide.h"

sensorSide::sensorSide(GPIO_TypeDef* PORT, uint16_t PIN) {
	// TODO Auto-generated constructor stub
	port = PORT;
	pin = PIN;
	track = 0;
}

sensorSide::~sensorSide() {
	// TODO Auto-generated destructor stub
}

void sensorSide::InitTrack() {
	track = 0;
}

void sensorSide::NextTrack() {
	track++;
}

uint8_t sensorSide::CurrentTrack() {
	return track;
}

uint16_t sensorSide::GetPin() {
	return pin;
}

GPIO_PinState sensorSide::State() {
	return HAL_GPIO_ReadPin(port, pin);
}







