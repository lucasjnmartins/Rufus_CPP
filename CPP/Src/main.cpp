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
#include "motorControl.h"
#include "control.h"
#include "robot.h"
#include "encoder.h"
#include "sensorSide.h"
#include "main.h"
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

enum {
	WAITING,
	CALIBRATION,
	PRE_RUN,
	RUNNING,
	FINISH
};

position p;
sensorSide marcEsq(MARC_ESQ_GPIO_Port, MARC_ESQ_Pin);
sensorSide marcDir(MARC_DIR_GPIO_Port, MARC_DIR_Pin);

led lfdir(L_FDIR_GPIO_Port, L_FDIR_Pin);
led lfesq(L_FESQ_GPIO_Port, L_FESQ_Pin);
led lfren(L_FREN_GPIO_Port, L_FREN_Pin);
led ldeb1(L_DEBUG1_GPIO_Port, L_DEBUG1_Pin);
led ldeb2(L_DEBUG2_GPIO_Port, L_DEBUG2_Pin);

button b(BUTTON_GPIO_Port, BUTTON_Pin);
encoder enc1(ENC1_GPIO_Port, ENC1_Pin);
encoder enc2(ENC2_GPIO_Port, ENC2_Pin);

int pos, k = 0, cont1, cont2, dirteste;
uint32_t z = 0;
uint16_t debounce = 0, state = 0, dbEsq = 0, dbDir = 0;
//test teste(&htim14);

motor m1(&htim17, 1, AIN2_GPIO_Port, AIN2_Pin, AIN1_GPIO_Port, AIN1_Pin);
motor m2(&htim16, 1, BIN2_GPIO_Port, BIN2_Pin, BIN1_GPIO_Port, BIN1_Pin);

motorControl mdir(&m1, &enc1);
motorControl mesq(&m2, &enc2);

control ctr(&p);
map circuit;

robot rufus(&ctr, &mdir, &mesq, &circuit);


void CppMain() {
	lfdir.Off();
	lfesq.Off();
	lfren.Off();
	ldeb1.Off();
	ldeb2.Off();

	while(1) {
		//dirteste = HAL_GPIO_ReadPin(MARC_DIR_GPIO_Port, MARC_DIR_Pin);
		switch(state) {
		case WAITING:
			mdir.Break();
			mesq.Break();
			break;

		case CALIBRATION:
			rufus.Calibrate(&z);
			circuit.InitTracks();
			state = PRE_RUN;
			break;

		case PRE_RUN:
			mdir.Break();
			mesq.Break();
			break;

		case RUNNING:
			rufus.Running();
			break;

		case FINISH:
			rufus.Finish(&z);
			state = WAITING;
			break;

		default:
			break;
		}
	}
}


void ADC_Interrupt(uint8_t* Array, int size) {
	p.SetAnalog(Array, size);
	ctr.PIDValue();
}


void TIM1_Interrupt() {
	if(z != 60000) {
		z++;
		if(z >= 50000) {
			z = 0;
		}
	}
	if(debounce > 0) {
		debounce--;
	}
	if(dbDir > 0) {
		if(state == RUNNING && dbDir == 1) {
			if(rufus.GetPosition() == 0) {
				rufus.NextState();
				enc1.RestartRotation();
				enc2.RestartRotation();
			}
			marcDir.NextTrack();

			if(marcDir.CurrentTrack() == 12) {
				rufus.NextState();
				mdir.Break();
				mesq.Break();
				state = FINISH;
			}
		}
		dbDir--;
	}

	if(dbEsq > 0) {
		if(state == RUNNING && dbEsq == 1) {
			rufus.NextState();
			marcEsq.NextTrack();
			enc1.RestartRotation();
			enc2.RestartRotation();
			if(marcEsq.CurrentTrack() == 82) {
				rufus.NextState();
				mdir.Break();
				mesq.Break();
				state = FINISH;
			}
		}
		dbEsq--;
	}

	if((state == RUNNING) || (state == CALIBRATION)) {
		enc1.Cont();
		enc2.Cont();
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == enc1.GetPin()) {
		if((state == RUNNING) || (state == CALIBRATION)) {
			//enc1.SetRps();
			enc1.RotationCont(mdir.GetSpeed());
			//rufus.CompareRotations();
		}
	}

	if (GPIO_Pin == enc2.GetPin()) {
		if((state == RUNNING) || (state == CALIBRATION)) {
			//enc2.SetRps();
			enc2.RotationCont(mesq.GetSpeed());
			//rufus.CompareRotations();
		}
	}

	if (GPIO_Pin == b.GetPin()) {
		if(debounce == 0) {
			debounce = 2000;
			switch(state) {
			case 0:
				state = 1;
				break;
			case 1:
				state = 2;
				break;
			case 2:
				rufus.ChangeTrack();
				state = 3;
				break;
			case 3:
				state = 0;
				break;
			default:
				break;
			}
		}
	}

	if (GPIO_Pin == marcEsq.GetPin()) {
		if(marcEsq.State() == GPIO_PIN_RESET) {
			dbEsq = 30;

			if(state == PRE_RUN) {
				rufus.sumLess();
			}

			lfesq.On();
		} else {

			lfesq.Off();
		}

	}

	if (GPIO_Pin == marcDir.GetPin()) {
		if(marcDir.State() == GPIO_PIN_RESET){
			dbDir = 30;

			if(state == PRE_RUN) {
				rufus.sumPlus();
			}
			lfdir.On();
		} else {
			lfdir.Off();
		}
	}
}



