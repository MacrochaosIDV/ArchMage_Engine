#pragma once
#include "amPrerequisitesCore.h"
#include "amSceneGraph.h"

namespace amEngineSDK {
  class amResourceManager;
  class amCameraManager;
  class amResource;
  class amCamera;
  class amSceneGraph;
  class amRenderPass;
  class amGraphicsAPI;
  class amVertexShader;
  class amPixelShader;
  class amRenderTarget;

  class AM_CORE_EXPORT amRenderManager
  {
  public:
    amRenderManager();
    ~amRenderManager();

    void
    setpManagers(amResourceManager* _rm, amCameraManager* _cm);

    Vector<amResource*>
    getResourcesOnCam(amCamera* _cam);

    void 
    setRenderPass(amRenderPass* _pass);

    virtual int32
    render();

    void 
    setRenderTargets(const Vector<amRenderTarget*>& _rt);

    void
    setScene(amSceneGraph* _scn);

    void 
    initRenderPasses();

    amResourceManager* m_resourceManager;
    amCameraManager* m_camManager;
    amCamera* m_currCam;
    amGraphicsAPI* m_api;
    //Vector<amRenderPass*> m_RenderPasses;
    amRenderPass* m_RP_GBuffer;
    amRenderPass* m_RP_SSAO;
    amRenderPass* m_RP_DownScale;
    amRenderPass* m_RP_BlurH;
    amRenderPass* m_RP_BlurV;
    amRenderPass* m_RP_Luminance;
    amRenderPass* m_RP_Final;
    amSceneGraph* m_currScene;
    ////// Render pass data //////
    // G_Buffer
    // SSAO
    // DownScale
    // BlurH
    // BlurV
    // Transparent things
    // Luminance
    // Final

    // Render order of things 
    // closest to farthest opaques
    // farthest to closest transparent obj
    // ui
  };
}
