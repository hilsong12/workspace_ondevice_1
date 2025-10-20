#include "sensor.h"
#include "main.h"
#include "elevator.h"
#include "stepper.h"
#include "fnd.h"

extern Elevator_t elevator;

void Sensor_EXTI_Init(void){
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = FLOOR1_Pin|FLOOR2_Pin|FLOOR3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI0_IRQn,2,0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    HAL_NVIC_SetPriority(EXTI1_IRQn,2,0);
    HAL_NVIC_EnableIRQ(EXTI1_IRQn);
    HAL_NVIC_SetPriority(EXTI2_IRQn,2,0);
    HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin==FLOOR1_Pin) elevator.currentFloor=1;
    else if(GPIO_Pin==FLOOR2_Pin) elevator.currentFloor=2;
    else if(GPIO_Pin==FLOOR3_Pin) elevator.currentFloor=3;

    Stepper_Stop();
    FND_Update(elevator.currentFloor);

    if(elevator.nextTargetFloor)
        Elevator_SetTarget(&elevator,elevator.nextTargetFloor);
}
