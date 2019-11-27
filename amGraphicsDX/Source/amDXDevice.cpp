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
#include "amDXRenderTargetView.h"
#include "amDXDepthStencilView.h"
#include "amRenderTarget.h"

namespace amEngineSDK {
  amDXDevice::amDXDevice() {}

  amDXDevice::~amDXDevice() {}

  amVertexShader* 
  amDXDevice::createVertexShader(amVertexShader * _pVS) {
    amDXVertexShader* dxVS = reinterpret_cast<amDXVertexShader*>(_pVS);

    HRESULT h = m_pDV->CreateVertexShader(dxVS->m_blob->GetBufferPointer(),
                                          dxVS->m_blob->GetBufferSize(),
                                          nullptr,
                                          &dxVS->m_vs);
    if(h == S_OK)
      return _pVS;
    return nullptr;
  }

  amPixelShader* 
  amDXDevice::createPixelShader(amPixelShader * _pPS) {
    amDXPixelShader* dxPS = reinterpret_cast<amDXPixelShader*>(_pPS);

    HRESULT h = m_pDV->CreatePixelShader(dxPS->m_blob->GetBufferPointer(),
                                         dxPS->m_blob->GetBufferSize(),
                                         nullptr,
                                         &dxPS->m_ps);
    if (h == S_OK)
      return _pPS;
    return nullptr;
  }

  amComputeShader* 
  amDXDevice::createComputeShader(amComputeShader * _pCS) {
    amDXComputeShader* dxCS = reinterpret_cast<amDXComputeShader*>(_pCS);

    HRESULT h = m_pDV->CreateComputeShader(dxCS->m_blob->GetBufferPointer(),
                                           dxCS->m_blob->GetBufferSize(),
                                           nullptr,
                                           &dxCS->m_cs);
    if (h == S_OK)
      return _pCS;
    return nullptr;
  }

  amShaderResourceView* 
  amDXDevice::createShaderResourceView(amShaderResourceView * _pSRV,
                                       amTexture* _texResource,
                                       const int32 amSRV_type,
                                       const int32 _format, 
                                       const int32 _rbf) {

    amDXTexture* texDX = reinterpret_cast<amDXTexture*>(_texResource);

    _texResource = createTexture(_texResource, _format, _rbf);
    
    amDXShaderResourceView* _pDXSRV = new amDXShaderResourceView();

    memset(&_pDXSRV->m_SRV_Desc, 0, sizeof(_pDXSRV->m_SRV_Desc));
    _pDXSRV->m_SRV_Desc.Format = static_cast<DXGI_FORMAT>(_format);
    _pDXSRV->m_SRV_Desc.ViewDimension = static_cast<D3D11_SRV_DIMENSION>(amSRV_type);
    _pDXSRV->m_SRV_Desc.Texture2D.MipLevels = 1;
    _pDXSRV->m_SRV_Desc.Texture2D.MostDetailedMip = 0;

    HRESULT h = m_pDV->CreateShaderResourceView(texDX->m_tex,
                                        &_pDXSRV->m_SRV_Desc,
                                        &_pDXSRV->m_pSRV);

    if (h == S_OK)
      return _pSRV;
    return nullptr;
  }

  amRenderTargetView* 
  amDXDevice::createRenderTargetView(amRenderTargetView * _RTV, 
                                     const int32 _format, 
                                     const int32 _rbf) {

    amDXRenderTargetView* dxRTV = reinterpret_cast<amDXRenderTargetView*>(_RTV);
    
    createTexture(_RTV->m_rt, _format, _rbf);

    amDXTexture* dxTex = reinterpret_cast<amDXTexture*>(_RTV->m_rt);

    //D3D11_RENDER_TARGET_VIEW_DESC rtDesc;
    memset(&dxRTV->m_desc, 0, sizeof(dxRTV->m_desc));
    dxRTV->m_desc.Format = static_cast<DXGI_FORMAT>(_format);

    if (_RTV->m_rt->m_hrd) {
      dxRTV->m_desc.ViewDimension = static_cast<D3D11_RTV_DIMENSION>(amSRV_Types::kSRV_TEXTURE2DARRAY);
    }
    else {
      dxRTV->m_desc.ViewDimension = static_cast<D3D11_RTV_DIMENSION>(amSRV_Types::kSRV_TEXTURE2D);
    }
    dxRTV->m_desc.Texture2D.MipSlice = 0;


    HRESULT h = m_pDV->CreateRenderTargetView(dxTex->m_tex,
                                              &dxRTV->m_desc,
                                              &dxRTV->m_pRTV);
    if (h == S_OK)
      return _RTV;
    return nullptr;
  }

  amTexture* 
  amDXDevice::createTexture(amTexture * _tex, 
                            const int32 _format,
                            const int32 _rbf) {
    amDXTexture* dxTex = reinterpret_cast<amDXTexture*>(_tex);

    D3D11_SUBRESOURCE_DATA subRes;
    memset(&subRes, 0, sizeof(subRes));
    dxTex->m_subRes.pSysMem = &_tex->m_tBuffer[0];

    //Set the ID3D11_TEXTURE2D_DESC
    memset(&dxTex->m_desc, 0, sizeof(dxTex->m_desc));
    dxTex->m_desc.Width = _tex->m_width;
    dxTex->m_desc.Height = _tex->m_height;
    dxTex->m_desc.MipLevels = dxTex->m_desc.ArraySize = 1;
    dxTex->m_desc.Format = static_cast<DXGI_FORMAT>(_format);
    dxTex->m_desc.SampleDesc.Count = 1;
    dxTex->m_desc.SampleDesc.Quality = 0;
    dxTex->m_desc.Usage = D3D11_USAGE_DEFAULT;
    dxTex->m_desc.BindFlags = static_cast<D3D11_BIND_FLAG>(_rbf);
    dxTex->m_desc.CPUAccessFlags = 0;
    dxTex->m_desc.MiscFlags = 0;

    HRESULT h = m_pDV->CreateTexture2D(&dxTex->m_desc, nullptr, &dxTex->m_tex);

    if (h != S_OK)
      return nullptr;
    return _tex;
  }

  amDepthStencilView* 
  amDXDevice::createDepthStencilView(amDepthStencilView * _DSV, 
                                     const int32 _RBF, 
                                     const int32 _format) {
    amDXDepthStencilView* dxDS = reinterpret_cast<amDXDepthStencilView*>(_DSV);
    amDXTexture* dxTex = reinterpret_cast<amDXTexture*>(_DSV->m_tex);

    createTexture(dxTex, _format, _RBF);
    

    memset(&dxDS->m_desc, 0, sizeof(dxDS->m_desc));
    dxDS->m_desc.Format = static_cast<DXGI_FORMAT>(_format);
    dxDS->m_desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    dxDS->m_desc.Flags = 0;
    dxDS->m_desc.Texture2D.MipSlice = 0;

    HRESULT h = m_pDV->CreateDepthStencilView(dxTex->m_tex, 
                                              &dxDS->m_desc, 
                                              &dxDS->m_pDSV);
    if (h != S_OK)
      return nullptr;
    return dxDS;
  }

  /**
  ************************
  * @TODO: The buffers for cleaner code
  ************************
  */
  amIndexBuffer*
  amDXDevice::createIndexBuffer(amIndexBuffer* _pIB,
                                const int32 _RBF) {
    amDXIndexBuffer* dxIB = reinterpret_cast<amDXIndexBuffer*>(_pIB);
    dxIB->setBufferData(D3D11_USAGE_DEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&dxIB->m_bd, 
                                    &dxIB->m_initData, 
                                    &dxIB->m_pIndexBuffer);
    if (h == S_OK)
      return _pIB;
    return nullptr;
  }

  amConstantBuffer*
  amDXDevice::createConstBuffer(amConstantBuffer* _pCB,
                                const int32 _RBF) {
    amDXConstantBuffer* dxCB = reinterpret_cast<amDXConstantBuffer*>(_pCB);
    dxCB->setBufferData(amUsageFlags::E::kDEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&dxCB->m_bd,
                                    &dxCB->m_subResData,
                                    &dxCB->m_pCB);
    if (h == S_OK)
      return _pCB;
    return nullptr;
  }

  amVertexBuffer*
  amDXDevice::createVertexBuffer(amVertexBuffer* pVB,
                                 const int32 _RBF) {
    amDXVertexBuffer* dxVB = reinterpret_cast<amDXVertexBuffer*>(pVB);
    dxVB->setBufferData(D3D11_USAGE_DEFAULT, _RBF);
    HRESULT h = m_pDV->CreateBuffer(&dxVB->m_bd,
                                    &dxVB->m_initData,
                                    &dxVB->m_pVB);
    if (h == S_OK)
      return pVB;
    return nullptr;
  }

}
