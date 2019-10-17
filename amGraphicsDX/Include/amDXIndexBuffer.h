#pragma once
#include "amDXPreReqs.h"
#include <amIndexBuffer.h>

namespace amEngineSDK {
  class amDXIndexBuffer : public amIndexBuffer
  {
  public:
    amDXIndexBuffer();
    ~amDXIndexBuffer();

    void 
    setBufferData(D3D11_USAGE _usageF,
                  const int32 _RBF = amResourceBindFlags::E::kBIND_INDEX_BUFFER);

    virtual void 
    setData(Vector<uint32>&  data) override;

    virtual void 
    clear() override;

    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_initData;
    ID3D11Buffer* m_pIndexBuffer;
  };
}
