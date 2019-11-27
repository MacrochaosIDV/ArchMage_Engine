#pragma once
#include "amPrerequisitesCore.h"
#include <amResource.h>

namespace amEngineSDK {
  class AM_CORE_EXPORT amConstantBuffer : public amResource
  {
  public:
    amConstantBuffer();
    ~amConstantBuffer();

    void 
    setBuffer(void* _data, const uint32 _dataSize);

    void* m_pCBuffer;
    uint32 m_size;
  };
}
