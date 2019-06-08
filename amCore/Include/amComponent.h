#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;

  namespace amComponentType {
    enum E
    {
      kEMPTY = 0,
      kTRANSFORM,
      kRESOURCE,
      kCAMERA,
      COUNT
    };
  }
  class AM_CORE_EXPORT amComponent
  {
  public:
    amComponent();
    ~amComponent();

    amResource* 
    getResource();

    bool m_hasRenderableResource;
    amResource* m_resourceComponent;
    amComponentType::E m_type;
  };
}
