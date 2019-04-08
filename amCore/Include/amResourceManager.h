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

    //Map<amResource*, String> m_mapResource;
    Vector<amResource*> m_vecResources;
  };
}


