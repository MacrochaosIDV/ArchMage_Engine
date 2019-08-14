#include "amDXShaderResourceView.h"
#include "amDXDevice.h"

namespace amEngineSDK {
  amDXShaderResourceView::amDXShaderResourceView() {}

  amDXShaderResourceView::~amDXShaderResourceView() {}

  void 
  amDXShaderResourceView::setDesc(const int32 _type, const int32 _format) {
    m_SRV_Desc.ViewDimension = static_cast<D3D11_SRV_DIMENSION>(_type);
    //TODO: make an automatic format detect depending on texture type
    m_SRV_Desc.Format = static_cast<DXGI_FORMAT>(_format);
    //m_SRV_Desc.Texture2D
  }

  void 
  amDXShaderResourceView::createSRV(amDevice* _device, 
                                    const int32 _type, 
                                    const int32 _format) {
    reinterpret_cast<amDXDevice*>(_device)->createShaderResourceView(this, _type, _format);
  }
}
