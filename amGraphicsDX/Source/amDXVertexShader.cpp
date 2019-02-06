#include "amDXVertexShader.h"

#include "amDXDevice.h"
#include "amDXDeviceContext.h"

namespace amEngineSDK {
  amDXVertexShader::amDXVertexShader() {
    m_vs = nullptr;
  }


  amDXVertexShader::~amDXVertexShader() {
    if (m_vs) {
      m_vs->Release();
      m_vs = nullptr;
    }
  }

  void
  amDXVertexShader::createVertexShader(amDXDevice* pDevice) {
    pDevice->m_pDV->CreateVertexShader(m_pblob->GetBufferPointer(),
                                       m_pblob->GetBufferSize(),
                                       nullptr,
                                       &m_vs);
  }

  void
    amDXVertexShader::setShader(amDXDeviceContext * pDC) {
    pDC->m_pDC->VSSetShader(m_vs, nullptr, 0);
  }
}

