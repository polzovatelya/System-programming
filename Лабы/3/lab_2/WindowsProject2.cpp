// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

HWND hStatic2;      // лог событий мышки
HWND hStatic1;   // поле вывода количества событий мыши
TCHAR event_clk[500];  // для записи событий
int count = 0;
bool mousedown = false;
POINT lastLocation;
POINT mouseL;
POINT mouseR;
bool flag = true;

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

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

    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
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

#define EDIT_ID 1001
#define STATIC_ID 1002

#define STATIC_ID1 1005
#define STATIC_ID2 1006



#define BUTTON_ID 1003
#define BUTTON1_ID 1004


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hed;
    static HWND hStatic;
    static HWND hStatic1;
    static HWND hStatic2;

    static HWND hBtn1;
    static HWND hBtn2;

    int len = 0;
    int num;
    TCHAR buff[100] = L"";

    switch (message)
    {


    case WM_CREATE:
    {   hBtn1 = CreateWindow(TEXT("BUTTON"), TEXT("Первая"), WS_VISIBLE | WS_CHILD, 50, 50, 80, 26, hWnd, (HMENU)BUTTON_ID, NULL, NULL);
    hBtn2 = CreateWindow(TEXT("BUTTON"), TEXT("Вторая"), WS_VISIBLE | WS_CHILD, 150, 50, 80, 26, hWnd, (HMENU)BUTTON1_ID, NULL, NULL);
    hed = CreateWindow(TEXT("EDIT"), TEXT("Tra-la-la"), WS_VISIBLE | WS_CHILD, 50, 100, 80, 26, hWnd, (HMENU)EDIT_ID, NULL, NULL);
    hStatic = CreateWindow(TEXT("STATIC"), TEXT("Вывод квадрата"), WS_CHILD | WS_VISIBLE | ES_RIGHT, 150, 100, 150, 26, hWnd, (HMENU)STATIC_ID, NULL, NULL);
    hStatic1 = CreateWindow(TEXT("STATIC"), TEXT("Вывод количества возникающих событий"), WS_CHILD | WS_VISIBLE | ES_RIGHT, 180, 150, 300, 40, hWnd, (HMENU)STATIC_ID1, NULL, NULL);
    hStatic2 = CreateWindow(TEXT("STATIC"), TEXT("События"), WS_CHILD | WS_VISIBLE | ES_RIGHT,50, 200, 500, 100, hWnd, (HMENU)STATIC_ID2, NULL, NULL);

    if (hed != NULL)  SetWindowLong(hed, GWL_ID, 10);
    if (hStatic != NULL)  SetWindowLong(hStatic, GWL_ID, 11);
    break;
    }

    case WM_RBUTTONDOWN: {
    }
    break;
    case WM_RBUTTONUP:
    {
        POINT p;
        TCHAR x[10], y[10];
        TCHAR result[300] = TEXT("( ");
        _itot_s(MAKEPOINTS(lParam).x, x, 10);
        _itot_s(MAKEPOINTS(lParam).y, y, 10);
        _tcscat_s(result, x);
        _tcscat_s(result, TEXT(", "));
        _tcscat_s(result, y);
        _tcscat_s(result, TEXT(")"));
        SetWindowText(hStatic, result);
        //}
       
    }
    break;

    case WM_LBUTTONDBLCLK:
    {   TCHAR str[100] = TEXT("Дабл;");
        _tcscat_s(event_clk, str);
        SetWindowText(hStatic2, event_clk);
    }
    break;

    case WM_LBUTTONDOWN:
    {   mouseR.x = MAKEPOINTS(lParam).x;
        mouseR.y = MAKEPOINTS(lParam).y;
        _tcscat_s(event_clk, _T("Зажата Левая кнопка мыши;"));
        SetWindowText(hStatic2, event_clk);
        mousedown = true;
        GetCursorPos(&lastLocation);
        RECT rect;
        GetWindowRect(hWnd, &rect);
        lastLocation.x = lastLocation.x - rect.left;
        lastLocation.y = lastLocation.y - rect.top;       
    }
    break;

    case WM_LBUTTONUP:
    {   
        _tcscat_s(event_clk, _T("Отпущена Левая кнопка мыши;"));
        SetWindowText(hStatic2, event_clk);
        mousedown = false;
        /*
        if ((mouseR.x == MAKEPOINTS(lParam).x) and (mouseR.y == MAKEPOINTS(lParam).y)) {
            _tcscat_s(event_clk, _T("КЛИК!"));
            SetWindowText(hStatic2, event_clk);
        }
        else {
            _tcscat_s(event_clk, _T("Перемещение мыши; "));
            SetWindowText(hStatic2, event_clk);
        }*/

    }
    break;

    case WM_MOUSEMOVE: {
        if (mousedown) {
            POINT currentpos;
            GetCursorPos(&currentpos);
            RECT rect;
            GetWindowRect(hWnd, &rect);
            int x = currentpos.x - lastLocation.x;
            int y = currentpos.y - lastLocation.y;
            MoveWindow(hWnd, x, y, rect.right - rect.left,rect.bottom - rect.top, false);
        }
        break;
    }

    case WM_NCHITTEST:
    {
        TCHAR str[10];
        _itot_s(count++, str, 10);
        SetWindowText(hStatic1, str);
        LRESULT result = DefWindowProc(hWnd, message, wParam, lParam);
        return result;
    }
    break;

    case WM_NCLBUTTONDOWN:
    {
        if (wParam != HTCAPTION) {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        else {
            return 0;
        }
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case 1003:
        {GetWindowText(hed, buff, 50);
        num = _wtoi(buff);
        _itow_s(num * num, buff, 10);
        SetWindowText(hStatic, buff);
        }
            break;
        case 1004: {
            //1 sposob

             SendMessage(hBtn1, BM_CLICK, 0, 0);

            //2sposob
            /*if (flag) {
               SendMessage(hBtn1, BM_SETSTATE, TRUE, 0);
               Sleep(100);
               SendMessage(hBtn1, BM_SETSTATE, FALSE, 0);
               flag = FALSE;
            }
            SendMessage(hWnd, WM_COMMAND, BUTTON_ID, 0);*/
        }
            break;
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

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_CLOSE:
        if (MessageBoxA(NULL, "Вы действительно хотите закрыть окно?", "Закрытие", MB_OK | MB_OKCANCEL | MB_ICONERROR) == IDOK) {
            DestroyWindow(hWnd);
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
