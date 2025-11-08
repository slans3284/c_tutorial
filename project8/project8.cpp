#include <stdio.h>

int main()
{
    // 배열(Array)[첨자 or index 배열의 전체 개수-1까지 가능, 시작은 0번 부터]
    int num;        // 정수형(4byte) 데이터를 1개 저장할 수 있는 공간 
    num = 10;
    printf("num변수의 크기: %d bytes\n", sizeof(num));

    int arr[5];     // 정수형(4byte) 데이터를 5개 저장할 수 있는 공간
    arr[0] = 10;    // arr의 첫번째 공간에 값 10을 대입한다.
    arr[1] = 20;    // arr의 두번째 공간에 값 20을 대입한다.
    arr[2] = 30;    // arr의 세번째 공간에 값 30을 대입한다.
    arr[3] = 40;    // arr의 네번째 공간에 값 40을 대입한다.
    arr[4] = 50;    // arr의 다섯번째 공간에 값 50을 대입한다.
    printf("arr배열의 크기: %d bytes\n", sizeof(arr));
    for (int i = 0; i < 5; i++)
        printf("arr[%d] : %d\n", i, arr[i]);

    // nums라는 이름의 short형 배열을 선언함과 동시에 각 아이템들의 값을 초기화한다.
    short nums[] = {10, 20, 30, 40, 50};    // 초기화하면서 선언할때는 개수 지정을 생략할 수 있다.
    printf("nums배열의 크기: %d bytes\n", sizeof(nums));

    long nums2[] = {5, 10, 15, 20, 25, 30, 35};
    int count = sizeof(nums2) / sizeof(long);
    printf("nums2 배열의 길이 : %d 개", count);

    // arr배열의 각 아이템에 0부터 2의 배수단위로 값을 대입하는 반복문을 작성하세요
 
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i*2; // arr[0] = 0*2, arr[1] = 1*2, arr[2] = 2*2, arr[3] = 3*2, arr[4] = 4*2
        printf("arr[%d] : %d\n", i, arr[i]);
    }

    // num2 배열의 모든 아이템들의 합을 구하여 출력하세요
    // 출력형식)
    // num2 배열의 합 : xxx 
    
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += nums2[i];
    }
    printf("nums2 배열의 합 : %d\n", sum);

    // nums2 배열을 역순으로 출력하세요
    //30     25    20  15   10    5 

    for (int i = count-1; i >= 0; i--)
    {
        printf("%d\t", nums2[i]);
    }
    printf("\n");
    int nums3[] = { 10, 9, 3, 20, 7, 3, 8 };
    int count2 = sizeof(nums3) / sizeof(int);
    // 최대값과 최소값을 구하여 출력하세요
    // 출력형식)
    // 최대값 : xxx
    // 최소값 : xxx
    int max = nums3[0];
    int min = nums3[0];

    for (int i = 0; i < count2; i++)
    {
        if (max < nums3[i]) max = nums3[i];   
        if (min > nums3[i]) min = nums3[i];
     }
    printf("최대값 : %d\n", max);
    printf("최소값 : %d\n", min);

    int n1 = 10, n2 = 5;
    int n3 = n1;
    n1 = n2;
    n2 = n3;
  
    printf("%d\n",n1);
    printf("%d\n",n2);






    return 0;
}
