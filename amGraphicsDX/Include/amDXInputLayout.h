#pragma once
#include "amDXPreReqs.h"
#include <amInputLayout.h>
#include "amDXDevice.h"

namespace amEngineSDK {
  class amDXDeviceContext;
  class amVertexShader;

  class amDXInputLayout : public amInputLayout
  {
  public:
    amDXInputLayout();
    amDXInputLayout(amShaderInputLayout::E _layout);
    ~amDXInputLayout();
    
    int32
    Create(amDXDevice* _pDV, amVertexShader* _pShaderBlob);
    
    void
    setLayout(amDXDeviceContext* pDC);

    virtual 
    void init() override;

    ID3D11InputLayout* m_pInputLayout;
    Vector<D3D11_INPUT_ELEMENT_DESC> m_layout; 
  };
}
