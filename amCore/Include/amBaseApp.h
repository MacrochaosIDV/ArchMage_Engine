#pragma once
#include <amPrerequisitesUtilities.h>
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>

#include "amGraphicsAPI.h"
#include <amDXGraphicsAPI.h>

namespace amEngineSDK {
  //class AM_CORE_EXPORT amBaseApp
  class amBaseApp
  {
   public:
    amBaseApp();
    virtual ~amBaseApp();

    int32
    run();

   private:
    void
    Init();
    void
    Update(float deltaTime);
     
    void
    Render();

    void
    Destroy();

   protected:
    virtual void
    preInit();

    virtual void
    postInit();

    virtual void
    postUpdate(float deltaTime);

    virtual void
    postRender();

    virtual void
    preDestroy();

    virtual void
    onMouseMove(float x, float y/*, btns*/);

    virtual void
    initSystems();

    virtual void
    initContent();

    
    ATOM MyRegisterClass(HINSTANCE hInstance);
    int32 InitInstance(HINSTANCE hInstance, int32 nCmdShow);
    static LRESULT CALLBACK WndProc(HWND hWnd, uint32 message, WPARAM wParam, LPARAM lParam);
    
    WNDCLASSEXW m_wcex;
    HINSTANCE m_hInst;                                // current instance
    HWND m_hWnd;
    WCHAR m_szTitle[100];                  // The title bar text
    WCHAR m_szWindowClass[100];            // the main window class name

    amDXGraphicsAPI m_DXGAPI;
  };
}


