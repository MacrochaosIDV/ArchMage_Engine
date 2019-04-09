#pragma once
#include "amPrerequisitesCore.h"
#include "amComponent.h"
#include <amMatrix4x4.h>

namespace amEngineSDK {
  class AM_CORE_EXPORT amTransform : public amComponent
  {
  public:
    amTransform();
    ~amTransform();

    amMatrix4x4 m_transform;
  };
}


