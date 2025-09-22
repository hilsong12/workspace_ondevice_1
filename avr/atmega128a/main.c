#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR    DDRD
#define LED_PORT   PORTD

uint8_t ledArr[]=
{

    0x81,   //1000 0001
    0x42,   //
    0x24,
    0x18

} ;



void ledInit(); // led  초기화 함수
void ledOn();
void ledOff();
void ledRight();
void ledleft();





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


int main()

{




ledInit();

  while(1)

  {

ledOn();
_delay_ms(1000);
ledOff();
_delay_ms(1000);

   }








}


void ledInit() // led  초기화 함수
{
   DDRD =0xff;
}

void ledOn()
{
   PORTD = 0xff;
}

void ledOff()
{
   PORTD= 0x00;
}


void ledRight()
{
    PORTD = PORTD>>1;
}

void ledLeft()
{
   PORTD = PORTD<<1;
}

