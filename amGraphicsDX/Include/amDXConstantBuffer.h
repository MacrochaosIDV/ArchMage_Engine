#pragma once
#include "amDXPreReqs.h"
#include <amMatrix4x4.h>

namespace amEngineSDK {
  struct VS_CBuffer
  {
    amMatrix4x4 WVP;
  };

  class amDXConstantBuffer
  {
  public:
    amDXConstantBuffer();
    ~amDXConstantBuffer();

    void 
    createConstBufferDefault();

    ID3D11Buffer* m_pCB;
    VS_CBuffer cbuffer;
    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_subResData;
  };
}
