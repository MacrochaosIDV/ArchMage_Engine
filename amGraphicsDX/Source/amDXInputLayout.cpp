#include "amDXInputLayout.h"
#include "amDXDeviceContext.h"
#include "amVertexShader.h"
#include "amDXVertexShader.h"

namespace amEngineSDK {
  amDXInputLayout::amDXInputLayout() {}

  amDXInputLayout::~amDXInputLayout() {}

  int32 
  amDXInputLayout::Create(amDXDevice* _pDV, amVertexShader* _pShaderBlob) {
    HRESULT h = _pDV->m_pDV->CreateInputLayout(&m_layout[0], 
                                   static_cast<uint32>(m_layout.size()), 
                                   reinterpret_cast<amDXVertexShader*>(_pShaderBlob)->m_blob->GetBufferPointer(),
                                   reinterpret_cast<amDXVertexShader*>(_pShaderBlob)->m_blob->GetBufferSize(),
                                   &m_pVertexLayout);
    if(h == S_OK)
      return 0;
    return -1;
  }

  void
  amDXInputLayout::setLayout(amDXDeviceContext * pDC) {
    pDC->m_pDC->IASetInputLayout(m_pVertexLayout);
  }

}
