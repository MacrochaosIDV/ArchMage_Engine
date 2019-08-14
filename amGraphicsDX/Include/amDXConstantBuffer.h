#pragma once
#include "amDXPreReqs.h"
#include "amConstantBuffer.h"
#include <amMatrix4x4.h>

namespace amEngineSDK {

  class amDXConstantBuffer : public amConstantBuffer
  {
  public:
    amDXConstantBuffer() = default;
    amDXConstantBuffer(void* _pCB, const SIZE_T _size);
    ~amDXConstantBuffer();

    void
    setBufferData(uint32 _usageF, uint32 _cpuAccessFlags, void* _data = nullptr);

    ID3D11Buffer* m_pCB;
    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_subResData;
  };
}
