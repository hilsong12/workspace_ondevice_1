#include "millis.h"


static volatile uint32_t timer0_Millis = 0;


ISR(TIMER0_COMP_vect)
{
    timer0_Millis++; // ISR 함수가 1ms 마다 호출되므로 1ms씩 증가됨
}

void millisInit()
{
    //Timer0를 CTC모드로 설정
   TCCR0 |= (1<<WGM01);
   // TCCR0 |= ~(1<<WGM00);  // 이렇게 하는 방법도 있다.

   //분주비 64
   TCCR0 = (1<<CS02);

   OCR0 = 249; //1ms 만들려면 250개의 카운팅이 필요하다. 0~249

   TIMSK |= (1<<OCIE0); // 인터럽트 인에이블
   sei();

}

uint32_t millis()
{
    uint32_t ms;

    cli(); // 글로벌 인럽트 차단
    ms =timer0_Millis;
    sei();

    return ms;
}