// #include <stdio.h>


// /**
//  * @brief 배열(array)
//  * -같은 데이터형의 변수들로 이루어진 유한집합
//  * -배열의 모든 요소는 연속된 메모리에 저장된다.
//  * @return int 
//  */
// int main() 
// {
//     int arr[5];   // 크기가 5개인 배열 선언  
//     //아직 배열을 초기화 하지 않았음
//     //배열은 딱 한번만 초기화 가능


//     int byteSize=0; //배열의 바이트 크기를 저장할 변수 선언, 초기화
//     int size=0; // 배열의 크기를 저장할 변수 선언, 초기화

//     byteSize= sizeof(arr);  // 배열의 바이트 크기확인 (반환)
//     printf("배열의 바이트 크기: %d\n",byteSize);

//     size =sizeof(arr)/sizeof(arr[0]); //배열의 개수?  
//     printf("배열의 크기:%d\n",size);
// }


// #include<stdio.h>
// // #define ARR_SIZE   5  // 매크로 상수!!

// int main()
// {
//     int arr[ARR_SIZE];  //배열의 크기를 매크로 상수로 지정 가능

//  for(int i=0; i<ARR_SIZE;i++)   //arr에 값을 넣어준다. 0 1 2 3 4
// {
//   arr[i] = 0;
// }
// printf("arr배열의 원소:");
// for(int i=0 ; i<ARR_SIZE;i++)   //배열의 값들을 출력한다. 0 0 0 0 0
// {
//     printf(" %d",arr[i]);
// }
//  printf("\n");
// }

// int arr[]={0}; //배열의 선언과 

// for ( int i = 0; i < 10; i++)
// {
//     printf("arr[%d]는 %d\n",i,arr[i]);
// }
// printf ("ARR의 4번째 요소는? :%d \n", arr[3]);


// int arr[0] ={0}; // 각 요소 초기화는 중간에 할수 없다.
// for ( int i = 0; i < 5; i++)
// {
//     printf("arr[i]는 %d\n",arr[i]);
// }
// printf ("ARR의 4번째 요소는? :%d \n", arr[3]);  


// int arr[5];
// arr[0]=1;
// arr[1]=2;
// arr[2]=3;
// arr[3]=4.5;  //4.5 넣으면 int형이여서 짤려서 4로 나옴
// arr[4]=5;
// for ( int i = 0; i < 5; i++)
// {
//     printf("arr[%d]는 %d\n",i,arr[i]);
// }
// }

// #include<stdio.h>

// int main()
// {

//     int arr[10];  //arr에 값넣기
//     int i=5;

//     arr[i]=3; // arr[5]-> 6번째
//     arr[i+1]=4; //arr[6]  ->7번째
//     arr[i+3] =5; //arr[8]-> 9번째

//     printf("arr의 6번째 요소: %d\n", arr[i]);
//     printf("arr의 7번째 요소: %d\n", arr[i+1]);
//      printf("arr의 9번째 요소: %d\n", arr[i+3]);
// }


// #include<stdio.h>
// #define ARR_SIZE   5  // 매크로 상수!!

// int add(int a ,int b)  // add라는 사용자지정함수 만들기
// {
//     return a+b;
// }


// int main()
// {

//     int arr[ARR_SIZE]={0};   //  전역함수로 지정했기에 가능 ,array 0으로 초기화

//     arr[0]=5;          //arr값 넣어줌
//     arr[1]=arr[0]+10;
//     arr[2]=add(arr[0],arr[1]);

//     printf("정수값 2개를 입력하세요\n"); //  0 12 는 지정됐고 34 는 지정해준다
//     scanf("%d %d",&arr[3],&arr[4]);   //scanf는 주소값에다가 값을 넣는거기 때문에 주소값 가져오기&

//     for (int i = 0; i < ARR_SIZE; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     printf("arr[5]=%d\n",arr[5]); //5값이 없어서 이상한값이 나옴

// }




// #include<stdio.h>


// int main()
// {
//     char c='A';
//     char d='B';
//     int i=5 ,j=6;


// printf ("변수 c의 주소값 :%p\t변수 c의 값 :%d\n",&c,c);  //1byte
// printf ("변수 d의 주소값 :%p\t변수 d의 값 :%d\n",&d,d);  //1byte
// printf ("변수 i의 주소값 :%p\t변수 i의 값 :%d\n",&i,i);  //4byte
// printf ("변수 j의 주소값 :%p\t변수 j의 값 :%d\n",&j,j);  //4byte

// }



// #include<stdio.h>


// int main()
// {

    // int arr[3];
    // arr[0]=3;
    // arr[1]=5;
    // arr[2]=7;

    // printf("arr[0]주소값 :%p\t 요소값%d\n",&arr[0],arr[0]); //cdef
    // printf("arr[1]주소값 :%p\t 요소값%d\n",&arr[1],arr[1]); //0123
    // printf("arr[2]주소값 :%p\t 요소값%d\n",&arr[2],arr[2]); //4567

    // int arr[5]={1,2,3};     
    // for (int i = 0; i < 5; i++)
    // {
    //    printf("array[%d] 는 %d\n",i,arr[i]);
    // }
    
// }

// }
#include<stdio.h>


int main()
{
//     // int arr[3];
//     // arr[0] = 3;
//     // arr[1] = 5;
//     // arr[2] = 7;

//     // printf("arr[0] 주소값 : %p\t요소값 : %d \n", &arr[0], arr[0]);
//     // printf("arr[1] 주소값 : %p\t요소값 : %d \n", &arr[1], arr[1]);
//     // printf("arr[2] 주소값 : %p\t요소값 : %d \n", &arr[2], arr[2]);


//     // char arr[3];
//     // arr[0] = 'a';
//     // arr[1] = 'b';
//     // arr[2] = 'c';

//     // printf("arr[0] 주소값 : %p\t요소값 : %d \n", &arr[0], arr[0]); // 소문자 a: 아스키코드 97
//     // printf("arr[1] 주소값 : %p\t요소값 : %d \n", &arr[1], arr[1]); // 소문자 b: 아스키코드 98
//     // printf("arr[2] 주소값 : %p\t요소값 : %d \n", &arr[2], arr[2]); // 소문자 c: 아스키코드 99


// }
// int decimal;
//     int binary[20] = { 0, };

//     int position = 0;

//     printf("2진수로 변환할 10진수를 입력하세요 : ");
//     scanf("%d", &decimal);

//     while (1)
//     {
//         binary[position] = decimal % 2;    // 2로 나누었을 때 나머지를 배열에 저장
//         decimal = decimal / 2;             // 2로 나눈 몫을 저장

//         position++;    // 자릿수 변경

//         if (decimal == 0)    // 몫이 0이 되면 반복을 끝냄
//             break;
//     }

//     // 배열의 요소를 역순으로 출력
//     for (int i = position - 1; i >= 0; i--)
//     {
//         printf("%d", binary[i]);
        
//     }

//     printf("\n");

//2차원 배열
//행열-중괄호 안에 중괄호 표현

int arr_2[3][3]=   //행의 크기는 생략가능 (열의 크기는 생략불가!!)
{
{1,2,3},
{4,5,6},
{7,8,9}
};

// int arr_22[3][3]={1,2,3,4,5,6,7,8,9};

// int arr_23[3][3]={0}; //전체를 초기화함


for (int  i = 0; i < 3; i++)
{
    for (int j = 0; j <3 ; j++)
    {
        printf("%d행 %d열: %d | 주소: %p",i,j,arr_2[i][j],&arr_2[i][j]);
        if(j<3)
         printf("  |  ");
        if(j==2)
         printf("\n");        

    }
    
}


}