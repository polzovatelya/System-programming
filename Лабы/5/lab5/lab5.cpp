// lab5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab5.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



bool flag_color = false;
HWND But_color;


//Флаги России
HWND But_Russian_Desktop;
HWND But_Russian_client;
HWND But_Russian_5;
bool  flag1=false;
bool  flag2=false;
bool  flag3=false;

//Редактор
bool drawing = false;
HPEN pen_line;
COLORREF color_cur = RGB(84,23,171);
COLORREF color_old = RGB(84, 23, 171);
POINT pt, old, cur;
bool change = false;
HWND But_color_red;


//Движение круга
HWND But_krug;
bool move_krug = false;
//Области окон
//C#
HWND C_hwnd;
HDC C_Client_hdc;
HDC C_Oblast_hdc;

//Рабочий стол
HWND Desktop_hwnd;
HDC Desktop_hdc;

//Наша программа
HDC Client_hdc;
HDC Oblast_hdc;

//Области кружков
RECT circleRect = { 0, 0, 50, 50 }; //Прямоугольник для круга
RECT circle = { 0,0,0,0 };          //Прямоугольник для кружков


//Таймер
int Tick = 0; // счетчик тиков
int const IDTimer = 4;

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
    LoadStringW(hInstance, IDC_LAB5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB5);
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

#define BUTTON_ID 1000
#define BUTTON_ID1 1001
#define BUTTON_ID2 1002
#define BUTTON_ID3 1003
#define BUTTON_ID4 1004
#define BUTTON_ID5 1005
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   But_color = CreateWindow(TEXT("BUTTON"), TEXT("ФОН"), WS_VISIBLE | WS_CHILD, 50, 400, 80, 26, hWnd, (HMENU)BUTTON_ID, NULL, NULL);
   //России
   But_Russian_Desktop = CreateWindow(TEXT("BUTTON"), TEXT("Флаг на Рабочий стол"), WS_VISIBLE | WS_CHILD, 165, 400, 200, 26, hWnd, (HMENU)BUTTON_ID1, NULL, NULL);
   But_Russian_client = CreateWindow(TEXT("BUTTON"), TEXT("Флаг на клиентскую область"), WS_VISIBLE | WS_CHILD, 165, 430, 200, 26, hWnd, (HMENU)BUTTON_ID2, NULL, NULL);
   But_Russian_5 = CreateWindow(TEXT("BUTTON"), TEXT("Флаг на приложение"), WS_VISIBLE | WS_CHILD, 165, 460, 200, 26, hWnd, (HMENU)BUTTON_ID3, NULL, NULL);

   //Редактор
   But_color_red=CreateWindow(TEXT("BUTTON"), TEXT("Изменить цвет"), WS_VISIBLE | WS_CHILD, 370, 400, 150, 26, hWnd, (HMENU)BUTTON_ID4, NULL, NULL);
   
   
   //Круг

   But_krug = CreateWindow(TEXT("BUTTON"), TEXT("Запустить движение круга"), WS_VISIBLE | WS_CHILD, 550, 400, 250, 26, hWnd, (HMENU)BUTTON_ID5, NULL, NULL);
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
COLORREF get_color() {
    HWND hDesktop = GetDesktopWindow();
    HDC hDcDesktop = GetDC(hDesktop);
    RECT rect_desktop;
    int red = 0, green = 0, blue = 0;
    GetWindowRect(hDesktop, &rect_desktop);
    COLORREF color_current;
    // обрабатывается 1/10 рандомных пикселей
    RECT new_oblast;
    new_oblast.left = int(rect_desktop.left/10);
    new_oblast.top = int(rect_desktop.top/10);
    new_oblast.right = int(rect_desktop.right/10);
    new_oblast.bottom = int(rect_desktop.bottom/10);
    int n = (new_oblast.bottom + new_oblast.right)/100;
    for (int i = 0; i < n; ++i) {
        color_current = GetPixel(hDcDesktop, new_oblast.top + n, new_oblast.left+n);
        red += GetRValue(color_current);
        green += GetGValue(color_current);
        blue += GetBValue(color_current);
    }
    red = int(red / n);
    green = int(green / n);
    blue = int(blue / n);
    COLORREF color_result = RGB(red, green, blue);
    ReleaseDC(hDesktop, hDcDesktop);
    return color_result;
}
void Russian_flag(HDC current_hDC,HWND hwnd, int x, int y,bool flag) {
    if (flag) {
        HPEN my_pen;

        //обводка
        my_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(current_hDC, my_pen);

        //белый
        SelectObject(current_hDC, (HBRUSH)CreateSolidBrush(RGB(255, 255, 255)));
        Rectangle(current_hDC, x, y, x + 150, y + 50);

        //синий
        SelectObject(current_hDC, (HBRUSH)CreateSolidBrush(RGB(0, 0, 255)));
        Rectangle(current_hDC, x, y + 50, x + 150, y + 100);

        //красный
        SelectObject(current_hDC, (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(current_hDC, x, y + 100, x + 150, y + 150);
    }
    else {
        
        RECT r = { x-40,y-40,x + 200,y + 200 };
        InvalidateRect(hwnd, &r, true);
        DrawMenuBar(hwnd);

    }
    return;
}


void DrawCircle(HDC hdc) {
    HPEN pen = CreatePen(PS_DASHDOTDOT, 4, RGB(41, 126, 140));
    HBRUSH brush = CreateHatchBrush(HS_FDIAGONAL, RGB(190, 128, 245));
    SelectObject(hdc, brush);
    Ellipse(hdc, circleRect.left + 1, circleRect.top + 1, circleRect.right + 1, circleRect.bottom + 1);
    DeleteObject(brush);
}
void Circles(HWND hWnd) {
    circle = { circleRect.left - 30, circleRect.top - 50,circleRect.right + 1, circleRect.bottom + 1 };
    InvalidateRect(Desktop_hwnd, &circle, true);
    UpdateWindow(Desktop_hwnd);
    DrawMenuBar(hWnd);
    InvalidateRect(hWnd, &circle, true);
    UpdateWindow(hWnd);


    if (C_Client_hdc) {
        InvalidateRect(C_hwnd, NULL, true);
        UpdateWindow(C_hwnd);
    }
    circleRect = {Tick, Tick,Tick + 100, Tick + 100 };
    DrawCircle(Desktop_hdc);
    DrawCircle(Client_hdc);
    DrawCircle(Oblast_hdc);
    if (C_Client_hdc) {
        DrawCircle(C_Client_hdc);
        DrawCircle(C_Oblast_hdc);
    }

}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC current_hDC;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case 1000:
                flag_color = !flag_color;
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
                break;
            case 1001:
                flag1 = !flag1;
                current_hDC = GetDC(GetDesktopWindow());
                Russian_flag(current_hDC, GetDesktopWindow(), 50,50,flag1);
                ReleaseDC(GetDesktopWindow(), current_hDC);
                break;
            case 1002:
                flag2 = !flag2;
                current_hDC = GetDC(hWnd);
                Russian_flag(current_hDC, hWnd,0,0,flag2);
                ReleaseDC(hWnd, current_hDC);
                break;
            case 1003:
                flag3 = !flag3;
                current_hDC = GetWindowDC(hWnd);
                Russian_flag(current_hDC,hWnd, 200, 40,flag3);                
                break;
            case 1004:
                change = true;
                color_cur = RGB(rand() % 255, rand() % 255, rand() % 255);
                break;
            case 1005:
                move_krug =! move_krug;
                if (move_krug) {
                    // получаем контекст устройства для каждого окна

                    Client_hdc = GetDC(hWnd);
                    Oblast_hdc = GetWindowDC(hWnd);

                    Desktop_hwnd = GetDesktopWindow();
                    Desktop_hdc = GetDC(Desktop_hwnd);

                    C_hwnd = FindWindow(NULL, L"MainWindow");
                    if (C_hwnd) {
                        C_Client_hdc = GetDC(C_hwnd);
                        C_Oblast_hdc= GetWindowDC(C_hwnd);
                    }
                    Tick = 0; // обнулить таймер
                    SetTimer(hWnd, IDTimer, 70, (TIMERPROC)NULL); // таймер с периодом 70мс
                }
                else {
                    // очистка областей
                    circleRect = { circleRect.left + 1, circleRect.top + 1,circleRect.right + 1, circleRect.bottom + 1 };
                    circle = { circle.left + 1 , circle.top + 1,circle.right + 1, circle.bottom + 1 };

                    InvalidateRect(Desktop_hwnd, &circle, true);
                    InvalidateRect(Desktop_hwnd, &circleRect, true);

                    InvalidateRect(hWnd, &circle, true);
                    DrawMenuBar(hWnd);

                    if (C_hwnd) InvalidateRect(C_hwnd, NULL, true);
                    // освобождение контекста
                    ReleaseDC(Desktop_hwnd, Desktop_hdc);
                    ReleaseDC(hWnd, Client_hdc);
                    ReleaseDC(hWnd, Oblast_hdc);

                    if (C_Client_hdc)
                    {
                        ReleaseDC(C_hwnd, C_Client_hdc);
                        ReleaseDC(C_hwnd, C_Oblast_hdc);

                    }
                    KillTimer(hWnd, IDTimer); // остановить таймер
                }


                break;

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
    case WM_TIMER :
        {
            if (move_krug) {
                ++Tick;
                Circles(hWnd);
            }
            else {
                KillTimer(hWnd, IDTimer); // остановить таймер
            }
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //область рисования
            HPEN pen = CreatePen(PS_DOT, 5, RGB(171, 40, 131));
            SelectObject(hdc, pen);
            Rectangle(hdc, 500, 50, 900, 370);

            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            if (flag_color) {
                RECT rWnd;
                GetWindowRect(hWnd, &rWnd);
                rWnd.bottom = rWnd.bottom - rWnd.top;
                rWnd.right = rWnd.right - rWnd.left;
                rWnd.top = 0;
                rWnd.left = 0;
                COLORREF color_desktop = get_color();
                SetBkColor(hdc, color_desktop);
                FillRect(hdc, &rWnd, (HBRUSH)CreateSolidBrush(color_desktop));


                //Квадрат
                HPEN pen1 = CreatePen(PS_DOT, 1, RGB(222, 17, 122));
                HBRUSH brush1 = CreateHatchBrush(HS_CROSS, RGB(57, 4, 120));
                SelectObject(hdc, pen1);
                SelectObject(hdc, brush1);
                Rectangle(hdc, 50, 50, 150, 150);
                SetTextColor(hdc, RGB(0, 0, 0));
                TextOut(hdc, 55, 30, TEXT("Квадратик"), 9);


                //Круг
                HPEN pen2 = CreatePen(PS_DOT, 4, RGB(5, 93, 120));
                HBRUSH brush2 = CreateHatchBrush(HS_FDIAGONAL, RGB(14, 222, 125));
                SelectObject(hdc, pen2);
                SelectObject(hdc, brush2);
                Ellipse(hdc, 165, 50, 265, 150);
                TextOut(hdc, 165, 30, TEXT("Кружочек"), 8);

                // Эллипс
                HPEN pen3 = CreatePen(PS_DOT, 4, RGB(99, 255, 252));
                HBRUSH brush3 = CreateHatchBrush(HS_FDIAGONAL, RGB(120, 47, 99));
                SelectObject(hdc, pen3);
                SelectObject(hdc, brush3);
                Ellipse(hdc, 280, 50, 350, 100);
                TextOut(hdc, 270, 30, TEXT("Эллипс"), 6);
            }
            EndPaint(hWnd, &ps);
        }
        break;



    //Графический редактор

    case WM_LBUTTONDOWN:
        drawing = true;
        pen_line = CreatePen(PS_INSIDEFRAME, 5, color_cur);
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        old.x = -1;
        old.y = -1;
        break;
    case WM_LBUTTONUP: {
        HDC hdc = GetDC(hWnd);
        drawing = false;
        SelectObject(hdc, pen_line);
        MoveToEx(hdc, pt.x, pt.y, NULL);
        LineTo(hdc, old.x, old.y);
    }
        break;
    case WM_MOUSEMOVE:
    {
        if (drawing) {
            cur.x = LOWORD(lParam);
            cur.y = HIWORD(lParam);
            HDC hdc = GetDC(hWnd);
            HPEN p = CreatePen(PS_INSIDEFRAME, 5, RGB(255,255,255));
            if ((cur.x >= 505 && cur.x <= 895 && cur.y >= 55 && cur.y <= 365) && (pt.x >= 505 && pt.x <= 895 && pt.y >= 55 && pt.y <= 365)) {
                SelectObject(hdc, pen_line);
                MoveToEx(hdc, pt.x, pt.y, NULL);
                // if (change)
                SetROP2(hdc, R2_NOTXORPEN);
                //SelectObject(hdc, pen_line);
                //else
                if (old.x >= 505 && old.x <= 895 && old.y >= 55 && old.y <= 365) {
                    LineTo(hdc, old.x, old.y);

                }
                MoveToEx(hdc, pt.x, pt.y, NULL);
                LineTo(hdc, cur.x, cur.y);
                ReleaseDC(hWnd, hdc);
                old.x = cur.x;
                old.y = cur.y;
            }
        }
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
