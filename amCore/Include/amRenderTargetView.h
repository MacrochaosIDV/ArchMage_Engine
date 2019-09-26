#pragma once
#include "amPrerequisitesCore.h"
#include "amView.h"

namespace amEngineSDK {
  class amRenderTarget;

  class AM_CORE_EXPORT amRenderTargetView : public amView
  {
  public:
    amRenderTargetView();
    ~amRenderTargetView();

    void 
    resize(const uint32 _height, const uint32 _width);

    amRenderTarget* m_rt;
    void* m_ApiPtr;
  };
}
