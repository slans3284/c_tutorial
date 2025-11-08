

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 제어문
// if, if~else, if~else if~else
// switch case


int main()
{
	/*
	<<if문 1형식>>
	if (조건식)
	{
		조건식이 참일때 실행될 문장1
		조건식이 참일때 실행될 문장2
		...
		조건식이 참일때 실행될 문장n
	}
	*/
	int n1 = 10;
	int n2 = 5;
	if (n1 == n2)		// '0은 FALSE 다' 진리 , 0이 아니면 다 참이다
	{					
		printf("n1과 n2는 같습니다.\n");
		//printf("n1=%d , n2=%d\n", n1, n2);
	}

	if (n1 == n2)			
		printf("n1과 n2는 같습니다.\n");	// 문장 하나만 쓰면 {} 없어도 된다
		//printf("n1=%d , n2=%d\n", n1, n2);

	/*
	* <<if문 2형식>>
	if(조건식)
		조건식이 참일때 실행될 문장;
	else
		조건식이 거짓일때 실행될 문장;

	*/
	if (n1 == n2)
		printf("n1과 n2는 같습니다.\n");
	else
		printf("n1과 n2는 다릅니다.\n");

	/*
	<< if문 3형식 >>
		if (조건식1)
			조건식1이 참일때 실행될 문장;
		else if(조건식2)
			조건식2이 참일때 실행될 문장;
		else if(조건식n)
			조건식n이 참일때 실행될 문장;
		else
		위 모든 조건식이 거짓일때 실행될 문장;
	*/
	n1 = 75;
	if (n1 > 90 && n1 <= 100)
		printf("A학점입니다\n");
	else if(n1 >=80 && n1 <= 89)
		printf("B학점입니다\n");
	else if (n1 >= 70 && n1 <= 79)
		printf("C학점입니다\n");
	else if (n1 >= 60 && n1 <= 69)
		printf("D학점입니다\n");
	else
		printf("F학점입니다\n");

	// 

	char color = 'w';
	// color 값을 판단하여 매칭되는 case 블럭으로 분기하고 
	// 그 지점부터 아래 방향으로 계속 실행됨
	// break 문을 만나면 즉시 switch문을 탈출함
	switch (color)
	{
	case 'r':
		printf("빨강색");
		break;	// switch~case 문을 즉시 탈출하라는 명령

	case 'g':
		printf("녹색");
		break;

	case 'b':
		printf("파랑");
		break;

	case 'w':
		printf("흰색");
		break;

	case 'k':
		printf("검정");
		break;

	default:	// 위의 모든 경우에 해당되지 않을때 이곳으로 분기됨
		printf("모름");
	}

	printf("\n\n");

	// 문제1) 
	/*
	scanf() 함수를 이용하여 1개의 정수를 입력받고
	입력받은 값이 짝수이면 "짝수" 아니면 "홀수"를 출력하세요

	입출력 예제)
	정수를 입력하세요 >>> 26
	짝수
	
	정수를 입력하세요 >>> 1
	홀수
	*/

	int number;
	printf("정수를 입력하세요 >>> " );
	scanf(" % d", &number);
	if (number % 2 == 1)
		printf("홀수\n");
	else
		printf("짝수\n");

	printf("%s\n", (number % 2 == 0) ? "짝수" : "홀수");
		
	//0914(일)
		//문제2)
		// 점수를 정수형으로 입력받아서
		//90이상 ~ 100이하이면 'A'
		//80이상 ~ 89이하면 'B'
		//70이상 ~ 79이하면 'C'
		//60이상 ~ 69이하면 'D'
		// 그렇지 않으면 'F'학점을 출력하는
		// 코드를 아래 예제와 같이 출력되도록 코드를 작성하세요
		// 반드시 switch ~ case문을 사용하여 코드를 작성하세요

		// 입출력 예정)
		//점수를 입력하세요 >>> 83
		// B학점


	int score;
	printf("점수를 입력하세요 >>>");
	scanf("%d", &score);
	int tmp = score / 10;
	char grade = 'F';

	switch (tmp)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	}
	printf("%c학점", grade);

	return 0;
}

