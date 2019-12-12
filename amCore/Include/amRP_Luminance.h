#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amRP_Luminance : public amRenderPass
  {
  public:
    amRP_Luminance();
    amRP_Luminance(const uint32 _pass,
                   const String& _strPS,
                   const String& _strVS,
                   const String& _name);
    ~amRP_Luminance();
  };
}
