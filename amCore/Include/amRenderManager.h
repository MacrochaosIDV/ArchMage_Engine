#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResourceManager;
  class amCameraManager;
  class amResource;
  class amCamera;
  class amSceneGraph;

  class AM_CORE_EXPORT amRenderManager
  {
  public:
    amRenderManager();
    ~amRenderManager();

    void 
    render();

    void 
    setpManagers(amResourceManager* _rm, amCameraManager* _cm);

    Vector<amResource*> 
    getResourcesOnCam(amCamera* _cam);

    amResourceManager* m_resourceManager;
    amCameraManager* m_camManager;
    Vector<amSceneGraph*> m_scenes;
    //Render pass data
  };
}


