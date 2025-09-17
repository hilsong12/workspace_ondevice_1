// #include <stdio.h>

// /**
//  * @brief if문
//  * 
//  * @return int 
//  */
// int main()
// {
//    int num=0;

//    printf("숫자를 입력하세요\n");
//    scanf("%d",&num);
  
//    if(num<5) //만약 num이 5보다 작다면...
//     {
//         printf("입력하신 숫자는 5보다 작습니다.\n");
//      }
//    if(num==5) //만약 num이 5라면...
//     {
//         printf("입력하신 숫자는 5입니다.\n");
//      }
//   if(num>5) //만약 num이 5보다 크다면...
//     {
//         printf("입력하신 숫자는 5보다 큽니다.\n");
//      }

//  if(num<5) //만약 num이 5보다 작다면...
//     {
//         printf("입력하신 숫자는 5보다 작습니다.\n");
//     }

// else
// {
//     if(num==5)
//     {
//         printf("입력하신 숫자는 5입니다.\n");
//     }

//     else
//     {
//         if(num>5)
//         {
//             printf("입력하신 숫자는 5보다 큽니다.\n");
//         }
//     }
// }

// if(num<5) //만약 num이 5보다 작다면...
// {
//         printf("입력하신 숫자는 5보다 작습니다.\n");
//       }

// else if (num==5)
// {
//             printf("입력하신 숫자는 5입니다.\n");

// } 
// else   //확실할때 이걸 거는거
// {
//            printf("입력하신 숫자는 5보다 큽니다.\n");    
//           }

// int pm;
// printf("미세먼지 농도를 입력하세요\n");
// scanf(":%d",&pm);
// //중첩 if 시작

// if(pm>0)
// {
//      if(pm<=30)
//      {
//         printf("미세먼지 농도가 낮으니 마스크 벗어!!\n");
//      }
//      else
//        {
//          if(pm<=80)
//          {
//             printf("미세먼지 농도가 보통이니까 마스크 써\n");
//          }
//          else
//          {
//             printf(" 미세먼지로 죽을수 있음");
//          }
//        }
// }
// else
// {
//    printf("숫자 높게 적어라\n");
// }

// // }

// // #include <stdio.h>

// // /**
// //  * @brief 
// //  * 
// //  */
// // int main()
// // {
// //   int num;
// //   printf("미세먼지 농도 선텍하세요\n");
// //   printf("1: 좋음\n");
// //   printf("2: 보통\n");
// //   printf("3: 나쁨\n");
// //   printf("4: 죽음\n");
// //   scanf("%d", &num);

//   switch (num)
//   {
//      case 1: 
//        printf("미세먼지가 좋으니 마스크 벗어\n");
//        break;
//      case 2: 
//        printf("미세먼지가 보통이니 마스크 써라\n");
//        break;
//      case 3: 
//        printf("미세먼지가 나쁘니 비싼 마스크 써라\n");
//        break;
//      case 4: 
//        printf("미세먼지가 농도가 죽음이니까 죽기 직전임\n");
//        break;
//      default:
//      printf("번호 잘 눌러라\n");
//        break;
//   }

// }

// #include <stdio.h>
// /**
//  * @brief while 문  w
//  * 
//  * @return int 
//  */
// int main()
// {
//   int weight=80 ;
//   int count=0;

//   while (weight>70)
//   {
//    printf("운동해서 1kg 빼자");
//    weight--;
//    count++;
//   }
//   printf("축하합니다 운동안해도 됨\n");
//   printf("%d 일 운동했다\n",count);
// }

#include <stdio.h>
/**
 * @brief  do while 문
 * 
 * @return int 
 */

 
int main()
{
   int weight=80 ;
   int count=0;
   int select;


   do
   {
      printf("운동해서 1kg 빼자\n");
      weight--;
      count++;

       printf("운동 더 할 거임?\n");
       printf("1. yes 2. no 숫자를 넣으시오\n");
       scanf("%d",&select);

       if(select ==2) break;
   } while (weight>70);
   {
   
      printf("축하합니다 운동안해도 됨\n");  
      printf("%d 일 운동했다\n",count); 
   }
}


#include <stdio.h>
// /**
//  * @brief  do while 문
//  * 
//  * @return int 
//  */
// int main()
// {
// // {
//     int weight ;
//     int count=0;

//     for(weight=80; weight<70; weight--)    //초기값 비교 for 문장 돈다음에 weight--로 감 그리고 
//     {
//        printf("운동해서 1kg 빼자\n");
//        count++;
//     }
//       printf("축하합니다 운동안해도 됨\n");  
//       printf("%d 일 운동했다\n",count); 
// }

// //무한 루프 
// while(1)
// {
//    //무한으로 돈다
// }

// for(;;)
// {

// }

// for (int i = 0; i < 5; i++)
// {
//    printf("외부 시작!! %d \n",i);
//    for (int j = 0; j< 3; j++)
//    {
//       printf("내부 for 수행중\n");
//    }
//    printf("외부 끝 %d!!\n",i);
   
// }
// }

// #include <stdio.h>

// int main()
// {
//    int i,j;
//    for(i=0;i<5;i++)
//    {
//       for(j=0;j<=i;j++)    // i=0 j=0 *  i=0 j=1이니까 내부 for 수행안하고 나와서 함 i=1 j=0 j=1 두번* 만듬
//       {
//          printf("*");
//       }
//       printf("\n");
//    }
//    for(i=4;i>0;i--)
//    {
//       for(j=0;j<=i-1;j++)
//       {
//          printf("*");
//       }
//       printf("\n");
//    }
// }

// #include <stdio.h>
// int main()
// {
//    int n;
//    int i=1;

//    printf("출력하고 싶은 구구단수는?: ");
//    scanf("%d",&n);

//    while (i<=9)
// {
//    printf("%d*%d=%d\n",n,i,n*i);
//    i++;
// }
// }
// #include <stdio.h>
// /**
//  * @brief  do while 문
//  * 
//  * @return int 
//  */
// int main()
// {
//     int weight ;
//     int count=0;

//     for(weight=80; weight>70; weight--)    //초기값 비교 for 문장 돈다음에 weight--로 감 그리고 
//     {
//        printf("운동해서 1kg 빼자\n");
//        count++;
//     }
//       printf("축하합니다 운동안해도 됨\n");  
//       printf("%d 일 운동했다\n",count); 
// }