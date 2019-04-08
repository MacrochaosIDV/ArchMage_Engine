#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amTexture : public amResource
  {
  public:
    amTexture();
    ~amTexture();

    Vector<char> m_tBuffer;
    String m_fileName;
  };
}
