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
	void RestartRotation();
	void RotationCont(int);
	uint32_t GetRotation();
	uint16_t GetPin();
	GPIO_PinState State();

private:
	int rps, time, rotations;
	int cont;
	uint16_t pin;
	uint16_t rotation;
	GPIO_TypeDef* port;

};

#endif /* ENCODER_H_ */
