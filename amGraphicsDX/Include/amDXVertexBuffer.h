#pragma once
#include "amDXPreReqs.h"
#include <vector>
#include <amVertexBuffer.h>
#include <amVertex.h>


namespace amEngineSDK {
  class amDXDevice;

  class amDXVertexBuffer : public amVertexBuffer
  {
   public:
    amDXVertexBuffer() = default;
    amDXVertexBuffer(const uint32 _size);
    ~amDXVertexBuffer() = default;

    void 
    setBufferData(D3D11_USAGE _usageF,
                  const int32 _RBF = amResourceBindFlags::E::kBIND_VERTEX_BUFFER);

    void
    setSubResourceData(const void* _data, uint32 SysMemPitch, uint32 SysMemSlicePitch);

    void 
    setVBSize(uint32 _size);

    //void 
    //createVertexBuffer(amDXDevice* pdevice);

    ID3D11Buffer* m_pVB;
    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_initData;
  };

}
