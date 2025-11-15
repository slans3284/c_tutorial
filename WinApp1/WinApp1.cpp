// WinApp1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "WinApp1.h"

#define MAX_LOADSTRING 100

// Handle : id

char ch = 'a';    // 1byte
wchar_t tch = L'a'; // 2bytet
//typedef wchar_t WCHAR;

// 전역 변수:
HINSTANCE hInst;                                // 현재 어플리케이션(인스턴스)의 id(handle) 입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

BOOL bShowText = FALSE;
BOOL bShowRect = FALSE;
BOOL bShowEllipse = FALSE;

int xPos = 0,  yPos = 0;
// HWND : 윈도우 핸들을 저장하는 타입
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

/*
int main(int argc, char* [] argv)
{
    return wWinMain(...);
}
*/

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);



    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPP1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        // 윈도우를 생성하지 못했으면 False를 반환하고 종료
        return FALSE;
    }

    // 단축키 로딩
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPP1));

    MSG msg;

    // 기본 메시지 루프입니다:
    // WM_QUIT : 프로그램 종료 메시지
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // 윈도우 프로시져에 msg를 전달함
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 Windows OS에 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPP1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPP1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   // 위에서 방금 만들어진 윈도우를 화면에 보이게 함
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void Draw(HDC hdc)
{
    // Draw Object: pen(선, 글자), brush(바탕)

    if (bShowText)
    {
        LPCWSTR lpszMsg = L"안녕하세요. 첫번째 윈도우 프로그램입니다.";
        ::TextOutW(hdc, 10, 10, lpszMsg, wcslen(lpszMsg));
    }

    if (bShowRect)
    {
        RECT rect;
        rect.left = 100;
        rect.right = rect.left + 100;
        rect.top = 100;
        rect.bottom = rect.top + 100;
        ::Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    }

    if (bShowEllipse)
    {
        // 펜 생성
        HPEN hPen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
        // 펜 선택
        HPEN hOldPen = (HPEN)::SelectObject(hdc, hPen);

        HBRUSH hbr = ::CreateSolidBrush(RGB(0, 25, 0));
        HBRUSH hOldBrush = (HBRUSH)::SelectObject(hdc, hbr);
        RECT rect;
        rect.left = 300;
        rect.right = rect.left + 100;
        rect.top = 300;
        rect.bottom = rect.top + 100;
        ::Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
        ::SelectObject(hdc, hOldPen);
        ::DeleteObject(hPen);
        ::SelectObject(hdc, hOldBrush);
        ::DeleteObject(hbr);
    
    }

  // HDC hdc = ::GetDC(hWnd);     // Device Context 얻음

   //::ReleaseDC(hWnd, hdc);      // Device Context 돌려줌
}

void CheckMyMenuItem(HWND hWnd, WORD menuItem)
{
    HMENU hMenu = ::GetMenu(hWnd);
    if (!hMenu) return;

    // 현재 menuItem(메뉴 아이템)의 상태를 구함
    UINT state = ::GetMenuState(hMenu, menuItem, MF_BYCOMMAND);

    // 0000 1010 : check와 disable
    // 0000 1000 &
    // 0000 0000 
    // toggle(토글) : switch 기능

    UINT check = (state & MFS_CHECKED) ? MF_UNCHECKED : MF_CHECKED;
    ::CheckMenuItem(hMenu, menuItem, MF_BYCOMMAND | check);
}

void DrawMenuProc(HWND hWnd, WORD menuItem)
{
    // 선택된 메뉴에 따라서 플래그 설정 
    switch (menuItem)
    {
    case IDM_FILE_STRING:
        bShowText = !bShowText;
    case IDM_FILE_RECT:
        bShowRect = !bShowRect;
    case IDM_FILE_ELLIPSE:
        bShowEllipse = !bShowEllipse;
    }
    CheckMyMenuItem(hWnd, IDM_FILE_STRING);
    bShowText = !bShowText;
    ::InvalidateRect(hWnd, NULL, TRUE); // WM_PAINT 메시지를 인위적으로 발생시킴 -> 클라이언트 영역을 강제로 다시 그리게 한다.
}

void DrawMousePosition(HDC hdc)
{
    WCHAR wOut[100] = L"";
    wprintf_s(wOut, L"x : %d\ny : %d", xPos, yPos);

    ::TextOutW(hdc, 0, 300, wOut, wcslen(wOut));
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:    // 메뉴가 클릭됐을때 발생되는 메시지 
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;

            case IDM_FILE_TEST:
                ::MessageBox(hWnd, L"안녕하세요, 테스트입니다.", L"메시지", MB_OK);
                break;

            case IDM_FILE_STRING:
            case IDM_FILE_RECT:
            case IDM_FILE_ELLIPSE:
                DrawMenuProc(hWnd, wmId);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        // 윈도우 클라이언트 영역을 다시 그려야 할 필요가 있을 때 
    case WM_PAINT:  
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);    // WM_PAINT에서만 BeginPaint()함수로 D.C를 구한다.
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            Draw(hdc);
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_MOUSEMOVE:
        xPos = GET_X_LPARAM(IParam);
        yPos = GET_Y_LPARAM(IParam);
        ::InvalidateRect(hWnd, NULL, TRUE);
            break;
    case WM_DESTROY:    // X 버튼 클릭됐을때 전달되는 메시지
        PostQuitMessage(0); // WM_QUIT 메시지 전송
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
