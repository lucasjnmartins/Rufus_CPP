/*
 * test.cpp
 *
 *  Created on: Jun 11, 2022
 *      Author: Lucas Martins
 */

#include "test.h"

test::test(TIM_HandleTypeDef* TIMER) {
	// TODO Auto-generated constructor stub
	timer = TIMER;
}

test::~test() {
	// TODO Auto-generated destructor stub
}

void test::PWM(uint8_t valor) {
	timer->Instance->CCR1 = (uint32_t)valor;
}

