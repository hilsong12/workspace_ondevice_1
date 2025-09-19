
//대망의 포인터
//포인터란
//메모리의 주소값을 저장하는 변수임
//포인터 변수라고도 함
//포인터는 주소값만 저장할 수 있음    포인터도 변수인데 주소값만 가질수 있다.
//메모리상에 위치한 특정한 데이터의 시작주소값을 보관한 변수
// 포인터와 연관된 연산자
//-> &(주소연산자) :변수의 이름앞에 사용, 해당 변수의 주소값을 반환
//-> *(참조연산자) : 포인터의 이름이나 주소앞에 사용
//                   ->포인터가 가리키는 (곳)주소에 저장된 값을 반환한다.
//-포인터의 크기는 일정하다.
//-> 플랫폼에 따라서...
//-> 32bit ->4byte | 64bit-> 8byte

// #include <stdio.h>

// int main() 
// {
    
// }



#include <stdio.h>

int main() 
{

    // int *pi;
    // double *pd;
    // char *pc;

    // printf("int형의 포인터의 크기: %d\n,",sizeof(pi));
    // printf("int형의 포인터의 크기: %d\n,",sizeof(pd));
    // printf("int형의 포인터의 크기: %d\n,",sizeof(pc));



    // int *ptr; //int 타입의 포인터 선언   int* ptr; 
    // int *p =NULL;

// int *p;
// int a;
// p=&a;

// printf("포인터 변수 p에 들어있는 값: %p\n",p);
// printf("변수 a의 주소는 ? %p\n",&a);
// printf("변수 p의 주소는 ? %p\n",&p);

// int *p;
// int a;
// p=&a;

// *p=3; //빈방이였는데 넣어졌다.

// printf("a의 값: %d\n",a);
// printf("p의 값  %d\n",*p);


// int a;
// int b;
// int *ptr; //포인터 변수 만듬

// ptr=&a;   //ptr도 변수다   
// *ptr =2;   
// ptr=&b;
// *ptr= 3;
// printf("a의 값: %d\n",a);  //
//  printf("b의 값 : %d\n",b);

//포인터의 덧셈
// int a;
// int *pa;
// pa=&a;

// int a_1;
// int *pa_1;
// pa_1= &a_1;

// *pa=3;
// pa_1=pa;  //대입 가능

// printf("pa의 주소: %p\n",pa);
// printf("pa_1의 주소: %p\n",pa_1);   

// char b;
// char *pb;
// pb= &b;

// printf("pb의 값: %p\n",pb);
// printf("pb+1의 값: %p\n",pb+1);         //1byte

// double c;
// double *pc;
// pc=&c;

// printf("pc의 값: %p\n",pc);
// printf("pc+1의 값: %p\n",pc+1);              //8byte

//pc=pa+pb //절대 불가
//대입은 가능


// int arr[10]={1,2,3,4,5,6,7,8,9,10};

// for (int i = 0; i < 10; i++)
// {
//     printf("arr[%d]의 주소값: %p\n", i,&arr[i]);
// }


//포인터로 배열 접근
//  int arr[10]={1,2,3,4,5,6,7,8,9,10};
//  int *parr;

//  parr=&arr[0];

//  for (int i= 0; i < 10; i++)

//  {
//     printf("arr[%d]의 주소값: %p  ",i,&arr[i]);
//     printf("parr+%d의 값: %p",i,(parr+i));
 
//  if (&arr[i]==(parr+i))
//  {
//     printf("일치\n");
//  }

// else
// printf("불일치\n");

//  }

// printf("arr[3]=%d\n *(parr+3)= %d\n",arr[3],*(parr+3)); //


// // 배열[0]과 주소의 관계-이름
// int arr[3]={1,2,3};
// int *parr;
// parr=arr;

// printf("arr의 %p\n",arr); //배열의 이름을 적으면 주소값을 가지고 있다. 
// printf("arr의 %p\n",&arr);  //arr의 주소를 나타내고 있다.
// printf("arr의 %d\n",arr); // arr은 주소값(고정)으로 나오고 값으로는 나오지 않는다.

// for (int i = 0; i < 3; i++)
// {
// printf("arr[%d]의 %d\n",i,arr[i]); // arr은 주소값(고정)으로 나오고 값으로는 나오지 않는다.
// }

// printf("arr[0]의 %p\n",&arr[0]);

// printf("arr %d\n",sizeof(arr)); // 배열 전체 크기 = int 3개 = 12바이트 (32비트에서는 12, 64비트도 12)
// printf("parr %d\n",sizeof(parr));  //sizeof(parr) → 포인터 크기 (주소 크기) = 보통 8바이트 (64비트 환경), 4바이트 (32비트 환경)
// // 배열의 이름은 주소값을 가지고 있지만 포인터는 아니다.



// int arr[10]={100,89,99,67,55,77,99,44,55,66};
// int *parr=arr;
// int sum=0;

// while (parr-arr <=9)  //???? arr은 값이다 주소값이 아니다 주소끼리 빼는건 불가능한데  arr++가 안된다.
// {
//     printf("%p-%p\n",parr, arr); // 
//     sum += (*parr);
//     parr++;           //주소를 하나씩 늘리는게 되는구나 
    
// }
// printf("점수평균 %d\n",sum/10);


// int a;
// int *pa;   //포인터 선언
// int **ppa; //이중포인터 선언

// pa=&a;
// ppa=&pa;

// a=3;

// printf("a:%d| *pa: %d |**ppa: %d\n",a,*pa,**ppa);
// printf("a주소:%p| pa가리키는: %p |**ppa저장값: %p\n",&a,pa,*ppa)
// printf("pa주소:%p| ppa가리키는: %p |",&pa,ppa);
  


// int arr[2][3];

// printf("arr[0]: %p \n",arr[0]);
// printf("arr[0][0]: %p \n",arr[0][0]);

// printf("arr[1]: %p \n",arr[0]);
// printf("arr[1][0]: %p \n",arr[1][0]);


// int arr[2][3]= {{1,2,3},{4,5,6}};
 
// printf("전체크기 %d\n",sizeof(arr))
// printf("총 열 갯수 : %d\n",sizeof*arr[0]/)

// int *arr[3]; //포인터배열
// int a=1, b=2, c=3; // 선언과 동시에 초기화 작업
// arr[0] =&a;
// arr[1] = &b;
// arr[2] = &c;

// printf(" a: %d *arr[0]: %d\n", a,*arr[0]);
// printf(" a: %d *arr[1]: %d\n", b,*arr[1]);
// printf(" a: %d *arr[2]: %d\n", b,*arr[2]);

// printf("&a: %p arr[0] %p\n", &a,arr[0]); //포인터도 배열로 만들수 있다. 
// //포인터 배열을 만들수 있다



// int arr[3]={1,2,3};
// int *p = &arr[0]; // int *p = arr;

// for (int i = 0; i < 3; i++,p++)   //  p++ 데이터 형의 만큼 뛰어가겠다.
// {
//     printf("p=%p,",p); //포인터 변수니까 주소를 찍고
//     printf("*p= %d\n", *p); //주소에 있는 값을 찍는다.
// }


// int arr[5]={1,3,5,7,9};
// int *p = &arr[0]; // int *p = arr;

// for (int i = 0; i < 5; i++)   //  p++ 데이터 형의 만큼 뛰어가겠다.
// {
//     printf("p=%p,",p); //포인터 변수니까 주소를 찍고
//     //printf("*p= %d\n", *p++); //주소에 있는 값을 찍는다.    p++실행 한다음에 올려줌 
//     printf("*p= %d\n", (*p)++); //주소에 있는 값을 찍는다.  주소값이 안올라 간다. 
// }






}


