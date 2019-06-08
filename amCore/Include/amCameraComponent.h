#pragma once
#include "amPrerequisitesCore.h"
#include "amComponent.h"

namespace amEngineSDK {
  class amCamera;
  class amCameraComponent : public amComponent
  {
  public:
    amCameraComponent();
    ~amCameraComponent();

    amCamera* m_pCam;
  };
}
