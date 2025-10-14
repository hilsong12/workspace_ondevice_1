
#include "stdint.h"

void delay_count(unsigned int timeCount)  //unsinged int는 16비트
{
	for(;timeCount>0; timeCount--);

}

int main()
{	//RCC_AHB1 레지스터의 GPIOAEN 인에이븐
	(*(volatile unsigned *)0x40023830) |= 0x01;

	//GPIOA의 모드 설정
	(*(volatile unsigned *) 0x40020000) &= ~(0x3 << 10); //11을 뒤집어서 00으로 만들고 민다.
	(*(volatile unsigned *) 0x40020000) |= (0x1 <<10);

	while(1)
	{
		//출력
		(*(volatile unsigned *)0x40020014) |= (1<<5);
		delay_count(0xffff);
		(*(volatile unsigned *)0x40020014) &= ~(1<<5);
		delay_count(0xffff);
	}
}
