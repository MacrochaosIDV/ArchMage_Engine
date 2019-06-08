#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXDepthStencilView
  {
  public:
    amDXDepthStencilView();
    ~amDXDepthStencilView();

    ID3D11DepthStencilView* m_pDSV;
  };
}
