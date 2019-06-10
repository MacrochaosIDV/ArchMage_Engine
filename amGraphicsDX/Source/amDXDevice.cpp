#include "amDXDevice.h"
#include "amVertexShader.h"
#include "amPixelShader.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"
#include "amDXComputeShader.h"

namespace amEngineSDK {
  amDXDevice::amDXDevice() {}

  amDXDevice::~amDXDevice() {}

  int32 
  amDXDevice::CreateIndexBufferDefault(amDXIndexBuffer * pIB) {
    pIB->setBufferData(D3D11_USAGE_DEFAULT);
    return m_pDV->CreateBuffer(&pIB->m_bd, &pIB->m_initData, &pIB->m_pIndexBuffer);
  }

  amVertexShader* 
  amDXDevice::createVertexShader(amVertexShader * _VS) {
    HRESULT h = m_pDV->CreateVertexShader(reinterpret_cast<amDXVertexShader*>(_VS)->m_blob->GetBufferPointer(),
                                          reinterpret_cast<amDXVertexShader*>(_VS)->m_blob->GetBufferSize(),
                                          nullptr,
                                          &reinterpret_cast<amDXVertexShader*>(_VS)->m_vs);
    if(h == S_OK)
      return _VS;
    return nullptr;
  }

  amPixelShader * 
  amDXDevice::createPixelShader(amPixelShader * _PS) {
    HRESULT h = m_pDV->CreatePixelShader(reinterpret_cast<amDXPixelShader*>(_PS)->m_blob->GetBufferPointer(),
                                         reinterpret_cast<amDXPixelShader*>(_PS)->m_blob->GetBufferSize(),
                                         nullptr,
                                         &reinterpret_cast<amDXPixelShader*>(_PS)->m_ps);
    if (h == S_OK)
      return _PS;
    return nullptr;
  }

  amComputeShader * amDXDevice::createComputeShader(amComputeShader * _CS) {
    HRESULT h = m_pDV->CreateComputeShader(reinterpret_cast<amDXComputeShader*>(_CS)->m_blob->GetBufferPointer(),
                                           reinterpret_cast<amDXComputeShader*>(_CS)->m_blob->GetBufferSize(),
                                           nullptr,
                                           &reinterpret_cast<amDXComputeShader*>(_CS)->m_cs);
    if (h == S_OK)
      return _CS;
    return nullptr;
  }

  int32 
  amDXDevice::CreateConstantBuffer(amDXConstantBuffer * pCB) {
    pCB->createConstBufferDefault();
    return  m_pDV->CreateBuffer(&pCB->m_bd, &pCB->m_subResData, &pCB->m_pCB);
  }

  int32 
  amDXDevice::CreateVertexBufferDefault(amDXVertexBuffer* pVB) {
    pVB->setBufferData(D3D11_USAGE_DEFAULT);
    return m_pDV->CreateBuffer(&pVB->m_bd, &pVB->m_initData, &pVB->m_pVB);
  }

}
