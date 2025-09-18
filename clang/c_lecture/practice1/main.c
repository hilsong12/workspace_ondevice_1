// #include <stdio.h>
// /**
//  * @brief  do while 문
//  * 
//  * @return int 
//  */
// int main()
// {
//     int weight=0;
//     int count=0;
    

//     for(weight=80; weight>70; weight--)    //초기값설정후 조건을 본다. for 문장 돈다음에 weight--로 감 그리고 
//     {
//        printf("운동해서 1kg 빼자\n");
//        count++;
//     }
//       printf("축하합니다 운동안해도 됨\n");  
//       printf("%d 일 운동했다\n",count); 
// }

// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     char ch;

//     while (1) {
//         printf("🔴 빨간불 - 정지!\n");
//         sleep(3);

//         printf("🟢 초록불 - 출발!\n");
//         sleep(3);

//         printf("🟡 노란불 - 준비!\n");
//         sleep(2);

//         printf("\n정지하려면 q를 누르세요: ");
//         scanf(" %c", &ch);   // 사용자 입력 대기
//         if (ch == 'q' || ch == 'Q') {
//             printf("프로그램을 종료합니다.\n");
//             break;
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h> // system("clear") 사용

int main() {
    int choice=0;
    int k=0;

    do {
        system("clear"); // 콘솔 화면 지우기 (리눅스)
        printf("+---------------------+\n");
        printf("|      메뉴 선택       |\n");
        printf("+---------------------+\n");
        printf("| 1. 계산기           |\n");
        printf("| 2. 게임             |\n");
        printf("| 3. 종료             |\n");
        printf("+---------------------+\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
            
            do{
            
            printf("계산기 실행!\n"); 
            
                      int a,b,c;
                      char op;
            
                scanf("%d %c %d",&a,&op,&b);
        
                        switch(op)
                          {
                            case '+' : c = a + b ;
                           printf("%d\n",c); break;
                            case '-' : c = a - b ;
                           printf("%d\n",c); break;
                            case '*' : c = a *b ;
                           printf("%d\n",c); break;
                            case '/' : c = a / b ;
                           printf("%d\n",c); break;

                          }
                    
            printf("1. 계속 사용 2. 계산기 나가기\n");   //근데 나는 나가면 전체 메뉴 선택하는걸로 나가고 싶어
            scanf("%d" , &k);
            getchar();
              }while(k == 1);
            
            break;
            
            
    
            case 2: printf("게임 실행!\n"); break;
            case 3: printf("프로그램 종료!\n"); break;
            default: printf("잘못된 선택!\n");
        }


    } while(choice != 3);

    return 0;
}