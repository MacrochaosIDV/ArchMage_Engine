#pragma once
#include "amDXPreReqs.h"
#include "amDXDeviceContext.h"

namespace amEngineSDK {
  class amDXDeviceContext
  {
  public:
    amDXDeviceContext();
    ~amDXDeviceContext();

    ID3D11DeviceContext* m_pDC;
  };
}


