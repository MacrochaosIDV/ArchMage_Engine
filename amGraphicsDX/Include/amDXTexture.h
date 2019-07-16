#pragma once
#include "amDXPreReqs.h"
#include "amTexture.h"

namespace amEngineSDK {
  class amDXTexture : public amTexture
  {
  public:
    amDXTexture();
    ~amDXTexture();

    ID3D11Texture2D* m_tex;
  };
}
