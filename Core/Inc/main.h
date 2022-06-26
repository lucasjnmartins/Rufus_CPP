/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define BUFFER 42
void CppMain();
void ADC_Interrupt(uint8_t*, int);
void TIM1_Interrupt();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AIN1_Pin GPIO_PIN_13
#define AIN1_GPIO_Port GPIOC
#define AIN2_Pin GPIO_PIN_14
#define AIN2_GPIO_Port GPIOC
#define BIN1_Pin GPIO_PIN_15
#define BIN1_GPIO_Port GPIOC
#define BIN2_Pin GPIO_PIN_0
#define BIN2_GPIO_Port GPIOF
#define MARC_DIR_Pin GPIO_PIN_1
#define MARC_DIR_GPIO_Port GPIOF
#define L_FESQ_Pin GPIO_PIN_0
#define L_FESQ_GPIO_Port GPIOB
#define L_FREN_Pin GPIO_PIN_1
#define L_FREN_GPIO_Port GPIOB
#define L_FDIR_Pin GPIO_PIN_2
#define L_FDIR_GPIO_Port GPIOB
#define MARC_ESQ_Pin GPIO_PIN_8
#define MARC_ESQ_GPIO_Port GPIOA
#define MARC_ESQ_EXTI_IRQn EXTI4_15_IRQn
#define BUTTON_Pin GPIO_PIN_11
#define BUTTON_GPIO_Port GPIOA
#define BUTTON_EXTI_IRQn EXTI4_15_IRQn
#define ENC2_Pin GPIO_PIN_12
#define ENC2_GPIO_Port GPIOA
#define ENC2_EXTI_IRQn EXTI4_15_IRQn
#define L_DEBUG2_Pin GPIO_PIN_6
#define L_DEBUG2_GPIO_Port GPIOF
#define L_DEBUG1_Pin GPIO_PIN_7
#define L_DEBUG1_GPIO_Port GPIOF
#define ENC1_Pin GPIO_PIN_7
#define ENC1_GPIO_Port GPIOB
#define ENC1_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
