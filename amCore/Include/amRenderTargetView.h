#pragma once
#include "amPrerequisitesCore.h"
#include "amView.h"

namespace amEngineSDK {
  class amTexture;

  class AM_CORE_EXPORT amRenderTargetView : public amView
  {
  public:
    amRenderTargetView(const uint32 _height, 
                       const uint32 _width, 
                       const float _scale = 1.0f);
    amRenderTargetView();
    ~amRenderTargetView();

    void 
    resize(const uint32 _height, const uint32 _width);

    amTexture* m_rt;
  };
}
