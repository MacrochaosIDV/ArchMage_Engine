#include "amDXVertexBuffer.h"
namespace amEngineSDK {
  void amDXVertexBuffer::setBufferData(D3D11_USAGE _usageF, uint32 _size, const void* _data) {
    memset(&m_bd, 0, sizeof(m_bd));
    m_bd.Usage = _usageF;
    m_bd.ByteWidth = _size;
    m_bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bd.CPUAccessFlags = 0;
    m_bd.MiscFlags = 0;
    m_initData.pSysMem = _data; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = 0;
    m_initData.SysMemSlicePitch = 0;
    m_vVertex.clear();
  }

  void amDXVertexBuffer::setSubResourceData(const void* _data, uint32 _sysMemPitch, uint32 _sysMemSlicePitch) {
    m_initData.pSysMem = _data; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = _sysMemPitch;
    m_initData.SysMemSlicePitch = _sysMemSlicePitch;

  }

  void amDXVertexBuffer::setVBSize(uint32 _size) {
    m_numVertex = _size;
    m_vVertex.resize(m_numVertex);
  }

  
}
