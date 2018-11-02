#include "amDXGraphicsAPI.h"
namespace amEngineSDK {
  amDXGraphicsAPI::amDXGraphicsAPI() {}


  amDXGraphicsAPI::~amDXGraphicsAPI() {}

  void amDXGraphicsAPI::createVertexBuffer(int nVertex, int vertexSize) {}

  void amDXGraphicsAPI::init() {
    m_windowClassExt.cbSize = sizeof(WNDCLASSEX);
    m_windowClassExt.style = CS_HREDRAW | CS_VREDRAW;
    m_windowClassExt.lpfnWndProc = WndProc;
    m_windowClassExt.cbClsExtra = 0;
    m_windowClassExt.cbWndExtra = 0;
    m_windowClassExt.hInstance = hInstance;
    m_windowClassExt.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    m_windowClassExt.hCursor = LoadCursor(NULL, IDC_ARROW);
    m_windowClassExt.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    m_windowClassExt.lpszMenuName = NULL;
    m_windowClassExt.lpszClassName = szWindowClass;
    m_windowClassExt.hIconSm = LoadIcon(m_windowClassExt.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&m_windowClassExt))
      return;

  }

#include <d3d9.h>

  // include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")

  // global declarations
  LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
  LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class

                               // function prototypes
  void initD3D(HWND hWnd);    // sets up and initializes Direct3D
  void render_frame(void);    // renders a single frame
  void cleanD3D(void);    // closes Direct3D and releases memory

                          // the WindowProc function prototype
  LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
}


