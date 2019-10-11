#include "amRenderTargetView.h"
#include "amTexture.h"

namespace amEngineSDK {
  amRenderTargetView::amRenderTargetView(const uint32 _height, 
                                         const uint32 _width,
                                         const float _scale) {
    _height;
    _width;
    _scale;
  }
  amRenderTargetView::amRenderTargetView() {}

  amRenderTargetView::~amRenderTargetView() {}

  void 
  amRenderTargetView::resize(const uint32 _height, const uint32 _width) {
    m_rt->resize(_height, _width);
  }
}
