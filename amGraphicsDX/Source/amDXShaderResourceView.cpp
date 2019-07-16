#include "amDXShaderResourceView.h"
#include "amDXDevice.h"

namespace amEngineSDK {
  amDXShaderResourceView::amDXShaderResourceView() {}

  amDXShaderResourceView::~amDXShaderResourceView() {}

  void 
  amDXShaderResourceView::setDesc(amDXSRV_Types::E _type, amDXFormats::E _format) {
    m_SRV_Desc.ViewDimension = static_cast<D3D11_SRV_DIMENSION>(_type);
    m_SRV_Desc.Format = static_cast<DXGI_FORMAT>(_format);
  }

  void 
  amDXShaderResourceView::createSRV(amDevice* _device, amDXSRV_Types::E _type, amDXFormats::E _format) {
    reinterpret_cast<amDXDevice*>(_device)->createShaderResourceView(this, &_type, &_format);
  }

}
