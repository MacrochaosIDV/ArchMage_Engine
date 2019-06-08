#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXViewPort
  {
  public:
    amDXViewPort();
    ~amDXViewPort();

    D3D10_VIEWPORT m_viewPort;
  };
}
