#pragma once
#include "amDXPreReqs.h"
#include "amDXDevice.h"

namespace amEngineSDK {
  class amDXInputLayout
  {
  public:
    amDXInputLayout();
    ~amDXInputLayout();

    ID3D11InputLayout* m_pVertexLayout; 


    Vector<D3D11_INPUT_ELEMENT_DESC> m_layout =
    {
      {"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"NORMAL",   0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"UV",       0, DXGI_FORMAT_R32G32_FLOAT,       0, 48, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };
    
    int32 Create(amDXDevice* _pDV, ID3DBlob* _pShaderBlob);
    //uint32 numElements = sizeof(layout) / sizeof(layout[0]);
  };
}


