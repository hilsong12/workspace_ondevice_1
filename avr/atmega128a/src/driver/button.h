#include"../common/def.h"



#define LED_DDR       DDRD
#define LED_PORT      PORTD
#define BUTTON_DDR    DDRG
#define BUTTON_PIN    PING
#define BUTTON_ON     2
#define BUTTON_OFF    3
#define BUTTON_TOGGLE 4

enum {PUSHED, RELEASED};   //0 1           //   (상태) 눌려있던가 떼어져 있던가
enum {NO_ACT,ACT_PUSH,ACT_RELEASE};  //0 1 2    //   (행위)   아무것도 안함,  누름, 눌렸다 뗀 상태

// enum{                  //enum은 정수값을 할당하고 싶을때 쓴다. 0번부터 시작인데 초기값을 바꿔주면 그것부터 1씩 증가한다. 
//     Sunday,                 //초기값을 넣어주면 그 다음에는 1씩 증가한다.  ex) '3'4 '9' 10 11
//     Monday,                  // 그 앞에거 더하기 1
//     Tuesday,
//     Wendsday,
//     Thursday,
//     Friday,
//     Saturday
// };


typedef struct button
{  
    volatile uint8_t *ddr;   
    volatile uint8_t *pin;   //volatile 은 최적화 하지 않겠다.
    uint8_t btnPin;   
    uint8_t prevState; // 이전상태  
}BUTTON;

void buttonInit(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t buttonGetState(BUTTON *button);