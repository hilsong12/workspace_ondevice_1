
#include "../common/def.h"

#define LED_DDR  DDRD
#define LED_PORT  PORTD

// void GPIO_Output(uint8_t data);
// void ledInit();
// void ledLeftShift(uint8_t *data);
// void ledRightShift(uint8_t *data);


//LED 구조체 정의
typedef struct 

{
    //volatile << 이것의 의미는 컴파일시 최적화 하지 마시오!!
    volatile uint8_t  *port;   
    uint8_t            pinNumber;

} LED;

void ledInit( LED *led);
void ledOn(LED *led);
void ledOff(LED *led);