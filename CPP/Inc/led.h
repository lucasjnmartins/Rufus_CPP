/*
 * led.h
 *
 *  Created on: Jun 9, 2022
 *      Author: Lucas Martins
 */

#ifndef LED_H_
#define LED_H_

#include "main.h"

class led {
public:
	led(GPIO_TypeDef*, uint16_t);
	virtual ~led();
	void On();
	void Off();
	void Toggle();

private:
	GPIO_TypeDef* port;
	uint16_t pin;

};

#endif /* LED_H_ */
