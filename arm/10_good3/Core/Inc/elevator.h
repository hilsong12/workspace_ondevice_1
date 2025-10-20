#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "stdint.h"

#define DIR_STOP 0
#define DIR_UP   1
#define DIR_DOWN 2

typedef struct {
    uint8_t currentFloor;
    uint8_t targetFloor;
    uint8_t nextTargetFloor;
    uint8_t moveDir;
} Elevator_t;

void Elevator_Init(Elevator_t *e);
void Elevator_SetTarget(Elevator_t *e, uint8_t floor);
void Elevator_Update(Elevator_t *e);

#endif
