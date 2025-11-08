#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int global = 10;    //전역 변수(Global)


//  함수 : 처리 단위, 정의(Define), 호출(Call)
// 함수는 호출하기전에 무조건 상위에 정의되어 있어야 한다!!!

// 함수의 정의
// 함수의_타입 함수의_이름(매개변수1,매개변수2, ...)
//{
//  처리할 명령문(들)...
//}

float divide(float a, int b)    // divde.a
{

    static int ch = 0;   // static
    printf("&d\n", ++ch);

    return a / b;
}

int add(int a, int b)   //매개변수:(=지역변수), 강제로 호출부에 의해 초기화된다.
{   // 지역(local)    // add.a
    int c;  //지역변수
    c = a + b;
    return c;   //c의 값을 반환한다, 반환 : 호출한 지점에 값을 되돌려 준다
}

    // scope : 변수의 생명 주기
    // 지역변수 : 해당 지역안에서만 활동한다
    // 전역변수 : 프로그램이 실행되는 동안 활동한다
    // static : 프로그램이 실행되는 동안 활동한다. 단, 그 지역안에서만 유효하다 

//  
//  void 함수 : 반환값이 없는 함수
void show_menu(/*생략 가능*/)
{
    printf("1. 새파일\n");
    printf("2. 파일 열기\n");
    printf("3. 파일 저장\n");
    return;

    printf("4. 종료\n");
}

// 3개의 정수를 입력받아서 그중에서 가장 큰 값을(정수) 반환하는 함수를 정의하고
// main 함수에서 호출해보고 결과를 출력하세요

int get_max(int a, int b, int c)
{
    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;

    return max;
}

// 양의정수를 입력받아서 1부터 해당 정수까지(포함)의 합을 구하여 
// 반환하는 함수를 정의하고 호출하여 출력하세요
// 10 ==>55

unsigned int total(unsigned int num)
{
    unsigned int tot = 0;
    for (unsigned int i = 1; i <= num; i++)
    {
        tot += i;
    }
    return tot;
}

// 어떤 정수를 입력받으면 해당 정수가 짝수인지 홀수인지 판별하여 
// 출력하는 함수를 정의하고(반환값 없음) 홀수와 짝수를 대입하여 호출하세요
// 10 ===> 10은(는) 짝수입니다.
// 5 ===> 5은(는) 홀수입니다.

void printf_odd_even(int num)
{
    // num % 2 == 0 ===> !(num % 2)
    // num % 2 !== 0 ===> (num % 2)


    printf("%d는(은) %s입니다.\n",num,(num % 2) ? "홀수" : "짝수");
}

// 배열을 전달받아서 해당 배열의 모든 값을 출력하는 함수
// void print_array(int arr[], int count)
void print_array(int* arr, int count)

{
    for (int i = 0; i < count; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

/*
arr = 배열
count : 배열의 길이
val : 찾을 값
반환값 : 찾은 경우에는 해당 값이 위치하는 배열의 인덱스, 못 찾으면 -1을 반환
*/
int find_value(int arr[], int count, int val)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == val)      // val을 arr에서 찾았으면...
            return i;           // 즉시 인덱스 i값을 반환하여 함수를 종료한다. 
    }

    // 여기까지 왔다는 것은 값을 찾지 못했다는 것임
    return -1;
}

void make_random_array(int arr[], int count)
{

   // printf("make_random_array :: arr 의 크기 : %u\n", sizeof(arr));

    int i = 0;
    while(i < count)
    {
        int tmp = rand() % 45 + 1;

        // tmp 값이 arr 배열에 없으면 tmp를 i번째 위치에 대입한다. 
        if(find_value(arr,count, tmp) < 0)
        arr[i++] = tmp; // 값을 먼저 대입하고 그 다음에 i를 증가시킴.

    }
}


void exchange(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



void sort_array(int arr[], int count)       // 배열의 시작 주소와 원소의 개수 표현
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                exchange(&arr[i], &arr[j]);
               
            }
        }
    }
}




int main()
{
    //printf("maximum = %d\n",get_max(10, 5, 7));
    //int tot = total(10);
    //printf("total = %u\n", tot);

    //printf_odd_even(10);
    //printf_odd_even(5);

    int lotto[6] = {0};       // 당첨번호 (1~45)
    int user[5][6];     // 로또 구매자 번호

    // 랜덤 초기화
    srand(time(NULL));

    printf("=====당첨번호=====\n");

    make_random_array(lotto, 6);    // 배열에 랜덤값을 채움
    sort_array(lotto, 6);
    print_array(lotto, 6);          // 배열의 내용 출력

    printf("\n");
    printf("=====구매자번호=====\n");

    for (int i = 0; i < 5; i++)
    {
        make_random_array(user[i], 6);
        sort_array(user[i], 6);
        print_array(user[i], 6);   


        // 각 라인별 당첨번호가 몇개인지 카운트하여
        // 결과를 출력하는 코드를 작성하세요
        // 당첨된 개수: x개

        int count = 0;
        for (int j = 0; j < 6; j++)
        {
            if (find_value(lotto, 6, user[i][j]) >= 0)
                ++count;
        }
        printf("당첨된 개수: %d개\n", count);

    }
    
    // 등수를 출력하는 함수를 구현하세요 
    // 3개 맞았으면 5등
    // 4개 맞았으면 4등
    // 5개 맞았으면 2등
    // 6개 맞았으면 1등
    // 2개 이하는 꽝 으로 출력하는 함수를 구현하세요



    // 당첨번호 1차우너 배열의 내용을 랜덤한 값으로 채우기
    // 조건1) 절대로 값이 중복해서 입력되면 안된다!
    // 조건2) 오름차순으로 정렬되어 출력되어야 한다.

    // 주소형(포인터): 주소만 저장할 수 있다!!
    // char*, short*, int*, long*, long long*, float*, double*, long double* 
    
    short n = 10;
    short* p;   // short형 포인터 변수
    int num = 300;
    int* ptr;

    printf("n의 값: %d\n", n);
    printf("n의 크기: %u\n", sizeof(n));
    printf("n의 주소: %p\n", &n);  // & 주소 연산자
    p = &n; // 변수 p에 변수 n의 주소를 저장
    printf("p의 값: %p\n", p);  
    printf("p가 참조하는 변수의 값: %d\n", *p);  // 역참조
    printf("p의 크기: %u\n", sizeof(p));

    printf("num의 값: %d\n", num);
    printf("num의 크기: %u\n", sizeof(num));
    printf("num의 주소: %p\n", &num);
    ptr = &num;
    printf("ptr의 값:%p\n", ptr);
    printf("ptr가 참조하는 변수의 값:%d\n", *ptr);
    printf("ptr의 크기: %u\n", sizeof(ptr));


    printf("lotto 배열의 크기: %u\n", sizeof(lotto));
    printf("lotto 배열의 주소: %p\n", lotto);    // 배열명은 곧 주소 그 자체이다.

    printf("lotto[0]의 크기:%u\n", sizeof(lotto[0]));
    printf("lotto[0]의 주소:%p\n", &lotto[0]);
    ptr = lotto;
    printf("lotto[0]의 값:%d\n", lotto[0]);
    printf("lotto[0]의 값:%d\n", ptr[2]);

    /*lotto = ptr;
    num = 10;
    10 = num */





    return 0;
}


