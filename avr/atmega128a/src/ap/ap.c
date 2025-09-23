#include "ap.h"

void apInit()
{
   
}

// void apMain()
// {

//      uint8_t ledData =0x01;

//     while(1)
//     {
          
//       ledLeftShift(&ledData);
//       _delay_ms(200); 

//     }
//     // while문에서 break는 안거는게 나음
// }



void apMain()
{

     LED led; // LED 타입의 구조체변수 led 선언

     led.port = &PORTD; //  여기서 PORTD의 주소값은 0x12(데이터시트 참조)
     led.pinNumber = 0;  //이건 그냥 핀번호임!!
    //  for (uint8_t i = 0; i < 8; i++)
    //  {
    //     led.pinNumber = i;
    // ledInit(&led);   // ledInit 함수를 호출하면서 led 변수의 주소를 보냄

    // }
     
     ledInit(&led);
     ledOn(&led);
    _delay_ms(500);

    while(1)
    {
         
          ledLeftShift(&led);
          _delay_ms(500);

    }
    // while문에서 break는 안거는게 나음
}

