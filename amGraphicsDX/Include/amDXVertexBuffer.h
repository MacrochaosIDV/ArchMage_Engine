#pragma once
#include <amVertexBuffer.h>
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXVertexBuffer : public amVertexBuffer
  {
  public:
    amDXVertexBuffer() = default;
    ~amDXVertexBuffer() = default;

    ID3D10Buffer* m_pVertexBuffer;
  };

}

