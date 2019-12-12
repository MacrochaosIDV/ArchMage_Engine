#pragma once
#include "amPrerequisitesCore.h"
#include "amComponent.h"

namespace amEngineSDK {
  class amCamera;
  class amTransform;

  class amCameraComponent : public amComponent
  {
  public:
    amCameraComponent();
    ~amCameraComponent();

    amTransform* m_transform;
    amCamera* m_pCam;
  };
}
