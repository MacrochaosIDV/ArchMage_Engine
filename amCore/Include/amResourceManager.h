#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;

  class AM_CORE_EXPORT amResourceManager
  {
  public:
    amResourceManager();
    ~amResourceManager();

    amResource*
    CreateModel(const String& pathName);

    amResource*
    CreateTexture(const String& pathName);

    Vector<amResource*> m_vecResources;
  };
}
