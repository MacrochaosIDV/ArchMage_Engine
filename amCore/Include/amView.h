#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amView
  {
  public:
    amView();
    ~amView();

    virtual void 
    resize(const uint32 _height, const uint32 _width) = 0;
  };
}


