#include <stdio.h>

// /**
//  * @brief    연산자 연습
//  * @version  버전은 1.0
//  * 
//  * @return int 
//  */

// int main() 
// {
//     int a = 30; // 정수타입의 a를 선언과 동시에 초기값을 입력
//     int b = 17; // 정수타입의 b를 선언과 동시에 초기값을 입력
//     int result; // 정수타입의 result라른 변수를 선언하고 초기값은 없음


//     result = a + b; // a와 b를 더해서 좌측의 result로 대입함
//     printf("a+b= %d 입니다...\n",result);

//     result = a - b; // a와 b를 빼서 좌측의 result로 대입함
//     printf("a-b= %d 입니다...\n",result);
    
//     result = a * b; // a와 b를 곱해서 좌측의 result로 대입함
//     printf("a*b= %d 입니다...\n",result);

//     result = a / b; // a와 b를 나눠서 좌측의 result로 대입함
//     printf("a/b= %d 입니다...\n",result);  //정수여서 소수점이 날아감 30/17=1.764  반올림 안함
    
//     result = a % b; // a와 b를 나눈 나머지를 좌측의 result로 대입함
//     printf("a %% b= %d 입니다...\n",result); //%는 서식이여서 %%로 한다
// }

/**
 * @brief 대인연산자 연습     <- main 함수가 있어야 브리핑 만들수 있음
 * @brief 복합연산자는 자기 자신과 남을 연산하여 자기에게 넣음
 * @return int 
 */

// int main()
// {
//    int a =34;
//    int c;

//    c=a;
//    printf("c=a 는 %d 입니다\n",c);

//    c += a; //c=c+a  34+34
//    printf("c += a는 %d입니다 \n",c); // 

//    c -= a; //c=c-a   68-34
//    printf("c -= a는 %d입니다 \n",c); // 

//    c *= a; //c=c*a    34*34
//    printf("c *= a는 %d입니다 \n",c); // 

//     c /= a; //c=c/a    1156/34
//    printf("c /= a는 %d입니다 \n",c); // 
// }

// /**
//  * @brief  관계연산자
//  * 
//  * @return int 
//  */
// int main()
// {
//    int a = 0 , b = 0 ;

//    printf("두 개의 정수를 입력하세요 \n"); 
//    scanf("%d %d",&a,&b);
//    printf(" %d>%d :%d \n",a,b,a>b); // 마지막 항인 a>b 가 참이면 1 반환, 거짓이면 0 반환
//    printf(" %d<%d :%d \n",a,b,a<b); // 마지막 항인 a<b 가 참이면 1 반환, 거짓이면 0 반환
//    printf(" %d>=%d :%d \n",a,b,a>=b); // 마지막 항인 a>=b 가 참이면 1 반환, 거짓이면 0 반환
//    printf(" %d<=%d :%d \n",a,b,a<=b); // 마지막 항인 a<=b 가 참이면 1 반환, 거짓이면 0 반환
//    printf(" %d==%d :%d \n",a,b,a==b); // 마지막 항인 a==b 가 참이면 1 반환, 거짓이면 0 반환   같다
//    printf(" %d!=%d :%d \n",a,b,a!=b); // 마지막 항인 a!=b 가 참이면 1 반환, 거짓이면 0 반환  같지 않다


// }

// /**
//  * @brief 논리 연산자
//  * 
//  * @return int 
//  */
// int main()
// {
//     int month;

//     printf("몇 월?? \n");
//     scanf("%d",&month);

//     if(month >= 6 && month <=8)
//     {
//         printf("성수기 요금 적용 \n");  //AND :&&
//     }

//     if(month < 6 || month >8)
//     {
//         printf("일반 요금 적용 \n");  //OR : ||
//     } 

// }
// /**
//  * @brief  삼항연산자 or 조건연산자
//  * 
//  * @return int 
//  */
// int main()
// {
//    int a =1, b=0;
//   int t ,f;

//    //expression1 ? expression2 : operation 3
//    // 만약 exp1이 참(true)이면 exp2가 수행되고 아니면 exp3가 수행됨
//    //삼항연산자를 베릴로그에서 많이 씀
//    t= a||b ? 1:2;
//    f= a&&b ? 1:2;
//    printf("%d \n",t);
//     printf("%d \n",f);
// }



//      특수연산
//  * sizeof 연산자
//  * & 주소반환 연산자
//  * * 포인터 역참조 연산자
//  * 
//  * 

 /**
//   * @brief 비트 연산자
//   * 
//   * @return int 
//   */
//  int main()
//  {
    // int n1 = 15;            //00000000 00000000 00000000 00001111
    // int n2 = 20;            //00000000 00000000 00000000 00010100
    // int result1 =n1 & n2;    //00000000 00000000 00000000 00000100 ->4

    // printf("n1 = %d \n",n1);
    // printf("n2 = %d \n",n2);
    // printf("result = %d \n",result1);

    // int n3 = 15;            //00000000 00000000 00000000 00001111
    // int n4 = 20;            //00000000 00000000 00000000 00010100
    // int result2 =n3 | n4;   //00000000 00000000 00000000 00011111 ->31

    // printf("n3 = %d \n",n3);
    // printf("n4 = %d \n",n4);
    // printf("result2 = %d \n",result2);

    // int n5 = 15;            //00000000 00000000 00000000 00001111
    // int n6 = 20;            //00000000 00000000 00000000 00010100
    // int result3 =n3 ^ n4;   //00000000 00000000 00000000 00011011 ->27

    // printf("n5 = %d \n",n5);
    // printf("n6 = %d \n",n6);
    // printf("result3 = %d \n",result3);

    // int n7 = 15;            //00000000 00000000 00000000 00001111
    // int result4 =~n7;      // 11111111 11111111 11111111 11110000
    
    // printf("result4 = %d \n",result4);


   //  int p1 = 1;            //00000000 00000000 00000000 00000001
   //  int s1 = p1 << 1;      //00000000 00000000 00000000 00000010
   //  int s2 = p1 << 2;      //00000000 00000000 00000000 00000100
   //  int s3 = p1 << 3;      //00000000 00000000 00000000 00001000
   //  int s4 = p1 << 4;      //00000000 00000000 00000000 00010000
   //  int s9 = p1 << 9;      //00000000 00000000 00000010 00000000
   //  int s31 = p1 << 31;      //10000000 00000000 00000000 00000000
   //  int s32 = p1 << 32;      //00000000 00000000 00000000 00000000
   //  int s33 = p1 << 33;      //00000000 00000000 00000000 00000000

   //  printf("s1 = %d \n",s1);
   //  printf("s2 = %d \n",s2);
   //  printf("s3 = %d \n",s3);
   //  printf("s4 = %d \n",s4);
   //  printf("s9 = %d \n",s9);
   //  printf("s31 = %d \n",s31);
   //  printf("s32 = %d \n",s32);
   //  printf("s33 = %d \n",s33);

//     char a;
//     a =127;
//     printf("%d\n",a);
//     //128;
//     a=127 +1;
//     printf("%d\n",a);

//  unsigned char b;
//     b =255;
//     printf("%d\n",b);
//     //255;
//     b=255 +1;
//     printf("%d\n",b);

//     unsigned char a1;
//     a1 =0;
//     printf("%d\n",a1);
//     //128;
//     a1=0 -1;
//     printf("%d\n",a1);
//  
// //  }
// /**
//  * @brief 비트마스크
//  * 
//  * 비트 논리 연산에 사용되어 특정 비트값을 조작하기 위한 목적
//  * AND,OR 연산을 이용해서 특정비트의 이진비트를 처리함
//  * 장점: 메모리 적게사용,빠르게 동작, 소스코드가 직관적
//  * @return int 
//  */
//   int main()
//   {
// //    unsigned short data= 0x5678; //0101 0110 0111 1000

// //    unsigned short mask1= 0xf000; //1111 0000 0000 0000
// //    unsigned short mask2= 0x0f00; //0000 1111 0000 0000
// //    unsigned short mask3= 0x00f0; //0000 0000 1111 0000
// //    unsigned short mask4= 0x000f; //0000 0000 0000 1111
// //    unsigned short mask5= 1<<5; //0000 0000 0000 1111
   


// //    printf ("결과1=%#.4x \n",data&mask1);
//    printf ("결과2=%#.4x \n",data&mask2);
//    printf ("결과3=%#.4x \n",data&mask3);
//    printf ("결과4=%#.4x \n",data&mask4);
//    printf ("결과6=%#.4x \n",mask5);
//    printf ("결과5=%#.4x \n",data&mask5);
//    //초기값 5678이 결과값 5000. 600, 70,8로 분리 가능
//    //마스크를 잘 정의하면 특정비트열을 뽑아낼 수 있다.

//    unsigned short data1= 0x0000; //0000 0000 0000 0000

//    unsigned short mask11= 0xf000; //1111 0000 0000 0000
//    unsigned short mask21= 0x0f00; //0000 1111 0000 0000
//    unsigned short mask31= 0x00f0; //0000 0000 1111 0000
//    unsigned short mask41= 0x000f; //0000 0000 0000 1111
//    unsigned short mask51= 1<<3;   //0000 0000 0000 1000
   


//    printf ("결과1=%#.4x \n",data1|mask11);
//    printf ("결과2=%#.4x \n",data1|mask21);
//    printf ("결과3=%#.4x \n",data1|mask31);
//    printf ("결과4=%#.4x \n",data1|mask41);
//    printf ("결과6=%#.4x \n",mask51);
//    printf ("결과5=%#.4x \n",data1|mask51);

//    //|연산은 특정비트열을 내가 원하는 것으로 변경할 수 있다.

//    //&연산자는 특정비트를 0으로
//    //|연산자는 특정비트를 1로
//    //^ 연산자는 특정비트를 반전!!!
//  }

// int main()
// {
//   int a,b,c;
//   double average ,average1;

//   printf ("정수 3개를 입력하세요 :\n");
//   scanf("%d %d %d",&a,&b,&c);

//   average =(double)(a+b+c)/3; //정수를 더한것을 실수로 바꿔주고 3으로 나눠줬다.
//   //묵시적 형변환 타입을 맞추기 위해서 
//   printf("평균 : %f \n",average);

//   average1 =(a+b+c)/3; //3으로 나눈걸 정수 취급하고 더블로 됨
//   printf("평균 : %f \n",average1);
// }
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

//   }
#include<stdio.h>
int main()
{
int pm;
printf("미세먼지 농도를 입력하세요\n");
scanf("%d",&pm);
//중첩 if 시작

if(pm>0)
{
     if(pm<=30)
     {
        printf("미세먼지 농도가 낮으니 마스크 벗어!!\n");
     }
     else
       {
         if(pm<=80)
         {
            printf("미세먼지 농도가 보통이니까 마스크 써\n");
         }
         else
         {
            printf(" 미세먼지로 죽을수 있음\n");
         }
       }
}
else
{
   printf("숫자 높게 적어라\n");
}
}



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


// #include <stdio.h>

// int main()
// {
//    int i,j;
//    for(i=0;i<5;i++)
//    {
//       for(j=0;j<=i,j++)
//       {
//          printf("*");
//       }
//       printf("\n");
//    }
// }
int main()
