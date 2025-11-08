// #이 앞에 불어있는 명령어를 전처리문 이라고 한다.
// 컴파일이 일어나기 전에 실행되는 명령문을 전처리문이라 한다.
#include <stdio.h> // 표준 입출력 관련 함수들을 제고하는 헤더 파일

// c언어는 함수들로 구성된 구조적 언어이다.
// 함수: 최소한의 기능을 구현하는 코드 블럭
// main함수 : 프로그램의 시작점이 되는 함수 

int main()
{
    // 이 부분에 코드를 작성함
    // console 화면에 hello world 출력하기
    printf("Hello World\n");

    // load : disk 또는 network로부터의 이진 데이터를 메모리에 올리는 것.
    // save : 메모리 ---> 디스크

    // 0 / 1
    // 정수형 / 실수형
    
    // 변수(Variable)
    // 바이트(byte)
    // 1 byte : 8bit ---> 256가지의 서로다른 정보를 표현할 수 있다.   1 byte부터 데이터 처리가 됨
    // 0000 0000 : 0
    // 0000 0001 : 1
    // 0000 0010 : 2
    // 0000 0011 : 3
    // 0000 0100 : 4
    // 0000 0101 : 5
    // 0000 0110 : 6
    // 0000 0111 : 7
    // 0000 1000 : 8
    // -128 ~ 0 ~ +127 

    // 자료형 (Data type) 첫번째 비트는 부호( 0=양수 1=음수)
    char num;   // 변수, char: num이라는 변수의 데이터 타입(정수형, 1바이트)
    short num2; // short, 2바이트 정수형
    int num3; // int, 4바이트 정수형
    long num4; // long, 4(또는 8)바이트 정수형
    long long num5; // long long, 8바이트 정수형

    float r1; // 4바이트 실수형 (정밀도의 차이)
    double r2; // 8바이트 실수형
    long double r3; // 

    // 변수명 작성 규칙
    // 1. 대소문자를 구분한다. Num 과 num은 서로 다른 변수이다.
    // 2. 영문자와 숫자 그리고 _(언더바)를 혼합하여 사용할 수 있다.
    // 3. 숫자가 제일 앞에 올 수 없다. _num(가능), 3num(불가)
    // 4. Reserved Word(예약어): 이미 c컴파일러에서 문법으로 지정된 단어들 사용 불가
 
    
    printf("char형의 크기: %d 바이트\n", sizeof(char));
    printf("short형의 크기: %d 바이트\n", sizeof(short));
    printf("int형의 크기: %d 바이트\n", sizeof(int));
    printf("long형의 크기: %d 바이트\n", sizeof(long));
    printf("long long형의 크기: %d 바이트\n", sizeof(long long));
    printf("float형의 크기: %d 바이트\n", sizeof(float));
    printf("double형의 크기: %d 바이트\n", sizeof(double));
    printf("long double형의 크기: %d 바이트\n", sizeof(long double));
 
    num = 127;
    printf("num = %d\n", num);

    num = num + 1;
    printf("num = %d\n", num);

    num2 = 32767;
    printf("num2 = %d\n", num2);

    num2 = num2 + 1;
    printf("num2 = %d\n", num2);

    // 문자의 표현
    num = 65;
    printf("num = %c\n", num);

    num = 'b';
    printf("num = %d\n", num);


    return 0;
}

// c언어 <<< C++언어 
