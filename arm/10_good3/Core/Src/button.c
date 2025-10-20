#include "button.h"
#include "elevator.h"

extern Elevator_t elevator;

void Button_Init(ButtonSet_t *btn){
    for(int i=0;i<BUTTON_COUNT;i++) btn->flags[i]=0;
}

void Button_Update(ButtonSet_t *btn){
    for(int i=0;i<BUTTON_COUNT;i++){
        if(btn->flags[i]){
            switch(i){
                case BUTTON_1_UP: Elevator_SetTarget(&elevator,1); break;
                case BUTTON_2_UP: Elevator_SetTarget(&elevator,2); break;
                case BUTTON_2_DOWN: Elevator_SetTarget(&elevator,2); break;
                case BUTTON_3_DOWN: Elevator_SetTarget(&elevator,3); break;
                case BUTTON_INT_1: Elevator_SetTarget(&elevator,1); break;
                case BUTTON_INT_2: Elevator_SetTarget(&elevator,2); break;
                case BUTTON_INT_3: Elevator_SetTarget(&elevator,3); break;
            }
            btn->flags[i]=0;
        }
    }
}

void Button_ExternalPressed(ButtonSet_t *btn, uint8_t buttonId){
    if(buttonId < BUTTON_COUNT) btn->flags[buttonId]=1;
}
