#include "amDepthStencilView.h"
#include "amTexture.h"

namespace amEngineSDK {
  amDepthStencilView::amDepthStencilView() {}

  amDepthStencilView::~amDepthStencilView() {}
  void 
  amDepthStencilView::resize(const uint32 _height, 
                             const uint32 _width) {
    m_tex->resize(_height, _width);
  }
}
