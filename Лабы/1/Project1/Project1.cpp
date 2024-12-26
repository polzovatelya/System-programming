// Project1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Project1.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    Procedura(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);



    


    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = Procedura;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

   HWND hWnd = CreateWindowW(szWindowClass, TEXT("Кунавина_1"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   //HWND hBut1, hBut2, hBut3, hBut4;


   /*hBut1 = CreateWindow(TEXT("BUTTON"), TEXT("Первая"), WS_VISIBLE | WS_CHILD, 50, 200, 80, 26, hWnd, NULL, hInstance, NULL);
   hBut2 = CreateWindow(TEXT("BUTTON"), TEXT("Вторая"), WS_VISIBLE | WS_CHILD, 150, 200, 80, 26, hWnd, NULL, hInstance, NULL);
   hBut3 = CreateWindow(TEXT("EDIT"), TEXT("Tra-la-la"), WS_VISIBLE | WS_CHILD, 50, 240, 80, 26, hWnd, NULL, hInstance, NULL);
   hBut4 = CreateWindow(TEXT("STATIC"), TEXT("Tra-la-la"), WS_VISIBLE | WS_CHILD, 150, 240, 80, 26, hWnd, NULL, hInstance, NULL);
   if (hBut1 != NULL)  SetWindowLong(hBut1, GWL_ID, 999);
   if (hBut2 != NULL)  SetWindowLong(hBut2, GWL_ID, 99);
   if (hBut3 != NULL)  SetWindowLong(hBut3, GWL_ID, 10);
   if (hBut4 != NULL)  SetWindowLong(hBut4, GWL_ID, 11);*/


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
#define BUTTON_ID 1002
#define BUTTON1_ID 1003
#define STATIC_ID 1004

LRESULT CALLBACK Procedura(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hed;
    static HWND hBtn1;
    static HWND hBtn2;
    static HWND hStatic;
    int len;
    TCHAR* buff;
    TCHAR* g;
    RECT rect;
    int h, w;

    switch (message)
    {
     // При создании окна загружаем указатели мыши
        HWND hweIn;
        HRGN cut,out;
    case WM_SIZE:
        RECT rc;
        int h, w, r;
        // прямоугольник окна
        GetWindowRect(hWnd, &rc);
        w = rc.right - rc.left;
        h = rc.bottom - rc.top;

        out = CreateEllipticRgn(0, -h+100, w, h);
        r = 20;
        cut = CreateEllipticRgn(w-300-r, 140-r, w-300+r, 140+r);
        //OffsetRect(&rc, -rc.left, -rc.top);
        CombineRgn(cut,cut, out, RGN_XOR);
        SetWindowRgn(hWnd, cut, TRUE);
        break;
    case WM_CREATE:
    {   
   

        hBtn1 = CreateWindow(TEXT("BUTTON"), TEXT("Первая"), WS_VISIBLE | WS_CHILD, 150, 200, 80, 26, hWnd, (HMENU)BUTTON_ID, NULL, NULL);
        hBtn2 = CreateWindow(TEXT("BUTTON"), TEXT("Вторая"), WS_VISIBLE | WS_CHILD, 250, 200, 80, 26, hWnd,(HMENU)BUTTON1_ID, NULL, NULL);
        hed = CreateWindow(TEXT("EDIT"), TEXT("Tra-la-la"), WS_VISIBLE | WS_CHILD, 150, 240, 80, 26, hWnd, (HMENU)EDIT_ID, NULL, NULL);
        hStatic = CreateWindow(TEXT("STATIC"), TEXT("Tra-la-la"), WS_CHILD | WS_VISIBLE | ES_RIGHT, 250, 240, 150, 26, hWnd, (HMENU)STATIC_ID, NULL, NULL);
        if (hBtn1 != NULL)  SetWindowLong(hBtn1, GWL_ID, 999);
        if (hBtn2 != NULL)  SetWindowLong(hBtn2, GWL_ID, 99);
        if (hed != NULL)  SetWindowLong(hed, GWL_ID, 10);
        if (hStatic != NULL)  SetWindowLong(hStatic, GWL_ID, 11);
        break;
       
    }
    case WM_LBUTTONUP:              // при нажатии на л.кнопку мыши
        MessageBox(hWnd, TEXT("Вы кликнули Левую кнопку мыши!"), TEXT("событие"), 0);
        break;
    case WM_RBUTTONUP:              // при нажатии на л.кнопку мыши
        MessageBox(hWnd, TEXT("Вы кликнули Правую кнопку мыши!"), TEXT("событие"), 0);
        if (KillTimer(hWnd, 1)) {
            SetParent(hBtn1, hWnd);
            MoveWindow(hBtn1, 50, 200, 80, 26, true);
        }
        break;


    /*case  WM_TIMER:
       GetWindowRect(hBtn1, &rect);
       w = rect.right - rect.left;
       h = rect.bottom - rect.top;
        while (not KillTimer(hBtn1, 1)) {
            GetWindowRect(hBtn1, &rect);
        MoveWindow(hBtn1, rect.left, rect.top + 10, w, h, true);
        }
            break;*/


    case WM_COMMAND:
        {   
            int h = 0;
            int w = 0;
            int count;
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {

            case 99:
                len = GetWindowTextLength(hWnd) + 1;
                buff = new TCHAR[255];
                GetWindowText(hWnd, buff, len);
                SetWindowText(hStatic, buff);
                break;
         
            case 999:
                len = GetWindowTextLength(hed) + 1;
                buff = new TCHAR[len];
                GetWindowText(hed, buff, len);
                SetWindowText(hStatic, buff);
                break;

            case ID_32774:
                SetParent(hBtn1, NULL);
                GetWindowRect(hBtn1, &rect); 
                SetTimer(hWnd, 1, 100, NULL);
                break;
            case ID_32772:
                if (GetWindowRect(hWnd, &rect))
                {
                    w = rect.right - rect.left;
                    h = rect.bottom - rect.top;

                }
                MoveWindow(hWnd, rect.left, rect.top, w-100, h-100, true);
                break;

            case ID_32773:
                if (GetWindowRect(hWnd, &rect))
                {
                    w = rect.right - rect.left;
                    h = rect.bottom - rect.top;

                }
                MoveWindow(hWnd, rect.left+100, rect.top-50, w, h, true);
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
    case WM_TIMER:
        GetWindowRect(hBtn1, &rect);
        MoveWindow(hBtn1, rect.left, rect.top + 10, rect.right - rect.left, rect.bottom - rect.top, true);
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
        if (MessageBoxA(NULL, "Вы дейтсвительно хотите закрыть окно?", "Закрытие", MB_OK | MB_OKCANCEL | MB_ICONERROR) == IDOK) {
            DestroyWindow(hWnd);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, 1);
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
