#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  namespace amResourceType {
    enum E
    {
      kUNDEF = 0,
      kCONSTANT,
      kIMG,
      kMODEL,
      kSOUND,
      kMATERIAL,
      COUNT
    };
  }
  class AM_CORE_EXPORT amResource
  {
  public:
    amResource();
    ~amResource();

    amResourceType::E m_resourceType;
  };
}
