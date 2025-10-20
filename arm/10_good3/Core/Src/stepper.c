#include "stepper.h"
#include "main.h"
#include "elevator.h"

static uint8_t stepIndex = 0;
static uint8_t direction = DIR_STOP;

const uint8_t HALF_STEP_SEQ[8][4] = {
    {1,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,1,0},
    {0,0,1,0},{0,0,1,1},{0,0,0,1},{1,0,0,1}
};

void Stepper_Init(void){
    stepIndex = 0;
    direction = DIR_STOP;
}

void Stepper_SetDirection(uint8_t dir){
    direction = dir;
}

void Stepper_Stop(void){
    direction = DIR_STOP;
    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, 0);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, 0);
    HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, 0);
    HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, 0);
}

void Stepper_Update(void){
    if(direction == DIR_STOP) return;

    HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, HALF_STEP_SEQ[stepIndex][0]);
    HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, HALF_STEP_SEQ[stepIndex][1]);
    HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, HALF_STEP_SEQ[stepIndex][2]);
    HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, HALF_STEP_SEQ[stepIndex][3]);

    if(direction == DIR_UP) stepIndex = (stepIndex+1)%8;
    else if(direction == DIR_DOWN) stepIndex = (stepIndex==0)?7:stepIndex-1;
}
