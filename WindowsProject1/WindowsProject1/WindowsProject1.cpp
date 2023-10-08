// WindowsProject1.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
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

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));


    //5、通过循环取消息
    /*
    HWND        hwnd;      主窗口句柄
    UINT        message;   具体消息名称
    WPARAM      wParam;    附加消息，键盘消息
    LPARAM      lParam;    附加消息 鼠标消息
    DWORD       time;      消息产生时间
    POINT       pt;        附加消息   鼠标消息 x y
    */

    MSG msg;

    // 主消息循环:

    /*
        _Out_ LPMSG lpMsg,       消息
        _In_opt_ HWND hWnd,      捕获的窗口 填NULL代表捕获所有的窗口
        _In_ UINT wMsgFilterMin, 最小和最大的过滤消息，一边代表填入0
        _In_ UINT wMsgFilterMax);填0代表捕获所有的消息
    */

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // 翻译消息和分发消息
            TranslateMessage(&msg);
            
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    //1.设计窗口 
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;     //显示风格 0代表默认风格
    wcex.lpfnWndProc    = WndProc;                     //回调函数 窗口过程
    wcex.cbClsExtra     = 0;                           //类的额外的内存
    wcex.cbWndExtra     = 0;                           //窗口额外的内存
    wcex.hInstance      = hInstance;                   //应用程序实例句柄 传入WinMain 中的形参即可
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));  //设置图标 如果第一个参数为NULL，表示使用系统提供的光标
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);  //设置光标，如果第一个参数为NULL，表示使用系统提供的光标
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);        //设置背景
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);  //菜单名称
    wcex.lpszClassName  = szWindowClass;                   //指定窗口类名称
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    //2.注册窗口类
    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中
   
   // 3.创建窗口
   /*
    lpClassName,  类名
    lpWindowName, 标题名  
    dwStyle,      常用混合风格：WS_OVERLAPPEDWINDOW
    x, y,         显示坐标   CW_USEDEFAULT默认值
    nWidth,
    nHeight,
    hWndParent,   父窗口 NULL
    hMenu,        菜单 NULL
    hInstance,    实例句柄
    lpParam       附加值 NULL
   */
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   //4.显示和更新窗口
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//

// 6.回调函数

/*
  LRESULT CALLBACK WindowProc
  ( 
  HWND hwnd,      // handle to window     消息所属的窗口句柄
  UINT uMsg,      // message identifier   具体消息名称 WM_XXXX 消息名
  WPARAM wParam,  // first message parameter  键盘附加消息
  LPARAM lParam   // second message parameter 鼠标附加消息
  );

*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                //所有XXWindow 为结尾的方法，都不会进入到消息队列中，而是直接执行
                DestroyWindow(hWnd);  //DestroyWindow发送另一个消息 WM_DESTROY
                break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        //2023-10-08 addtion
    case WM_LBUTTONDOWN:  //鼠标左键按下
     
        {//int xPos = GET_X_LPARAM(lParam);
            int xPos = LOWORD(lParam);
            //int yPos = GET_Y_LPARAM(lParam);
            int yPos = HIWORD(lParam);
            //char buf[1024];
            //wsprintf(buf,TEXT("x=%d,y=%d"), xPos, yPos);
            //MessageBox(hWnd, buf, TEXT("鼠标左键按下"), MB_OK);
        }
        break;

    case WM_KEYDOWN://键盘
        {
            MessageBox(hWnd, TEXT("键盘按下"),TEXT("键盘按下"),MB_OK);
        }
        break;
    case WM_PAINT:  //绘图
        {
            PAINTSTRUCT ps;  //绘图结构体
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...

            TextOut(hdc, 100, 100, TEXT("HELLO"), strlen("HELLO"));

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

// “关于”框的消息处理程序。
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
