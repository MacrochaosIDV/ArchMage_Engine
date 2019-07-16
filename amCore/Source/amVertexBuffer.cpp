#include "amVertexBuffer.h"

namespace amEngineSDK {
  amVertexBuffer::amVertexBuffer() {}

  amVertexBuffer::~amVertexBuffer() {}

  uint32 
  amVertexBuffer::getVertSize() {
    return sizeof(amVertex);
  }
}
