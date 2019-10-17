#include "amDXIndexBuffer.h"
#include <amVertex.h>

namespace amEngineSDK {
  amDXIndexBuffer::amDXIndexBuffer() {}

  amDXIndexBuffer::~amDXIndexBuffer() {}

  void 
  amDXIndexBuffer::setBufferData(D3D11_USAGE _usageF,
                                 const int32 _RBF) {
    memset(&m_bd, 0, sizeof(m_bd));
    m_bd.Usage = _usageF;
    m_bd.ByteWidth = static_cast<uint32>(sizeof(uint32) * m_vecIB.size());
    m_bd.BindFlags = static_cast<D3D11_BIND_FLAG>(_RBF);
    m_bd.CPUAccessFlags = 0;
    m_bd.MiscFlags = 0;
    m_bd.StructureByteStride = sizeof(amVertex);
    m_initData.pSysMem = &m_vecIB[0]; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = 0;
    m_initData.SysMemSlicePitch = 0;
    //m_vecIB.clear();
  }

  void 
  amDXIndexBuffer::setData(Vector<uint32>& data) {
    m_vecIB = data;
  }

  void 
  amDXIndexBuffer::clear() {
    m_vecIB.clear();
    m_vecIB.resize(0);
  }
}
