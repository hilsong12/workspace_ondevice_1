

#ifndef INC_DELAY_US_H_
#define INC_DELAY_US_H_


//#include "main.h"
#include "stm32f4xx_hal.h" //할함수를 몽땅 가지고 있다.    main.h가 이걸 끌어 당긴다.
//#include "stm32f1xx_hal.h"
//#include "stm32c1xx_hal.h"
#include "tim.h"


void delay_us(uint16_t us);   //65535까지 밖에 못씀 그래서 인트16

#endif /* INC_DELAY_US_H_ */
