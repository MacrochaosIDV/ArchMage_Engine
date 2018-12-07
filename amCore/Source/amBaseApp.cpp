#include "amBaseApp.h"
#include <WinUser.h>

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
    
    

    // TODO: Place code here.

    
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
      
      m_DXGAPI.Render();

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
    m_DXGAPI.Render();
    postRender();
    //end();
    //swap();
  }

  void amBaseApp::Destroy() {}

  void amBaseApp::preInit() {
    mbstowcs(m_szTitle, "ArchMage Engine", 100);
    mbstowcs(m_szWindowClass, "MainWindow", 100);

    HINSTANCE hInstance = GetModuleHandle(nullptr);

    int32 nCmdShow = SW_SHOW;
    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TSTPROJ, m_szWindowClass, MAX_LOADSTRING);
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

  void amBaseApp::postUpdate(float deltaTime) {}

  void amBaseApp::postRender() {}

  void amBaseApp::preDestroy() {}

  void amBaseApp::onMouseMove(float x, float y) {}

  void amBaseApp::initSystems() {
    m_DXGAPI.init(m_hWnd);
  }

  void amBaseApp::initContent() {}

  ATOM amBaseApp::MyRegisterClass(HINSTANCE hInstance) {
    

    m_wcex.cbSize = sizeof(WNDCLASSEX);

    m_wcex.style = CS_HREDRAW | CS_VREDRAW;
    m_wcex.lpfnWndProc = WndProc;
    m_wcex.cbClsExtra = 0;
    m_wcex.cbWndExtra = 0;
    m_wcex.hInstance = hInstance;
    m_wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TSTPROJ));
    m_wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    m_wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    m_wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TSTPROJ);
    m_wcex.lpszClassName = m_szWindowClass;
    m_wcex.cbWndExtra = sizeof(void*); // 
    m_wcex.hIconSm = LoadIcon(m_wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&m_wcex);
  }

  int32 amBaseApp::InitInstance(HINSTANCE hInstance, int32 nCmdShow) {
    m_hInst = hInstance; // Store instance handle in our global variable

    tagCREATESTRUCTA tCS;
    m_hWnd = CreateWindowExW(0, m_szWindowClass, m_szTitle, 
                             0, 0, CW_USEDEFAULT, CW_USEDEFAULT, WS_MAXIMIZE,
                             nullptr, nullptr, hInstance, &tCS.lpCreateParams);

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


