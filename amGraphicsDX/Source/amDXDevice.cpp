#include "amDXDevice.h"
#include "amVertexShader.h"
#include "amPixelShader.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"
#include "amDXComputeShader.h"
#include "amDXShaderResourceView.h"
#include "amDXTexture.h"
#include "amDXTextureObject.h"
#include "amRenderTargetView.h"
#include "amRenderTarget.h"

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
                                       amTexture* _texResource,
                                       const int32 amSRV_type,
                                       const int32 _format) {
    //TODO check if RBF is correct on _pSRV->m_texResource for binding as shader resource
    //if(_pSRV->m_texResource->)
    //
    amDXShaderResourceView* _pDXSRV = new amDXShaderResourceView();
    memset(&_pDXSRV->m_SRV_Desc, 0, sizeof(_pDXSRV->m_SRV_Desc));
    _pDXSRV->m_SRV_Desc.Format = static_cast<DXGI_FORMAT>(_format);
    _pDXSRV->m_SRV_Desc.ViewDimension = static_cast<D3D11_SRV_DIMENSION>(amSRV_type);
    _pDXSRV->m_SRV_Desc.Texture2D.MipLevels = 1;
    _pDXSRV->m_SRV_Desc.Texture2D.MostDetailedMip = 0;

    D3D11_SUBRESOURCE_DATA subRes;
    memset(&subRes, 0, sizeof(subRes));
    subRes.pSysMem = &_texResource->m_tBuffer[0];
    subRes.SysMemPitch = 0;
    subRes.SysMemSlicePitch = 0;
    
    D3D11_TEXTURE2D_DESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.Width = _texResource->m_width;
    desc.Height = _texResource->m_height;
    desc.MipLevels = desc.ArraySize = 1;
    desc.Format = static_cast<DXGI_FORMAT>(_format);
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;
    _pSRV = _pDXSRV;

    HRESULT h = m_pDV->CreateTexture2D(&desc,
                                       nullptr,
                                       reinterpret_cast<ID3D11Texture2D**>(
                                         &_texResource->m_apiPtr));

    if (h != S_OK)
      return nullptr;

    h = m_pDV->CreateShaderResourceView(reinterpret_cast<ID3D11Texture2D*>(
                                                  _texResource->m_apiPtr),
                                                &_pDXSRV->m_SRV_Desc,
                                                &_pDXSRV->m_pSRV);

    if (h == S_OK)
      return _pSRV;
    return nullptr;
  }

  amRenderTargetView* 
  amDXDevice::createRenderTargetView(amRenderTargetView * _RTV, amResourceBindFlags::E _RBF) {

    D3D11_SUBRESOURCE_DATA subRes;
    memset(&subRes, 0, sizeof(subRes));
    subRes.pSysMem = &_RTV->m_rt->m_tex->m_tex->m_tBuffer[0];
    subRes.SysMemPitch = 0;
    subRes.SysMemSlicePitch = 0;

    D3D11_TEXTURE2D_DESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.Width = _RTV->m_rt->m_tex->m_tex->m_width;
    desc.Height = _RTV->m_rt->m_tex->m_tex->m_height;
    desc.MipLevels = desc.ArraySize = 1;
    desc.Format = static_cast<DXGI_FORMAT>(_RTV->m_rt->m_tex->m_tex->m_format);
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_RENDER_TARGET || D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    D3D11_RENDER_TARGET_VIEW_DESC rtDesc;
    memset(&rtDesc, 0, sizeof(rtDesc));
    rtDesc.Format = static_cast<DXGI_FORMAT>(_RTV->m_rt->m_tex->m_tex->m_format);

    if (_RTV->m_rt->m_tex->m_tex->m_hrd) {
      rtDesc.ViewDimension = static_cast<D3D11_RTV_DIMENSION>(amSRV_Types::kSRV_TEXTURE2DARRAY);
    }
    else {
      rtDesc.ViewDimension = static_cast<D3D11_RTV_DIMENSION>(amSRV_Types::kSRV_TEXTURE2D);
    }
    rtDesc.Texture2D.MipSlice = 0;

    HRESULT h = m_pDV->CreateTexture2D(&desc,
                                       nullptr,
                                       reinterpret_cast<ID3D11Texture2D**>(
                                       &_RTV->m_rt->m_tex->m_tex->m_apiPtr));

    if (h != S_OK)
      return nullptr;

    HRESULT h = m_pDV->CreateRenderTargetView(reinterpret_cast<ID3D11Texture2D*>(
                                                &_RTV->m_rt->m_tex->m_tex->m_apiPtr), 
                                              &rtDesc, 
                                              reinterpret_cast<ID3D11RenderTargetView**>(
                                                &_RTV->m_ApiPtr));
    if (h == S_OK)
      return _RTV;
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
    reinterpret_cast<amDXConstantBuffer*>(_pCB)->setBufferData(amUsageFlags::E::kDEFAULT, _RBF);
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
