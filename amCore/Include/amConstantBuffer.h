#pragma once
#include "amPrerequisitesCore.h"
#include <amResource.h>

namespace amEngineSDK {
  class AM_CORE_EXPORT amConstantBuffer : public amResource
  {
  public:
    amConstantBuffer();
    ~amConstantBuffer();

    void* m_pCBuffer;
    SIZE_T m_size;
  };
}
