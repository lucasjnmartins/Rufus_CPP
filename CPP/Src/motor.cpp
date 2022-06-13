/*
 * motor.cpp
 *
 *  Created on: Jun 10, 2022
 *      Author: Lucas Martins
 */

#include "motor.h"

motor::motor(TIM_HandleTypeDef*  TIMER, uint8_t CHANNEL,  GPIO_TypeDef* PORT1, uint16_t PIN1, GPIO_TypeDef* PORT2, uint16_t PIN2) {
	// TODO Auto-generated constructor stub
	channel = CHANNEL;
	timer = TIMER;
	in1Port = PORT1;
	in2Port = PORT2;
	in1Pin = PIN1;
	in2Pin = PIN2;
}

motor::~motor() {
	// TODO Auto-generated destructor stub
}



void motor::PWM(uint8_t pwm) {
	if(pwm > 255) {
		pwm = 255;
	}
	if( channel == 1) {
		timer->Instance->CCR1 = pwm;
	} else if(channel == 2) {
		timer->Instance->CCR2 = pwm;
	} else if(channel == 2) {
		timer->Instance->CCR1 = pwm;
	} else if(channel == 2) {
		timer->Instance->CCR3 = pwm;
	} else {
		timer->Instance->CCR4 = pwm;
	}

}

void motor::CW() {
	HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_RESET);
}

void motor::CCW() {
	HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_SET);
}

void motor::MotorBreak() {
	HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_SET);
}



