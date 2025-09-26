#include "ap.h"

//--------------------------  충전됐다가 방전됨-------------------------
// void apMain()
// {
//     //  DDRD =0xff;
//     //  LED ledData ;
//     //  ledData.port =&PORTD;  //0xaa;
//      LED_PORT= 0x00; 
//      int count =0;
//      LED_DDR =0xff;
//       while(1)
//     {
           
     
     
//          if (count<8)
//             for (int i = 0; i <8 ; i++)
//          {
//             PORTD |= (1 << i);  
//              _delay_ms(200);
//              count++;
//          }

//          else
//          {
//            for (int i=8; i>0; i--)
//             {
//             PORTD &= ~(1 << (i-1)); 
//             _delay_ms(200);
//             }
//             count=0;
//           } 

//     }



//  }
    // while문에서 break는 안거는게 나음
//-------------------------------  불빛 양옆으로 움직이기----------------------


// void apMain()
// {
// LED_DDR = 0xff;
// while(1)
// {
//    for (int8_t i = 0; i < 8; i++)
//   {
    
//     PORTD = ((0x10 << i) | (0x08 >> (i))) | ((0x10 >> (8-i)) | (0x08 << (8-i)))     ;
//     _delay_ms(500);      // 0000 0010 
//                          // 0000 0001  0000 
//   }
  
// }
// }



//--------------------------------------led left shifting----------------------------

// void apInit()
// {
   
// }

// void apMain()     
// {

//      LED led; // LED 타입의 구조체변수 led 선언

//      led.port = &PORTD; //  여기서 PORTD의 주소값은 0x12(데이터시트 참조)
//      led.pinNumber = 0;  //이건 그냥 핀번호임!!
   

//      ledInit(&led);  

//      while(1)
//      {
//          for (uint8_t i = 0; i < 8; i++)
//      {
//         led.pinNumber = i;  // ledInit 함수를 호출하면서 led 변수의 주소를 보냄

//      ledInit(&led); 
//      ledOn(&led);
//      _delay_ms(500);
//      ledOff(&led);
//      _delay_ms(500);

//     }

//      }

    // _delay_ms(500);

    // while(1)
    // {
         
    //       ledLeftShift(&led);
    //       _delay_ms(500);

    // }
    // while문에서 break는 안거는게 나음
// }



//-------------------------------------------버튼 누르면 켜지기 온 오프 토글---------------------

// void apInit()
// {
   
// }

// void apMain()     
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
//    }                                                                       //xor 연산
// }

//-------------------------------포트 A 숫자0부터 9까지------------------------------------


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



//------------------------------------4-array 세븐세그먼트 0부터 9까지 무한 출력------------


// void apInit()
// {

// }

// void apMain()
// {


// DDRB =0xff;           //b는 출력 c는 컨트롤
//     DDRC = 0xff;
//     PORTC =0x00;   // 모든걸 받겠다
//     DDRA =0xff;


//     uint8_t fndNumber[]=
//     {
//         0x3f,0x06,0x5b,0x4f,0x66,0x6d, 0x7d,0x27,0x7f,0x67
//     };


//     int count = 0;
//     while(1)
    
//     {
//         PORTB = fndNumber[count];
//         count = (count + 1) %10;    //13이라면 나머지가 3이여서 3의 값을 나타낸다.

//         _delay_ms(1000);
//     }



// }


//-------------------0000부터 9999까지 세기-----------------------------------------

// void apInit()
// {

// }

// void apMain()
// {
  
//     FND_DATA_DDR =0xff;
//     FND_SELECT_DDR=0xff;

//     FND_SELECT_PORT= 0x00;

//     uint16_t count = 0;     //
//     uint32_t timeTick = 0;
//     uint32_t prevTime = 0;


     
//   while (1)
//   {
//     FND_Display(count);    //FND에 count 값을 츨력

//     if(timeTick -prevTime >100)   // 100ms 지날때마다 count값을 1씩 증가
//     {
//         prevTime = timeTick;
//         count++;
//     }
//      _delay_ms(1);
//      timeTick++;
//   }
  
// }

//--------------------uart a,b값과 숫자에 따른 fnd설정---------------------------

// void apMain()
// {

//     UART0_Init();
 
//     DDRD =0xff;  
//     DDRA =0xff;
//    int8_t fndDAta[10] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d, 0x7d,0x27,0x7f,0x67};


//     char data;
    

//     while(1)
//     {
//         data = UART0_Receive();
//         UART_Tramsmit(data);
//         int i = data -'0';

//         if(data == 'a')
//         { PORTD =0xaa; }
        
//         else if(data == 'b') 
//         {PORTD =0x11;}

//         else if (data >= '0' && data <= '9') 
//         {
//             switch ( i )
//         {
         
//         case  0 : PORTA = fndDAta[0]; break;
//         case  1 : PORTA = fndDAta[1]; break;
//         case  2:  PORTA = fndDAta[2]; break;
//         case  3 : PORTA = fndDAta[3]; break;
//         case  4 : PORTA = fndDAta[4]; break;
//         case  5 : PORTA = fndDAta[5]; break;
//         case  6 : PORTA = fndDAta[6]; break;
//         case  7 : PORTA = fndDAta[7]; break;
//         case  8 : PORTA = fndDAta[8]; break;
//         case  9:  PORTA = fndDAta[9]; break;
//         }
//     }
//         // 단일 fnd 사용할거고 숫자를 받으면 숫자에 맞는 값이 출력되도록 할거다
//         // 숫자를 받는걸 i를 사용해서 할수 있나
//         else 
//         {
//             PORTD =0x00;
//             PORTA =0x00;
//         }
//     }
// }
//--------------------------------------------------------------------


//출력 스트림 표준입출력(stdio.h)
FILE OUTPUT = FDEV_SETUP_STREAM(uart0_int_transmit,NULL,_FDEV_SETUP_WRITE);

char rxBuff[100] ={0}; //수신버퍼
volatile uint8_t rxFlag =0; //수신 완료 플래그

ISR(USART0_RX_vect)  //수신 인터러븥 서비스 루틴
{
    static uint8_t rxHead =0;  //수신된 데이터의 인덱스
    uint8_t rxData = UDR0;     //수신된 데이터

    if(rxData =='\n' || rxData == '\r')  //수신된 데이터가 마지막이 개행이나 리턴이면
    {
        rxBuff[rxHead] = '\0'; //문자열의 마지막에 널문자 삽입
        rxHead = 0;            //인덱스 초기화
        rxFlag = 1;            //문자열을 수신했다고 깃발 세움
    }
    else                        //그렇지 않다면 다음 문자를 계속 받음
    {
        rxBuff[rxHead] = rxData;  //수신된 데이터를 버퍼에 계속 추가
        rxHead++;                 //버퍼 인덱스를 하나씩 증가
    }
}

void apMain()
{

    uart0_int_init();

    stdout = &OUTPUT;

    sei();

    while(1)
    {
        if(rxFlag == 1)
        {
            rxFlag = 0;
            printf("%s",rxBuff);
            printf("\n");
        }
    }
}