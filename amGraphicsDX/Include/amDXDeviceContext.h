#pragma once
#include "amDXPreReqs.h"
#include "amDeviceContext.h"

namespace amEngineSDK {
  class amDXDeviceContext : public amDeviceContext
  {
  public:
    amDXDeviceContext();
    ~amDXDeviceContext();

    void
    setPixelShader(amPixelShader* _PS) override;

    void
    setVertexShader(amVertexShader* _VS) override;

    ID3D11DeviceContext* m_pDC;
  };
}
