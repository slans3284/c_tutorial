
#include <stdio.h>

int main()
{
	// 삼항 연산자:
	// 변수 = 조건식 ? 참일때 결과 : 거짓일 때 결과

	int n1 = 10;
	int n2 = 7;
	char ch;

	ch = n1 > n2 ? 'G' : 'L';
	printf("ch=%c\n", ch);

	// 비트 연산자: &, |, ~, ^(XOR)
	char c1 = 5;  // 0000 0101
	char c2 = 3;  // 0000 0011
	ch = c1 & c2;
	printf("ch=%d\n", ch);
	
	ch = c1 | c2;
	printf("ch=%d\n", ch);

	ch = c1 ^ c2;	// xor 서로 같으면 0 , 다르면 1
	printf("ch=%d\n", ch);

	c2 = 1;
	ch = ~c2;
	printf("ch=%d\n", ch);

	//shift: <<, >> 
	ch = c2 << 3;	// 새로 채워지는 비트가 무조건 0으로 채워짐
	printf("ch=%d, c2=%d\n", ch, c2);

	c2 = 16;
	ch = c2 >> 3;		// 오른쪽 쉬프트는 1000 0000 일떄 부호는 변경하지 않고 이동
	printf("ch=%d, c2=%d\n", ch, c2);


	return 0;
}


