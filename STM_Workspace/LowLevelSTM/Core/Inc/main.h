/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Led_Pin GPIO_PIN_13
#define Led_GPIO_Port GPIOC
#define ResetMotors_Pin GPIO_PIN_4
#define ResetMotors_GPIO_Port GPIOA
#define SleepMotors_Pin GPIO_PIN_5
#define SleepMotors_GPIO_Port GPIOA
#define Nema1_Dir_Pin GPIO_PIN_6
#define Nema1_Dir_GPIO_Port GPIOA
#define Nema1_En_Pin GPIO_PIN_7
#define Nema1_En_GPIO_Port GPIOA
#define PWM_Nema1_Pin GPIO_PIN_8
#define PWM_Nema1_GPIO_Port GPIOA
#define Nema3_En_Pin GPIO_PIN_4
#define Nema3_En_GPIO_Port GPIOB
#define Nema3_Dir_Pin GPIO_PIN_5
#define Nema3_Dir_GPIO_Port GPIOB
#define Nema2_En_Pin GPIO_PIN_6
#define Nema2_En_GPIO_Port GPIOB
#define Nema2_Dir_Pin GPIO_PIN_7
#define Nema2_Dir_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
