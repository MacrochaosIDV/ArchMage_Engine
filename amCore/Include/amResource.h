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
      kTEX_OBJ,
      kCOUNT
    };
  }
  class AM_CORE_EXPORT amResource
  {
  public:
    amResource();
    ~amResource();

    amResourceType::E m_resourceType;
    amResourceBindFlags::E m_resBindFlag;
    void* m_pApiResource;
  };
}
