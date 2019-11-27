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
    setPrimitiveTopology(const uint32 _pt = 
                         amPrimitiveTopology::kPRIMITIVE_TOPOLOGY_TRIANGLELIST);

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
    setCS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB) override;

    virtual void 
    setPS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB) override;

    virtual void 
    setVS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB) override;

    virtual void 
    setPSResources(uint32 _starSlot, 
                   uint32 _nViews, 
                   amShaderResourceView* _SRV) override;


    virtual void 
    clearRenderTargetView(amRenderTargetView* _pRTV, 
                          amVector4* _color) override;

    ID3D11DeviceContext* m_pDC;
  };
}
