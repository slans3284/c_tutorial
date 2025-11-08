#include <stdio.h>

// 문자열(String) 만들기
int main()
{
	char arr[] = { 'A','B','C' };
	//char arr[] = { '65','66','67' };

	for (int i = 0; i < 3; i++)
	{
		printf("%c",arr[i]);
	}
		
	printf("%s", arr);	//%s는 문자열 포맷 스트링

	return 0;
}


