# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// 전역 변수(Global Variable)
int g_val = 0;

void save_text(const char filename[], const char data[], size_t size)
{
	FILE* fp = NULL;	// 파일을 가리키는 포인터

	// test01.txt 파일을 테스트 데이터 저장 용도로 연다.
	fp = fopen(filename, "wt");
	// fp에 포인터가 정상적으로 할당되었는지 반드시 체크해야 한다!
	if (fp == NULL)	// = > if(!fp) // NULL(주소끼리 비교) == 0(값끼리 비교)
	{
		printf("파일 열기 실패!\n");
		return;
	}

	//char ch = '1';
	//char str[] = "1234";	// 5 byte, \0 숨음, 앨리먼트 개수는 5개, 앨리먼트 크기는 1byte
	//int arr[] = { 1,2,3,4 };  // 16 byte, 앨리먼트 크기 4개, 앨리먼트 크기 4byte


	fwrite(data, sizeof(char), size, fp);

	//fwrite(data, sizeof(char), sizeof(data) - sizeof(char), fp);


	/*
	fwrite(
			const void* Buffer,	// 저장할 데이터가 있는 메모리 공간의 주소(포인터)
			size_t elementSize,	// 각element 의 크기
			size_t elementCount, // 전체 element의 개수
			FILE* stream		// 저장할 대상, 파일 포인터
	)
	*/


	// 파일을 닫는다!
	fclose(fp);



}

void load_text(const char filename[])
{

	static int n = 0; // 프로그램의 시작 ~ 종료시점까지 유지 

	FILE* fp = NULL; // 파일 포인터를 준비
	fp = fopen(filename, "rt");	// rt = read text 
	if (!fp)
	{
		printf("파일을 열 수 없습니다\n");
		return;
	}

	char sz[100] = { 0 };	// 넉넉하게 읽어들일 버퍼를 확보한다.
	fread(sz, sizeof(char), 100, fp);

	fclose(fp);

	printf("%s", sz);

	printf("%s %d번 호출됨", sz, ++n);
}

void save_binary(const char filename[], int arr[], int count)
{
	FILE* fp = NULL; // 파일 포인터를 준비
	fp = fopen(filename, "wb");	// rt = read text 
	if (!fp)
	{
		int n;
		printf("파일을 열 수 없습니다\n");
		return;
	}
	fwrite(arr, sizeof(int), count, fp);

	
	fclose(fp);
}

long get_file_size(const char filename[])
{
	FILE* fp = NULL;
	fp = fopen(filename, "rb");
	if (!fp)
		return -1;

	// fseek의 origin : 
	// SEEK_SET : 파일의 시작지점,(BOF)
	// SEEK_CUR : 현재 커서의 위치
	// SEEK_END : 파일의 끝지점(EOF)
	// fseek(fp, 기준점으로부터 떨어진 거리, 기준점)
	//	fseek(fp, 3, SEEK_SET);	// 파일의 시작점으로부터 3바이트 떨어진 거리로 커서를 이동시킴
	//	ftell(fp);	// 3
	//	fseek(fp, -3, SEEK_CUR);// BOF 지점으로 이동시킴
	//	ftell(fp);	// 0 
	fseek(fp, 0, SEEK_END);	// 커서를 EOF지점으로 이동시킴
	long fsize = ftell(fp);	// 파일의 크기

	fclose(fp);
	return fsize;
}

int* load_binary(const char filename[], int* pCount) 
{

	//파일의 크기를 구할 수 있는가? 가능.
	// 어떻게? fseek를 이용하여 EOF지점으로 이동후 ftell을 이용하여 커서의 위치를 구함 --> 파일크기
	//	fseek() : 커서를 이동시킴 -> 탐색
	// ftell() : 커서의 현재 위치를 알려줌
	long file_size = get_file_size(filename);
	printf("%s 파일의 크기는 %d 바이트 입니다\n", filename, file_size);

	// malloc(Memory Allocate) : 바이트 단위로 메모리 할당을 요청
	int* pArr = (int*)malloc(file_size);
	if (!pArr)
		return NULL;

	FILE* fp = NULL;
	fp = fopen(filename, "rb");
	if (!fp)
	{
		free(pArr);
		return NULL;
	}
	size_t count = file_size / sizeof(int);
	// 메모리 할당 & 파일오픈 성공
	fread(pArr, sizeof(int), count, fp);


	//free(pArr);
	fclose(fp);

	*pCount = count;

	return pArr;
}

void print_array(int arr[], int count)
{
	printf("배열의 출력할 요소의 개수는 %d개입니다\n",count);
	for (int i = 0; i < count; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	// 파일에 데이터를 저장(SAVE)하고 읽어오기(LOAD)

	// file open mode
	// w : write mode, 파일에 데이터를 저장하기 위한 모드, 항상 새파일로 만듬
	// r : read mode, 파일로부터 데이터를 읽기 위한 모드
	// a : append mode,  파일에 데이터를 저장하기 위한 모드, 만약에 데이터가 있다면 데이터를 가장 뒤에 추가하여 쓰기

	// t : text file (메모장 모드)
	// b : binary file( 이미지, 사운드,,, 메모장 제외) 

	char sz1[] = "Hello, SBS Academy\n안녕하세요, 반갑습니다.";
	save_text("test01.txt", sz1, sizeof(sz1) - sizeof(char));
	load_text("test02.txt");

	printf("test01.txt파일의 크기: %d 바이트\n", get_file_size("test01.txt"));
	
	int arr1[] = { 5,10,12,21,33,38 };

	save_binary("test01.dat",arr1,6);

	int arr2[] = { 5,10,12,21,33,38, 100, 200, 300, 400 };
	save_binary("test02.dat", arr2, 10);

	int arr3[] = { 1,2 };
	save_binary("test03.dat", arr3, 2);

	int* pArr = NULL;
	//int count = get_file_size("test01.cat") / sizeof(int);
	int count = 0;
	pArr = load_binary("test01.dat", &count);
	print_array(pArr,count);
	
	if (pArr)  // (pArr != NULL)
	{
		free(pArr);
		pArr = NULL;
	}


	pArr = load_binary("test02.dat",&count);
	print_array(pArr, count);

	if (pArr)  // (pArr != NULL)
	{
		free(pArr);
		pArr = NULL;
	}
	load_binary("test03.dat",&count);
	print_array(pArr, count);

	if (pArr)  // (pArr != NULL)
	{
		free(pArr);
		pArr = NULL;
	}



	return 0;	// 정상 종료
}
