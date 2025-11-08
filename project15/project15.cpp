#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> // debug 일때만 사용

// typedef : 타입(형) 재정의 명령
// unsigned int 를 uint로 쓰겠다 라고 선언
typedef unsigned int uint;  

// unsighed char를 uchar로 재정의 하기
typedef unsigned char uchar;

//구조체(structure)
// align 4 바이트 단위로 정렬함 41바이트이면 44바이트
// 사람을 모델링 : 생년, 월, 일, 이름, 성별, 키
//  PERSON이라는 구조체 타입을 정의
typedef struct _person  {
    // 멤버(member)
    int birth_year; // 생년        4
    char birth_mon; // 월        1
    char birth_day; //일        1
    char name[30];  //이름        30
    char gender;    // 1:남자, 2:여자, 3:모름     1
    float height;   // 키        4
}PERSON;

//typedef struct {
//    PERSON* p;
//    size_t count;
//};PERSON_RET;


void print_person(PERSON who)
{
    char gender[6] = { 0 }; // 빈 문자열

    printf("이름 : %s\n", who.name);
    printf("생년월일 : %d-%d-%d\n", who.birth_year, who.birth_mon, who.birth_day);
    if (who.gender == 1)
        strcpy(gender, "남자");
    else if (who.gender == 2)
        strcpy(gender, "여자");
    else
        strcpy(gender, "모름");
    printf("성별 : %s\n", gender);
    printf("키 : % .2fcm\n", who.height);
}


void print_person(const PERSON* p)  
// 매개변수 앞에 const가 붙으면 해당 변수를 이 함수에서 
// 명시적으로 수정하지 않겠다는 선언 -> 논리적인 오류를 줄일 수 있다
{
    char gender[6] = { 0 }; // 빈 문자열
       
    printf("이름 : %s\n", p->name);   // 포인터가 구조체를 가리킬때는 소유의 의미인 . 대신에 ->를 사용한다
    printf("생년월일 : %d-%d-%d\n", p->birth_year, p->birth_mon, p->birth_day);
    if (p->gender == 1)
        strcpy(gender, "남자");
    else if (p->gender == 2)
        strcpy(gender, "여자");
    else
        strcpy(gender, "모름");
    printf("성별 : %s\n", gender);
    printf("키 : % .2fcm\n", p->height);
}


PERSON input_person()
{
    PERSON who = {0};   // 문자열 입력은 0으로 클리어하는게 안전    지역변수

    printf("생년월일을 연도를 입력하세요.(예.2002) : ");
    scanf("%d", &who.birth_year);

    printf("생년월일을 월을 입력하세요.(예.12) : ");
    scanf("%d", &who.birth_mon);

    printf("생년월일을 일을 입력하세요.(예.30) : ");
    scanf("%d", &who.birth_day);

    char ch;
    scanf("%c", &ch);  // 입력버퍼에 남아있는데 \n(New Line) 제어문자를 삭제

    printf("이름을 입력하세요.(예.아이유) : ");
    fgets(who.name, 30, stdin);
    int idx=strlen(who.name)-1; // \n을 지우기 위하여 인덱스를 구함
    who.name[idx] = 0;  // \n이 위치한 인덱스의 0을 대입하여 삭제 시킴

    printf("성별을 입력하세요.(1.남자, 2.여자, 3.모름) : ");
    scanf("%d", &who.gender);

    printf("키를 입력하세요.(예.175.5) : ");
    scanf("%f", &who.height);

    return who;

    //return &who;    // 스택에  생성된 지역변수의 주소를 반환하지 않는다!
}

void input_person(PERSON* p_in)
{
    if (!p_in) return;  // p_in 이 null이면 즉시 함수를 종료시킴


    printf("생년월일을 연도를 입력하세요.(예.2002) : ");
    scanf("%d", &p_in->birth_year);

    printf("생년월일을 월을 입력하세요.(예.12) : ");
    scanf("%d", &p_in->birth_mon);

    printf("생년월일을 일을 입력하세요.(예.30) : ");
    scanf("%d", &p_in->birth_day);

    char ch;
    scanf("%c", &ch);  // 입력버퍼에 남아있는데 \n(New Line) 제어문자를 삭제

    printf("이름을 입력하세요.(예.아이유) : ");
    fgets(p_in->name, 30, stdin);
    int idx = strlen(p_in->name) - 1; // \n을 지우기 위하여 인덱스를 구함
    p_in->name[idx] = 0;  // \n이 위치한 인덱스의 0을 대입하여 삭제 시킴

    printf("성별을 입력하세요.(1.남자, 2.여자, 3.모름) : ");
    scanf("%d", &p_in->gender);

    printf("키를 입력하세요.(예.175.5) : ");
    scanf("%f", &p_in->height);


}


void save_person(const PERSON* p)
{

    assert(p);      // p가 유효해야 한다     --> 디버깅 전용 코드
    FILE* fp = NULL;
    fp = fopen("person.dat", "wb");
    if (!fp)
    {
        printf("person.dat 파일을 열 수 없습니다.\n");
    }

    size_t ret = fwrite(p, sizeof(PERSON), 1, fp);
    assert(ret == 1);

    fclose(fp);
}

void load_person(PERSON* p)
{
    assert(p);      // p가 유효해야 한다     --> 디버깅 전용 코드
    FILE* fp = NULL;
    fp = fopen("person.dat", "rb");
    if (!fp)
    {
        printf("person.dat 파일을 열 수 없습니다.\n");
    }

    size_t ret = fread(p, sizeof(PERSON), 1, fp);
    assert(ret == 1);

    fclose(fp);

}

//파일명을 전달받아서 해당 파일의 크기를 구하여 반환하는 함수
size_t get_file_size(const char* filename)
{
    assert(filename);

    FILE* fp = NULL;
    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END); // 파일 끝으로 커서를 보내서 0만큼 이동 시킴
    size_t size = ftell(fp);

    fclose(fp);
    return size;
}


PERSON* load_people()
{
    size_t buf_size = get_file_size("person.dat");  // 파일 사이즈를 바이트 단위로 구함
    size_t count = buf_size / sizeof(PERSON);   // 배열의 개수를 구함

    // malloc을 이용하여 할당받은 배열(메모리 저장 공간)은 Heap 영역에 할당된다.
    PERSON* pArr = (PERSON*)malloc(buf_size);
    if (!pArr)
    {
        printf("메모리 할당 실패!");
        return NULL;
    }

    FILE* fp = NULL;
    fp = fopen("person.dat", "rb");
    if (!fp)
    {
        free(pArr);
        printf("persion.dat 파일을 열 수 없습니다.");
        return NULL;
    }

    size_t ret = fread(pArr, sizeof(PERSON), count, fp);
    assert(ret == count);

    fclose(fp);

    return pArr;
}


size_t load_people(PERSON** pp)
{
    size_t buf_size = get_file_size("person.dat");  // 파일 사이즈를 바이트 단위로 구함
    size_t count = buf_size / sizeof(PERSON);   // 배열의 개수를 구함

    // malloc을 이용하여 할당받은 배열(메모리 저장 공간)은 Heap 영역에 할당된다.
    PERSON* pArr = (PERSON*)malloc(buf_size);
    if (!pArr)
    {
        printf("메모리 할당 실패!");
        return NULL;
    }

    FILE* fp = NULL;
    fp = fopen("person.dat", "rb");
    if (!fp)
    {
        free(pArr);
        printf("persion.dat 파일을 열 수 없습니다.");
        return NULL;
    }

    size_t ret = fread(pArr, sizeof(PERSON), count, fp);
    assert(ret == count);

    fclose(fp);

    // *pp는 호출부의 1차원 포인터 변수이다.
    *pp = pArr;
    return count;
}

void print_value(int** pp)
{
    int* p = *pp;
    printf("값은? %d\n", *p);
}

int main()
{
    /*PERSON hong;
    load_person(&hong);*/
    //hong.birth_year = 1990;
    //hong.birth_mon = 3;
    //hong.birth_day = 1;
    //strcpy(hong.name, "홍길동");
    //hong.gender = 3;
    //hong.height = 170.F; // 소수점이하의 값이 0이면 0은


    uint ids[10];

    /*int num = 10;
    int* ptr = &num;*/
    //int** pptr = &ptr;  // 2차원 포인터 변수는 1차원 포인터 변수의 주소를 저장할 수 있다

    // prt을 이용하여 num 값 출력하기
    //printf("num의 값 : %d\n", *ptr);
    //printf("num의 값 : %d\n", *(*pptr));
    //print_value(&ptr);


    PERSON iu = { 0 };
    input_person(&iu);
    PERSON iu2 = { 0 };
    input_person(&iu2);

    PERSON* pArr = NULL;    // 가르키고 있지 않도록 선언 
    printf("pArr의 값:%p\n", pArr);
    size_t count = load_people(&pArr);
    printf("pArr의 값:%p\n", pArr);


    printf("PERSON 구조체의 크기 : %llubytes\n", sizeof(PERSON)); // %llu = unsigned long long 
    printf("pArr의 크기 : %llubytes\n", sizeof(pArr)); 

   // print_person(iu);

     print_person(&iu);
     print_person(&iu2);

    //print_person(hong);
    //save_person(&hong);
    print_person(pArr);


    if (pArr)
    {
        free(pArr);
        pArr = NULL;
    }
   


    return 0;
}

