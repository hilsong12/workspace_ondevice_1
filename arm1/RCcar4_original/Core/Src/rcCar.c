

#include "rcCar.h"
#include "main.h"


void rcCar_init()
{
	  TIM3->CCR1 = 0;
	  TIM3->CCR2 = 0;
	  TIM3->CCR3 = 0;
	  TIM3->CCR4 = 0;

	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8 , GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);

	  HAL_Delay(100);
}


void rcCar(char data)
{
    // 입력에 따라 모터 제어
    switch(data)
    {
        case 'd':    //오른쪽
        	TIM3->CCR1 = 1000;
			TIM3->CCR2 = 0;
			TIM3->CCR3 = 0;
			TIM3->CCR4 = 1000;

            break;
        case 'a':      //왼쪽

        	TIM3->CCR1 = 0;
			TIM3->CCR2 = 1000;
			TIM3->CCR3 = 1000;
			TIM3->CCR4 = 0;

            break;
        case 's':        //후진
        	TIM3->CCR1 = 1000;
			TIM3->CCR2 = 0;
			TIM3->CCR3 = 1000;
			TIM3->CCR4 = 0;

            break;
        case 'w':         //전진
        	TIM3->CCR1 = 0;
			TIM3->CCR2 = 1000;  //오른쪽 바퀴
			TIM3->CCR3 = 0;
			TIM3->CCR4 = 1000;   //왼쪽 바퀴
            break;
        default:
            TIM3->CCR1 = 0;
            TIM3->CCR2 = 0;
            TIM3->CCR3 = 0;
            TIM3->CCR4 = 0;
            // 아무것도 안함, 이미 0으로 초기화됨
            break;
    }
}


