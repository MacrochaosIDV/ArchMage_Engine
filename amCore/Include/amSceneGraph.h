#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amCameraManager;
  class amResourceManager;
  class amCamera;
  class amSceneNode;

  class AM_CORE_EXPORT amSceneGraph
  {
  public:
    amSceneGraph();
    ~amSceneGraph();

    Vector<amResource*>
    getAllResourcesInCam(amCamera* _cam);


    amSceneNode* m_pRoot;
    amResourceManager* m_pResourceManager;
    amCameraManager* m_pCamManager;
    Vector<amResource*> m_pSceneResources;
  };
}
