/*
 * test.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Lucas Martins
 */

#ifndef TEST_H_
#define TEST_H_

#include "main.h"

class test {
public:
	test(TIM_HandleTypeDef*);
	virtual ~test();
	void PWM(uint8_t);
	TIM_HandleTypeDef* timer;
};

#endif /* TEST_H_ */
