#pragma once
#include "amPrerequisitesCore.h"
namespace amEngineSDK {
  class AM_CORE_EXPORT amIndexBuffer
  {
  public:
    amIndexBuffer();
    ~amIndexBuffer();

    virtual void setData(Vector<int32>) = 0;
    virtual void clear() = 0;
  };
}


