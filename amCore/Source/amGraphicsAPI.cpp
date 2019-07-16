#include "amGraphicsAPI.h"
#include "amRenderTarget.h"

namespace amEngineSDK {
  amGraphicsAPI::amGraphicsAPI() {}


  amGraphicsAPI::~amGraphicsAPI() {}

  void 
  amGraphicsAPI::createVertexBuffer(int64 nVertex, int64 vertexSize) {
    nVertex;
    vertexSize;
  }

  void 
  amGraphicsAPI::Draw(amResource* _pMesh, amMaterial* _pMat, amRenderTarget* _pOutRenderTarget) {
    _pMesh; _pMat; _pOutRenderTarget;
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
  amGraphicsAPI::initScene() {
  
  }

  void 
  amGraphicsAPI::renderResourcesOnCam(amCamera * _cam, amRenderPass * _pass) 
  {
    _cam; _pass;
  }

  void amGraphicsAPI::setRenderTargets(const Vector<amRenderTarget*>& _rt) {
    _rt;
  }

  void 
  amGraphicsAPI::clearRenderTarget() {}

  void 
  amGraphicsAPI::setShaderConstantBuffers(Vector<amResource*> _vecRes, uint32 _shaderFlags) {
    _vecRes;
    _shaderFlags;
  }

  void 
  amGraphicsAPI::Present() {}

  void amGraphicsAPI::setShaders(amVertexShader * _VS, amPixelShader * _PS) {
    _VS; _PS;
  }

}
