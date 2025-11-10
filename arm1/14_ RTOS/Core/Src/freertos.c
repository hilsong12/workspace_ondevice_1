/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LED_TASK_01 */
osThreadId_t LED_TASK_01Handle;
const osThreadAttr_t LED_TASK_01_attributes = {
  .name = "LED_TASK_01",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LED_TASK_02 */
osThreadId_t LED_TASK_02Handle;
const osThreadAttr_t LED_TASK_02_attributes = {
  .name = "LED_TASK_02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LEDTASK01(void *argument);
void LEDTASK02(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LED_TASK_01 */
  LED_TASK_01Handle = osThreadNew(LEDTASK01, NULL, &LED_TASK_01_attributes);

  /* creation of LED_TASK_02 */
  LED_TASK_02Handle = osThreadNew(LEDTASK02, NULL, &LED_TASK_02_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_LEDTASK01 */
/**
* @brief Function implementing the LED_TASK_01 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LEDTASK01 */
void LEDTASK01(void *argument)
{
  /* USER CODE BEGIN LEDTASK01 */
  /* Infinite loop */
  for(;;)
  {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
    osDelay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
    osDelay(500);
  }
  /* USER CODE END LEDTASK01 */
}

/* USER CODE BEGIN Header_LEDTASK02 */
/**
* @brief Function implementing the LED_TASK_02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LEDTASK02 */
void LEDTASK02(void *argument)
{
  /* USER CODE BEGIN LEDTASK02 */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
	  osDelay(1000);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
	  osDelay(1000);
//	  vTaskDelay(xTicksToDelay)

  }
  /* USER CODE END LEDTASK02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

