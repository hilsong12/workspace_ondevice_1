#include <stdio.h>


int main() 
{
    char score[6];

    int count =sizeof(score)/sizeof(score[0])-1;

    for (int i = 0; i < count; i++)
    {
        scanf( " %c",&score[i]);
    }
    score[count]='\0';

    printf("%s",score);
}

