// #include <stdio.h>

// /**
//  * @brief  Function:
//  - 프로그래밍에서 함수란 하나의 특별한 목적을 수행하기 위해서 독립적을 설계된 프로그램 코드의 집합
//  - c언어에서는 표준함수와 사용자 정의함수로 구분할 수 있다.  printf scanf
//  * -함수의 이름을 지을때는 기본적으로 함수가 가지고 있는 기능을 이름으로 표현한다. 
//  * @return int 
//  */


// int print_hello(void); // 내가 만든 함수의 이름만 가져오는 것
// void print_hello1(void); //이것을 함수의 원형 선언 이라고 한다.
 
// int main()  //main함수는 무조건 있어야 하고 하나만 있어야 한다. 
// {
//     printf("사용자 정의 함수를 불러봅시다!!!\n");   //함수를 호출하자
//     print_hello();

//     printf("사용자 정의 함수를 또 불러봅시다!!!\n");   //두번째 함수를 호출하자
//     print_hello1();
// }

// int print_hello(void)  //함수명 앞에 데이터형이 있으면 반환값이 있어야 함  ,0을 반환하면 이 프로그램이 정상적으로 끝났어를 알려줌 
// {
//     printf("사용자 정의 함수  int형!!\n");
//     return 0;
// }
    
// void print_hello1(void) // 함수명 앞에 void가 있으면 반환값이 없음!!  함수를 호출하면서 줄게 없다.
// {
//     printf("사용자 정의함수 void 형!!\n");
// }




// #include <stdio.h>

// int add( int x, int y) // x,y는 parameter (매개변수)
// {
//    return x+y;  
// }


// int main()
// {
//    int a,b, sum;
//    a=3;
//    b=5;
//    sum = add(a,b);
//    printf("a+b= %d \n",sum);

// }




// //매크로 상수로 만든 함수 선언
// #include <stdio.h>
// #define add(x,y) (x+y)
// #define APPLE 10

// int main()
// {
// int sum;
// sum=add(5,8);
// printf("5+8 =%d \n",sum);
// }

//변수의 유효범위!!
//지역벼수, 전역변수,정적변수, 레지스터변수



/**
 * @brief 지역변수(local variable)
 * -지역변수란 "블록" 내에서 선언된 변수를 의미함
 * -변수가 선언된 "블록" 내에서만 유효함   //블록은 {}을 뜻함  
 * -"블록"이 종료되면 메모리에서 삭제됨
 * -메모리상에서 스택(stack)영역에 저장됨
 * -초기화 하지 않으면 쓰레기 값임
 * -함수의 매개변수도 함수내에서 정의된 지역변수로 취급함
 */


//  #include<stdio.h>

// void local()
// {
//     int var=20;
//     printf("local()함수내의 지역변수 var의 값은 : %d\n",var);   //2-1번지
// }

//  int main()
//  {
//     int i=5;
//     int var=10;   //1번지

//     printf("main함수내의 지역변수 var의 값은: %d\n",var);

//     if(i<10)
//     {
//         local();  //2-1번지
//         int var=30;  //2-2번지
//         printf("if문내의 지역변수 var의 값 :%d\n",var );  //2-2번지
//     }
    
//     printf("현재 지역변수var의 값은: %d\n",var); //1번지   블록이 사라지면 지역번수 사라진다!
//  }


// /**
//  * @brief 전역변수(global variable)
//  * -전역함수란 (메인)함수의 외부에서 선언된 변수를 의미함
//  * -전역변수는 프로그램의 어디에서나 접근이 가능
//  * -프로그램이 종료되어야 메모리에서 삭제
//  * -메모리의 데이터(data)영역에 저장
//  * -컴파일시 메모리 공간을 확보
//  * -초기화 하지 않아도 0으로 자동 초기와 됨
//  */

//  #include<stdio.h>
 
//  void local(); //함수의 원형선언

//  int var;      //전역 변수 선언


//  int main()
//  {
//      printf("전역변수 var의 초기값은 :%d\n",var);
//      int i=5;
//      int var=10; //지역변수

//    printf("main함수내의 지역변수 var의 값은 :%d\n",var);

//  if(i<10)
//     {
//         local();
//          printf("현재 var의 값 :%d\n",var );  //지역변수에 접근
//     }

//     printf("더 이상 메인함수에서는 전역변수 var에 접근이 불가\n"); //local 로끌어오지 않는한
//     printf("지역변수 var값: %d\n",var);
//  }

//  void local()
//  {
//     var=20;
//      printf("local()함수내의 지역변수 var의 값은 : %d\n",var);  
//  }


/**
 * @brief 정적변수(static variable)
 * -static 키워드로 선언된 변수
 * -정적변수는 지역변수와 전역변수의 특징을 모두 가진다
 * -함수내에서 선언된 정적변수는 단 한번만 전역변수처럼 초기화 됨  <-전역변수 특징
 * -프로그램이 종료 되어야 메모리에서 삭제   <-전역변수 특징
 * -정적변수는 지역변수처럼 해당함수내에서만 접근가능  <-지역변수 특징
 */

 #include<stdio.h>

void local();
void staticVar();


 int main()
 {
    for(int i=0;i<3;i++)
    {

        local();
         staticVar();
    }
 }

 void local()
 {
    int count=1;
    printf ("local()함수가 %d번째 호출되었음\n",count);
    count++;

 }
    

 void staticVar()
 {
 static int static_count=1;
 printf("statiVar()함수가 %d번째 호출 되었음\n",static_count);
 static_count++;
 }