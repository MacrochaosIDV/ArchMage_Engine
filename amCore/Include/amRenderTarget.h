#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amTextureObject;

  class AM_CORE_EXPORT amRenderTarget
  {
  public:
    amRenderTarget();
    ~amRenderTarget();

    virtual void 
    resize(const uint32 _height, const uint32 _width);

    uint32 m_height;
    uint32 m_width;
    amTextureObject* m_tex;
  };
}
