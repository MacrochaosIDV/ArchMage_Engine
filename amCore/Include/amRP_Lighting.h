#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amRP_Lighting : public amRenderPass
  {
  public:
    amRP_Lighting();
    amRP_Lighting(const uint32 _pass,
                  const String& _strPS,
                  const String& _strVS,
                  const String& _name);
    ~amRP_Lighting();
  };
}
