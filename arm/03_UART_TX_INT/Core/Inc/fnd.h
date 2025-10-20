
#ifndef INC_FND_H_
#define INC_FND_H_

#include "main.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} SegmentPin;


void displayNumber(uint8_t num);





#endif /* INC_FND_H_ */
