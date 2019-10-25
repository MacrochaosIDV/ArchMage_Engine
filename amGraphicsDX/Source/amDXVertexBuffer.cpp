#include "amDXVertexBuffer.h"
#include "amDXDevice.h"

namespace amEngineSDK {

  amDXVertexBuffer::amDXVertexBuffer(const uint32 _size) {
    m_vVertex.resize(_size);
  }

  void
  amDXVertexBuffer::setBufferData(D3D11_USAGE _usageF,
                                  const int32 _RBF) {
    memset(&m_bd, 0, sizeof(m_bd));
    m_bd.Usage = _usageF;
    m_numVertex = m_vVertex.size();
    m_bd.ByteWidth = static_cast<uint32>(sizeof(amVertex) * m_numVertex); // total byte size of all vertexes
    m_bd.BindFlags = static_cast<D3D11_BIND_FLAG>(_RBF);
    m_bd.CPUAccessFlags = 0;
    m_bd.MiscFlags = 0;
    m_bd.StructureByteStride = 0;
    m_initData.pSysMem = &m_vVertex[0]; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = 0;
    m_initData.SysMemSlicePitch = 0;
    m_vVertex.clear();
  }

  void 
  amDXVertexBuffer::setSubResourceData(const void* _data, uint32 _sysMemPitch, uint32 _sysMemSlicePitch) {
    m_initData.pSysMem = _data; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = _sysMemPitch;
    m_initData.SysMemSlicePitch = _sysMemSlicePitch;

  }

  void 
  amDXVertexBuffer::setVBSize(uint32 _size) {
    m_numVertex = _size;
    m_vVertex.resize(m_numVertex);
  }

}
