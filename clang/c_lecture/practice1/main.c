#include <stdio.h>
/**
 * @brief  do while 문
 * 
 * @return int 
 */
int main()
{
    int weight ;
    int count=0;
    

    for(weight=80; weight<70; weight--)    //초기값설정후 조건을 본다. for 문장 돈다음에 weight--로 감 그리고 
    {
       printf("운동해서 1kg 빼자\n");
       count++;
    }
      printf("축하합니다 운동안해도 됨\n");  
      printf("%d 일 운동했다\n",count); 
}
