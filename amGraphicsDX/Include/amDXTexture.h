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
    D3D11_TEXTURE2D_DESC m_desc;
  };
}
