#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXTexture
  {
  public:
    amDXTexture();
    ~amDXTexture();

    void 
    loadFromFile(std::string filePathName);
    void 
    unload();

    ID3D11Texture2D* m_tex;
    uint32 m_height;
    uint32 m_width;
  };
}
