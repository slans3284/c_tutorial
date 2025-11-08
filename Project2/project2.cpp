// 0907(일) 
#define _CRT_SECURE_NO_WARNINGS
// 에러없이 scanf 를 쓸 수 있다



/*
표준 입력출력 함수

출력 함수
printf() : 콘솔(터미널)장치에 문자열 형 형식으로 출력한다.

입력 함수
scanf() : 콘솔장치의 키보드로부터 데이터를 입력받아 변수에 저장하는 함수
*/
#include<stdio.h>

int main()
{
	printf("Hello C\n");		// Hello C <-- 문자열 상수  \n <-- 제어문자
	printf("Hello\t");
	printf("Hello\n");
	printf("Next text\r");
	printf("Clear text\n");
	printf("Back space\b");
	printf("\nThis\t is new l\bine\n");
	printf("\\");	// 여슬래시 한개를 출력

	// 제어 문자(Control Character)
	/*
	\n: new line, 커서를 다음줄 첫번째 칸으로 이동시킴
	\t: tab, tab만큼 커서를 우측으로 이동시킴
	\r: 커서를 현재줄의 가장 처음위치로 이동시킴
	\b: Back space, 백스페이스키를 한번 누른건과 동일한 효과
	\v: Vertical tab, 아래 방향으로 커서를 이동시킴(잘 안됨)
	\a: alarm, 삑 소리르 냄(옛날 컴퓨터만 가능)
	\\: \를 출력
	*/

	//데이터의 출력
	int num = 10;	// 4바이트 메모리 공간에 10을 대입
	char ch = 'z';	// "" <-- 문자열, '' <-- 문자 
	float pi = 3.14F;	// F가 붙으면 float형 리터럴이 됨, 안 붙으면 double 형으로 간주됨


	// 형식 문자(Formatted String)
	printf("num의 값: %d\n", num);
	printf("num의 값: %u\n", num);
	printf("ch의 값: %c\n", ch);
	printf("pi의 값: %f\n", pi);
	printf("num의 값: %x\n", num);
	printf("%s %s %s\n", "one", "two", "three");
	printf("num의 주소 : 0x%p\n", &num);	// &(엔퍼샌드)를 붙이면 번수의 주소르 알려준다

	// decoration
	printf("%10d%10d\n", num, 11);
	printf("%-5d%-5d\n", num, 11);
	printf("%6.2f\n", pi);
	printf("%-6.2f\n", pi);

	// 타입 일치시키기
	// char, short, int, long, long long
	// 모든 정수형 자료형 타입 앞에 unsigned 가 붙을 수 있고 음의 정수는 표현하지 않는다.
	long money = 100000L;
	unsigned long long dist = 10000000000LL;
	printf("num의 값: %ld\n", money);	// signed long long decimal
	printf("num의 값: %llu\n", dist);	// unsigned long long decimal


	// 형식 문자(Formatted String)
	/*
	%d : decimal, signed integer, 부호가 있는 정수형 데이터를 표현한다.
	%u : decimal, unsigned integer, 부호가 없는 양의  정수형 데이터를 표현한다.
	%c : character, 문자로 표현
	%f : float, 실수형으로 데이터를 표헌
	%x,%X : (소,대문자로) Hex, 16진수로 데이터를 표현 
	%o : oct, 8진수로 데이터를 표현
	%s : string, 문자열을 표현
	%p : pointer, 변수의 주소를 표현
	*/

	/*
	%10d : 10칸을 확보후 데이터를 우측 정렬하여 출력한다. 
	%-5d : 5칸을 확보후 데이터를 좌측 정렬하여 출력한다.
	%6.2f : 소수점을 포함하여 총 6자리 확보후 소수점 이하를 두자리까지 우측 정렬 표현한다.
	%-6.2f : 소수점을 포함하여 총 6자리 확보후 소수점 이하를 두자리까지 좌측 정렬 표현한다.
	*/

	// 표준 입력함수
	/*scanf("%d", &num);
	printf("입력받은 값:%d\n", num);*/

	//scanf("%f", &pi);
	//printf("입력받은 값: %.2f\n", pi);

	//scanf("%c", &ch);	// 알파벳 한글자 입력 받음
	//printf("입력받은 값: %c\n", ch);

	//short sh;
	//scanf("%hd", &sh);	// h : half 
	//printf("입력받은 값: %d\n", sh);

	//scanf("%hhd", &ch);	// char형을 정수형으로 입력받기
	//printf("입력받은 값: %c\n", ch);

	/*scanf("%d %c %f", &num, &ch, &pi);
	printf("입력받은 값: %d, %c, %.2f\n", num, ch, pi);*/
	
	//형변환(Type Casting)
	num = 1000;
	// 묵시적 형변환 (일반적으로 사용하지 않는다) 
	pi = num;	// pi에 들어가는 값은 100.0
	ch = num;	// 데이터 손실이 발생함

	pi = 3.999999F;
	num = pi;	// 데이터 손실이 발생함
	
	// 명시적 형변환
	num = (int)pi;
	pi = (float)num;
	
	
	return 0;

}