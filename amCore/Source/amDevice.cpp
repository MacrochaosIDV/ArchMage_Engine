#include "amDevice.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amConstantBuffer.h"
#include "amPixelShader.h"
#include "amVertexShader.h"

namespace amEngineSDK {
  amDevice::amDevice() {}

  amDevice::~amDevice() {}
  amIndexBuffer * 
  amDevice::createIndexBuffer(amIndexBuffer* _IB) {
    _IB;
    return nullptr;
  }

  amVertexBuffer * 
  amDevice::createVertexBuffer(amVertexBuffer * _VB) {
    _VB;
    return nullptr;
  }

  amConstantBuffer * 
  amDevice::createConstBuffer(amConstantBuffer * _CB) {
    _CB;
    return nullptr;
  }

  amPixelShader * 
  amDevice::createPixelShader(amPixelShader * _PS) {
    _PS;
    return nullptr;
  }

  amVertexShader * 
  amDevice::createVertexShader(amVertexShader * _VS) {
    _VS;
    return nullptr;
  }

  amComputeShader * 
  amDevice::createComputeShader(amComputeShader * _CS) {
    _CS;
    return nullptr;
  }
}
