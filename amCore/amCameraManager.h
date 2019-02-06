#pragma once
#include "amPrerequisitesCore.h"
#include "amCamera.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amCameraManager
  {
  public:
    amCameraManager();
    ~amCameraManager();

    amMatrix4x4 getViewMatrix();

    void camTransition(amCamera* A, amCamera* B, float time);

    Vector<amCamera> m_camVec;
    amCamera* m_activeCam;
    amCamera* m_initialCam;
    amCamera* m_targetCam;
  };
}


