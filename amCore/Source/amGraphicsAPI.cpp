#include "amGraphicsAPI.h"

namespace amEngineSDK {
  amGraphicsAPI::amGraphicsAPI() {}


  amGraphicsAPI::~amGraphicsAPI() {}

  void 
  amGraphicsAPI::createVertexBuffer(int64 nVertex, int64 vertexSize) {
    nVertex;
    vertexSize;
  }

  void 
  amGraphicsAPI::Draw(amIndexBuffer * _IB, amVertexBuffer * _VB) {
    _IB; _VB;
  }

  void 
  amGraphicsAPI::init(void * _wnd) {
    _wnd;
  }

  void 
  amGraphicsAPI::Render() {}

  void 
  amGraphicsAPI::destroy() {}

  void 
  amGraphicsAPI::initContent() {}

  void 
  amGraphicsAPI::initSystems() {}

  void 
  amGraphicsAPI::setManagers() {}

  void 
  amGraphicsAPI::renderResourcesOnCam(amCamera * _cam, amRenderPass * _pass) 
  {
    _cam; _pass;
  }

  void 
  amGraphicsAPI::ClearRenderTarget() {}

  void 
  amGraphicsAPI::Present() {}

}
