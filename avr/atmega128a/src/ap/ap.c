#include "ap.h"


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




// void apInit()
// {
   
// }

// void apMain()     ***************************led 왼쪽으로 옮기기
// {

//      LED led; // LED 타입의 구조체변수 led 선언

//      led.port = &PORTD; //  여기서 PORTD의 주소값은 0x12(데이터시트 참조)
//      led.pinNumber = 0;  //이건 그냥 핀번호임!!
//     //  for (uint8_t i = 0; i < 8; i++)
//     //  {
//     //     led.pinNumber = i;
//     // ledInit(&led);   // ledInit 함수를 호출하면서 led 변수의 주소를 보냄

//     // }
     
//      ledInit(&led);
//      ledOn(&led);
//     _delay_ms(500);

//     while(1)
//     {
         
//           ledLeftShift(&led);
//           _delay_ms(500);

//     }
//     // while문에서 break는 안거는게 나음
// }




// void apInit()
// {
   
// }

// void apMain()     //**********************버튼 누르면 켜지는거 */
// {
//    DDRD = 0xff;  //대충 led 세팅

//    BUTTON btnOn;   //BUTTON 이라는 데이터형의 변수 btnOn 선언과 동시에 메모리 확보
//    BUTTON btnOff;   
//    BUTTON btnTog;

//    buttonInit(&btnOn,&BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);    //버튼들을 init시켜준다
//    buttonInit(&btnOff,&BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
//    buttonInit(&btnTog,&BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);


//    while(1)
//    {
//       if(buttonGetState(&btnOn) == ACT_RELEASE)  {PORTD = 0xff;}    //눌렀다가 떼면 작동

//       if(buttonGetState(&btnOff) == ACT_RELEASE)  {PORTD = 0x00;}      //눌렀다가 떼면 작동

//       if(buttonGetState(&btnTog) == ACT_RELEASE)  {PORTD ^= 0xff;}        //눌렀다가 떼면 작동
//    }
// }




//  DDRA =0xff;
//   PORTA = 0x06;
//   _delay_ms(500);
//   PORTA = 0x5b;
//   _delay_ms(500);
//   PORTA = 0x4f;
//   _delay_ms(500);
//   PORTA = 0x66;
//   _delay_ms(500);
//   PORTA = 0x6d;
//   _delay_ms(500);
//   PORTA = 0x7d;
//   _delay_ms(500);
//   PORTA = 0x07;
//   _delay_ms(500);
//   PORTA = 0x7f;
//   _delay_ms(500);
//   PORTA = 0x6f;
//   _delay_ms(500);
//   PORTA = 0x3f;
//   _delay_ms(500);






void apInit()
{

}

void apMain()
{






}


