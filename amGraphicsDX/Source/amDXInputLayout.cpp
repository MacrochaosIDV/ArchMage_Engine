#include "amDXInputLayout.h"
#include "amDXDeviceContext.h"
#include "amVertexShader.h"
#include "amDXVertexShader.h"

namespace amEngineSDK {
  amDXInputLayout::amDXInputLayout() {
    m_shaderLayout = amShaderInputLayout::E::kGBUFFER;
  }

  amDXInputLayout::amDXInputLayout(amShaderInputLayout::E _layout) {
    m_shaderLayout = _layout;
  }

  amDXInputLayout::~amDXInputLayout() {}

  int32 
  amDXInputLayout::Create(amDXDevice* _pDV, amVertexShader* _pShaderBlob) {
    HRESULT h = _pDV->m_pDV->CreateInputLayout(&m_layout[0], 
                                   static_cast<uint32>(m_layout.size()), 
                                   reinterpret_cast<amDXVertexShader*>(_pShaderBlob)->m_blob->GetBufferPointer(),
                                   reinterpret_cast<amDXVertexShader*>(_pShaderBlob)->m_blob->GetBufferSize(),
                                   &m_pInputLayout);
    if(h == S_OK)
      return 0;
    return -1;
  }

  void
  amDXInputLayout::setLayout(amDXDeviceContext * pDC) {
    pDC->m_pDC->IASetInputLayout(m_pInputLayout);
  }

  void amDXInputLayout::init() {
    if (m_shaderLayout == amShaderInputLayout::E::kDEFFERRED) 
      m_layout =
      {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
      };
    else if (m_shaderLayout == amShaderInputLayout::E::kGBUFFER)
      m_layout = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"TANGENT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 36, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 48, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };
  }
}
