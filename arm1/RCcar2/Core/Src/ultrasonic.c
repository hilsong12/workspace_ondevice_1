
#include "ultrasonic.h"




uint16_t IC_Value1_1 = 0;
uint16_t IC_Value2_1 = 0;
uint16_t echoTime1 = 0;
uint8_t captureFlag1 = 0;
uint8_t distance1 = 0;    // 오른쪽

uint16_t IC_Value1_2 = 0;
uint16_t IC_Value2_2 = 0;
uint16_t echoTime2 = 0;
uint8_t captureFlag2 = 0;
uint8_t distance2 = 0;      //중앙

uint16_t IC_Value1_3 = 0;
uint16_t IC_Value2_3 = 0;
uint16_t echoTime3 = 0;
uint8_t captureFlag3 = 0;
uint8_t distance3 = 0;         //왼쪽



void HCSR04_TRIGGER(uint8_t sensor)
{
	switch(sensor)
	{
	case 1: // 중앙
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
		delay_us(2);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		delay_us(10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
		__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC2);
		break;

	case 2: // 오른쪽
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
		delay_us(2);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
		delay_us(10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
		__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC1);
		break;

	case 3: // 왼쪽
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		delay_us(2);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		delay_us(10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC3);
		break;
	}

}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel ==HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(captureFlag1 == 0)  //캡쳐를 한번도 안했다면
		{
			IC_Value1_1 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
			captureFlag1 =1; // 캡쳐플레그 세움( 캡쳐했음)
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(captureFlag1 == 1)
		{
			IC_Value2_1 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_RISING);
			if(IC_Value2_1 >IC_Value1_1)
			{
				echoTime1 = IC_Value2_1 - IC_Value1_1;
			}
			else if(IC_Value2_1 <IC_Value1_1)
			{
				echoTime1 = (0xffff -IC_Value1_1 + IC_Value2_1 ); // f하나에 4비트 ffff는 16비트다
			}
			distance1 = echoTime1 / 58;
			captureFlag1 = 0;
			__HAL_TIM_DISABLE_IT(&htim4,TIM_IT_CC1);  //인터럽트를 죽인다.
		}
	}

	if(htim->Channel ==HAL_TIM_ACTIVE_CHANNEL_2)
		{
			if(captureFlag2 == 0)  //캡쳐를 한번도 안했다면
			{
				IC_Value1_2 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_2);
				captureFlag2 =1; // 캡쳐플레그 세움( 캡쳐했음)
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_2,TIM_INPUTCHANNELPOLARITY_FALLING);
			}
			else if(captureFlag2 == 1)
			{
				IC_Value2_2 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_2);
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_2,TIM_INPUTCHANNELPOLARITY_RISING);
				if(IC_Value2_2 >IC_Value1_2)
				{
					echoTime2 = IC_Value2_2 - IC_Value1_2;
				}
				else if(IC_Value2_2 <IC_Value1_2)
				{
					echoTime2 = (0xffff -IC_Value1_2 + IC_Value2_2 ); // f하나에 4비트 ffff는 16비트다
				}
				distance2 = echoTime2 / 58;
				captureFlag2 = 0;
				__HAL_TIM_DISABLE_IT(&htim4,TIM_IT_CC2);  //인터럽트를 죽인다.
			}
		}

	if(htim->Channel ==HAL_TIM_ACTIVE_CHANNEL_3)
		{
			if(captureFlag3 == 0)  //캡쳐를 한번도 안했다면
			{
				IC_Value1_3 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_3);
				captureFlag3 =1; // 캡쳐플레그 세움( 캡쳐했음)
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3,TIM_INPUTCHANNELPOLARITY_FALLING);
			}
			else if(captureFlag3 == 1)
			{
				IC_Value2_3 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_3);
				__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_3,TIM_INPUTCHANNELPOLARITY_RISING);
				if(IC_Value2_3 >IC_Value1_3)
				{
					echoTime3 = IC_Value2_3 - IC_Value1_3;
				}
				else if(IC_Value2_3 <IC_Value1_3)
				{
					echoTime3 = (0xffff -IC_Value1_3 + IC_Value2_3 ); // f하나에 4비트 ffff는 16비트다
				}
				distance3 = echoTime3 / 58;
				captureFlag3 = 0;
				__HAL_TIM_DISABLE_IT(&htim4,TIM_IT_CC3);  //인터럽트를 죽인다.
			}
		}




}

