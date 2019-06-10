#pragma once
#include "amPrerequisitesCore.h"
#include "amTexture.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amRenderTarget : public amTexture
  {
  public:
    amRenderTarget();
    ~amRenderTarget();

    virtual void 
    resize(const uint32 _height, const uint32 _width);

    uint32 m_height;
    uint32 m_width;
    Vector<UANSICHAR> m_RTBuffer;
  };
}
