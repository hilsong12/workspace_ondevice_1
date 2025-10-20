#ifndef BUTTON_H
#define BUTTON_H

#include "stdint.h"

#define BUTTON_1_UP    0
#define BUTTON_2_UP    1
#define BUTTON_2_DOWN  2
#define BUTTON_3_DOWN  3
#define BUTTON_INT_1   4
#define BUTTON_INT_2   5
#define BUTTON_INT_3   6
#define BUTTON_COUNT   7

typedef struct {
    uint8_t flags[BUTTON_COUNT];
} ButtonSet_t;

void Button_Init(ButtonSet_t *btn);
void Button_Update(ButtonSet_t *btn);
void Button_ExternalPressed(ButtonSet_t *btn, uint8_t buttonId);

#endif
