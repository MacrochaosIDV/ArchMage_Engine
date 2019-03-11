#include "amDXPixelShader.h"

#include "amDXDevice.h"
#include "amDXDeviceContext.h"

namespace amEngineSDK {
  amDXPixelShader::amDXPixelShader() {
    m_ps = nullptr;
  }

  amDXPixelShader::~amDXPixelShader() {
    if (m_ps) {
      m_ps->Release();
      m_ps = nullptr;
    }
  }

  void
  amDXPixelShader::createPixelShader(amDXDevice* pDevice) {
    pDevice->m_pDV->CreatePixelShader(m_pblob->GetBufferPointer(),
                                      m_pblob->GetBufferSize(),
                                      nullptr,
                                      &m_ps);
  }

  void
  amDXPixelShader::setShader(amDXDeviceContext * pDC) {
    pDC->m_pDC->PSSetShader(m_ps, nullptr, 0);
  }
  void amDXPixelShader::createPS(const char* pathFileName, amDXDevice * pDevice) {
    CompileShaderFromFile(pathFileName, "PS", "ps_5_0", &m_pblob);
    createPixelShader(pDevice);
  }
}

