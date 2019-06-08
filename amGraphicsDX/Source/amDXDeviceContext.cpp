#include "amDXDeviceContext.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"


namespace amEngineSDK {
  amDXDeviceContext::amDXDeviceContext() {}

  amDXDeviceContext::~amDXDeviceContext() {}

  void
  amDXDeviceContext::setPixelShader(amPixelShader * _PS) {
    m_pDC->PSSetShader(reinterpret_cast<amDXPixelShader*>(_PS)->m_ps, nullptr, 0);
  }

  void 
  amDXDeviceContext::setVertexShader(amVertexShader * _VS) {
    m_pDC->VSSetShader(reinterpret_cast<amDXVertexShader*>(_VS)->m_vs, nullptr, 0);
  }

}
