// #include <stdio.h>
// #include <avr/io.h>
// #include <util/delay.h>

// #define LED_DDR    DDRD
// #define LED_PORT   PORTD

// uint8_t ledArr[]=
// {

//     0x81,   //1000 0001
//     0x42,   //
//     0x24,
//     0x18

// } ;






// int main()
// {

    //방향레지스터를 통해서 PORTD를 출력으로 설정
        // DDRD=0b11111111; //2진수, 방향레지스터니까 1을 쓰면 출력
        // DDRD= 0xFF // 16 진수 //방향이니까 내보내



    
    // while (1)
    // {
    //     for (int i = 0; i < 8; i++)
    //     {
    //         PORTD = (1 << i); //  불 하나씩 켜지게 
    //     _delay_ms(500); //500ms  멈춰(지연)!!
    //     }
        
    //     PORTD = 0; 


    
    //     for (int i = 0; i < 8; i++)
    // {
    //     PORTD |= (1 << i);  // i번째 LED를 누적해서 켜기   복합연산자+ (비트마스킹, << >>)
    //     _delay_ms(500);
    // }
        

    // for (int i = 0; i < 8; i++)
    // {
    //     PORTD &= ~(1 << i);   // i번째 비트만 끄기
    //     _delay_ms(500);
    // }
        
        
    // }
    


//     DDRD= 0xff;
    
//     while(1)
//    {

//         LED_PORT = 0x0f;  // 하위비트 4개만 켬
//         _delay_ms(500);
//         LED_PORT = 0xf0;
//         _delay_ms(500);
//    }

    // DDRD= 0xff;
    




//  while(1)
//    {


    //         for (int i = 0; i < 8; i++)
    // {
    //     PORTD = 0; 
    //     PORTD |= (1 << i);
    //     _delay_ms(500);  // i번째 LED를 누적해서 켜기   복합연산자+ (비트마스킹, << >>)
        
    // }
                  
        

        // LED_PORT = 0x55;  // 짝수 홀수 것만 스위치
        // _delay_ms(500);
        // LED_PORT = 0xaa;
        // _delay_ms(500);



        // for (uint8_t i = 0; i < 8; i++)    //8bit , unsigned 0~155  8비트 255 16비트 6만5천5백3십오  32비트 42억 언저리
        //                                    //공간확보를 위해서 8비트 짜리의 i를 선언 그냥 int 하면 4바이트가 나와서 32비트 쓴다....
        // {
        //     /* code */
        // }
        





//3칸 짜리가 움직이는거 해보고 싶다.

// for (uint8_t i = 0; i < 8; i++)
// {
    
//     PORTD = (0x07 << i);
//     _delay_ms(200);

// }
//     PORTD =0;
//     _delay_ms(200);


// for (uint8_t i = 0; i < 4; i++)
// {

//    PORTD =  (0x10<<i)| (0x08>>i);
//    _delay_ms(200); 


// }

// for (uint8_t i = 0; i < 4; i++)
// {

//    PORTD =  ((0x40>>i) | (0x02<<i) );
//    _delay_ms(200); 

// }


// for (uint8_t i = 0; i < 6; i++)
// {
//     PORTD = (0x07 <<i);
//     _delay_ms(200);
// }




// for (uint8_t i = 0; i < 4; i++)
// {
//     PORTD = ledArr[i];
//     _delay_ms(200);
// 

//    }


// void ledInit(); // led  초기화 함수
// void ledOn();
// void ledOff();
// void ledRight();
// void ledleft();



// int main()

// {



// ledInit();

//   while(1)

//   {

// ledOn();
// _delay_ms(500);
// ledOff();
// _delay_ms(1000);

//    }



// }


// void ledInit() // led  초기화 함수
// {
//    DDRD =0xff;
// }

// void ledOn()
// {
//    PORTD = 0xff;
// }

// void ledOff()
// {
//    PORTD= 0x00;
// }


// void ledRight()
// {
//     PORTD = PORTD>>1;
// }

// void ledLeft()
// {
//    PORTD = PORTD<<1;
// }




// int main()
// {

// DDRD = 0xff;

// while (1)
// {

//   for (int8_t i = 0; i < 8; i++)
//   {
    
//     PORTD = ((0x10 << i) | (0x08 >> (8-i))) | ((0x10 >> i) | (0x08 << (8-i)))     ;
//     _delay_ms(500);      // 0000 0010 
//                          // 0000 0001  0000 
//   }
  
  
  


// }


// }



// #include<avr/io.h>   // I/O 입출력에 관계된 헤더파일
// #include<util/delay.h>  // 딜레이 함수에 관계된 헤더파일

// #include<led.h>



// #define LED_DDR  DDRD
// #define LED_PORT  PORTD



// // 함수 원형 선언
// void GPIO_Output(uint8_t data);
// void ledInit();
// void ledLeftShift(uint8_t *data);
// void ledRightShift(uint8_t *data);





// //led.c로 이동


// //LED 포트 레지스터에 데이터를 출력하는 함수
// void GPIO_Output(uint8_t data)
// {
//   LED_PORT = data;
// }

// // LED 포트 레지스터를 출력모드로 설정하는 함수
// void ledInit()
// {
//    LED_DDR = 0xFF;
  
// }

// // LED 데이터를 좌측으로 이동하는 함수
// void ledLeftShift(uint8_t *data)
// {
//    *data = ( *data >> 7) | (*data <<1); //LED 데이터를 좌측으로 1이동
//    GPIO_Output(*data);                  // 이동된 데이터를 LED포트 레지스터 출력    
// }

// // LED 데이터를 우측으로 이동하는 함수
// void ledRightShift(uint8_t *data)
// {
//    *data = (*data<< 7) | (*data >>1);
//     GPIO_Output(*data);
// }

// #include "led.h"
// #include "button.h"


// #include"./src/ap/ap.h"    //버튼누르면 켜짐


// int main()
// {

//     DDRD=0xff;
//     //DDRG &= ~(1 <<2);  //DDRG의 2번핀을 입력으로 설정
//     DDRG &= ~(1<<DDRG4);  // DDRG = 1111 1011           DDRG2=2 => 0000 0100  => 1111 1011 0을 써야하기때문에 &연산자
//     DDRG &= ~(1<<DDRG3);   // 0을 쓰겠다. 입력으로 쓰겠다.
//     DDRG &= ~(1<<DDRG3);


//    while(1)
//    {
//     //0000 0100 ping 평상시 pull-up 저항이기때문에
//     if(PING &(1<<PING2))   //스위치를 누르지 않으면 0000 0100 & 0000 0100 => 0000 0100
//     {                         //& 하나 붙으면 비트 연산자  //if 면 0이 아니면 다 참이다 0000 0100 !!
//         PORTD=0x00;
//     }
//     else                      //스위치를 누르면 0000 0000 & 0000 0100  => 0000 0000
//     {
//         PORTD = 0xff;
//     }
    

//    if (!(PING & (1<<PING3 )))   //누르면 시행하게 만들고 싶어 지금은 안눌러야 시행돼 
//     {
//    PORTD =0x01;
//    _delay_ms(200);
//    for (uint8_t i = 0; i < 7; i++)
//    {
//      PORTD = ( (PORTD) >> 7) | ((PORTD) <<1); //LED 데이터를 좌측으로 1이동
//      _delay_ms(200);

//      if(!(PING &(1<<PING2)))
//      {
//      break;
//      } 
//    }
//     }

//    if(!(PING &(1<<PING4)))
//    {
//     PORTD= 0x80;
//     _delay_ms(200);
//     for (uint8_t i = 0; i < 7; i++)
//    {
//      PORTD = ( (PORTD) << 7) | ((PORTD) >>1); //LED 데이터를 우측으로 1이동
//      _delay_ms(200);

//      if(!(PING &(1<<PING2)))
//      {
//      break;
//      } 

     

//    }

//    }

   

//     }
// }


   








// #include "./src/ap/ap.h"     

// int main()
// {

// apMain();

// while (1)
// {
//     /* code */
// }
// }
//-------------------------------------------------------------------------------------------------

// #include "./src/ap/ap.h"      PORTB 모든 세그먼트 키기 0부터 9까지 반복

// int main()
// {
//     DDRB =0xff;           //b는 출력 c는 컨트롤
//     DDRC = 0xff;
//     PORTC =0x00;   // 모든걸 받겠다
//     


//     uint8_t fndNumber[]=
//     {
//         0x3f,0x06,0x5b,0x4f,0x66,0x6d, 0x7d,0x27,0x7f,0x67
//     };


//     int count = 0;
//     while(1)

//     {
//         PORTB = fndNumber[count];
//         count = (count + 1) %10;    //13이라면 나머지가 3이여서 3의 값을 나타낸다.

//         _delay_ms(200);
//     }


// }

//---------------------------------------------------------------------




#include "./src/ap/ap.h"     //숫자가 0부터 9999까지 올라기는것

int main()
{
    DDRB =0xff;           //b는 출력 c는 컨트롤
    DDRC = 0xff;
    PORTC =0x00;   // 모든걸 받겠다
    DDRA =0xff;


    uint8_t fndNumber[]=
    {
        0x3f,0x06,0x5b,0x4f,0x66,0x6d, 0x7d,0x27,0x7f,0x67
    };


    int count = 0;
    while(1)
    
    {
        PORTB = fndNumber[count];
        count = (count + 1) %10;    //13이라면 나머지가 3이여서 3의 값을 나타낸다.

        _delay_ms(200);
    }


    


}








// int main()
// {
//    ledInit();

//    uint8_t ledData = 0x01; //초기 LED 데이터 값을 0x01로 설정

//    while (1)
//    {
//     for (uint8_t i=0; i<7; i++)
//       {
//             ledLeftShift(&ledData);
//             _delay_ms(100);
//       }

//    }
   

// }


