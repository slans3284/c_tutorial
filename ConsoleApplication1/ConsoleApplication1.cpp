
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_value(int arr[], int count, int to_find)
{
	for (int i = 0;i < count;i++)
	{
		// 해당 배열에서 to_find 값을 찾았으면
		if (arr[i] == to_find)
			return i;	// 해당 배열의 현재 인덱스값을 반환
	}
	return -1;	// to_find값을 arr 배열에서 찾지 못했을 때
}

void print_array(const int arr[], int count)
{
	//arr[0] = 1; const라는 상수 지정하면 값을 변경할 수 없다

	for (int i = 0;i < count;i++)
	{
		printf("%2d ", arr[i]);
	}
}

// 배열 + 포인터 + 함수
//void make_random_array(int* arr, int count)
void make_random_array(int arr[], int count)	
{
	int i = 0;	// 배열의 인덱스로 사용할 변수 초기화
	while (i<count)
	{
		int tmp = rand() % 45 + 1;	// 1부터 45 사이의 난수값 생성
		if (find_value(arr,count,tmp) < 0)
			arr[i++] = tmp;
	}
}

void exchange(int* num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void sort_array(int arr[], int count)
{
	for (int i = 0; i < count;i++)
	{
		for (int j = i + 1;j < count;j++)
		{
			if (arr[i] > arr[j])
				exchange(&arr[i], &arr[j]);
		}
	}
}

int rank(int hit)
{
	switch (hit)
	{
	case 6: return 1;
	case 5: return 2;
	case 4: return 3;
	case 3: return 4;
	default: return 0;
	}
}

//매크로함수
#define COUNT	6
#define ROW		5


// 로또 시뮬레이션

int main()
{
	/*
	*당첨 번호와 구매자 로또 번호를 랜덤하게 생성하여
	* 서로 비교하여 매칭 여부에 따른 등수를 구함
	*/

	// 당첨 번호 배열
	int lotto[COUNT] = { 0 };
	int user_nums[ROW][COUNT] = { 0 };

	/*
	user_nums = {
			{1,2,3,4,5,6},
			{1,2,3,4,5,6},
			{1,2,3,4,5,6},
			{1,2,3,4,5,6},
			{1,2,3,4,5,6}
	};
	user_nums[1][3]; // user_nums배열의 두번째 줄의 네번째 값
	user_nums[1]; // user_nums 배열의 두번째 요소인 1차원 배열
	*/


	// 랜덤한 값으 생성하기 위한 초기화 작업
	srand(time(NULL));

	// 당첨 번호 생성

	printf("=====당첨번호=====\n");
	make_random_array(lotto, COUNT);
	sort_array(lotto, COUNT);
	print_array(lotto, COUNT);

	printf("\n\n=====구매자번호=====\n");

	for (int i = 0;i < ROW;i++)
	{
		make_random_array(user_nums[i], COUNT);
		sort_array(user_nums[i], COUNT);
		print_array(user_nums[i], COUNT);
		int hit_count = 0;
		for (int j = 0;j < COUNT;j++)
		{
			if (find_value(lotto, COUNT, user_nums[i][j]) > 0)
				++hit_count;
		}
		printf("\nHit:%d, %d등\n\n", hit_count,rank(hit_count));
	}



	return 0;
}
