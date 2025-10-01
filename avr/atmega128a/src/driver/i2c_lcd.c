#include "i2c_lcd.h"


uint8_t I2C_LCD_DATA;


void LCD_Data4Bit(uint8_t data)
{
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f)|(data & 0xf0); //상위 4비트 추출해서 1차로 보냄
    LCD_EnablePin();
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f)|((data & 0x0f) << 4); //상위 4비트 추출해서 2차로 보냄
    LCD_EnablePin();
}


void LCD_EnablePin()
{
    I2C_LCD_DATA&= ~(1<<LCD_E); // low로 설정
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);

    I2C_LCD_DATA |= (1<<LCD_E);  // high
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);

    I2C_LCD_DATA &= ~(1<<LCD_E); // low
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);
    _delay_us(1600);           // 데이터가 나갈 시간 필요함
}

void LCD_WriteCommand(uint8_t command)
{
    I2C_LCD_DATA &= ~(1<<LCD_RS); // RS핀을 LOW로
    I2C_LCD_DATA &= ~(1<<LCD_RW); 
    LCD_Data4Bit(command);           // 명령어 데이터를 데이터핀에 출력
}

void LCD_WriteDate(char charData)
{
    I2C_LCD_DATA |= (1<<LCD_RS); //
    I2C_LCD_DATA &= ~(1<<LCD_RW);           
    LCD_Data4Bit(charData);                 

}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
    // 보통 나머지로 위치설정
    col %=16;   // 열 16으로 제한
    row %=2;    // 행을 2로 제한

    uint8_t address = (0x40 * row) + col;
    uint8_t command = 0x80 + address;
    LCD_WriteCommand(command);
}

void LCD_WriteString(char* string) // 문자열 집어넣는 방법
{
    for(uint8_t i = 0; i < string[i] ; i++)
    {
        LCD_WriteDate (string[i]);
    }
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
    LCD_GotoXY(row, col);
    LCD_WriteString(string);
}

void LCD_BackLightOn()
{
    I2C_LCD_DATA |= (1<<LCD_BACKLIGHT);
    I2C_TxByte(LCD_DEV_ADRESS, I2C_LCD_DATA);
}

void LCD_Init()
{
    I2C_Init();

    _delay_ms(20);

    LCD_WriteCommand(0x03);
    _delay_ms(5);

    LCD_WriteCommand(0x03);
    _delay_ms(5);
   
    LCD_WriteCommand(0x03);

    LCD_WriteCommand(0x02);
    LCD_WriteCommand(COMMAND_4_BIT_MODE);

    LCD_WriteCommand(COMMAND_DISPLAY_OFF);
    LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
    LCD_WriteCommand(COMMAND_DISPLAY_ON);
    LCD_WriteCommand(COMMAND_ENTRY_MODE);
    LCD_BackLightOn();
}

