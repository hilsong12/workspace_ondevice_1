#include "fnd.h"


void FND_Display(uint16_t data)
{  
    static uint8_t position = 0;  // 정적변수는 프로그램이 끝나야 끝남. 정적변수는 메모리에서 삭제되지 않음. 
                                      // 초기화도 0으로 자동으로 됨. 하지만 확실하게 하기 위해 0 넣음
    uint8_t fndDAta[10] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d, 0x7d,0x27,0x7f,0x67};

    switch (position)  //현재 출력할 자리에 따라서 해당자리의 FND를 출력
    {
    case 0:
         //입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
         FND_DATA_PORT = fndDAta[data/1000];   //1000의 자리

         //첫번째 자리 출력을 위해서는 0번핀이 LOW, 1,2,3핀은 HIGH
         FND_SELECT_PORT &= ~(1 << 0);  //digit 1: ON   
                                //  portc가 로우가 되야 전류흘러 출력이 되고 하이되면 전류 안흘러서 off
         FND_SELECT_PORT |= (1<<1) | (1<<2) |(1 <<3); // digit 2,3,4 :OFF
         
        break;
    
    case 1:
         //입력된 데이터의 백의 자리를 구해서 해당 FND에 데이터 값을 출력
         FND_DATA_PORT = fndDAta[data/100%10]; //100으로 나눠서 10의 나머지를 넣는다 
                                             //ex  1234/100 =12    12%10 =2

         //두번째 자리 출력을 위해서는 0번핀이 LOW, 1,2,3핀은 HIGH                      
         FND_SELECT_PORT &= ~(1 << 1);  //digit 2: ON   
                                    //  portc가 로우가 되야 전류흘러 출력이 되고 하이되면 전류 안흘러서 off
         FND_SELECT_PORT |= (1<<0) | (1<<2) |(1 <<3); // digit 1,3,4 :OFF
         
        break;

    case 2:
        
         //입력된 데이터의 십의 자리를 구해서 해당 FND에 데이터 값을 출력
         FND_DATA_PORT = fndDAta[data/10%10];  //ex 1234/10 = 123 ,123%10=3 

           //세번째 자리 출력을 위해서는 2번핀이 LOW, 0,1,3핀은 HIGH
         FND_SELECT_PORT &= ~(1 << 2);  //digit 3: ON   
                                //  portc가 로우가 되야 전류흘러 출력이 되고 하이되면 전류 안흘러서 off
         FND_SELECT_PORT |= (1<<0) | (1<<1) |(1 <<3); // digit 1,2,4 :OFF
         
        break;

    case 3:
         
         //입력된 데이터의 일의 자리를 구해서 해당 FND에 데이터 값을 출력
         FND_DATA_PORT = fndDAta[data%10];

         //네번째 자리 출력을 위해서는 3번핀이 LOW, 0,1,2핀은 HIGH
         FND_SELECT_PORT &= ~(1 << 3);  //digit 4: ON   
                                //  portc가 로우가 되야 전류흘러 출력이 되고 하이되면 전류 안흘러서 off
         FND_SELECT_PORT |= (1<<0) | (1<<1) |(1 <<2); // digit 1,2,3 :OFF
         
        break;

    }
    position++;  //다음 자리로 이동하기 위해 ++를 함
    position = position % 4;   // 4자리를 출력한 후에 다시 첫번째 자리로 돌아가기 위해 
                               //position %4 한 값을 저장
 

}