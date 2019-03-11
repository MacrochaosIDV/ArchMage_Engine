#include "amDXDevice.h"
namespace amEngineSDK {
  amDXDevice::amDXDevice() {}

  amDXDevice::~amDXDevice() {}

  int32 amDXDevice::CreateIndexBufferDefault(amDXIndexBuffer * pIB) {
    pIB->setBufferData(D3D11_USAGE_DEFAULT);
    return m_pDV->CreateBuffer(&pIB->m_bd, &pIB->m_initData, &pIB->m_pIndexBuffer);
  }

  int32 amDXDevice::CreateConstantBuffer(amDXConstantBuffer * pCB) {
    pCB->createConstBufferDefault();
    return  m_pDV->CreateBuffer(&pCB->m_bd, &pCB->m_subResData, &pCB->m_pCB);
  }

  int32 amDXDevice::CreateVertexBufferDefault(amDXVertexBuffer* pVB) {
    pVB->setBufferData(D3D11_USAGE_DEFAULT);
    return m_pDV->CreateBuffer(&pVB->m_bd, &pVB->m_initData, &pVB->m_pVB);
  }
}



