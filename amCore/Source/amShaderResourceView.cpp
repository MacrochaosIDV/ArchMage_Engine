#include "amShaderResourceView.h"
#include "amTexture.h"
#include "amDevice.h"


namespace amEngineSDK {
  amShaderResourceView::amShaderResourceView() {}

  amShaderResourceView::~amShaderResourceView() {}

  void 
  amShaderResourceView::createSRV(amTexture * _tex, amDevice * _device) {
    _tex; _device;
  }

  void 
  amShaderResourceView::resize(const uint32 _height, const uint32 _width) {
    m_texResource->resize(_height, _width);
  }
}
