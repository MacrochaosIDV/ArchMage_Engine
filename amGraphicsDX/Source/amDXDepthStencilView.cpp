#include "amDXDepthStencilView.h"
#include "amDXTexture.h"

namespace amEngineSDK {
  amDXDepthStencilView::amDXDepthStencilView() {}

  amDXDepthStencilView::amDXDepthStencilView(const uint32 _height, 
                                             const uint32 _width, 
                                             const float _scale) {
    m_tex = new amDXTexture();
    m_tex->resize(static_cast<uint32>(_height * _scale), 
                  static_cast<uint32>(_width * _scale));
  }

  amDXDepthStencilView::~amDXDepthStencilView() {}
}
