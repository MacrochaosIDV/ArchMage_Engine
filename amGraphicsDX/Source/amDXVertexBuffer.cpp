#include "amDXVertexBuffer.h"
namespace amEngineSDK {
  void amDXVertexBuffer::setBufferDesc(D3D11_USAGE _usageF, uint32 _bindF, uint32 _cpuF, uint32 _miscF) {
    m_bd.Usage = _usageF;
    m_bd.ByteWidth = m_vertexSize;
    m_bd.BindFlags = _bindF;
    m_bd.CPUAccessFlags = _cpuF;
    m_bd.MiscFlags = _miscF;
    m_vVertex.resize(0);
  }

  void amDXVertexBuffer::setSubResourceData(const void* _data, uint32 _sysMemPitch, uint32 _sysMemSlicePitch) {
    m_initData.pSysMem = _data; // the actual vertex data that goes into the GPU
    m_initData.SysMemPitch = _sysMemPitch;
    m_initData.SysMemSlicePitch = _sysMemSlicePitch;

  }

  void amDXVertexBuffer::setVertexSize(uint32 _size) {
    m_vertexSize = _size;
    m_vVertex.resize(0);
  }

  void amDXVertexBuffer::setVBSize(uint32 _size) {
    m_numVertex = _size;
    m_vVertex.resize(m_numVertex);
  }

  
}
