
#include <stdio.h>
#include <stdlib.h>


// 주의 : 지역변수의 주소를 반환해서는 안된다!!!
int* get_value(int index)
{
    int arr[5] = { 1,2,3,4,5 };

    //return &arr[index];
    return arr + index;
}

// 함수의 오버로딩(Overloading): 
// 보통 동일한 함수이름으로 다양한 방법을 제공하기 위해 사용한다. 
void get_value(int index, int* p)
{
    int arr[5] = { 1,2,3,4,5 };
    *p = arr[index];
}

int get_value_ex(int index)
{
    int arr[5] = { 1,2,3,4,5 };
    return arr[index];
}


void print_array(int arr[], int count)
//void print_array(int* arr, int count)

{
    printf("arr의 크기 : %d bytes\n", sizeof(arr));
    for (int i = 0; i < count; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");

   // arr[count - 1] = 100;
   // 위 코드는 runtime error을 발생시킬 수 있음, 절대 해서는 안됨! 
}


void print_array()
{
    int arr[] = { 1,2,3,4,5 };
    for (int i = 0; i < 5; i++)
        printf("%2d", arr[i]);
    
    printf("\n");
    
    for (int i = 0; i < 5; i++)
        printf("%2d", *(arr + i));
    
    printf("\n");

    int* p = arr;
    for (int i = 0; i < 5; i++)
        printf("%2d", *(p++));
    
    // 포인터에서 1씩 증가라함은 1단위(데이터의 타입) 증가를 의미한다.


    /*for (int i = 0; i < 5; i++)
    {
        int* p = arr + i;
        printf("%2d",*p);
    }*/
}




int main()
{
    int* p = get_value(0);
    printf("\n");
    printf("%d", *p);

    printf("\n");
    print_array();

    printf("\n");

    int n;
    get_value(0, &n);
    printf("0번째 값: %d\n", n);

    n = get_value_ex(0);
    printf("0번째 값: %d\n", n);

    int arr[] = {10,20,30,40,50};
    printf("arr의 크기 : %d bytes\n", sizeof(arr));
    print_array(arr, 5);

    //arr[5] = 100; ---> complie error


    // 고정길이배열
    // 가변길이배열  => malㅣoc 함수 이용
    short nums[10] = { 0 };


    // melㅣoc(바이트수) : 시스템에게 메모리 공간 할당을 요청하는 함수
    // malloc 함수의 호출이 성공하면 할당된 주소를 반환해줌
    // 이때 malloc이 반환하는 주소는 타입이 지정되지 않은 주소이다.
    // 타입이 지정되지 않은 주소 == void*
    // 따라서 malloc으로부터 반환되는 주소는 타입을 지정(변환)해주어야 한다.
    // malloc 함수의 호출이 실패하면 NULL이 반환된다.
    short* p = (short*)malloc(sizeof(nums) + sizeof(short));
    //if (p != NULL) // p에 메모리 주소가 할당되었는가?
    //{
    //    //안전하게 p라는 공간을 사용할 수 있다
    //}
    p[0] = nums[0]; // 코드의 안정성을 보장할 수 없다.
    // malloc(sizeof(nums) + sizeof(nums[0]));




    return 0;
}

