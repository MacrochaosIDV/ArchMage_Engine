#include "amDXConstantBuffer.h"

namespace amEngineSDK {
  amDXConstantBuffer::amDXConstantBuffer() {}

  amDXConstantBuffer::~amDXConstantBuffer() {}

  void 
  amDXConstantBuffer::createConstBufferDefault() {
    m_bd.Usage = D3D11_USAGE_DYNAMIC;
    m_bd.ByteWidth = sizeof(cbuffer);
    m_bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    m_bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    m_bd.MiscFlags = 0;
    m_bd.StructureByteStride = 0;
    m_subResData.pSysMem = &cbuffer;
    m_subResData.SysMemPitch = 0;
    m_subResData.SysMemSlicePitch = 0;
  }

}
