#pragma once
#include "amPrerequisitesCore.h"
#include <amMatrix4x4.h>

namespace amEngineSDK {
  class amTransform
  {
  public:
    amTransform();
    ~amTransform();

    amMatrix4x4 m_transform;
  };
}


