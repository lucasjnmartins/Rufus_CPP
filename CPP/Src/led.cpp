/*
 * led.cpp
 *
 *  Created on: Jun 9, 2022
 *      Author: Lucas Martins
 */

#include "led.h"

led::led(GPIO_TypeDef* PORT, uint16_t PIN) {
	// TODO Auto-generated constructor stub
	port = PORT;
	pin = PIN;
}

led::~led() {
	// TODO Auto-generated destructor stub
}

void led::On() {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void led::Off() {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void led::Toggle() {
	HAL_GPIO_TogglePin(port, pin);
}


