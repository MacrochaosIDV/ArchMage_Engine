#pragma once

#include "amDXPreReqs.h"
#include "amDXShader.h"

#include <d3d11.h>

namespace amEngineSDK {
  class amDXDevice;
  class amDXDeviceContext;

  class amDXPixelShader : public amDXShader
  {
  public:
    amDXPixelShader();
    ~amDXPixelShader();

    void
    createPixelShader(amDXDevice* pDevice);

    virtual void
    setShader(amDXDeviceContext* pDC) override;

    ID3D11PixelShader* m_ps;
  };
}


