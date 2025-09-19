// #include <stdio.h>

// int swap_value( int *ptr_i)
// {

//  *ptr_i= 3;
// return 0;

// }


// int main() 
// {
    
//      int i=0;
//      printf("호출 이전에 i값: %d\n",i);
//      swap_value(&i);
//      printf("호출 이후에 i의 값: %d\n",i); 

// }



// int swap_value( int i)
// {

//  i= 3;
// return 0;

// }


// int main() 
// {
    
//      int i=0;
//      printf("호출 이전에 i값: %d\n",i);
//      swap_value(i);
//      printf("호출 이후에 i의 값: %d\n",i); 

// }




// int swap_value( int *a , int *b)
// {
// int temp=*a;  //주소에 있는 값을 넣는다.
// *a=*b;
// *b=temp;

// return 0;
// }

// int main ()
// {

//   int i, j;
//   i=3;
//   j=5;
//   printf("스왑 이전 : i %d  , j : %d\n\n",i,j);
//   swap_value( &i, &j);  //주소값 던저줌
//   printf("스왑 이후 : i %d  , j : %d\n\n",i,j);  //안바뀐다.

// }


//문자열 
//문자열 : 연속된 문자들의 집합? 모임?? (very)
//문자: 하나의 문자('a')
//c언어에서는 문자열을 지원을 안해준다.




// #include <stdio.h>

// int main()
// {

// //    //아래 3개는 모두 동일
// //    char null_1 ='\0';
// //    char null_2 = 0;
// //    char null_3 = (char)NULL;
// //    char not_null= '0';

// //    printf("NULL의 아스키값 : %d, %d, %d\n",null_1,null_2,null_3);
// //    printf("'0'의 아스키값 : %d\n",not_null);


// // char str[]={"good"};
// // char str0[10]= "";  // 초기화 방법


// // char sentence_1[5]= {'G','o','o','d', '\0'};
// // char sentence_2[5]= {'G','o','o','d',0};
// // char sentence_3[5]= {'G','o','o','d',NULL};
// // char sentence_4[5]= {"Good"}; // 보이지 않는 곳에 null 이 들어가 있다. 문자 갯수보다 반드시 1개가 많아야함!!

// // printf("sentence_1 : %s\n", sentence_1);
// // printf("sentence_2 : %s\n", sentence_2);
// // printf("sentence_3 : %s\n", sentence_3);
// // printf("sentence_4 : %s\n", sentence_4);


// // char word[]= {"long sentence"};
// // printf ("조작이전 : %s\n",word);

// // word[0]= 'a';
// // word[1]= 'b';
// // word[2]= 'c';
// // word[3]= 'd';

// // printf ("조작이후: %s\n",word);





// }


#include<stdio.h>

int str_length(char *str)    //?????? 비상
{
int i=0;
while (str[i])  //아스키코드값이 0 이 아니면 계속 돈다. 마지막에 null 이 나오면 튕겨서 나옴
{
    i++;
}
return i;
}

int main()

{
char str[]= {"Good Morning!!"};
printf(" 이 문자열의 길이는? : %d\n", str_length(str)); //str 배열 이름은 포인터가 아니지만 포인터 처럼 주소값을 가진다. (첫번째)
printf(" 이 문자열의 길이는? : %d\n", str_length(&str[0])); //이게 원칙이다.
}