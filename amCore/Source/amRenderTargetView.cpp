#include "amRenderTargetView.h"
#include "amRenderTarget.h"

namespace amEngineSDK {
  amRenderTargetView::amRenderTargetView(const uint32 _height, 
                                         const uint32 _width,
                                         const float _scale) {
    m_rt = new amRenderTarget(static_cast<uint32>(_height * _scale), 
                              static_cast<uint32>(_width * _scale));
  }
  amRenderTargetView::amRenderTargetView() {}

  amRenderTargetView::~amRenderTargetView() {}
  void amRenderTargetView::resize(const uint32 _height, const uint32 _width) {
    m_rt->resize(_height, _width);
  }
}
