
#include "rcCar_auto.h"
#include "ultrasonic.h"






void rcCarAuto (uint8_t distance1, uint8_t distance2 ,uint8_t distance3)
{

	if( (distance1 >= 2) && (distance3 >= 2))    //오른쪽 왼쪽이 둘다 2이상이면
  {

    if (distance2 > 20)    //15까지는 앞으로 가도 된다고 판단
    {
        TIM3->CCR1 = 0;
        TIM3->CCR2 = 500;
        TIM3->CCR3 = 0;
        TIM3->CCR4 = 500;
    }


    else if (distance2 >5)    //10부터 20사이 일때 방향을 틀어라
    {
        if (distance1 - distance3> 2)         //왼쪽이 크면 오른쪽으로 돌아라
        {

            TIM3->CCR1 = 550;
            TIM3->CCR2 = 0;
            TIM3->CCR3 = 0;
            TIM3->CCR4 = 550;
        }
        else if(distance3 - distance1 > 2)    //오른쪽이 크면 왼쪽으로 돌아라
        {

            TIM3->CCR1 = 0;
            TIM3->CCR2 = 550;
            TIM3->CCR3 = 550;
            TIM3->CCR4 = 0;
        }

    }

    else if( distance2 > 3 )   //10보다 이내가 되면 정지해라
    {
        TIM3->CCR1 = 0;
        TIM3->CCR2 = 0;
        TIM3->CCR3 = 0;
        TIM3->CCR4 = 0;
    }

	else
	{
        TIM3->CCR1 = 600;
        TIM3->CCR2 = 0;
        TIM3->CCR3 = 600;
        TIM3->CCR4 = 0;
	}

  }

	else
	{
        if (distance1 < 2)         //왼쪽이 크면 오른쪽으로 돌아라
        {
            TIM3->CCR1 = 550;
            TIM3->CCR2 = 0;
            TIM3->CCR3 = 0;
            TIM3->CCR4 = 550;
        }
        else  //오른쪽이 크면 왼쪽으로 돌아라
        {
            TIM3->CCR1 = 0;
            TIM3->CCR2 = 550;
            TIM3->CCR3 = 550;
            TIM3->CCR4 = 0;
        }
	}


}





//
//
//void rcCarAuto (uint8_t distance1, uint8_t distance2 ,uint8_t distance3)   //오 중앙 왼쪽
//{
//  if (distance2 > 30)
//  {
//
//	    TIM3->CCR1 = 0;        //오른쪽 후진
//	    TIM3->CCR2 = 600;     //오른쪽 전진
//	    TIM3->CCR3 = 0;      //왼쪽 후진
//	    TIM3->CCR4 = 600;  //왼쪽 전진
//
//
//		if ((distance1 < 10))    //오른쪽이 더 크면   , 왼쪽에 물체 있음
//		{
//			TIM3->CCR1 = 600;
//			TIM3->CCR2 = 0;   //오른쪽 전진
//			TIM3->CCR3 = 0;
//			TIM3->CCR4 = 600;   //왼쪽 전진
//		}
//		else if( (distance3 < 10 ))   //왼쪽이 더 크면 , 오른쪽 에 물체 있음
//		{
//			TIM3->CCR1 = 0;
//			TIM3->CCR2 = 600;
//			TIM3->CCR3 = 600;
//			TIM3->CCR4 = 0;
//		}
//
//  }
//
//	else
//	{
//
//	    TIM3->CCR1 = 300;        //오른쪽 후진
//		TIM3->CCR2 = 0;     //오른쪽 전진
//	    TIM3->CCR3 = 300;      //왼쪽 후진
//		TIM3->CCR4 = 0;  //왼쪽 전진
//	}
//
//}






//    // 입력에 따라 모터 제어
//    switch(direction)
//    {
//        case 'd':    //오른쪽
//        	TIM3->CCR1 = 1000;
//			TIM3->CCR2 = 0;
//			TIM3->CCR3 = 0;
//			TIM3->CCR4 = 1000;
//
//            break;
//        case 'a':      //왼쪽
//
//        	TIM3->CCR1 = 0;
//			TIM3->CCR2 = 1000;
//			TIM3->CCR3 = 1000;
//			TIM3->CCR4 = 0;
//
//            break;
//        case 's':        //후진
//        	TIM3->CCR1 = 1000;
//			TIM3->CCR2 = 0;
//			TIM3->CCR3 = 1000;
//			TIM3->CCR4 = 0;
//
//            break;
//        case 'w':         //전진
//        	TIM3->CCR1 = 0;
//			TIM3->CCR2 = 1000;  //오른쪽 바퀴
//			TIM3->CCR3 = 0;
//			TIM3->CCR4 = 1000;   //왼쪽 바퀴
//            break;
//        default:
//            TIM3->CCR1 = 0;
//            TIM3->CCR2 = 0;
//            TIM3->CCR3 = 0;
//            TIM3->CCR4 = 0;
//            // 아무것도 안함, 이미 0으로 초기화됨
//            break;
//    }
//}
