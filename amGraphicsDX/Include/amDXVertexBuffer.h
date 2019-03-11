#pragma once
#include "amDXPreReqs.h"
#include <vector>
#include <amVertexBuffer.h>
#include <amVertex.h>
class amDXDevice;

namespace amEngineSDK {
  class amDXVertexBuffer : public amVertexBuffer
  {
   public:
    amDXVertexBuffer() = default;
    ~amDXVertexBuffer() = default;

    

    void 
    setBufferData(D3D11_USAGE _usageF);

    void
    setSubResourceData(const void* _data, uint32 SysMemPitch, uint32 SysMemSlicePitch);

    void 
    setVBSize(uint32 _size);

    //void 
    //createVertexBuffer(amDXDevice* pdevice);

    ID3D11Buffer* m_pVB;
    D3D11_BUFFER_DESC m_bd;
    D3D11_SUBRESOURCE_DATA m_initData;
    Vector<amVertex> m_vVertex;
    uint32 m_numVertex;
  };

}

