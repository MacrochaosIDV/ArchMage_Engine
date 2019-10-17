#pragma once
#include "amPrerequisitesCore.h"
#include "amView.h"

namespace amEngineSDK {
  class amTexture;

  class AM_CORE_EXPORT amDepthStencilView : public amView
  {
  public:
    amDepthStencilView();
    ~amDepthStencilView();

    virtual void 
    resize(const uint32 _height, const uint32 _width) override;

    amTexture* m_tex;
  };
}
