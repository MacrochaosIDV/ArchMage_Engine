#include "amDXDevice.h"
#include "amVertexShader.h"
#include "amPixelShader.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"
#include "amDXComputeShader.h"
#include "amDXShaderResourceView.h"
#include "amDXTexture.h"

namespace amEngineSDK {
  amDXDevice::amDXDevice() {
    //temp initializing of temp vars
    m_VB = new amDXVertexBuffer();
    m_IB = new amDXIndexBuffer();
  }

  amDXDevice::~amDXDevice() {}

  

  amVertexShader* 
  amDXDevice::createVertexShader(amVertexShader * _pVS) {
    HRESULT h = m_pDV->CreateVertexShader(reinterpret_cast<amDXVertexShader*>(_pVS)->m_blob->GetBufferPointer(),
                                          reinterpret_cast<amDXVertexShader*>(_pVS)->m_blob->GetBufferSize(),
                                          nullptr,
                                          &reinterpret_cast<amDXVertexShader*>(_pVS)->m_vs);
    if(h == S_OK)
      return _pVS;
    return nullptr;
  }

  amPixelShader* 
  amDXDevice::createPixelShader(amPixelShader * _pPS) {
    HRESULT h = m_pDV->CreatePixelShader(reinterpret_cast<amDXPixelShader*>(_pPS)->m_blob->GetBufferPointer(),
                                         reinterpret_cast<amDXPixelShader*>(_pPS)->m_blob->GetBufferSize(),
                                         nullptr,
                                         &reinterpret_cast<amDXPixelShader*>(_pPS)->m_ps);
    if (h == S_OK)
      return _pPS;
    return nullptr;
  }

  amComputeShader* 
  amDXDevice::createComputeShader(amComputeShader * _pCS) {
    HRESULT h = m_pDV->CreateComputeShader(reinterpret_cast<amDXComputeShader*>(_pCS)->m_blob->GetBufferPointer(),
                                           reinterpret_cast<amDXComputeShader*>(_pCS)->m_blob->GetBufferSize(),
                                           nullptr,
                                           &reinterpret_cast<amDXComputeShader*>(_pCS)->m_cs);
    if (h == S_OK)
      return _pCS;
    return nullptr;
  }

  amShaderResourceView* 
    amDXDevice::createShaderResourceView(amShaderResourceView * _pSRV,
                                         void* amSRV_type,
                                         void* _format) {
    //TODO check if RBF is correct on _pSRV->m_texResource for binding as shader resource
    //if(_pSRV->m_texResource->)
    reinterpret_cast<amDXShaderResourceView*>(_pSRV)->setDesc(*reinterpret_cast<amDXSRV_Types::E*>(amSRV_type), 
                                                              *reinterpret_cast<amDXFormats::E*>(_format));
    HRESULT h = m_pDV->CreateShaderResourceView(reinterpret_cast<amDXTexture*>(_pSRV->m_texResource)->m_tex, //texture must have been init'ed with shader resource bind flags
                                                &reinterpret_cast<amDXShaderResourceView*>(_pSRV)->m_SRV_Desc,
                                                &reinterpret_cast<amDXShaderResourceView*>(_pSRV)->m_pSRV);
    if (h == S_OK)
      return _pSRV;
    return nullptr;
  }

  amIndexBuffer*
  amDXDevice::createIndexBuffer(amIndexBuffer* _pIB,
                                amResourceBindFlags::E _RBF) {
    reinterpret_cast<amDXIndexBuffer*>(_pIB)->setBufferData(D3D11_USAGE_DEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&reinterpret_cast<amDXIndexBuffer*>(_pIB)->m_bd,
                        &reinterpret_cast<amDXIndexBuffer*>(_pIB)->m_initData,
                        &reinterpret_cast<amDXIndexBuffer*>(_pIB)->m_pIndexBuffer);
    if (h == S_OK)
      return _pIB;
    return nullptr;
  }

  amConstantBuffer*
  amDXDevice::createConstBuffer(amConstantBuffer* _pCB,
                                     amResourceBindFlags::E _RBF) {
    reinterpret_cast<amDXConstantBuffer*>(_pCB)->setBufferData(D3D11_USAGE_DEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&reinterpret_cast<amDXConstantBuffer*>(_pCB)->m_bd,
                        &reinterpret_cast<amDXConstantBuffer*>(_pCB)->m_subResData,
                        &reinterpret_cast<amDXConstantBuffer*>(_pCB)->m_pCB);
    if (h == S_OK)
      return _pCB;
    return nullptr;
  }

  amVertexBuffer*
  amDXDevice::createVertexBuffer(amVertexBuffer* pVB,
                                   amResourceBindFlags::E _RBF) {
    reinterpret_cast<amDXVertexBuffer*>(pVB)->setBufferData(D3D11_USAGE_DEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&reinterpret_cast<amDXVertexBuffer*>(pVB)->m_bd,
                        &reinterpret_cast<amDXVertexBuffer*>(pVB)->m_initData,
                        &reinterpret_cast<amDXVertexBuffer*>(pVB)->m_pVB);
    if (h == S_OK)
      return pVB;
    return nullptr;
  }

}
