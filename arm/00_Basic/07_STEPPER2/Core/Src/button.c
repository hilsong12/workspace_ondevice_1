

#include "button.h"



BUTTON_CONTROL button[3]=
	{
			{GPIOA,GPIO_PIN_1,0},
			{GPIOA,GPIO_PIN_0,0}
	};

//blocking 코드

//bool buttonGetPressed(uint8_t num)
//{
//	bool ret = false;
//
//	if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//	{
//		HAL_Delay(20);
//		if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//		{
//			ret = true;
//		}
//	}
//	return ret;
//}

//-----------------non-blocking----------------------------------------------------------


//bool buttonGetPressed(uint8_t num)
//{
//	static uint32_t prevTime = 0;  //최초 첫번째 디바운스 안됨
//
//	bool ret = false;
//
//	if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//	{
//		uint32_t currTime = HAL_GetTick();
//
//		if (currTime- prevTime >50)
//		{
//			f(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//					{
//						ret = true;
//					}
//			prevTime = currTime;
//		}
//	}
//	return ret;
//}

//--------------------non-blocking2-------------------------------------

//bool buttonGetPressed(uint8_t num)
//{
//	static uint32_t prevTime = 0xFFFFFFFF;  //최초 첫번째 디바운스 안됨
//
//	if(prevTime == 0xFFFFFFFF)
//	{
//		preTime = HAL_GetTick();
//	}
//
//	bool ret = false;
//
//	if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//	{
//		uint32_t currTime = HAL_GetTick();
//
//		if (currTime- prevTime >50)
//		{
//			f(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//					{
//						ret = true;
//					}
//			prevTime = currTime;
//		}
//	}
//	return ret;
//}

//-------------------------non blocking3 ------------------

//bool buttonGetPressed(uint8_t num)
//{
//	static uint32_t prevTime[3] = {0xFFFFFFFF};  //최초 첫번째 디바운스 안됨
//
//	if(prevTime[num] == 0xFFFFFFFF)
//	{
//		prevTime[num] = HAL_GetTick();
//	}
//
//	bool ret = false;
//
//	if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//	{
//		uint32_t currTime = HAL_GetTick();
//
//		if (currTime- prevTime[num] >50)
//		{
//			if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
//					{
//						ret = true;
//					}
//			prevTime[num] = currTime;
//		}
//	}
//	return ret;
//}
//
//

bool buttonGetPressed(uint8_t num)
{
    static uint32_t prevTime[3];
    static bool isInit = false;   // 초기화 여부 플래그

    // 최초 1회만 초기화
    if (!isInit)
    {
        for (int i = 0; i < 3; i++)
        {
            prevTime[i] = 0xFFFFFFFF;
        }
        isInit = true;
    }

    bool ret = false;

    // 첫 번째 호출 시 초기 tick 세팅
    if (prevTime[num] == 0xFFFFFFFF)
    {
        prevTime[num] = HAL_GetTick();
    }

    // 버튼 읽기
    if (HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
    {
        uint32_t currTime = HAL_GetTick();

        if (currTime - prevTime[num] > 50)
        {
            if (HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
            {
                ret = true;
            }
            prevTime[num] = currTime;
        }
    }

    return ret;
}


