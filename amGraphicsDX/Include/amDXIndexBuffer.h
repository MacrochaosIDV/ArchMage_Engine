#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXIndexBuffer
  {
  public:
    amDXIndexBuffer();
    ~amDXIndexBuffer();

    ID3D10Buffer* m_pIndexBuffer;
  };
}


