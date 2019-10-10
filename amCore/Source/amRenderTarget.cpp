#include "amRenderTarget.h"
#include "amTextureObject.h"

namespace amEngineSDK {
  amRenderTarget::amRenderTarget(const uint32 _height, const uint32 _width) {
    m_height = _height;
    m_width = _width;
  }

  amRenderTarget::amRenderTarget() {}

  amRenderTarget::~amRenderTarget() {}

  void 
  amRenderTarget::resize(const uint32 _height, const uint32 _width) {
    m_height = _height;
    m_width = _width;
    m_tex->resize(_height, _width);
  }
}
