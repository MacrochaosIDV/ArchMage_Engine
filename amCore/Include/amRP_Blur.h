#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amRP_Blur : public amRenderPass
  {
  public:
    amRP_Blur();
    amRP_Blur(const uint32 _pass,
              const String& _strPS,
              const String& _strVS,
              const String& _name);
    ~amRP_Blur();

    uint32 m_kernelMode;
  };
}
