# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // 표준 입출력에 관련된 함수들이 정의되어 있는 헤더 파일
#include <stdlib.h> // srand()
#include <time.h>


int main()
{
	// time(NULL) : 현재 시스템 시간을 구하는 함수
	// 랜덤초기화
	srand(time(NULL));

	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;	// 0 ~ 99 사이의 난수(랜덤값)를 구함
		printf("%d\t", arr[i]);
	}

	// 정렬하기
	for (int i = 0; i < 10 - 1;i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	printf("\n");
	//출력하기 
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}

	printf("\n");


	// 이진 탐색(Binary Search)
	int to_find = 55;
	printf("찾을 값을 입력하세요 >>>");
	scanf("%d", &to_find);

	int count = 0;
	int found = 0; // 상태를 표현하는 flag 변수

	int start = 0;		// 시작 인덱스
	int end = 10 - 1;   // 마지막 인덱스
	while (start <= end)
	{
		++count;

		int mid = (start + end) / 2;
		if (arr[mid] == to_find)
		{
			
			// 원하는 값을 찾은 경우에는 위치를 출력하고 while 반복문을 탈출한다.
			printf("%d는 %d index에 있습니다.\n", to_find, mid);
			printf("%d 탐색과정에서 데이터를 찾았음", count);
			found = 1;
			break;
		}

		if (to_find < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}

	if (!found)	// found == 0
		printf("데이터를 찾지 못함");

	return 0;
}


