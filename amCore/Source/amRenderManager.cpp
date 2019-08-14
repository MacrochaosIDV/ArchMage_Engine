#include "amRenderManager.h"
#include "amGraphicsAPI.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  amRenderManager::amRenderManager() {
    
  }

  amRenderManager::~amRenderManager() {}

  int32 
  amRenderManager::render() {
    m_api->clearRenderTarget();
    // Get geometry to draw
    Vector<amResource*> objsCam = m_currScene->getAllResourcesInCam(m_currCam);
    uint32 objsCamSize = static_cast<uint32>(objsCam.size());
    // Render all objects in cam
    // TODO: upgrade to have this render in stages accounting for textures with tranparencies
    for (uint32 i = 0; i < objsCamSize; ++i) {
      // TODO: make a way to get the materials along their meshes
      //m_api->Draw(objsCam[i],,);

    }
    m_api->Present();
    return 0;
  }

  void 
  amRenderManager::setRenderTargets(const Vector<amRenderTarget*>& _rt) {
    _rt;
  }

  void 
  amRenderManager::setScene(amSceneGraph* _scn) {
      m_currScene = _scn;
  }

  void amRenderManager::initRenderPasses() {
    m_RP_GBuffer->setShaders("PS_PBR.hlsl", "VS_GBuffer.hlsl");
    m_RP_GBuffer->compileShaders();
    m_RP_SSAO->setShaders("PS_SSAO.hlsl", "VS_Generic.hlsl");
    m_RP_SSAO->compileShaders();
    m_RP_DownScale->setShaders("PS_Bloom.hlsl", "VS_Generic.hlsl");
    m_RP_DownScale->compileShaders();
    m_RP_BlurH->setShaders("PS_Kernels.hlsl", "VS_Generic.hlsl");
    m_RP_BlurH->compileShaders();
    m_RP_BlurV->setShaders("PS_Kernels.hlsl", "VS_Generic.hlsl");
    m_RP_BlurV->compileShaders();
    m_RP_Luminance->setShaders("PS_Luminance.hlsl", "VS_Generic.hlsl");
    m_RP_Luminance->compileShaders();
    m_RP_Final->setShaders("PS_Lighting.hlsl", "VS_Generic.hlsl");
    m_RP_Final->compileShaders();
  }

  void 
  amRenderManager::setpManagers(amResourceManager * _rm, amCameraManager * _cm) {
    m_camManager = _cm;
    m_resourceManager = _rm;
  }

  Vector<amResource*> 
  amRenderManager::getResourcesOnCam(amCamera* _cam) {
    return m_currScene->getAllResourcesInCam(_cam);
  }

  void 
  amRenderManager::setRenderPass(amRenderPass * _pass) {
    m_api->setShaders(_pass);
  }
}
