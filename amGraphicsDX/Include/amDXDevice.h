/**
***********************************************
 * @file amDXDevice.h
 * @date 2018/10/31
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief 
 *
 * TODO: long description
 *
 * @note
***********************************************
*/
#pragma once
#include "amDXPreReqs.h"
#include <amDevice.h>
#include "amDXVertexBuffer.h"
#include "amDXIndexBuffer.h"
#include "amDXConstantBuffer.h"

namespace amEngineSDK {
  class amVertexShader;
  class amPixelShader;
  class amComputeShader;
  class amShaderResourceView;
  class amRenderTargetView;
  class amRenderTarget;

  class amDXDevice : public amDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    virtual amConstantBuffer*
    createConstBuffer(amConstantBuffer* _pCB,
                      const int32 _RBF =
                        amResourceBindFlags::E::kBIND_CONSTANT_BUFFER) override;

    virtual amVertexBuffer*
    createVertexBuffer(amVertexBuffer* _pVB,
                       const int32 _RBF =
                         amResourceBindFlags::E::kBIND_VERTEX_BUFFER) override;

    virtual amIndexBuffer*
    createIndexBuffer(amIndexBuffer* _pIB,
                      const int32 =
                        amResourceBindFlags::E::kBIND_INDEX_BUFFER) override;

    virtual amVertexShader*
    createVertexShader(amVertexShader* _pVS) override;

    virtual amPixelShader*
    createPixelShader(amPixelShader* _pPS) override;

    virtual amComputeShader* 
    createComputeShader(amComputeShader* _pCS) override;

    virtual amShaderResourceView* 
    createShaderResourceView(amShaderResourceView* _SRV,
                             amTexture* _texResource,
                             const int32 amSRV_type,
                             const int32 _format, 
                             const int32 _rbf) override;

    virtual amShaderResourceView* 
    createCubeShaderResourceView(amShaderResourceView* _SRV, 
                                 amTexture* _texResource, 
                                 const int32 amSRV_type, 
                                 const int32 _format, 
                                 const int32 _rbf) override;

    virtual amRenderTargetView* 
    createRenderTargetView(amRenderTargetView* _RTV, 
                           const int32 _format,
                           const int32 _rbf) override;

    virtual amTexture*
    createTexture(amTexture* _tex, 
                  const int32 _format, 
                  const int32 _rbf) override;

    virtual amDepthStencilView*
    createDepthStencilView(amDepthStencilView* _DSV,
                           const int32 _RBF = amResourceBindFlags::kBIND_DEPTH_STENCIL,
                           const int32 _format = amFormats::kFORMAT_D24_UNORM_S8_UINT);

    virtual amTexture*
    createTextureArray(amTexture* _tex,
                       const int32 _format,
                       const int32 _rbf,
                       const uint32 _arrSize) override;

    ID3D11Device* m_pDV;
  };
}
