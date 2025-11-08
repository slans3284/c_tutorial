#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 반복문
// while, do while, for

int main()
{
	// while (조건식)  
	// 조건식이 참일 동안만 명령문 실행. 조건식이 처음부터 거짓이면 진입하지 않는다.
	// {
	// 반복 실행할 명령문(들) 
	// }
	int i = 0;
	while (i < 10)
	{
		printf("i = %d\n", ++i);
	}

	i = 0;
	int total = 0;	// 1+2+3+4+5+...+10 = ???
	while (i <= 10)
	{
		total += i;
		i++;
	}
	printf("1부터 10까지의 합 = %d\n", total);

	// 1부터 100까지 짝수들의 합을 구하여 출력하세요
	i = 2;
	total = 0;

	while (i <= 100)
	{
		total += i;
		i += 2;
	}

	printf("1부터 100까지 짝수들의 합 = %d\n", total);

	// while문은 주로 반복 횟수가 명화하지 않을 떄 사용한다.

	// 사용자가 'x'키를 입력하기전까지 반복 실행
	char ch = '0';
	while (ch != 'x')
	{
		printf("아무키나 입력하세요 : ");
		scanf("%c", &ch);
		
		// enter 키를 클리어함
		char tmp;
		scanf("%c", &tmp);
	}

	// do ~ while():
	// 
	do
	{
		printf("1. 새파일\n");
		printf("2. 파일저장\n");
		printf("3. 파일열기\n");
		printf("x. 종료\n");

		printf("아무키나 입력하세요 : ");
		scanf("%c", &ch);

	} while (ch != 'x');

	printf("while문이 종료됨\n");

	return 0;
}

