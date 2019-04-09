#include "amBaseApp.h"
// Windows Header Files:
#include <windows.h>


#define MAX_LOADSTRING 100
#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_TSTPROJ_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_TSTPROJ			107
#define IDI_SMALL				108
#define IDC_TSTPROJ			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif

namespace amEngineSDK {

  

  amBaseApp::amBaseApp() {}

  amBaseApp::~amBaseApp() {}

  int32 amBaseApp::run() {
    Init();
    
    // Main message loop:
    HINSTANCE hInstance = GetModuleHandle(nullptr);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TSTPROJ));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
      if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }

      //Update Game Logic
      
      Render();

      //Render Game Frame
      //Render();
    }
    //Destroy DirectX
    //DestroyGraphicsContent();
    //g_GraphicsAPI.Destroy()

    return (int)msg.wParam;
  }
  void amBaseApp::Init() {
    preInit();
    initSystems();
    initContent();
    postInit();
  }
  void amBaseApp::Update(float deltaTime) {
    //input.update();
    postUpdate(deltaTime);
  }

  void amBaseApp::Render() {
    //Begin();
    m_GAPI->Render();
    postRender();
    //end();
    //swap();
  }

  void amBaseApp::Destroy() {}

  void amBaseApp::preInit() {
    // Initialize global strings

    m_szTitle = L"ArchMage Engine";
    m_szWindowClass = L"MainWindow";
    m_wndHeight = 600;
    m_wndWidth = 800;

    HINSTANCE hInstance = GetModuleHandle(nullptr);

    int32 nCmdShow = SW_SHOW;
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow)) {
      //Error
    }

    //Init DirectX
    //g_GraphicsAPI.Init(m_hWnd);
    //Load graphics data (shaders, meshes, models, textures, buffers, etc...)
    //InitGraphicsContent();
    
    ShowWindow(m_hWnd, nCmdShow);
  }

  void amBaseApp::postInit() {}

  void amBaseApp::postUpdate(float deltaTime) {
    deltaTime;
  }

  void amBaseApp::postRender() {}

  void amBaseApp::preDestroy() {}

  void amBaseApp::onMouseMove(float x, float y) {
    x;
    y;
  }

  void amBaseApp::initSystems() {
    m_GAPI->init(m_hWnd);
  }

  void amBaseApp::initContent() {}

  void amBaseApp::setGraphicsAPI(amGraphicsAPI & _API) {
    m_GAPI = &_API;
  }

  ATOM amBaseApp::MyRegisterClass(HINSTANCE hInstance) {
    m_wcex.cbSize = sizeof(WNDCLASSEXW);
    m_wcex.style = CS_HREDRAW | CS_VREDRAW;
    m_wcex.lpfnWndProc = WndProc;
    m_wcex.cbClsExtra = 0;
    m_wcex.cbWndExtra = 0;
    m_wcex.hInstance = hInstance;
    m_wcex.hIcon = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_TSTPROJ));
    m_arrowName = L"IDC_ARROW";
    m_wcex.hCursor = LoadCursorW(nullptr, m_arrowName.c_str());
    m_wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    m_wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TSTPROJ);
    m_wcex.lpszClassName = m_szWindowClass.c_str();
    m_wcex.cbWndExtra = sizeof(void*); // 
    m_wcex.hIconSm = LoadIconW(m_wcex.hInstance, MAKEINTRESOURCEW(IDI_SMALL));
    
    if (!RegisterClassExW(&m_wcex)) {
      //Error
      return 1;
    }
    return 0;
  }

  int32 amBaseApp::InitInstance(HINSTANCE hInstance, int32 nCmdShow) {
    m_hInst = hInstance; // Store instance handle in our global variable

    m_hWnd = CreateWindowExW(0, m_szWindowClass.c_str(), m_szTitle.c_str(),
                             WS_OVERLAPPEDWINDOW, 0, 0, m_wndWidth, m_wndHeight,
                             nullptr, nullptr, hInstance, nullptr);

    if (!m_hWnd) {
      return FALSE;
    }

    ShowWindow(m_hWnd, nCmdShow);
    UpdateWindow(m_hWnd);

    return TRUE;
  }

  LRESULT amBaseApp::WndProc(HWND hWnd, uint32 message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
      case WM_COMMAND:
      {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId) {
          case IDM_ABOUT:
            //DialogBoxW(m_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        hdc;
        // TODO: Add any drawing code that uses hdc here...
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
}


