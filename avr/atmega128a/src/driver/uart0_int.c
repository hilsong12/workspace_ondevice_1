#include "uart0_int.h"


void uart0_int_init()
{
    //9600 bps
    UBRR0H = 0x00;
    UBRR0L = 0xCF;

    UCSR0A |= (1<<U2X0); //2배속
    UCSR0B |= (1<<RXCIE0); // 수신 인터럽트 활성화
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0); // UART RX, Tx enable
  
}

void uart0_int_transmit(char data)
{
    while(!(UCSR0A & (1<<UDRE0))) // UDR이 비어있는지?
    {

    }
    UDR0 =data;
}

unsigned char uart0_int_receive()
{
    while(!(UCSR0A &(1<<RXC0))); //수신 확인
    return UDR0;
}