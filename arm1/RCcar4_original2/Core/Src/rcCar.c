

#include "rcCar.h"
#include "main.h"


uint8_t speed = speed_middle;

void rcCar_init()
{

	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);

	  HAL_Delay(100);
}

void rcCarmode(uint8_t *speed)   //버튼을 누르면 빨리간다.
{
  *speed = speed_high ;
}

void rcCar(char data)
{
    // 입력에 따라 모터 제어
    switch(data)
    {
        case 'd':  move_right();  break;
        case 'a':  move_left();  break;
        case 's':  move_backward();  break;
        case 'w':  move_front(); break;
        default:   move_stop();  break;
    }
}

void move_front()
   {
	left_forward  = speed;
	right_forward = speed;
	}

void move_backward()
{
	left_backward = speed;
	right_backward = speed;
}


void move_left()
{
	left_backward = speed;
	right_forward = speed;
}
void move_right()
{
	left_forward =speed;
	right_backward =speed;
}
void move_stop()
{
left_forward   = 0;
left_backward  = 0;
right_forward  = 0;
right_backward = 0;
}








