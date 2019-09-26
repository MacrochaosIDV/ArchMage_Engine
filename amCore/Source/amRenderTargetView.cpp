#include "amRenderTargetView.h"
#include "amRenderTarget.h"

namespace amEngineSDK {
  amRenderTargetView::amRenderTargetView() {}

  amRenderTargetView::~amRenderTargetView() {}
  void amRenderTargetView::resize(const uint32 _height, const uint32 _width) {
    m_rt->resize(_height, _width);
  }
}
