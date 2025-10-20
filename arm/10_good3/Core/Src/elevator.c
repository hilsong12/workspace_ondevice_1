#include "elevator.h"
#include "stepper.h"
#include "fnd.h"

extern Elevator_t elevator;

void Elevator_Init(Elevator_t *e) {
    e->currentFloor = 1;
    e->targetFloor = 1;
    e->nextTargetFloor = 0;
    e->moveDir = DIR_STOP;
}

void Elevator_SetTarget(Elevator_t *e, uint8_t floor) {
    if(floor == e->currentFloor) return;
    if(e->moveDir == DIR_STOP) {
        e->targetFloor = floor;
        e->moveDir = (floor > e->currentFloor) ? DIR_UP : DIR_DOWN;
    } else {
        e->nextTargetFloor = floor;
    }
}

void Elevator_Update(Elevator_t *e) {
    if(e->moveDir == DIR_STOP) return;
    Stepper_SetDirection(e->moveDir);
    Stepper_Update();
}
