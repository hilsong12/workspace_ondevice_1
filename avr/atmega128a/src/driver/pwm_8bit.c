#include "pwm_8bit.h"


void pwm_8bit_init()
{
   DDRB |= (1<<PB4);
  //FAST PWM, NON-INVERTED MODE PRESCALAR 256  (비반전 256분주)
  TCCR0 |= (1<< WGM00) |(1<< COM01) |( 1<< WGM01) | (1<< CS02) |( 1<< CS01)  ;

}