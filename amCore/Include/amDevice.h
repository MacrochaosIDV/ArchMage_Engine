#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amIndexBuffer;
  class amVertexBuffer;
  class amTexture;
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
                      const int32 =
                        amResourceBindFlags::E::kBIND_INDEX_BUFFER);

    virtual amVertexBuffer*
    createVertexBuffer(amVertexBuffer* _VB,
                       const int32 _RBF =
                         amResourceBindFlags::E::kBIND_VERTEX_BUFFER);

    virtual amConstantBuffer*
    createConstBuffer(amConstantBuffer* _CB,
                      const int32 _RBF =
                        amResourceBindFlags::E::kBIND_CONSTANT_BUFFER);

    virtual amPixelShader*
    createPixelShader(amPixelShader* _PS);

    virtual amVertexShader*
    createVertexShader(amVertexShader* _VS);

    virtual amComputeShader* 
    createComputeShader(amComputeShader* _CS);

    virtual amShaderResourceView*
    createShaderResourceView(amShaderResourceView* _SRV,
                             amTexture* _texResource,
                             const int32 amSRV_type,
                             const int32 _format,
                             const int32 _rbf);

    virtual amDepthStencilView*
    createDepthStencilView(amDepthStencilView* _DSV,
                           const int32 _RBF = 
                             amResourceBindFlags::E::kBIND_DEPTH_STENCIL);

    virtual amRenderTargetView*
    createRenderTargetView(amRenderTargetView* _RTV,
                           const int32 _format,
                           const int32 _rbf);

    virtual amUnorderedAccessResourceView*
    createUnorderedAccessResourceView(amUnorderedAccessResourceView* _UAV,
                                      const int32 _RBF =
                                        amResourceBindFlags::E::kBIND_UNORDERED_ACCESS);

    virtual amTexture*
    createTexture(amTexture* _tex, 
                  const int32 _format,
                  const int32 _rbf);

  };
}
