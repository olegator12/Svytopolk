/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define FS_PPM_Pin GPIO_PIN_0
#define FS_PPM_GPIO_Port GPIOA
#define ADC1_Pin GPIO_PIN_3
#define ADC1_GPIO_Port GPIOA
#define ADC2_Pin GPIO_PIN_4
#define ADC2_GPIO_Port GPIOA
#define ADC3_Pin GPIO_PIN_5
#define ADC3_GPIO_Port GPIOA
#define BTN1_PWM_Pin GPIO_PIN_6
#define BTN1_PWM_GPIO_Port GPIOA
#define BTN2_PWM_Pin GPIO_PIN_7
#define BTN2_PWM_GPIO_Port GPIOA
#define BTN3_PWM_Pin GPIO_PIN_0
#define BTN3_PWM_GPIO_Port GPIOB
#define PDI4_PWM_Pin GPIO_PIN_8
#define PDI4_PWM_GPIO_Port GPIOA
#define PDI3_PWM_Pin GPIO_PIN_9
#define PDI3_PWM_GPIO_Port GPIOA
#define PDI2_PWM_Pin GPIO_PIN_10
#define PDI2_PWM_GPIO_Port GPIOA
#define PDI1_PWM_Pin GPIO_PIN_11
#define PDI1_PWM_GPIO_Port GPIOA
#define BTN1_DIR_Pin GPIO_PIN_3
#define BTN1_DIR_GPIO_Port GPIOB
#define BTN2_DIR_Pin GPIO_PIN_4
#define BTN2_DIR_GPIO_Port GPIOB
#define BTN3_DIR_Pin GPIO_PIN_5
#define BTN3_DIR_GPIO_Port GPIOB
#define PDI5_PWM_Pin GPIO_PIN_6
#define PDI5_PWM_GPIO_Port GPIOB
#define PDI6_PWM_Pin GPIO_PIN_7
#define PDI6_PWM_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
