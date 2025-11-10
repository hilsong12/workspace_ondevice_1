
#include "rcCar_auto.h"
#include "ultrasonic.h"

static uint8_t dir =0; //도리도리 안하게 한방향으로만 돌게끔 만듬  0이면 직진 1이면 직진이 아님




void rcCarAuto(uint8_t distance1, uint8_t distance2, uint8_t distance3)
{
    // 전방이 뚫려있으면 앞으로 전진
    if (distance2 > 20)
    {
        TIM3->CCR1 = 0;
        TIM3->CCR2 = 700;
        TIM3->CCR3 = 0;
        TIM3->CCR4 = 700;
        dir = 0; // 상태를 '전진 중'으로 변경
    }

    // 전방이 막혀있고 (10~20cm), 회피 중이 아닐 때 방향 결정
    else if (distance2 > 5 && distance2 <= 20)
    {
        // 방향이 아직 정해지지 않았으면 판단
        if (dir == 0)
        {
            if (distance1 > distance3)
                dir = 2; // 오른쪽 회전 선택
            else
                dir = 1; // 왼쪽 회전 선택
        }

        // dir에 따라 회전 유지
        if (dir == 2)
        {
            // 오른쪽 회전
            TIM3->CCR1 = 600;
            TIM3->CCR2 = 0;
            TIM3->CCR3 = 0;
            TIM3->CCR4 = 600;

        }
        else if (dir == 1)
        {
            // 왼쪽 회전
            TIM3->CCR1 = 0;
            TIM3->CCR2 = 600;
            TIM3->CCR3 = 600;
            TIM3->CCR4 = 0;

        }
    }

    else
      {
          // 전방 너무 가까움 → 한 방향으로 느리게 제자리 회전
          if (dir == 0)
              dir = 1; // 기본 왼쪽 회전

          if (dir == 1) // 왼쪽 회전
          {
              TIM3->CCR1 = 0;
              TIM3->CCR2 = 400;  // 느린 회전
              TIM3->CCR3 = 400;
              TIM3->CCR4 = 0;
          }
          else if (dir == 2) // 오른쪽 회전
          {
              TIM3->CCR1 = 400;
              TIM3->CCR2 = 0;
              TIM3->CCR3 = 0;
              TIM3->CCR4 = 400;
          }
          // dir은 그대로 유지 → 전방 열리면 직진
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
