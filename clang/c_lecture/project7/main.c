#include <stdio.h>

// struct human // human 이라는 구조체
// {            //사용자 데이터 형을 선언
//     int age;          
//     int height;
//     int weight;
// };


// int main() 
// {
    
//     struct human info; //info 라는 구조체 변수를 선언 , 구조체는 객체와 같다. 서로다른 값이 3개

//     info.age =99; //. 은 멤버를 부른다
//     info.height = 200;           
//     info.weight = 100;
    
//     printf("나이 : %d\n",info.age);
//     printf("키 : %d\n",info.height);
//     printf("무게 : %d\n",info.weight);
    
    
// }

#include<string.h>

// struct contact
// {
//     char name[20]; // 이름
//     char phone[20];  // 전화번호
//     char ringtone;   //벨소리 0-9
// };

// int main()
// {
// struct contact ct= {"김석진","01011112222",0};
// struct contact ct1 = {0}, ct2= {0};
// struct contact ct4  =ct;

// ct.ringtone =5; //링톤 번경
// strcpy(ct.phone, "01099998888"); //ct의 전번을 바꿈
// printf("이 름: %s \n ", ct.name);
// printf("전 번: %s \n ", ct.phone);
// printf("링 톤: %d \n ", ct.ringtone);


// strcpy(ct1.name,"전전국");
// strcpy(ct1.phone,"01066665555");
// ct1.ringtone =3;

// printf("이 름: %s \n ", ct1.name);
// printf("전 번: %s \n ", ct1.phone);
// printf("링 톤: %d \n ", ct1.ringtone);

// // printf("이 름 :");
// // scanf("%s",ct2.name);  //scanf쓰면 주소값 붙어야 하는데 배열이라 괜찮으
// // printf("전 번 :");
// // scanf("%s",ct2.phone);
// // printf("링 톤 :");
// // scanf("%d",&ct2.ringtone); //배열이 아니여서 주소를 넣어야 한다.

// // printf("------------------\n");

// // printf("이 름: %s \n ", ct2.name);
// // printf("전 번: %s \n ", ct2.phone);
// // printf("링 톤: %d \n ", ct2.ringtone);

// printf("------------------\n");

// printf("이 름: %s \n ", ct4.name);
// printf("전 번: %s \n ", ct4.phone);
// printf("링 톤: %d \n ", ct4.ringtone);


// }

// typedef unsigned int myUnsignedIngefer; //자료 재 정의
// typedef char 바이트_1개;
// typedef int 바이트_4개;
// int main()
// {
//   바이트_1개 문자열[100]= "한글이 좋아" ;
//   바이트_1개 정수 = 100;

//   printf("문자열 : %s\n",문자열);
//   printf("정수 : %s\n",정수);


// // myUnsignedIngefer num;
// // num=10;
// // printf ("Num")

// }

// typedef struct food
// {
//     char name[10]; 
//     int price ;
//     int cooktime;
//     int preferance;
// }FOOD_REFERENCE;


// int main()
//     {
 
//         FOOD_REFERENCE testFood = {"라면", 4000,3,10};
//         printf("이 름 : %s\n", testFood.name);
//         printf("가 격 : %d\n",testFood.price);
//         printf("시 간 : %d\n",testFood.cooktime);
//         printf("선호도 : %d\n",testFood.preferance);
//     }


// typedef struct test
// {
//    int a;
//    int b;
// }TEST;

// int main()
// {
//    TEST st; // 이반 구조체 변수를 선언
//    TEST *ptr; //TEST 라는 구조체를 가리킬 포인터 변수 선언  8바이트이다. 

//    ptr= &st;

//    (*ptr).a = 1;   ///연산자 우선순위 주의!!!!!!
//    (*ptr).b = 2;

//    printf("st의 멤버인 a 의 값 : %d\n",st.a);
//    printf("st의 멤버인 b 의 값 : %d\n",st.b);

//    printf("----------------\n");

//    ptr ->a =3;
//    ptr ->b =5;

//     printf("st의 멤버인 a 의 값 : %d\n",st.a);   //.은 멤버를 데려오고 화살표는 멤버의 값이다. 위 아래 같은 것이다. 
//    printf("st의 멤버인 b 의 값 : %d\n",st.b);

// }

// typedef struct test
// {
//     int c;
//     int *pointer;
// }TEST;

// int main()
// {
//     TEST t;
//     TEST *pt =&t;
//     int i = 0;

//     t.pointer = &i; //t의 멤버인 pointer는 i를 가리킴
//     *t.pointer = 3; //t의 멤버인 pointer이 가리키는 곳에 값 3을 대입
//     printf("i : %d\n",i);

//     *pt->pointer = 4;
//     printf("i : %d\n",i);

// }

int add_one(int *a);

struct TEST
{
    int c;
};
//연산자 우선순위를 참고하세요!!!
int main()
{
    struct TEST t;
    struct TEST *pt= &t;
    // pt 가 가르키는 구조체 변의 c 의 멤버의 값을 0으로 변경
    pt->c = 0;

    //add_one 함수의 인자에 t구조체 변수의 멤버인 c 주소값을 전달
    
    add_one(t.c);
    printf("t.c : %d\n",t.c);


    // add_one 함수의 인자에 pt 가 가르키는 구조체 변수의 멤버인 c의 주소값 전달
    add_one("t.c: %d\n",t.c);
    printf("t.c : %d\n",t.c);
}

int add_one(int *a)
{
    *a +=1;
    return 0;

}