#pragma once
#include <amVertexBuffer.h>
#include "amDXPreReqs.h"

#include <vector>

namespace amEngineSDK {
  class amDXVertexBuffer : public amVertexBuffer
  {
  public:
    amDXVertexBuffer() = default;
    ~amDXVertexBuffer() = default;

    ID3D11Buffer* m_pVB;
    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_initData;

    void 
    setBufferDesc(D3D11_USAGE _usageF, uint32 _bindF, uint32 _cpuF, uint32 _miscF);

    void
    setSubResourceData(const void* _data, uint32 SysMemPitch, uint32 SysMemSlicePitch);

    void 
    setVertexSize(uint32 _size);

    void 
    setVBSize(uint32 _size);

    std::vector<amVertex> m_vVertex;
    uint32 m_vertexSize;
    uint32 m_numVertex;
  };

}

