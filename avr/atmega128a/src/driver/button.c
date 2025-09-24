#include"button.h"





 //BUTTON btnOn;   //BUTTON 이라는 데이터형의 변수 btnOn 선언과 동시에 메모리 확보
 //buttonInit(&btnOn,&BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);


void buttonInit(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
   button->ddr = ddr;
   button->pin = pin;
   button->btnPin = pinNum;
   button->prevState = RELEASED;// 아무것도 안누른 상태 (버튼!!)
   *button->ddr &= ~(1<< button->btnPin);  //버튼핀을 입력으로 설정(PING의 해당 비트를 0으로)
   
}

uint8_t buttonGetState(BUTTON *button)
{
   uint8_t currState = *button->pin & (1<< button->btnPin);  //비트별로 &연산  0000 0100 으로 들어감

   if ((currState == PUSHED) && (button->prevState == RELEASED))   // &&비교 연산자 == 비교연산자
   {
    _delay_ms(50);                     //debounce code  // 딜레이를 주는이유 
    button->prevState = PUSHED;        //버튼 상태를 누른 상태로 변환
    return ACT_PUSH;                    //버튼이 눌렸음을 반환
   }
   else if ((currState != PUSHED) && (button->prevState == PUSHED))  //버튼을 누른 상태에서 손을 떼면
   {
     _delay_ms(50);                  //디바운스코드
     button->prevState =RELEASED;    //버튼 상태를 안누른 상태로 변환
     return ACT_RELEASE;             //버튼에서 손을 뗏음을 반환
     
   }
   return NO_ACT;                     //아무것도 안한 상태
}