// #include "lcd_4bit.h"


// // void LCD_Data(uint8_t data)
// // {
// //     LCD_DATA_PORT =data;   //data핀에 데이터 출력
// // }

// void LCD_Data4Bit(uint8_t data)
// {
//     LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) |(data &0xf0); // 상위4비트 추출 1차 보냄
//     LCD_EnablePin();
//     LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) |((data &0x0f)<<4); // 상위4비트 추출 2차 보냄
//     LCD_EnablePin();
// }

// void LCD_WritePin()
// {
//     LCD_RW_PORT &= ~(1<<LCD_RW); //RW핀을 low로 설정해 쓰기모드 진입
// }

// //만약에 read라면
// // void LCD_ReadPin()
// // { 
// //     LCD_RW_PORT |= (1<<LCD_RW);   //read
// // }

// void LCD_EnablePin()
// {
//     LCD_E_PORT &= ~(1<<LCD_E);  //low로 설정
//     LCD_E_PORT |=(1<<LCD_E);      //high로 설정
//     LCD_E_PORT &= ~(1<<LCD_E);    //low로 설정
//     _delay_us(1600);   //데이터가 나갈 시간 확보
// }

// void LCD_WriteCommand(uint8_t command)
// {   
//     LCD_RS_PORT &= ~(1<<LCD_RS); //RS핀을 low로 설정해서 명령어 모드
//     LCD_WritePin();                //쓰기모드로 진입
//     LCD_Data4Bit(command);           // 명령어 데이터를 데이터 핀에 출력
//     // LCD_EnablePin();              //4개 보내고 enable 4개 보내고 enable이여서 또 있으면 안된다.
// }

// void LCD_WriteData(char charData)
// {
//     LCD_RS_PORT |=(1<<LCD_RS); // high로 설정해서 데이터모드
//     LCD_WritePin();                //쓰기모드로 진입
//     LCD_Data4Bit(charData);           // 명령어 데이터를 데이터 핀에 출력
//     // LCD_EnablePin();              //LCD  동작 신호를 전송     //트리거 해서 동작해 하는 신호
// }

// void LCD_GotoXY(uint8_t row, uint8_t col)
// {
//     col %= 16;  //열을 16으로 제한
//     row %= 2;    //행을 2로 제한

//     uint8_t address = (0x40*row) + col;
//     uint8_t command = 0x80 + address;
//     LCD_WriteCommand(command); 
// }

// void LCD_WriteString(char *string)
// {
//     for (uint8_t i = 0; i < string[i]; i++)
//     {
//         LCD_WriteData(string[i]);
//     }
    
// }

// void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
// {
//     LCD_GotoXY(row, col);
//     LCD_WriteString(string);
// }

// void LCD_Init()
// {
//     LCD_DATA_DDR = 0xff;
//     LCD_RS_DDR |= (1<< LCD_RS);
//     LCD_RW_DDR |= (1<<LCD_RW);
//     LCD_E_DDR |=(1<< LCD_E);

//     _delay_ms(20);
//     LCD_WriteCommand(0x03);
//     _delay_ms(5);
//     LCD_WriteCommand(0x03);
//     _delay_ms(5);
//     LCD_WriteCommand(0x03);

//     LCD_WriteCommand(0x02);
//     LCD_WriteCommand(COMMAND_4_BIT_MODE);

//     LCD_WriteCommand(COMMAND_DISPLAY_OFF);
//     LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
//     LCD_WriteCommand(COMMAND_DISPLAY_ON);           //요거만 우리가 넣음
//     LCD_WriteCommand(COMMAND_ENTRY_MODE);
// }
