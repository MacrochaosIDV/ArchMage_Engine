#include "amDXRenderTargetView.h"
#include "amDXTexture.h"

namespace amEngineSDK {
  amDXRenderTargetView::amDXRenderTargetView() {}

  amDXRenderTargetView::amDXRenderTargetView(const uint32 _height, 
                                             const uint32 _width, 
                                             const float _scale) {
    m_rt = new amDXTexture();

    m_rt->resize(static_cast<uint32>(_height * _scale), 
                 static_cast<uint32>(_width * _scale));
  }

  amDXRenderTargetView::~amDXRenderTargetView() {}
}
