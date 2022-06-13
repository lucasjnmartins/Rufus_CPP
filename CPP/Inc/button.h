/*
 * button.h
 *
 *  Created on: Jun 10, 2022
 *      Author: Lucas Martins
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"

class button {
public:
	button(GPIO_TypeDef*, uint16_t);
	virtual ~button();
	uint16_t GetPin();
	GPIO_PinState State();

private:
	uint16_t pin;
	GPIO_TypeDef* port;
};

#endif /* BUTTON_H_ */
