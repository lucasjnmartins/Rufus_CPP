/*
 * button.cpp
 *
 *  Created on: Jun 10, 2022
 *      Author: Lucas Martins
 */

#include "button.h"

button::button(GPIO_TypeDef* PORT, uint16_t PIN) {
	// TODO Auto-generated constructor stub
	port = PORT;
	pin = PIN;
}

button::~button() {
	// TODO Auto-generated destructor stub
}

uint16_t button::GetPin() {
	return pin;
}

GPIO_PinState button::State() {
	return HAL_GPIO_ReadPin(port, pin);
}
