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
  void amDeviceContext::clearDepthStencilView(amDepthStencilView * _pDSV) {
    _pDSV;
  }

  void amDeviceContext::clearRenderTargetView(amRenderTargetView * _pRTV) {
    _pRTV;
  }

  void amDeviceContext::draw(uint32 nVertex, uint32 startIndex) {
    nVertex; startIndex;
  }

  void amDeviceContext::drawIndexed(uint32 nIndexToDraw, uint32 firstIndex, int32 indexOffsetinVB) {
    nIndexToDraw; firstIndex; indexOffsetinVB;
  }

  void amDeviceContext::setIndexBuffer(amIndexBuffer * _IB) {
    _IB;
  }

  void amDeviceContext::setVertexBuffer(amVertexBuffer * _VB) {
    _VB;
  }

  void amDeviceContext::setConstBuffer(amConstantBuffer * _CB) {
    _CB;
  }

  void amDeviceContext::setPixelShader(amPixelShader * _PS) {
    _PS;
  }

  void amDeviceContext::setVertexShader(amVertexShader * _VS) {
    _VS;
  }
}

