#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amViewPort
  {
  public:
    amViewPort();
    ~amViewPort();

    uint32 m_height;
    uint32 m_width;
    float m_nearP;
    float m_farP;
  };
}
