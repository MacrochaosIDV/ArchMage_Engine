#pragma once
#include "amPrerequisitesCore.h"
namespace amEngineSDK {
  class AM_CORE_EXPORT amIndexBuffer
  {
  public:
    amIndexBuffer();
    ~amIndexBuffer();

    virtual void setData(Vector<uint32>& _data);
    virtual void clear();

    Vector<uint32> m_vecIB;
  };
}
