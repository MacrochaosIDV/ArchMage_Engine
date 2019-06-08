#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amDevice;
  class amIndexBuffer;
  class amVertexBuffer;
  class amConstantBuffer;
  class amPixelShader;
  class amVertexShader;
  class amDepthStencilView;
  class amRenderTargetView;

  class AM_CORE_EXPORT amDeviceContext
  {
  public:
    amDeviceContext();
    ~amDeviceContext();

    

    virtual void
    clearDepthStencilView(amDepthStencilView* _pDSV);

    virtual void
    clearRenderTargetView(amRenderTargetView* _pRTV);

    virtual void
    draw(uint32 nVertex, uint32 startIndex = 0);

    /**
    ************************
    *
    *  @brief Draws Vertexes by index
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
    setVertexBuffer(amVertexBuffer* _VB);

    virtual void
    setConstBuffer(amConstantBuffer* _CB);

    virtual void
    setPixelShader(amPixelShader* _PS);

    virtual void
    setVertexShader(amVertexShader* _VS);
  };
}
