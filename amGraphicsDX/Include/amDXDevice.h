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
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_CONSTANT_BUFFER) override;

    virtual amVertexBuffer*
    createVertexBuffer(amVertexBuffer* _pVB,
                       amResourceBindFlags::E _RBF = 
                         amResourceBindFlags::E::kBINDF_VERTEX_BUFFER) override;

    virtual amIndexBuffer*
    createIndexBuffer(amIndexBuffer* _pIB,
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_INDEX_BUFFER) override;

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
                             const int32 _format) override;

    virtual amRenderTargetView* 
    createRenderTargetView(amRenderTargetView* _RTV, 
                           amResourceBindFlags::E _RBF = 
                             amResourceBindFlags::E::kBINDF_RENDER_TARGET) override;

    virtual amTexture*
    createTexture(amTexture* _tex, amFormats::E _format) override;

    ID3D11Device* m_pDV;
  };
}
