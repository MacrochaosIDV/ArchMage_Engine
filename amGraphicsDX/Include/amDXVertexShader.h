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

  protected:
    void
    createVertexShader(amDXDevice* pDevice);

  public:

    virtual void
    setShader(amDXDeviceContext* pDC) override;

    void 
    createVS(const char* pathFileName, amDXDevice* pDevice);

    ID3D11VertexShader* m_vs;
  };
}


