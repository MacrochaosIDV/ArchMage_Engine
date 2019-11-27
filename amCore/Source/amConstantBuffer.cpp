#include "amConstantBuffer.h"

namespace amEngineSDK {
  amConstantBuffer::amConstantBuffer() {
    m_resourceType = amResourceType::kCONSTANT;
  }

  amConstantBuffer::~amConstantBuffer() {}

  void 
  amConstantBuffer::setBuffer(void * _data, const uint32 _dataSize) {
    m_size = _dataSize;
    m_pCBuffer = _data;
  }
}
