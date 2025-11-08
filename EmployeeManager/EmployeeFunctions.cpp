#define _CRT_SECURE_NO_WARNINGS
#include "EmployeeManager.h"


size_t input_rank(RANK** ppRank, size_t old_count)
{
	assert(ppRank);

	system("cls");

	RANK* pRank = *ppRank;

	// 기존 배열의 유무에 따라 1개 또는 기존배열 개수 + 1로 new_count를 설정
	size_t new_count = (!pRank) ? 1 : old_count + 1;
	// new_count 개수에 따라서 할당받을 메모리의 바이트수를 계산
	size_t alloc_bytes = new_count * sizeof(RANK);

	RANK* pNew = (RANK*)malloc(alloc_bytes);
	if (!pNew) return old_count;	//할당 실패이므로 기존 개수를 반환

	RANK tmp;	// 입력값을 임시 저장할 지역 변수 
	printf("직급 코드를 입력하세요 : ");
	scanf("%hd", &tmp.id);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼에 남아있는 \n 삭제하기

	printf("직급명를 입력하세요 : ");
	fgets(tmp.name, RANK_NAME, stdin);
	tmp.name[strlen(tmp.name) - 1] = 0; // \n을 \0으로 바꿔서 줄바꿈을 방지함

	if (pRank)	// 기존에 배열이 있다면
	{
		size_t old_size = old_count * sizeof(RANK);
		memcpy(pNew, pRank, old_size);	// 기존 배열을 새배열에 복사
	}

	// 입력받은 데이터를 새배열 마지막에 복사 
	memcpy(pNew + old_count, &tmp, sizeof(RANK));

	// 정리 작업
	if (pRank)
	{
		free(pRank);
		pRank = NULL;
	}

	// main 함수의 1차원 RANK 배열에 pNew 메모리 주소를 대입
	*ppRank = pNew;

	return new_count;
}

int update_rank(RANK* pRank, size_t count)
{
	assert(pRank);
	assert(count);

	print_rank(pRank, count);
	printf("================\n");

	printf("수정할 코드를 입력하세요 >>> ");
	USHORT code;
	scanf("%hd", &code);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼 비우기

	// 입력받은 코드를 이용하여 해당 배열에서 데이터의 인덱스를 구한다

	int idx = find_rank(pRank, count, code);
	if (idx < 0)
	{
		printf("직급 코드를 찾을 수 없습니다");
		return -1;
	}

	printf("직급명를 입력하세요 : ");
	fgets(pRank[idx].name, RANK_NAME, stdin);
	pRank[idx].name[strlen(pRank[idx].name) - 1] = 0; // \n을 \0으로 바꿔서 줄바꿈을 방지함


	return idx;
}

size_t delete_rank(RANK** ppRank, size_t old_count)
{
	assert(ppRank);
	assert(old_count);

	print_rank(*ppRank, old_count);
	printf("================\n");

	printf("삭제할 코드를 입력하세요 >>> ");
	USHORT code;
	scanf("%hd", &code);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼 비우기

	// 입력받은 코드를 이용하여 해당 배열에서 데이터의 인덱스를 구한다

	int idx = find_rank(*ppRank, old_count, code);
	if (idx < 0)
	{
		printf("직급코드를 찾을 수 없습니다");
		return old_count;
	}
	//
	size_t new_count = old_count - 1;
	size_t new_bytes = new_count * sizeof(RANK);

	if (!new_count)
	{
		free(*ppRank);
		*ppRank = NULL;
		return new_count;
	}

	RANK* pTemp = (RANK*)malloc(new_bytes);
	if (!pTemp)
	{
		printf("메모리 할당 실패");
		return old_count;
	}

	for (int i = 0, j = 0; i < old_count; i++)
	{
		if (idx != i)
		{
			memcpy(pTemp + j, (*ppRank) + i, sizeof(RANK));
			j++;
		}
	}

	free(*ppRank);

	*ppRank = pTemp;

	return new_count;

}


int find_rank(RANK* pRank, size_t count, USHORT code)
{
	for (int i = 0; i < count; i++)
	{
		if (pRank[i].id == code)
			return i;
	}
	return -1;
}

void print_rank(const RANK* pRank, const size_t count)
{
	system("cls");


	// 타이틀 출력
	printf("직급코드  직급명\n");
	printf("================\n");



	// 데이터 출력
	for (int i = 0; i < count; i++)
	{
		printf("%8d  %s\n", pRank[i].id, pRank[i].name);
	}
}
void save_rank(const RANK* pRank, const size_t count)
{
	if (!pRank || !count)
	{
		// 파일 삭제
		char cmd[30] = { 0 };
		sprintf(cmd, "del %s", RANK_FILE);	// cmd = del part.dat
		system(cmd);
	}

	FILE* fp = NULL;
	fp = fopen(RANK_FILE, "wb");
	if (!fp)
	{
		printf("직급 파일을 저장할 수 없습니다");
		return;
	}

	fwrite(pRank, sizeof(RANK), count, fp);

	fclose(fp);
}

size_t load_rank(RANK** ppRank)
{
	assert(ppRank);

	FILE* fp = NULL;
	fp = fopen(RANK_FILE, "rb");
	if (!fp)
	{
		printf("직급 정보를 불러올 수 없습니다");
		return 0;
	}

	fseek(fp, 0, SEEK_END);	// EOF 지점으로 보냄
	long size = ftell(fp);	// 파일 크기를 구함
	fseek(fp, 0, SEEK_SET);	// BOF 지점으로 돌려놈

	RANK* pTemp = (RANK*)malloc(size);
	if (!pTemp)
	{
		fclose(fp);
		printf("메모리 할당 실패!");
		return 0;
	}

	size_t count = size / sizeof(RANK);
	fread(pTemp, sizeof(RANK), count, fp);
	fclose(fp);

	*ppRank = pTemp;

	return count;

}

size_t input_part(PART** ppPart, size_t old_count)
{
	assert(ppPart);

	system("cls");

	PART* pPart = *ppPart;

	// 기존 배열의 유무에 따라 1개 또는 기존배열 개수 + 1로 new_count를 설정
	size_t new_count = (!pPart) ? 1 : old_count + 1;
	// new_count 개수에 따라서 할당받을 메모리의 바이트수를 계산
	size_t alloc_bytes = new_count * sizeof(PART);

	PART* pNew = (PART*)malloc(alloc_bytes);
	if (!pNew) return old_count;	//할당 실패이므로 기존 개수를 반환

	PART tmp;	// 입력값을 임시 저장할 지역 변수 
	printf("부서 코드를 입력하세요 : ");
	scanf("%hd", &tmp.id);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼에 남아있는 \n 삭제하기

	printf("부서명를 입력하세요 : ");
	fgets(tmp.name, PART_NAME, stdin);
	tmp.name[strlen(tmp.name) - 1] = 0; // \n을 \0으로 바꿔서 줄바꿈을 방지함

	if (pPart)	// 기존에 배열이 있다면
	{
		size_t old_size = old_count * sizeof(PART);
		memcpy(pNew, pPart, old_size);	// 기존 배열을 새배열에 복사
	}

	// 입력받은 데이터를 새배열 마지막에 복사 
	memcpy(pNew + old_count, &tmp, sizeof(PART));

	// 정리 작업
	if (pPart)
	{
		free(pPart);
		pPart = NULL;
	}

	// main 함수의 1차원 PART 배열에 pNew 메모리 주소를 대입
	*ppPart = pNew;

	return new_count;
}
int update_part(PART* pPart, size_t count)
{

	assert(pPart);
	assert(count);

	print_part(pPart, count);
	printf("================\n");

	printf("수정할 코드를 입력하세요 >>> ");
	USHORT code;
	scanf("%hd", &code);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼 비우기

	// 입력받은 코드를 이용하여 해당 배열에서 데이터의 인덱스를 구한다

	int idx = find_part(pPart, count, code);
	if (idx < 0)
	{
		printf("부서 코드를 찾을 수 없습니다");
		return -1;
	}

	printf("부서명를 입력하세요 : ");
	fgets(pPart[idx].name, PART_NAME, stdin);
	pPart[idx].name[strlen(pPart[idx].name) - 1] = 0; // \n을 \0으로 바꿔서 줄바꿈을 방지함


	return idx;
}
size_t delete_part(PART** ppPart, size_t old_count)
{

	assert(ppPart);
	assert(old_count);

	print_part(*ppPart, old_count);
	printf("================\n");

	printf("삭제할 코드를 입력하세요 >>> ");
	USHORT code;
	scanf("%hd", &code);

	char ch;
	scanf("%c", &ch);	// 입력 버퍼 비우기

	// 입력받은 코드를 이용하여 해당 배열에서 데이터의 인덱스를 구한다

	int idx = find_part(*ppPart, old_count, code);
	if (idx < 0)
	{
		printf("부서 코드를 찾을 수 없습니다");
		return old_count;
	}
	//
	size_t new_count = old_count - 1;
	size_t new_bytes = new_count * sizeof(PART);

	if (!new_count)
	{
		free(*ppPart);
		*ppPart = NULL;
		return new_count;
	}

	PART* pTemp = (PART*)malloc(new_bytes);
	if (!pTemp)
	{
		printf("메모리 할당 실패");
		return old_count;
	}

	for (int i = 0, j = 0; i < old_count; i++)
	{
		if (idx != i)
		{
			memcpy(pTemp + j, (*ppPart) + i, sizeof(PART));
			j++;
		}
	}

	free(*ppPart);

	*ppPart = pTemp;

	return new_count;

}
void print_part(const PART* pPart, const size_t count)
{

	system("cls");


	// 타이틀 출력
	printf("부서코드  직급명\n");
	printf("================\n");



	// 데이터 출력
	for (int i = 0; i < count; i++)
	{
		printf("%8d  %s\n", pPart[i].id, pPart[i].name);
	}
}
void save_part(const PART* pPart, const size_t count)
{

	if (!pPart || !count)
	{
		// 파일 삭제
		char cmd[30] = { 0 };
		sprintf(cmd, "del %s", PART_FILE);	// cmd = del part.dat
		system(cmd);
	}

	FILE* fp = NULL;
	fp = fopen(PART_FILE, "wb");
	if (!fp)
	{
		printf("부서 파일을 저장할 수 없습니다");
		return;
	}

	fwrite(pPart, sizeof(PART), count, fp);

	fclose(fp);
}
size_t load_part(PART** ppPart)
{

	assert(ppPart);

	FILE* fp = NULL;
	fp = fopen(PART_FILE, "rb");
	if (!fp)
	{
		printf("부서 정보를 불러올 수 없습니다");
		return 0;
	}

	fseek(fp, 0, SEEK_END);	// EOF 지점으로 보냄
	long size = ftell(fp);	// 파일 크기를 구함
	fseek(fp, 0, SEEK_SET);	// BOF 지점으로 돌려놈

	PART* pTemp = (PART*)malloc(size);
	if (!pTemp)
	{
		fclose(fp);
		printf("메모리 할당 실패!");
		return 0;
	}

	size_t count = size / sizeof(PART);
	fread(pTemp, sizeof(PART), count, fp);
	fclose(fp);

	*ppPart = pTemp;

	return count;

}
int find_part(PART* pPart, size_t count, USHORT code)
{

	for (int i = 0; i < count; i++)
	{
		if (pPart[i].id == code)
			return i;
	}
	return -1;
}

size_t input_employee(EMPLOYEE** ppEmp, size_t count_emp,
	const PART* pPart, size_t count_part,
	const RANK* pRank, size_t count_rank)

{
	assert(ppEmp);

	system("cls");

	// 사원정보를 입력받는다.
	EMPLOYEE emp = { 0 };	// 문자열 입력을 받기위해 모든 값을 0으로 초기화하는게 좋다.
	printf("사원 코드를 입력하세요 >>>");
	scanf("%hd", &emp.id);

	char ch;
	scanf("%c", &ch);	// 입력버퍼 클리어

	printf("사원명을 입력하세요 >>>");
	fgets(emp.name, EMPL_NAME, stdin);
	emp.name[strlen(emp.name) - 1] = 0; // \n을 \0으로 바꿔서 줄바꿈을 방지함

	print_part(pPart, count_part);
	printf("부서 코드를 입력하세요 >>> ");
	scanf("%hd", &emp.part);

	print_rank(pRank, count_rank);
	printf("직급 코드를 입력하세요 >>> ");
	scanf("%hd", &emp.rank);

	// 기존 Employee 배열을 얻는다.
	EMPLOYEE* pOldEmp = *ppEmp;
	size_t new_count = count_emp + 1;
	size_t new_bytes = sizeof(EMPLOYEE) * new_count;

	EMPLOYEE* pNewEmp = (EMPLOYEE*)malloc(new_bytes);
	if (!pNewEmp)
	{
		printf("메모리 할당 실패!\n");
		return count_emp;
	}

	// 메모리 할당을 받았으면 기존 데이터를 복사하고, 새 데이터를 추가한다.
	if (pOldEmp)
	{
		// 기존 데이터가 존재하면... 
		memcpy(pNewEmp, pOldEmp, sizeof(EMPLOYEE) * count_emp);
	}

	// 새 데이터를 추가 
	memcpy(pNewEmp + count_emp, &emp, sizeof(EMPLOYEE));

	// 기존 배열 포인터를 대치 
	*ppEmp = pNewEmp;


	// 기존 메모리 해제

	if (pOldEmp)
	{
		free(pOldEmp);
		pOldEmp = NULL;
	}

	return new_count;
}

const char* get_part_name(const PART* pPart, size_t count_part, USHORT part_id)
{
	for (int i = 0; i < count_part; i++)
	{
		if (pPart[i].id == part_id)
			return pPart[i].name;
	}

	return NULL;
}

const char* get_rank_name(const RANK* pRank, size_t count_rank, USHORT rank_id)
{
	for (int i = 0; i < count_rank; i++)
	{
		if (pRank[i].id == rank_id)
			return pRank[i].name;
	}

	return NULL;
}

void print_employee(const EMPLOYEE* pEmp, size_t count_emp,
	const PART* pPart, size_t count_part,
	const RANK* pRank, size_t count_rank)
{
	system("cls");


	// 타이틀 출력
	printf("사원코드 사원명\t부서명\t직급명\n");
	printf("=======================================\n");

	// 데이터 출력
	for (int i = 0; i < count_emp; i++)
	{
		const char* pPartName = get_part_name(pPart, count_part, pEmp[i].part);
		const char* pRankName = get_rank_name(pRank, count_rank, pEmp[i].rank);
		printf("%8d  %s\t%s\t%s\n", pEmp[i].id, pEmp[i].name, pPartName, pRankName);
	}
}
void save_employee(const EMPLOYEE* pEmp, size_t count_emp)
{
	assert(pEmp);
	FILE* fp = NULL;
	fp = fopen(EMPL_FILE, "wb");
	if (!fp)
	{
		printf("사원정보를 파일에 저장할 수 없습니다.");
		return;
	}
	fwrite(pEmp, sizeof(EMPLOYEE), count_emp, fp);

	fclose(fp);
}

size_t load_employee(EMPLOYEE** ppEmp)
{
	assert(ppEmp);

	FILE* fp = NULL;
	fp = fopen(EMPL_FILE, "r");
	if (!fp) return 0;

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	size_t count = size / sizeof(EMPLOYEE);
	EMPLOYEE* pEmp = (EMPLOYEE*)malloc(size);
	if (pEmp)
	{
		fread(pEmp, sizeof(EMPLOYEE), count, fp);
	}

	*ppEmp = pEmp;
	fclose(fp);

	return count;
}

int find_employee(const EMPLOYEE* pEmp, const size_t count_emp, const int id)
{
	for (int i = 0; i < count_emp; i++)
	{
		if (pEmp[i].id == id)
			return i;
	}
	return -1;
}

int update_employee(EMPLOYEE* pEmp, size_t count_emp,
	const PART* pPart, size_t count_part,
	const RANK* pRank, size_t count_rank)
{
	print_employee(pEmp, count_emp, pPart, count_part, pRank, count_rank);

	printf("=======================================\n");
	printf("수정할 사원 코드를 입력하세요 >>> ");

	USHORT id;
	scanf("%hd", &id);

	int idx = find_employee(pEmp, count_emp, id);
	if (idx < 0)
	{
		printf("해당 id를 찾을 수 없습니다.\n");
		return -1;
	}

	char ch;
	scanf("%c", &ch);

	printf("사원명을 입력하세요 >>>");
	fgets(pEmp[idx].name, EMPL_NAME, stdin);
	pEmp[idx].name[strlen(pEmp[idx].name) - 1] = 0;

	print_part(pPart, count_part);
	printf("변경할 부서 코드를 입력하세요 >>> ");
	scanf("%hd", &pEmp[idx].part);

	print_rank(pRank, count_rank);
	printf("변경할 직급 코드를 입력하세요 >>> ");
	scanf("%hd", &pEmp[idx].rank);

	return idx;
}


