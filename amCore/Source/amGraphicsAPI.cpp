#include "amGraphicsAPI.h"
#include "amRenderTarget.h"
#include "amMesh.h"

namespace amEngineSDK {
  amGraphicsAPI::amGraphicsAPI() {}


  amGraphicsAPI::~amGraphicsAPI() {}

  void 
    amGraphicsAPI::Draw(amMesh* _pMesh) {
    _pMesh;
  }

  void 
  amGraphicsAPI::init(void * _wnd) {
    _wnd;
  }

  void 
  amGraphicsAPI::Update() {}

  void 
  amGraphicsAPI::Run() {}

  void 
  amGraphicsAPI::destroy() {}

  void 
  amGraphicsAPI::initContent() {}

  void 
  amGraphicsAPI::initSystems() {}

  void 
  amGraphicsAPI::setManagers() {}

  void 
  amGraphicsAPI::initScene() {}

  void 
  amGraphicsAPI::renderResourcesOnCam(amCamera * _cam, 
                                      amRenderPass * _pass) {
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
                                    const uint32 _shaderFlags) {
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
  amGraphicsAPI::setRenderPass(amRenderPass* _pass, amDeviceContext* _dc) {
    _pass;
    _dc;
  }

  void 
  amGraphicsAPI::setConstantBuffer(amConstantBuffer * _cb, 
                                   const int32 _shaderFlags) {
    _cb;
    _shaderFlags;
  }

  void 
  amGraphicsAPI::setConstantBuffer(Vector<amConstantBuffer*> _cbVec, 
                                   const int32 _shaderFlags) {
    _cbVec;
    _shaderFlags;
  }

  amModel* 
  amGraphicsAPI::createModel(const String& _pathName, 
                             const uint32 _meshLoadFlags) {
    _pathName;
    _meshLoadFlags;
    return nullptr;
  }
  amShaderResourceView* 
  amGraphicsAPI::loadCubeMap(const String & _pathFileName, 
                             const bool _hdr) {
    _pathFileName;
    _hdr;
    return nullptr;
  }
}
