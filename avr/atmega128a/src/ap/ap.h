#include "../common/def.h" //공통적인 헤더파일
#include "../driver/led.h"
#include"../driver/button.h"
#include"../driver/fnd.h"
#include"../driver/uart0.h"
#include"../driver/uart0_int.h"
#include"../driver/pwm_8bit.h"
#include"../driver/delay_ms.h"
#include"../driver/millis.h"
// #include"../driver/lcd_8bit.h"
// #include"../driver/lcd_4bit.h"
#include"../driver/i2c.h"
#include"../driver/i2c_lcd.h"

void apInit();
void apMain();
