#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amView
  {
  public:
    amView(const uint32 _height, 
           const uint32 _width, 
           const float _scale = 1.0f);
    amView();
    ~amView();

    virtual void 
    resize(const uint32 _height, const uint32 _width) = 0;
  };
}


