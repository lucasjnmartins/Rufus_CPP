/*
 * encoder.h
 *
 *  Created on: Jun 23, 2022
 *      Author: Lucas Martins
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "main.h"

class encoder {
public:
	encoder(GPIO_TypeDef*, uint16_t);
	virtual ~encoder();
	int GetRps();
	void Cont();
	void SetRps();
	uint16_t GetPin();
	GPIO_PinState State();

private:
	int rps, time;
	int cont;
	uint16_t pin;
	GPIO_TypeDef* port;

};

#endif /* ENCODER_H_ */
