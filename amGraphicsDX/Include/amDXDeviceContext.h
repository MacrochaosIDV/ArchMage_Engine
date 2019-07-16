#pragma once
#include "amDXPreReqs.h"
#include "amDeviceContext.h"

namespace amEngineSDK {
  class amDXDeviceContext : public amDeviceContext
  {
  public:
    amDXDeviceContext();
    ~amDXDeviceContext();

    virtual void 
    setPrimitiveTopology(amPrimitiveTopology::E _pt = amPrimitiveTopology::E::PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    virtual void 
    setInputLayout(amInputLayout* _il) override;

    virtual void 
    setVertexBuffer(amVertexBuffer* _VB,
                    const uint32 _stride,
                    const uint32 _offset) override;

    virtual void 
    setIndexBuffer(amIndexBuffer* _IB) override;

    virtual void
    setPixelShader(amPixelShader* _PS) override;

    virtual void
    setVertexShader(amVertexShader* _VS) override;

    virtual void 
    setComputeShader(amComputeShader* _CS) override;

    virtual void 
    clearDepthStencilView(amDepthStencilView* _pDSV,
                          uint32 _clearFlags,
                          float _depth,
                          uint8 _stencil) override;

    virtual void 
    clearRenderTargetView(amRenderTargetView* _pRTV, amVector4* _color) override;

    ID3D11DeviceContext* m_pDC;
  };
}
