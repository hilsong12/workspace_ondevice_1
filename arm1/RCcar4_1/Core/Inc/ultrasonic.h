
#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_


#define TRIG_PORT	GPIOA
#define TRIG_PIN	GPIO_PIN_5


#include "main.h"
#include "tim.h"
#include "delay_us.h"

extern uint8_t distance1 ;
extern uint8_t distance2 ;
extern uint8_t distance3 ;


void HCSR04_TRIGGER();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#endif /* INC_ULTRASONIC_H_ */
