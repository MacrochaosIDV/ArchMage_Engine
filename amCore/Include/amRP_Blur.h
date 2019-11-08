#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class amRP_Blur : public amRenderPass
  {
  public:
    amRP_Blur();
    ~amRP_Blur();

    uint32 m_kernelMode;
  };
}
