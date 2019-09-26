#include "amGraphicsAPI.h"
#include "amRenderTarget.h"
#include "amMesh.h"

namespace amEngineSDK {
  amGraphicsAPI::amGraphicsAPI() {}


  amGraphicsAPI::~amGraphicsAPI() {}

  void 
  amGraphicsAPI::createVertexBuffer(int64 nVertex, int64 vertexSize) {
    nVertex;
    vertexSize;
  }

  void 
  amGraphicsAPI::Draw(amMesh* _pMesh,
                      amRenderTarget* _pOutRenderTarget,
                      amMaterial* _pMat) {
    _pMesh; _pMat; _pOutRenderTarget;
  }

  void 
  amGraphicsAPI::init(void * _wnd) {
    _wnd;
  }

  void 
  amGraphicsAPI::Update() {}

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
  amGraphicsAPI::renderResourcesOnCam(amCamera * _cam, 
                                      amRenderPass * _pass) 
  {
    _cam; _pass;
  }

  void 
  amGraphicsAPI::setRenderTargets(const Vector<amRenderTarget*>& _rt) {
    _rt;
  }

  void 
  amGraphicsAPI::clearRenderTargets() {}

  void 
  amGraphicsAPI::setShaderResources(Vector<amResource*> _vecRes, 
                                    uint32 _shaderFlags) {
    _vecRes;
    _shaderFlags;
  }

  void 
  amGraphicsAPI::Present() {}

  void 
  amGraphicsAPI::setShaders(amVertexShader * _VS, 
                            amPixelShader * _PS) {
    _VS; _PS;
  }

  void 
  amGraphicsAPI::setShaders(amRenderPass* _pass) {
    _pass;
  }

  void 
  amGraphicsAPI::setConstantBuffer(amConstantBuffer * _cb, 
                                   int32 _shaderFlags) {
    _cb;
    _shaderFlags;
  }

  void 
  amGraphicsAPI::setConstantBuffer(Vector<amConstantBuffer*> _cbVec, 
                                   int32 _shaderFlags) {
    _cbVec;
    _shaderFlags;
  }
}
