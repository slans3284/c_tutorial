


#include <stdio.h>

int main()
{
	// for 반복문
	// 반복 횟수가 명확할 때 사용한다.
	// for(초기문; 조건문; 증감식)				
	// 초기문 -> 조건문 -> 실행 ->증감식
	//        ->조건문(참,거짓)
	// 초기문 : 반복문 실행 전 한번만 실행될 부분 
	// 조건문 : 증감식 다음에 실행될 부분( 조건 안쓰고 결과가 0이면 빠져나감)
	// 증감식 : 조건문 실행 후 실행될 부분
	// ==================
	for (int i = 0; i < 20; i++)
	{
		printf("=");
	}

	//for (;;); // 무한반복, 다 생략가능함
	//for (;;)
	//{
	//	//
	//	//
	//}


	int i = 0;
	while (i < 20)
	{
		printf("=");
		i++;
	}
	printf("\n");
		// 구구단 3단 출력하기
		for (int i = 1; i < 10; i++)
		{
			printf("3 x %d = %d\n", i, 3 * i);
		}

		// for문을 이용하여 1 ~ 100까지 홀수의 합을 구하세요
		int total = 0;
		for (int i = 1; i <= 100 ; i+=2)
		{
			total += i;
		}
		printf("total = %d\n", total);

		//
		/*
		*****
		*****
		*****
		*****
		***** 
		*/

		// 중첩 for문
	/*	for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("*");
			}
			printf("\n");
		}*/

		/*
		*****
		****
		***
		**
		*
		*/

		for (int i = 5; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)  // i=5
			{
				printf("*");
			}
			printf("\n");
		}

		/*
		*
		**
		***
		****
		*****
		*/

		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j < i+1; j++)  // i=5
			{
				printf("*");
			}
			printf("\n");
		}

		// 구구단 2단~9단 출력하기

		for (int i = 2; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				printf("%d x %d = %d", i, j, i * j);
				printf("\n");
			}
			printf("\n");
		}

		/*
		2x1 = 2	   3x1 = 3		... 	9x1 = 9
		2x2 = 4
		
		
		*/
		for (int i = 1; i < 10; i++)
		{
			for (int j = 2; j < 10; j++)
			{
				printf("%d x %d = %d\t", j, i, j * i);
			}
			printf("\n");
		}

		// 중첩 for를 사용하지 않고, 단일 for 문으로 1~100까지 출력하기
		/*
		1	2	3	4	5	6	7	8	10
		11	12
		*/

		for (int i = 1; i <99; i++)
		{
			
			
			// 10의 숫자를 구함
			int ten = i / 10;
			// 1의 자리 숫자를 구함
			int nam = i % 10;

			int no_zero = ten != 0 && nam != 0;
			// 10의 자리와 1의 자리 모두 3의 배수이면
			//cc 출력
			if (ten % 3 == 0 && nam % 3 == 0 && no_zero)
				printf("cc\t");
			// 아니고 10의 자리 또는 1의 자리만 3의 배수이면 c를 출력
			else if ((ten % 3 == 0 || nam % 3 == 0) && no_zero)
				printf("c\t");
			else
				printf("%d\t",i);
			// 숫자를 출력
			if(i%10==0)
			printf("\n");




		}

		//int i = 0;
		//while (1)
		//{
		//	while (1)	//무한반복...
		//	{
		//		printf("*");

		//		// i의 값이 100보다 크거나 같아지는 순간에 while 반복문을 즉시 탈출한다.
		//		if (++i >= 100)
		//			break;  // break는 해당 while문을 즉시 탈출시킨다.

		//		printf("=");
		//	}
		//	
		//}
	return 0;
}

