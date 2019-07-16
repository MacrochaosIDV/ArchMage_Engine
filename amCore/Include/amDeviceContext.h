#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amDevice;
  class amInputLayout;
  class amIndexBuffer;
  class amPixelShader;
  class amVertexBuffer;
  class amVertexShader;
  class amComputeShader;
  class amConstantBuffer;
  class amDepthStencilView;
  class amRenderTargetView;
  class amShaderResourceView;

  class AM_CORE_EXPORT amDeviceContext
  {
  public:
    amDeviceContext();
    ~amDeviceContext();

    virtual void 
    setPrimitiveTopology(amPrimitiveTopology::E _pt = amPrimitiveTopology::E::PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    virtual void 
    setInputLayout(amInputLayout* _il);

    virtual void
    clearDepthStencilView(amDepthStencilView* _pDSV, uint32 _clearFlags, float _depth, uint8 _stencil);

    virtual void
    clearRenderTargetView(amRenderTargetView* _pRTV, amVector4* _color);

    virtual void
    draw(uint32 nVertex, uint32 startIndex = 0);

    /**
    ************************
    *
    *  @TODO Upgrade to draw indexed instantiated
    *
    ************************
    */

    virtual void 
    drawIndexed(uint32 nIndexToDraw, uint32 firstIndex = 0, int32 indexOffsetinVB = 0);

    virtual void
    setIndexBuffer(amIndexBuffer* _IB);

    virtual void
    setVertexBuffer(amVertexBuffer* _VB, const uint32 _stride, const uint32 _offset);

    virtual void
    setConstBuffer(amConstantBuffer* _CB);

    virtual void
    setPixelShader(amPixelShader* _PS);

    virtual void
    setVertexShader(amVertexShader* _VS);

    virtual void
    setComputeShader(amComputeShader* _CS);

    virtual void 
    setPS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB);

    virtual void
    setVS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB);

    virtual void
    setCS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer* _CB);

    virtual void
    setPSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV);

    virtual void
    setVSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV);

    virtual void
    setCSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV);

    virtual void 
    dispatchCS();


  };
}
