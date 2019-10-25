#include "amGraphicsAPI.h"
#include "amRenderTarget.h"
#include "amMesh.h"

namespace amEngineSDK {
  amGraphicsAPI::amGraphicsAPI() {}


  amGraphicsAPI::~amGraphicsAPI() {}

  void 
  amGraphicsAPI::createVertexBuffer(const int64 nVertex, 
                                    const  int64 vertexSize) {
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

  /*amShaderResourceView* 
  amGraphicsAPI::createTextureShaderResourceV(const String & _pathName,
                                              const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }

  amShaderResourceView*
  amGraphicsAPI::loadTexture(const String & _pathName, 
                             const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }

  amRenderTargetView* 
  amGraphicsAPI::createRenderTargetV(const uint32 _height, 
                                     const uint32 _width,
                                     const amFormats::E _format,
                                     const float _scale) {
    _height;
    _width;
    _format;
    _scale;
    return nullptr;
  }

  amTexture* 
  amGraphicsAPI::createTexture(const uint32 _height, 
                               const uint32 _width, 
                               const amFormats::E _format) {
    _height;
    _width;
    _format;
    return nullptr;
  }

  amTexture* 
  amGraphicsAPI::createTexture(const String& _pathName, 
                               const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }*/

  amModel* 
  amGraphicsAPI::CreateModel(const String& _pathName, 
                             const uint32 _meshLoadFlags) {
    _pathName;
    _meshLoadFlags;
    return nullptr;
  }

  /*amDepthStencilView* 
  amGraphicsAPI::createDepthStencilV(const uint32 _height,
                                     const uint32 _width,
                                     const amFormats::E _format) {
    _height;
    _width;
    _format;
    return nullptr;
  }

  amMaterial* 
  amGraphicsAPI::CreateMaterial(amTextureObject * _tex, 
                                const String & _matName) {
    _tex;
    _matName;
    return nullptr;
  }

  amMaterial* 
  amGraphicsAPI::CreateMaterial(Vector<amTextureObject*>& _texVec, 
                                const String & _matName) {
    _texVec;
    _matName;
    return nullptr;
  }
  amMaterial* 
  amGraphicsAPI::CreateMaterial(const String & _pathName, uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }*/
}
