/*
 * main.cpp
 *
 *  Created on: Jun 9, 2022
 *      Author: Lucas Martins
 */
#include "main.h"
#include "position.h"
#include "led.h"
#include "button.h"
#include "motor.h"
#include "test.h"
#include "motorControl.h"
#include "control.h"
#include "robot.h"
#include "main.h"
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

position p;
led lfdir(L_FDIR_GPIO_Port, L_FDIR_Pin);
led lfesq(L_FESQ_GPIO_Port, L_FESQ_Pin);
led lfren(L_FREN_GPIO_Port, L_FREN_Pin);
button b(BUTTON_GPIO_Port, BUTTON_Pin);
int z = 0, pos, k=0;
uint8_t debounce = 0, state = 0;
//test teste(&htim14);
motor m1(&htim17, 1, AIN1_GPIO_Port, AIN1_Pin, AIN2_GPIO_Port, AIN2_Pin);
motor m2(&htim16, 1, BIN1_GPIO_Port, BIN1_Pin, BIN2_GPIO_Port, BIN2_Pin);

motorControl mdir(&m1);
motorControl mesq(&m2);

control controle(&p);
robot rufus(&controle, &mdir, &mesq);
float pidValue, vel1, vel2;


void CppMain() {
	lfdir.Off();
	lfesq.Off();
	lfren.Off();
	p.InitCalibration();
	rufus.Calibrate(&z);

	while(1) {
		rufus.RunningState(state);
		if (state == 1) {
			pos = p.DefinePosition();
			if((pos < -3) && (pos >= -5)) {
				lfdir.On();
				lfesq.Off();
				lfren.Off();
			} else if((pos < 0) && (pos > -3)) {
				lfdir.On();
				lfesq.Off();
				lfren.On();
			} else if(pos == 0) {
				lfdir.Off();
				lfesq.Off();
				lfren.On();
			} else if((pos > 0) && (pos < 3)) {
				lfdir.Off();
				lfesq.On();
				lfren.On();
			} else if((pos > 3) && (pos <= 5)) {
				lfdir.Off();
				lfesq.On();
				lfren.Off();
			}
		} else {
			lfdir.On();
			lfesq.On();
			lfren.On();
		}

	}
}


void ADC_Interrupt(uint8_t* Array, int size) {
	p.SetAnalog(Array, size);
	pidValue = controle.PIDValue();
}


void TIM1_Interrupt() {
	if(z != -1) {
		z++;
		if(z >= 200) {
			z = 0;
		}
	}

	if(debounce > 0) {
		debounce--;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == b.GetPin()) {
		if(debounce == 0) {
			debounce = 5;
			switch(state) {
			case 0:
				state = 1;
				break;
			case 1:
				state = 0;
				break;
			default:
				break;
			}
		}
	}
}


