#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class amRP_SSAO : public amRenderPass
  {
  public:
    amRP_SSAO(amRenderPassStage::E _pass, String _strPS, String _strVS, String _name);
    ~amRP_SSAO();
  };
}
