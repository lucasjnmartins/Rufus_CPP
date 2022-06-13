/*
 * motor.h
 *
 *  Created on: Jun 10, 2022
 *      Author: Lucas Martins
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "main.h"

class motor {
public:
	motor(TIM_HandleTypeDef*, uint8_t, GPIO_TypeDef*, uint16_t, GPIO_TypeDef*, uint16_t);
	virtual ~motor();
	void CCW();
	void CW();
	void PWM(uint8_t);
	void MotorBreak();

private:
	TIM_HandleTypeDef*  timer;
	uint8_t channel;
	GPIO_TypeDef* in1Port;
	GPIO_TypeDef* in2Port;
	uint16_t in1Pin;
	uint16_t in2Pin;

};

#endif /* MOTOR_H_ */
