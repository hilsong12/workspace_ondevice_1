#ifndef STEPPER_H
#define STEPPER_H

#include "stdint.h"

void Stepper_Init(void);
void Stepper_SetDirection(uint8_t dir);
void Stepper_Update(void);
void Stepper_Stop(void);

#endif
