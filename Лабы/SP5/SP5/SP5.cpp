// SP5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "SP5.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна


HWND ColorBack;
int const IDColorBack = 1;
bool Flag1;

HWND RussiaFlag;
int const IDRussiaFlag = 2;
bool Flag2;

HWND CircleMove;
int const IDCircleMove = 3;
bool Flag3;
RECT circleRect = { 0, 0, 50, 50 }; // начальный box для круга
RECT circle = { 0,0,0,0 };
HWND hwndDesktop; // дескриптор рабочего стола
HWND hwndCSharp; // дескриптор С#
HDC hdcDesktop; // рабочий стол 
HDC hdcClient; // клиентская область нашего приложения
HDC hdcWindow; // вся область нашего приложения
HDC hdcCSharp; // клиентская область  С#
HDC hdcCSharpW; // вся область  С#
int Tick = 0; // счетчик тиков
int const IDTimer = 4;

HWND RedactorPaint;
int const IDRedactorPaint = 5;
bool Flag4;
bool isDrawing = false; // флаг состояния, когда зажата ЛКМ
POINT PBegin, PEnd; // начало и конец линии
HPEN pen;
int penWidth = 3;
RECT editorRect = { 300, 30, 800, 450 }; // прямоугольник редактора



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
    LoadStringW(hInstance, IDC_SP5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SP5));

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
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SP5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SP5);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   ColorBack = CreateWindow(L"BUTTON", L"Фон + фигуры", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 10, 200, 30, hWnd, NULL, hInstance, NULL);
   RussiaFlag = CreateWindow(L"BUTTON", L" Флаг ", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 60, 200, 30, hWnd, NULL, hInstance, NULL);
   CircleMove = CreateWindow(L"BUTTON", L" Круг ", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 110, 200, 30, hWnd, NULL, hInstance, NULL);
   RedactorPaint = CreateWindow(L"BUTTON", L" Редактор ", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 160, 200, 30, hWnd, NULL, hInstance, NULL);


   if (ColorBack != NULL)  SetWindowLong(ColorBack, GWL_ID, IDColorBack);
   if (RussiaFlag != NULL)  SetWindowLong(RussiaFlag, GWL_ID, IDRussiaFlag);
   if (CircleMove != NULL)  SetWindowLong(CircleMove, GWL_ID, IDCircleMove);
   if (RedactorPaint != NULL)  SetWindowLong(RedactorPaint, GWL_ID, IDRedactorPaint);

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


COLORREF GetColor()
{
    HDC desktop = GetDC(NULL);
    RECT rec;
    COLORREF color = RGB(0, 0, 0);
    int dx = 5, dy = 5, start_x = 200, start_y = 100;
    for (int i = start_x; i < start_x + dx; i++) {
        for (int j = start_y; j < start_y + dy; j++) {
            color += GetPixel(desktop, i, j);
        }
    }
    color = color / (dx * dy);

    return color;
}

VOID PaintFlag(HWND hWnd, bool is_client = false) {
    HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

    HDC hdc;
    RECT rect;
    if (is_client) {
        hdc = GetDC(hWnd);
        rect.left = 600, rect.top = 0, rect.bottom = 100, rect.right = 800;
        FillRect(hdc, &rect, whiteBrush);
    }
    else {
        hdc = GetWindowDC(hWnd);
        rect.left = 270, rect.top = 0, rect.bottom = 100, rect.right = 470;
        FillRect(hdc, &rect, whiteBrush);
    }
    rect.top = 100, rect.bottom = 200;
    FillRect(hdc, &rect, blueBrush);
    rect.top = 200, rect.bottom = 300;
    FillRect(hdc, &rect, redBrush);
    ReleaseDC(hWnd, hdc);

    // очищаем ресурсы
    DeleteObject(whiteBrush);
    DeleteObject(blueBrush);
    DeleteObject(redBrush);
}

void DrawCircle(HDC hdc) {
    HBRUSH brush = CreateSolidBrush(RGB(0, 100, 200));
    SelectObject(hdc, brush);
    Ellipse(hdc, circleRect.left+1, circleRect.top+1, circleRect.right+1, circleRect.bottom+1);
    DeleteObject(brush);
}
void Circles(HWND hWnd) {
    circle = { circleRect.left - 30, circleRect.top - 50,circleRect.right + 1, circleRect.bottom +  1};
    InvalidateRect(hwndDesktop, &circle, true);
    UpdateWindow(hwndDesktop);
    DrawMenuBar(hWnd);
    InvalidateRect(hWnd, &circle, true);
    UpdateWindow(hWnd);


    if (hdcCSharp) {
        InvalidateRect(hwndCSharp, NULL, true);
        UpdateWindow(hwndCSharp);
    }
    circleRect = { Tick, Tick,Tick + 100, Tick + 100 };
    DrawCircle(hdcDesktop);
    DrawCircle(hdcClient);
    DrawCircle(hdcWindow);
    if (hdcCSharp) {
        DrawCircle(hdcCSharp);
        DrawCircle(hdcCSharpW);
    }

}

bool isInRedactoc(DWORD lParam) {
    bool flag = false;
    if (LOWORD(lParam) > editorRect.left + penWidth && LOWORD(lParam) < editorRect.right - penWidth &&
        HIWORD(lParam) > editorRect.top + penWidth &&HIWORD(lParam) < editorRect.bottom - penWidth) {
        flag = true;
    }
    return flag;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {

            case IDColorBack:
                Flag1 = !Flag1;
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
                break;


            case IDRussiaFlag:
                Flag2 = !Flag2;
                InvalidateRect(hWnd, NULL, true);
                UpdateWindow(hWnd);
                break;
            

            case IDCircleMove:
                Flag3 = !Flag3;
                if (Flag3) {
                    // получаем контекст устройства для каждого окна

                    hdcClient = GetDC(hWnd);
                    hdcWindow = GetWindowDC(hWnd);

                    hwndDesktop = GetDesktopWindow();
                    hdcDesktop = GetDC(hwndDesktop);

                    hwndCSharp = FindWindow(NULL, L"Dli SP");
                    if (hwndCSharp) {
                        hdcCSharp = GetDC(hwndCSharp);
                        hdcCSharpW = GetWindowDC(hwndCSharp);
                    }
                    Tick = 0; // обнулить таймер
                    SetTimer(hWnd, IDTimer, 70, (TIMERPROC)NULL); // таймер с периодом 70мс
                }
                else {
                    // очистка областей
                    circleRect = { circleRect.left +1, circleRect.top + 1,circleRect.right + 1, circleRect.bottom + 1 }; 
                    circle = { circle.left +1 , circle.top +1,circle.right + 1, circle.bottom + 1 };

                    InvalidateRect(hwndDesktop, &circleRect, true);

                    InvalidateRect(hWnd, &circle, true);
                    DrawMenuBar(hWnd);

                    if (hwndCSharp) InvalidateRect(hwndCSharp, NULL, true);
                    // освобождение контекста
                    ReleaseDC(hwndDesktop, hdcDesktop);
                    ReleaseDC(hWnd, hdcWindow);
                    ReleaseDC(hWnd, hdcClient);

                    if (hdcCSharp)
                    {
                        ReleaseDC(hwndCSharp, hdcCSharp);
                        ReleaseDC(hwndCSharp, hdcCSharpW);

                    }
                    KillTimer(hWnd, IDTimer); // остановить таймер
                }

                
                break;

            case IDRedactorPaint:
                Flag4 = !Flag4;
                InvalidateRect(hWnd, NULL, true);
                UpdateWindow(hWnd);
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
    {
        if (Flag3) {
            ++Tick;
            Circles(hWnd);
        }
        else {
            KillTimer(hWnd, IDTimer); // остановить таймер
        }
    }
    break;

    case WM_LBUTTONDOWN:
    {
        if (Flag4 && isInRedactoc(lParam))
        {
            isDrawing = true;
            PEnd = PBegin = { LOWORD(lParam) , HIWORD(lParam) };
            pen = CreatePen(PS_SOLID, penWidth, RGB(rand() % 256, rand() % 256, rand() %
                256));
        }
    }
    break;
    case WM_LBUTTONUP:
    {
        // если в состоянии рисования линии отпускаем ЛКМ
        if (Flag4 && isInRedactoc(lParam))
        {
            DeleteObject(pen);
            isDrawing = false;
        }
    }
    break;
    
    case WM_MOUSEMOVE:
    {
        // если в состоянии рисования линии двигаем мышь
        if (Flag4 && isInRedactoc(lParam))
        {
            HDC hdc = GetDC(hWnd);
            SelectObject(hdc, pen);
            // чтобы оставались только линии R2_NOTMASKPEN, R2_XORPEN, R2_NOTXORPEN
            SetROP2(hdc, R2_XORPEN);
            MoveToEx(hdc, PBegin.x, PBegin.y, nullptr);
            LineTo(hdc, PEnd.x, PEnd.y);
            MoveToEx(hdc, PBegin.x, PBegin.y, nullptr);
            LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
            PEnd = { LOWORD(lParam) , HIWORD(lParam) };
            ReleaseDC(hWnd, hdc);
        }
    }
    break;


    

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            if (Flag1) {
                RECT rWnd;
                GetWindowRect(hWnd, &rWnd);
                rWnd.bottom = rWnd.bottom - rWnd.top;
                rWnd.right = rWnd.right - rWnd.left;
                rWnd.top = 0;
                rWnd.left = 0;
                COLORREF clrDesktop = GetColor(); 
                SetBkColor(hdc, clrDesktop);
                HBRUSH brush = CreateSolidBrush(clrDesktop);
                FillRect(hdc, &rWnd,brush);

                HPEN pen1 = CreatePen(PS_DOT, 1, RGB(10, 255, 105));
                SelectObject(hdc, pen1);
                Rectangle(hdc, 100, 400, 200, 450);
                SetTextColor(hdc, RGB(200, 0, 0));
                TextOut(hdc, 105, 370, TEXT("Прямоугольник"), 14);

                HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
                SelectObject(hdc, pen);
                SelectObject(hdc, CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 255)));
                Ellipse(hdc, 300, 400, 400, 450);
                TextOut(hdc, 320, 370, TEXT("Эллипс"), 7);

                HGDIOBJ font = CreateFont(40, 0, -60, 0, FW_BOLD, true, false, false, RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, L"Courier new");
                SetTextColor(hdc, RGB(100, 200, 100));
                SelectObject(hdc, font);
                TextOut(hdc, 200, 180, L"Ты сможешь, кто если не ты", 26);

                DeleteObject(pen);
                DeleteObject(pen1);
                DeleteObject(font);
                DeleteObject(brush);

            }

            if (Flag2){
                PaintFlag(GetDesktopWindow());
                PaintFlag(hWnd);
                PaintFlag(hWnd, true);

            }

            if (Flag4) {
                HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
                SelectObject(hdc, pen);
                Rectangle(hdc, editorRect.left, editorRect.top, editorRect.right, editorRect.bottom);
                DeleteObject(pen);
            }

           

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
