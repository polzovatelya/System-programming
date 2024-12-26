// Project1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Project1.h"
#include <iostream>

using namespace std;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна





HWND LAB2; // Окно программы ЛР_2
HWND BORLAND; // Окно программы c++ builder
HWND SHARP;

int cnt = 0;
int p = 0;
int child = 0;
int win = 0;
bool f = false;
TCHAR result[10000];
int all_win = 0;
int all_child = 0;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PROJECT1);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//




#define BUTTON1_ID 1001
#define BUTTON2_ID 1002
#define BUTTON3_ID 1003
#define BUTTON4_ID 1004
#define BUTTON5_ID 1005
#define BUTTON6_ID 1006
#define BUTTON7_ID 1007


void SIZE1(HWND hWnd) {
    RECT rect;
    TCHAR w[10] = L"", h[10] = L"";
    if (GetWindowRect(hWnd, &rect))
    {
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        _itow_s(width, w, 10);
        _tcscat_s(result, _T("( "));
        _tcscat_s(result, w);
        _tcscat_s(result, _T(", "));
        _itow_s(width, h, 10);
        _tcscat_s(result, h);
        _tcscat_s(result, _T(" ) "));
        _tcscat_s(result, _T("\r\n"));
    }
    if (GetClientRect(hWnd, &rect))
    {
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        _itow_s(width, w, 10);
        _tcscat_s(result, _T("( "));
        _tcscat_s(result, w);
        _tcscat_s(result, _T(", "));
        _itow_s(width, h, 10);
        _tcscat_s(result, h);
        _tcscat_s(result, _T(" )"));
        _tcscat_s(result, _T("\r\n"));
    }
    TCHAR win_class[MAX_PATH];
    int res = GetClassName(hWnd, win_class, MAX_PATH);
    _tcscat_s(result, win_class);
}

BOOL CALLBACK num_child(HWND hWnd, LPARAM lParam)
{   
    child++;
    int* k = (int *)lParam;
    TCHAR str[50] = L"Child ", n[50] = L"";
    TCHAR title[20] = L"";
    _itow_s(child, n, 10);
    wcscat_s(str, n);
    if (child == 20){
        _tcscat_s(result, _T("\r\n"));
        GetWindowTextW(hWnd, title, 20);
        _tcscat_s(result, title);
        _tcscat_s(result, _T(" - "));
        _tcscat_s(result, str);
        _tcscat_s(result, _T("\r\n"));
        SIZE1(hWnd);
    }
    SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)str);
    return TRUE;
}



BOOL CALLBACK num(HWND hWnd, LPARAM lParam)
{
    all_win++;
    TCHAR str[50] = L"ОКНО ", n[50] = L"";
    f = false;
        win++;
        TCHAR title[100] = L"";

        _itow_s(win, n, 10);
        wcscat_s(str, n);

        if (win == 20) {
            f = true;
            GetWindowTextW(hWnd, result, 20);
            _tcscat_s(result, title);
            _tcscat_s(result, _T(" - "));
             _tcscat_s(result, str);
             _tcscat_s(result, _T("\r\n"));
             SIZE1(hWnd);
        }





        SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)str);
        int cnt = 0;

        EnumChildWindows(hWnd, &num_child, (LPARAM)&cnt);
    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hBtn1;
    static HWND hBtn2;
    static HWND hBtn3;
    static HWND hBtn4;
    static HWND hBtn5;
    static HWND hBtn6;
    static HWND hBtn7;

    static HWND Text;
    switch (message)
    {



    case WM_CREATE:
    {
        hBtn1 = CreateWindow(TEXT("BUTTON"), TEXT("Спрятать окно Borland"), WS_VISIBLE | WS_CHILD, 50, 50, 250, 26, hWnd, (HMENU)BUTTON1_ID, NULL, NULL);
        hBtn2 = CreateWindow(TEXT("BUTTON"), TEXT("Сделать недоступным окно C#"), WS_VISIBLE | WS_CHILD, 50, 80, 250, 26, hWnd, (HMENU)BUTTON2_ID, NULL, NULL);
        Text = CreateWindow(TEXT("STATIC"), TEXT("Лаба 2"), WS_VISIBLE | WS_CHILD, 100, 130, 80, 26, hWnd, (HMENU)BUTTON3_ID, NULL, NULL);
        hBtn3 = CreateWindow(TEXT("BUTTON"), TEXT("Нажать (программно) кнопку и выполнить команду"), WS_VISIBLE | WS_CHILD, 50, 150, 400, 26, hWnd, (HMENU)BUTTON3_ID, NULL, NULL);
        hBtn4 = CreateWindow(TEXT("BUTTON"), TEXT("Выполнить команду пункта меню"), WS_VISIBLE | WS_CHILD, 50, 180, 400, 26, hWnd, (HMENU)BUTTON4_ID, NULL, NULL);
        hBtn5 = CreateWindow(TEXT("BUTTON"), TEXT("Нажать правую кнопку мыши"), WS_VISIBLE | WS_CHILD, 50, 210, 400, 26, hWnd, (HMENU)BUTTON5_ID, NULL, NULL);
        hBtn6 = CreateWindow(TEXT("BUTTON"), TEXT("Найти и пронумеровать все запущенные в системе окна."), WS_VISIBLE | WS_CHILD, 50, 240, 400, 26, hWnd, (HMENU)BUTTON6_ID, NULL, NULL);
        hBtn7 = CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 50, 300, 400, 400, hWnd, (HMENU)BUTTON7_ID, NULL, NULL);

        LAB2 = FindWindow(0, TEXT("WindowsProject2"));
        if (!LAB2)
            MessageBox(hWnd, TEXT("Окно LABA2 не найдено!"), TEXT("Ошибка"), MB_OK);
        BORLAND = FindWindow(0, TEXT("Borland C++"));
        if (!BORLAND)
            MessageBox(hWnd, TEXT("Окно BORLAND ненайдено!"), TEXT("Ошибка"), MB_OK);
        SHARP = FindWindow(0, L"C#");
        if (!SHARP) MessageBox(hWnd, TEXT("Окно C# не найдено!"),
            TEXT("Ошибка"), MB_OK);
    }
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {

        case 1001:
            if (IsWindowVisible(BORLAND)) {
                ShowWindow(BORLAND, SW_HIDE);
                Sleep(40);
                ShowWindow(BORLAND, SW_SHOW);
            }
            break;

        case 1002:
            EnableWindow(SHARP, false);
            Sleep(100);
            EnableWindow(SHARP, true);

            break;

        case 1003:
            HWND but;
            but = FindWindowEx(LAB2, 0, TEXT("BUTTON"), TEXT("Первая"));
            SendMessage(but, BM_SETSTATE, TRUE, 0);
            Sleep(20);
            SendMessage(but, BM_CLICK, 0, 0);
            SendMessage(but, BM_SETSTATE, FALSE, 0);
            break;

        case 1004:
            SendMessage(LAB2, WM_COMMAND, IDM_ABOUT, 0);
            break;

        case 1005:
            POINT mouse;
            mouse.x = MAKEPOINTS(lParam).x;
            mouse.y = MAKEPOINTS(lParam).y;
            SendMessage(LAB2, WM_RBUTTONUP, 0,lParam);
            //SendMessage(LAB2, WM_RBUTTONUP, 0, 0);
            break;

        case 1006: {
            child = 0;
            win = 0;
            TCHAR w[10] = L"", c[10]= L"";
            SendMessageA(hBtn7, WM_SETTEXT, WPARAM(0), LPARAM(""));

            EnumWindows(num, (LPARAM)&p);


            _tcscat_s(result, _T("\r\n"));
            _tcscat_s(result, _T("Количество окон: "));

            _itow_s(all_win, w , 10);
            _tcscat_s(result, w);
            _tcscat_s(result, _T("\n"));

            _tcscat_s(result, _T("Количество дочерних окон: "));

            _itow_s(child, c, 10);
            _tcscat_s(result, c);
            _tcscat_s(result, _T("\n"));


            SetWindowText(hBtn7, result);


            break;
        }
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_LBUTTONDOWN:
        SendMessage(LAB2, WM_LBUTTONDOWN, 0, lParam);
        break;
    case WM_LBUTTONUP:
        SendMessage(LAB2, WM_LBUTTONUP, 0, lParam);
        break;
    case WM_MOUSEMOVE:
        SendMessage(LAB2, WM_MOUSEMOVE, 0, lParam);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
