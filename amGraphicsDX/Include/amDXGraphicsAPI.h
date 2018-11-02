/**
***********************************************
 * @file CGraphicsAPI.h
 * @date 2018/10/17
 *
 * @author Usuario
 * Contact: user@company.com
 *
 * @brief  Implements a Graphics API of DirectX
 *
 * @note
***********************************************
*/
#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXGraphicsAPI
  {
  public:
    amDXGraphicsAPI();
    ~amDXGraphicsAPI();

    void createVertexBuffer(int nVertex, int vertexSize);
    void init();
    void destroy();

    HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
    HRESULT InitDevice();
    void CleanupDevice();
    LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
    void Render();

    WNDCLASSEX m_windowClassExt;
  };
}


