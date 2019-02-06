#pragma once
#include "amDXPreReqs.h"
#include "amDXShader.h"

namespace amEngineSDK {
  class amDXDevice;
  class amDXDeviceContext;

  class amDXVertexShader : public amDXShader
  {
  public:
    amDXVertexShader();
    ~amDXVertexShader();

    void
    createVertexShader(amDXDevice* pDevice);

    virtual void
    setShader(amDXDeviceContext* pDC) override;

    ID3D11VertexShader* m_vs;
  };
}


