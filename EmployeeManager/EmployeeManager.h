 #pragma once

//전처리문
//#ifndef __abc__	// if not define __abc__  --> __abc__ 라는게 정의되어 있지 않다면... 
//#define __abc__

//if (!__abc__)
//{
//
//}

#include <stdio.h>	// 표준 입출력 관련 함수들 정의
#include <stdlib.h>	// 표준 라이브러리(여러가지 유틸리티 함수들이 정의)
#include<memory.h>	// heap 제어(복사, 삭제, 재할당...)
#include<conio.h>	// 비표준, Windows OS에서만 사용가능,키입력시 즉시 반환하는 함수를 사용하기 위함.
#include<string.h>	// 문자열 처리 함수들 정의

#ifdef _DEBUG
#include<assert.h>	//디버그 모드에서만 포함시킴
#endif

// 매크로 상수들 정의
#define RANK_NAME	20
#define	PART_NAME	20
#define	EMPL_NAME	20
#define	EMPL_PHONE	20

# define EMPL_FILE	"employee.dat"
# define RANK_FILE	"rank.dat"
# define PART_FILE	"part.dat"



// 타입 재정의(구조체, 열거체 정의)
typedef unsigned short	USHORT;

typedef struct {
	USHORT id;		//직급 코드
	char name[RANK_NAME];	//직급명
} RANK;

typedef struct {
	USHORT id;		//부서 코드
	char name[PART_NAME];	//부서명
} PART;
// 뭔가 변경 2
typedef struct {
	USHORT id;					// 사원 코드
	char    name[EMPL_NAME];	// 사원명 
	USHORT  rank;				// 직급
	USHORT  part;				// 부서
	char	phone[EMPL_PHONE];	// 전화번호
}EMPLOYEE;

typedef struct {
	PART* pPart;
	size_t count_part;
	
	RANK* pRank;
	size_t count_rank;
}PART_RANK;

// 함수들의 원형 정의

// 직급 정보 입력 함수
size_t input_rank(RANK** ppRank,size_t old_count);
int update_rank(RANK* pRank, size_t count);
size_t delete_rank(RANK** ppRank, size_t old_count);
void print_rank(const RANK* pRank,const size_t count);
void save_rank(const RANK* pRank, const size_t count);
size_t load_rank(RANK** ppRank);
int find_rank(RANK* pRank, size_t count, USHORT code);


// 부서 정보 입력 함수
size_t input_part(PART** ppPart, size_t old_count);
int update_part(PART* pPart, size_t count);
size_t delete_part(PART** ppPart, size_t old_count);
void print_part(const PART* pPart, const size_t count);
void save_part(const PART* pPart, const size_t count);
size_t load_part(PART** ppPart);
int find_part(PART* pPart, size_t count, USHORT code);

const char* get_part_name(const PART* pPart, size_t count_part, USHORT part_id);
const char* get_rank_name(const RANK* pRank, size_t count_rank, USHORT rank_id);


size_t input_employee(const EMPLOYEE** ppEmp, size_t count_emp, 
	                  const PART* pPart,size_t count_part, 
	                 const RANK* pRank, size_t count_rank);

void print_employee(const EMPLOYEE* pEmp, size_t count_emp,
	const PART* pPart, size_t count_part,
	const RANK* pRank, size_t count_rank);

int find_employee(const EMPLOYEE* pEmp, const size_t count_emp, const int id);

void save_employee(const EMPLOYEE* pEmp, size_t count_emp);

size_t load_employee(EMPLOYEE** ppEmp);
int update_employee(EMPLOYEE** pEmp, size_t count_emp,
	const PART* pPart, size_t count_part,
	const RANK* pRank, size_t count_rank);

//#endif // !__abc__

