#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXShaderResourceView
  {
   public:
    amDXShaderResourceView();
    ~amDXShaderResourceView();

    ID3D10ShaderResourceView* g_pTextureRV;
  };
}


