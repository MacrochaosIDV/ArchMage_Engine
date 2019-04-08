#include "amDXInputLayout.h"

#include "amDXDeviceContext.h"

namespace amEngineSDK {
  amDXInputLayout::amDXInputLayout() {}
  

  amDXInputLayout::~amDXInputLayout() {}
  int32 amDXInputLayout::Create(amDXDevice* _pDV, ID3DBlob* _pShaderBlob) {
    _pDV->m_pDV->CreateInputLayout(&m_layout[0], static_cast<uint32>(m_layout.size()), _pShaderBlob->GetBufferPointer(),
                                   _pShaderBlob->GetBufferSize(), &m_pVertexLayout);
    return 0;
  }

  void
  amDXInputLayout::setLayout(amDXDeviceContext * pDC) {
    pDC->m_pDC->IASetInputLayout(m_pVertexLayout);
  }
}
