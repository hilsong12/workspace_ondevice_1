/*
 * led.h
 *
 *  Created on: Oct 13, 2025
 *      Author: user13
 */

#ifndef INC_LED_H_
#define INC_LED_H_


#include "main.h"
#include "stdint.h"


typedef struct
{
	GPIO_TypeDef	*port;
	uint16_t			pinNumber;
	GPIO_PinState onState;
	GPIO_PinState offState;
}LED_CONTROL;

static LED_CONTROL externalButtonLed[4]=
        {
                {GPIOA, GPIO_PIN_15, GPIO_PIN_SET, GPIO_PIN_RESET},
                {GPIOB, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
                {GPIOC, GPIO_PIN_11, GPIO_PIN_SET, GPIO_PIN_RESET},
                {GPIOD, GPIO_PIN_2, GPIO_PIN_SET, GPIO_PIN_RESET},
        };


void segNumOn(uint8_t num);
void segNumOff(uint8_t num);

#endif /* INC_LED_H_ */
