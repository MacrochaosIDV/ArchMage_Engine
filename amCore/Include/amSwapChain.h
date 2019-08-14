#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amSwapChain
  {
  public:
    amSwapChain();
    ~amSwapChain();

    virtual void 
    Present();
  };
}
