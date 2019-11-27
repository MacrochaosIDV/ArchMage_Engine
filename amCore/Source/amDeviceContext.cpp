#include "amDeviceContext.h"
#include "amDepthStencilView.h"
#include "amRenderTargetView.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amConstantBuffer.h"
#include "amPixelShader.h"
#include "amVertexShader.h"

namespace amEngineSDK {
  amDeviceContext::amDeviceContext() {}

  amDeviceContext::~amDeviceContext() {}

  void amDeviceContext::setPrimitiveTopology(const uint32 _pt) {
    _pt;
  }

  void amDeviceContext::setInputLayout(amInputLayout * _il) {
    _il;
  }

  void 
  amDeviceContext::clearDepthStencilView(amDepthStencilView * _pDSV, 
                                         uint32 _clearFlags, 
                                         float _depth, 
                                         uint8 _stencil) {
    _pDSV;
    _clearFlags;
    _depth;
    _stencil;
  }

  void 
  amDeviceContext::clearRenderTargetView(amRenderTargetView * _pRTV, amVector4* _color) {
    _pRTV;
    _color;
  }

  void 
  amDeviceContext::draw(uint32 nVertex, uint32 startIndex) {
    nVertex; startIndex;
  }

  void 
  amDeviceContext::drawIndexed(uint32 nIndexToDraw, uint32 firstIndex, int32 indexOffsetinVB) {
    nIndexToDraw; firstIndex; indexOffsetinVB;
  }

  void 
  amDeviceContext::setIndexBuffer(amIndexBuffer* _IB) {
    _IB;
  }

  void 
  amDeviceContext::setVertexBuffer(amVertexBuffer* _VB, 
                                   const uint32 _stride, 
                                   const uint32 _offset) {
    _VB;
    _stride;
    _offset;
  }

  void 
  amDeviceContext::setConstBuffer(amConstantBuffer* _CB, amShaderType::E _shdr) {
    _CB;
    _shdr;
  }

  void 
  amDeviceContext::setPixelShader(amPixelShader* _PS) {
    _PS;
  }

  void 
  amDeviceContext::setVertexShader(amVertexShader* _VS) {
    _VS;
  }

  void 
  amDeviceContext::setComputeShader(amComputeShader* _CS) {
    _CS;
  }

  void 
  amDeviceContext::setPS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer * _CB) {
    _starSlot;
    _nViews;
    _CB;
  }

  void 
  amDeviceContext::setVS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer * _CB) {
    _starSlot;
    _nViews;
    _CB;
  }

  void 
  amDeviceContext::setCS_CB(uint32 _starSlot, uint32 _nViews, amConstantBuffer * _CB) {
    _starSlot;
    _nViews;
    _CB;
  }

  void
  amDeviceContext::setPSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV) {
    _starSlot;
    _nViews;
    _SRV;
  }

  void 
    amDeviceContext::setVSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV) {
    _starSlot;
    _nViews;
    _SRV;
  }

  void 
    amDeviceContext::setCSResources(uint32 _starSlot, uint32 _nViews, amShaderResourceView* _SRV) {
    _starSlot;
    _nViews;
    _SRV;
  }

  void 
  amDeviceContext::dispatchCS() {}

}
