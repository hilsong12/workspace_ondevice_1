#include "../common/def.h"


#define FND_DATA_DDR  DDRB
#define FND_DATA_PORT PORTB
#define FND_SELECT_DDR  DDRC
#define FND_SELECT_PORT  PORTC

void FND_Display(uint16_t data); //4라지여서 16진수이다. 8bit는 255가 한정 9999 는 6만5천 안에 들어와 있다.
