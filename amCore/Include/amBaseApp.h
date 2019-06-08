#pragma once
#include <amPrerequisitesUtilities.h>


#include "amGraphicsAPI.h"

namespace amEngineSDK {
  //class amBaseApp
  class AM_CORE_EXPORT amBaseApp
  {
   public:
    amBaseApp();
    virtual ~amBaseApp();

    int32
    run();

    virtual void 
    setGraphicsAPI(amGraphicsAPI& _API);

   private:
    virtual void
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
    
    ATOM 
    MyRegisterClass(HINSTANCE hInstance);

    int32 
    InitInstance(HINSTANCE hInstance, int32 nCmdShow);

    static LRESULT CALLBACK 
    WndProc(HWND hWnd, uint32 message, WPARAM wParam, LPARAM lParam);
    
    WNDCLASSEXW m_wcex;
    HINSTANCE m_hInst;                                // current instance
    HWND m_hWnd;
    std::wstring m_szTitle;// [100];                  // The title bar text
    std::wstring m_szWindowClass;// [100];            // the main window class name
    std::wstring m_arrowName;
    uint32 m_wndWidth;
    uint32 m_wndHeight;

    amGraphicsAPI* m_GAPI;
  };
}
