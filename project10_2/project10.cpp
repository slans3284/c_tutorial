#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	// 문자열 처리 함수들이 정의되어있는 헤더파일 

// 문자열(String) 만들기
// 문자열은 배열의 일부이다.
// 모든 문자열은 배열이지만, 모든 배열이 문자열은 아니다.
int main()
{
	//char arr[] = { 'A','B','C','\0'};
	char arr[] = { 65,66,67,0};
	// \0 : NULL Terminated Character

	// char sz[] = { 'H','e','l','l','o',' ','W','o','r','l','d','\0' };
	char sz[] = "Hello World"; // 문자열의 길이는 11자 데이터의 크기는 12byte(\0 포함)

	/*for (int i = 0; i < 3; i++)
	{
		printf("%c", arr[i]);
	}*/

	printf("%s\n", arr);	//%s는 문자열 포맷 스트링
	printf("%s\n", sz);
	printf("sz의 크기 : %d bytes\n", sizeof(sz));
	printf("sz 문자열의 길이 : %d개\n", strlen(sz));
	//strlen(문자열배열) : 문자열의 길이를 반환해줌

	//for (int i = 0; i < sizeof(sz)-1; i++)
	for (int i = 0; i < strlen(sz); i++)

	{
		printf("%c\n", sz[i]);
	}

	sz[0] = 'h';
	sz[6] = 'w';
	printf("%s\n", sz);

	char sz2[12] ;
	// 문자열 복사(문자열 대입)
	strcpy(sz2, sz);
	printf("%s\n", sz2);
	//for (int i = 0; i < strlen(sz); i++)

	//{
	//	sz2[i]=sz[i];
	//}

	char sz3[] = "Hello\0World";
	printf("sz3의 크기 : %d bytes\n", sizeof(sz3));
	printf("sz3 : %s\n", sz3);
	printf("sz3문자열의 길이 : %d개\n", strlen(sz3));
	if (sz == sz2)
		printf("sz와 sz2는 같습니다.\n");
	else
		printf("sz와 sz2는 다릅니다.\n");

	printf("sz 와 sz2는 %s", strcmp(sz, sz2) == 0 ? "같다\n" :"다르다\n");
	// strcmp(문자열1, 문자열2) : 문자열1과 문자열 2를 비교하여 같으면 0을 반환한다. 

	// str = "Hello " + "World"; ===> Hello World(c언어는 불가능)
	char sz4[20] = { 0 }; // sz4배열의 모든 아이템들의 값을 0으로 초기화한다.
	// 0 == \0
	// strcat : 문자열 이어 붙이기
	strcat(sz4, "Hello2 ");	// sz4 == "Hello "
	strcat(sz4, "World2");	// sz4 == "Hello World "
	printf("%s\n", sz4);

	// A = 65
	// a = 97

	char str[] = "Ax?Rb^lo%Wk";
	//문제)
	//str문자열의 각 문자를 확인하여 대문자이면 소문자로 변환하고,
	//소문자는 대문자로 변환하세요
	// 변환 완료후에는 문자열출력 포맷 스트링을 이용하여 출력하세요

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')	// str[i] 대문자인 경우
			str[i] += 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}

	printf("%s\n", str);


	return 0;
}
