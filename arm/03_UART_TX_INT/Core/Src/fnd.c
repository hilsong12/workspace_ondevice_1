#include "fnd.h"


// 세그먼트 핀 설정
SegmentPin segments[7] = {
    {GPIOA, GPIO_PIN_5}, // a
    {GPIOA, GPIO_PIN_6}, // b
    {GPIOA, GPIO_PIN_7}, // c
    {GPIOB, GPIO_PIN_6}, // d
    {GPIOC, GPIO_PIN_7}, // e
    {GPIOA, GPIO_PIN_9}, // f
    {GPIOA, GPIO_PIN_8}  // g
};

// 각 숫자에 대한 세그먼트 ON/OFF 데이터 (common cathode 기준)
uint8_t fndNumber[10] = {
    0x3F, // 0 -> a,b,c,d,e,f ON
    0x06, // 1 -> b,c
    0x5B, // 2 -> a,b,d,e,g
    0x4F, // 3 -> a,b,c,d,g
    0x66, // 4 -> b,c,f,g
    0x6D, // 5 -> a,c,d,f,g
    0x7D, // 6 -> a,c,d,e,f,g
    0x07, // 7 -> a,b,c
    0x7F, // 8 -> all
    0x6F  // 9 -> a,b,c,d,f,g
};

// 숫자 표시 함수
void displayNumber(uint8_t num) {
    uint8_t data = fndNumber[num];
    for (int i = 0; i < 7; i++) {
        if (data & (1 << i))
            HAL_GPIO_WritePin(segments[i].port, segments[i].pin, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(segments[i].port, segments[i].pin, GPIO_PIN_RESET);
    }
}
