#include "amDevice.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amConstantBuffer.h"
#include "amPixelShader.h"
#include "amVertexShader.h"
#include "amTexture.h"

namespace amEngineSDK {
  amDevice::amDevice() {}

  amDevice::~amDevice() {}
  amIndexBuffer* 
  amDevice::createIndexBuffer(amIndexBuffer* _IB,
                              const int32 _RBF) {
    _RBF;
    _IB;
    return nullptr;
  }

  amVertexBuffer* 
  amDevice::createVertexBuffer(amVertexBuffer * _VB,
                               const int32 _RBF) {
    _RBF;
    _VB;
    return nullptr;
  }

  amConstantBuffer* 
  amDevice::createConstBuffer(amConstantBuffer * _CB,
                              const int32 _RBF) {
    _RBF;
    _CB;
    return nullptr;
  }

  amPixelShader* 
  amDevice::createPixelShader(amPixelShader * _PS) {
    _PS;
    return nullptr;
  }

  amVertexShader* 
  amDevice::createVertexShader(amVertexShader * _VS) {
    _VS;
    return nullptr;
  }

  amComputeShader* 
  amDevice::createComputeShader(amComputeShader * _CS) {
    _CS;
    return nullptr;
  }

  amShaderResourceView* 
    amDevice::createShaderResourceView(amShaderResourceView * _SRV,
                                       amTexture* _texResource,
                                       const int32 amSRV_type,
                                       const int32 _format,
                                       const int32 _rbf) {
    _rbf;
    _texResource;
    _SRV;
    amSRV_type;
    _format;
    return nullptr;
  }

  amDepthStencilView* 
  amDevice::createDepthStencilView(amDepthStencilView * _DSV,
                                   const int32 _RBF,
                                   const int32 _format) {
    _format;
    _RBF;
    _DSV;
    return nullptr;
  }

  amRenderTargetView* 
  amDevice::createRenderTargetView(amRenderTargetView * _RTV,
                                   const int32 _format,
                                   const int32 _rbf) {
    _rbf;
    _format;
    _RTV;
    return nullptr;
  }

  amUnorderedAccessResourceView* 
  amDevice::createUnorderedAccessResourceView(amUnorderedAccessResourceView * _UAV,
                                              const int32 _RBF) {
    _RBF;
    _UAV;
    return nullptr;
  }

  amTexture* 
  amDevice::createTexture(amTexture * _tex, 
                          const int32 _format,
                          const int32 _rbf) {
    _rbf;
    _tex;
    _format;
    return nullptr;
  }

  amTexture* 
  amDevice::createCubeMap(amTexture * _tex, 
                          const int32 _format, 
                          const int32 _rbf) {
    return nullptr;
  }
 
}
