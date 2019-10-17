#include "amDXConstantBuffer.h"

namespace amEngineSDK {
  amDXConstantBuffer::amDXConstantBuffer(void* _pCB, const SIZE_T _size) {
    m_pCBuffer = _pCB;
    m_size = _size;
  }

  amDXConstantBuffer::~amDXConstantBuffer() {}

  void 
  amDXConstantBuffer::setBufferData(uint32  _usageF, uint32 _cpuAccessFlags, void* _data) {
    m_bd.Usage = static_cast<D3D11_USAGE>(_usageF);
    m_bd.ByteWidth = static_cast<uint32>(m_size);
    m_bd.BindFlags = static_cast<D3D11_BIND_FLAG>(amResourceBindFlags::E::kBIND_CONSTANT_BUFFER);
    m_bd.CPUAccessFlags = _cpuAccessFlags;
    m_bd.MiscFlags = 0;
    m_bd.StructureByteStride = 0;
    if(_data)
      m_pCBuffer = _data;
    m_subResData.pSysMem = m_pCBuffer;
    m_subResData.SysMemPitch = 0;
    m_subResData.SysMemSlicePitch = 0;
  }

}
