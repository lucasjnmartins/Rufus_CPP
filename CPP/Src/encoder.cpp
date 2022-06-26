/*
 * encoder.cpp
 *
 *  Created on: Jun 23, 2022
 *      Author: Lucas Martins
 */

#include "encoder.h"

encoder::encoder(GPIO_TypeDef* PORT, uint16_t PIN) {
	// TODO Auto-generated constructor stub
	port = PORT;
	pin = PIN;
	rps = 0;
	time = 0;
	cont = 0;
}

encoder::~encoder() {
	// TODO Auto-generated destructor stub
}

uint16_t encoder::GetPin() {
	return pin;
}

GPIO_PinState encoder::State() {
	return HAL_GPIO_ReadPin(port, pin);
}

int encoder::GetRps() {
	return rps;
}

void encoder::SetRps() {
	time = cont;
	if(time < 200) {
		rps = 1 / (0.00015*time);
	} else {
		rps = 0;
	}
	cont = 0;
}

void encoder::Cont() {
	if(cont < 200) {
		cont++;
	} else {
		SetRps();
	}
}
