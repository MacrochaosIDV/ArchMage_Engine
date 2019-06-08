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
    addScene(amSceneGraph* _scn);

    virtual int32 
    render();

    void 
    setScene(int32 _index);

    amResourceManager* m_resourceManager;
    amCameraManager* m_camManager;
    amGraphicsAPI* m_api;
    Vector<amRenderPass*> m_RenderPasses;
    Vector<amSceneGraph*> m_scenes;
    amSceneGraph* m_currScene;
    //Render pass data
  };
}


