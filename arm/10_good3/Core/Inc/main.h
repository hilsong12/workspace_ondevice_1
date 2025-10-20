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

// 외부 버튼
#define BTN_1_UP_Pin       GPIO_PIN_1
#define BTN_2_UP_Pin       GPIO_PIN_15
#define BTN_2_DOWN_Pin     GPIO_PIN_14
#define BTN_3_DOWN_Pin     GPIO_PIN_13
#define BTN_1_UP_GPIO_Port GPIOB
#define BTN_2_UP_GPIO_Port GPIOB
#define BTN_2_DOWN_GPIO_Port GPIOB
#define BTN_3_DOWN_GPIO_Port GPIOB

// 내부 버튼
#define BTN_INT_1_Pin      GPIO_PIN_0
#define BTN_INT_2_Pin      GPIO_PIN_1
#define BTN_INT_3_Pin      GPIO_PIN_4
#define BTN_INT_1_GPIO_Port GPIOA
#define BTN_INT_2_GPIO_Port GPIOA
#define BTN_INT_3_GPIO_Port GPIOA

// 층 센서
#define FLOOR1_Pin         GPIO_PIN_2
#define FLOOR2_Pin         GPIO_PIN_1
#define FLOOR3_Pin         GPIO_PIN_0
#define FLOOR1_GPIO_Port   GPIOC
#define FLOOR2_GPIO_Port   GPIOC
#define FLOOR3_GPIO_Port   GPIOC

// FND
#define FND_A_Pin GPIO_PIN_9
#define FND_B_Pin GPIO_PIN_8
#define FND_C_Pin GPIO_PIN_10
#define FND_D_Pin GPIO_PIN_4
#define FND_E_Pin GPIO_PIN_5
#define FND_F_Pin GPIO_PIN_3
#define FND_G_Pin GPIO_PIN_10
#define FND_A_GPIO_Port GPIOA
#define FND_B_GPIO_Port GPIOA
#define FND_C_GPIO_Port GPIOB
#define FND_D_GPIO_Port GPIOB
#define FND_E_GPIO_Port GPIOB
#define FND_F_GPIO_Port GPIOB
#define FND_G_GPIO_Port GPIOA

// 모터
#define IN1_Pin GPIO_PIN_5
#define IN2_Pin GPIO_PIN_6
#define IN3_Pin GPIO_PIN_7
#define IN4_Pin GPIO_PIN_6
#define IN1_GPIO_Port GPIOA
#define IN2_GPIO_Port GPIOA
#define IN3_GPIO_Port GPIOA
#define IN4_GPIO_Port GPIOB

// EMERGENCY & BUZZER
#define EMG_STOP_Pin GPIO_PIN_5
#define BUZZER_Pin GPIO_PIN_2
#define EMG_STOP_GPIO_Port GPIOB
#define BUZZER_GPIO_Port GPIOB

// UART
#define UART1_TX_Pin GPIO_PIN_11
#define UART1_RX_Pin GPIO_PIN_12
#define UART2_TX_Pin GPIO_PIN_2
#define UART2_RX_Pin GPIO_PIN_3
#define UART1_TX_GPIO_Port GPIOA
#define UART1_RX_GPIO_Port GPIOA
#define UART2_TX_GPIO_Port GPIOA
#define UART2_RX_GPIO_Port GPIOA



#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

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

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
