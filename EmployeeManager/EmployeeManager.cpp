#include "EmployeeManager.h"


void show_menu()
{
	system("cls");	// 콘솔 화면 클리어 명령
	printf("1. 사원 정보 입력\n");
	printf("2. 사원 정보 출력\n");
	printf("3. 사원 정보 수정\n");
	printf("4. 사원 정보 삭제\n");
	printf("=================\n");
	printf("5. 직급 정보 입력\n");
	printf("6. 직급 정보 출력\n");
	printf("7. 직급 정보 수정\n");
	printf("8. 직급 정보 삭제\n");
	printf("=================\n");
	printf("a. 부서 정보 입력\n");
	printf("b. 부서 정보 출력\n");
	printf("c. 부서 정보 수정\n");
	printf("d. 부서 정보 삭제\n");
	printf("=================\n");
	printf("x. 프로그램 종료\n");
	printf("=================\n");
}

int input_menu()
{
	printf("메뉴를 선택하세요 >>> ");
	return _getch();	// conio.h에 정의, 키입력시 즉시 반환 
}

void wait()
{
	printf("\n========================\n");
	printf("아무키나 입력하세요...");
	_getch();

}

int main()
{
	RANK* pRank = NULL;	// RANK 구조체 항목을 구성요소로 갖는 배열
	size_t count_rank = 0;
	
	PART* pPart = NULL;	// PART 구조체 항목을 구성요소로 갖는 배열
	size_t count_part = 0;

	EMPLOYEE* PEmp = NULL;
	size_t count_emp = 0;


	PART_RANK info;
	//저장되어 있는 직급 데이터를 불러옴
	count_rank = load_rank(&pRank);
	count_part = load_part(&pPart);
	count_emp = load_employee(&pEmp);

	int ch;
	do
	{
		show_menu();
		ch = input_menu();
		switch (ch)
		{
		case '1': // 사원 정보 입력 기능 수행
		count_emp = input_employee(&pEmp, count_emp, pPart,count_part,count_rank);
		save_employee(pEmp, count_emp);
		print_employee(pEmp, count_emp, pPart, count_part, pRank, count_rank);

		
			break;

		case '2': // 사원 정보 출력
			print_employee(pEmp, count_emp, pPart, count_part, pRank, count_rank);
			break;
		case '3' : // 사원 정보 수정
			update_employee(pEmp, count_emp, pPart, count_part, pRank, count_rank);
			save_employee(pEmp, count_emp);
			print_employee(pEmp, count_emp, pPart, count_part, pRank, count_rank);
			break;
		case '4': // 사원 삭제 수정
		case '5': // 직급 정보 입력 기능 수행
			count_rank = input_rank(&pRank, count_rank);
			save_rank(pRank, count_rank);
			print_rank(pRank, count_rank);
			break;
		case '6': // 직급 정보 출력6
			print_rank(pRank, count_rank);
			break;
		case '7': // 직급 정보 수정
			update_rank(pRank, count_rank);
			save_rank(pRank, count_rank);
			print_rank(pRank, count_rank);
			break;

		case '8': // 직급 삭제 수정
			count_rank = delete_rank(&pRank, count_rank);
			save_rank(pRank, count_rank);
			print_rank(pRank, count_rank);
			break;
		case 'a': // 부서 정보 입력 기능 수행
			count_part = input_part(&pPart, count_part);
			save_part(pPart, count_part);
			print_part(pPart, count_part);
			break;
		case 'b': // 부서 정보 출력
			print_part(pPart, count_part);
			break;
		case 'c': // 부서 정보 수정
			update_part(pPart, count_part);
			save_part(pPart, count_part);
			print_part(pPart, count_part);
			break;
		case 'd': // 부서 삭제 수정
			count_part = delete_part(&pPart, count_part);
			save_part(pPart, count_part);
			print_part(pPart, count_part);
			break;
		}
		
		wait();

	} while (ch !='x');

	// Heap 메모리 해제
	if (pRank)
	{
		free(pRank);
		pRank = NULL;
	}

	if (pPart)
	{
		free(pPart);
		pPart = NULL;
	}

	if (pPart)
	{
		free(pPart);
		pPart = NULL;
	}

	if (pEmp)
	{
		free(pEmp);
		pEmp = NULL;
	}

	return 0;
}

