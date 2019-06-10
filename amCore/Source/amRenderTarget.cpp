#include "amRenderTarget.h"

namespace amEngineSDK {
  amRenderTarget::amRenderTarget() {}

  amRenderTarget::~amRenderTarget() {}

  void 
  amRenderTarget::resize(const uint32 _height, const uint32 _width) {
    uint32 size = _height * _width;
    if (size != m_RTBuffer.size()) {
      m_RTBuffer.resize(size);
    }
  }

}
