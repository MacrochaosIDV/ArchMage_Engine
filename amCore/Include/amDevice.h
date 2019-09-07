#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amIndexBuffer;
  class amVertexBuffer;
  class amConstantBuffer;
  class amPixelShader;
  class amVertexShader;
  class amComputeShader;
  class amShaderResourceView;
  class amDepthStencilView;
  class amRenderTargetView;
  class amUnorderedAccessResourceView;

  class AM_CORE_EXPORT amDevice
  {
  public:
    amDevice();
    ~amDevice();

    virtual amIndexBuffer*
    createIndexBuffer(amIndexBuffer* _IB,
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_INDEX_BUFFER);

    virtual amVertexBuffer*
    createVertexBuffer(amVertexBuffer* _VB,
                       amResourceBindFlags::E _RBF = 
                         amResourceBindFlags::E::kBINDF_VERTEX_BUFFER);

    virtual amConstantBuffer*
    createConstBuffer(amConstantBuffer* _CB,
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_CONSTANT_BUFFER);

    virtual amPixelShader*
    createPixelShader(amPixelShader* _PS);

    virtual amVertexShader*
    createVertexShader(amVertexShader* _VS);

    virtual amComputeShader* 
    createComputeShader(amComputeShader* _CS);

    virtual amShaderResourceView*
    createShaderResourceView(amShaderResourceView* _SRV,
                             const int32 amSRV_type,
                             const int32 _format,
                             const int32 _rbf);

    virtual amDepthStencilView*
    createDepthStencilView(amDepthStencilView* _DSV,
                           amResourceBindFlags::E _RBF = 
                             amResourceBindFlags::E::kBINDF_DEPTH_STENCIL);

    virtual amRenderTargetView*
    createRenderTargetView(amRenderTargetView* _RTV,
                           amResourceBindFlags::E _RBF = 
                             amResourceBindFlags::E::kBINDF_RENDER_TARGET);

    virtual amUnorderedAccessResourceView*
    createUnorderedAccessResourceView(amUnorderedAccessResourceView* _UAV,
                                      amResourceBindFlags::E _RBF = 
                                        amResourceBindFlags::E::kBINDF_UNORDERED_ACCESS);

  };
}
