#include "uart0.h"


//통신속도 9600bps
//비동기모드, 2배속,  8비트 데이터 , 패리티비트 없음, 스톱비트1개

void UART0_Init()
{
    // 일단 통신속도 
    UBRR0H = 0x00;
    UBRR0L=207;  //CF

    // 2배속 모드 세팅
    UCSR0A |= (1<<U2X0);
    
    // 수신활성화, 송신활성화
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);

     //비동기. 패리티 없음 , 스톱비트1개, 데이터8비트
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);  //아 세팅값이 디폴트 값이랑 같아서 패스해도 됨. 데이터 시트 보면서 왔다 갔다함

}

void UART_Tramsmit(char data)
{
    while(!(UCSR0A & (1<<UDRE0))); // 송신 가능?? UDR 비어 있는지?  !는 논리값을 뒤집는것. true가 false 된다 
    UDR0 =data;
}

unsigned UART0_Receive()
{
    while(!(UCSR0A & (1<< RXC0)));   //데이터 수신 대기
    return UDR0;
}
