#include <stdio.h>

struct Student {
    char name;   // 문자열을 가리키는 포인터
    int age;
};

int main() {
    struct Student s1;

    s1.name = "홍길동"; // 문자열 상수를 포인터에 연결
    s1.age = 20;

    printf("이름: %s, 나이: %d\n", s1.name, s1.age);

    return 0;
}

