#include "delay_ms.h"


ISR(TIMER0_OVF_vect)
{
    static uint16_t count; // 정적변수 초기화 하지 않아도 0, ISR 함수 내에서만 사용

    if(++count >= countValue)
    {
        count = 0;
        TCCR0 &= ~((1<<CS02)|(1<<CS00)); // 초기화
        delayCompleteFlag = 1; // 깃발 세움(내가 설정한 시간까지 delay 되면)
    }
}


void delayInit()
{
    delayCompleteFlag = 0;

    TIMSK |= (1<< TOIE0);; // interrupt enable (overflow)

    TCCR0 |= (1<<CS02 ) | (1<<CS00); //128분주   ,노말모드

    sei();  //글로벌 인터럽트 활성화

}

void delay_ms(uint16_t ms)
{
    delayCompleteFlag = 0; //호출하면 초기화 개념
    countValue = ms; //초기화 개념

    TCNT0 = 256- 125; //TCNT 값을 131부터 세어나감   총 256개다 255개 가 아니라 0부터 255까지여서 
    TCCR0 |= (1<<CS02 ) | (1<<CS00); //타이머 다시 시작 개념

    while (!delayCompleteFlag); //깃발 세울때까지 잡아 놓을거다.
    
    
}
