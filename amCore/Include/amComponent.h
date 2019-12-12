#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amGameObject;

  namespace amComponentType {
    enum E
    {
      kEMPTY = 0,
      kTRANSFORM,
      kRESOURCE,
      kCAMERA,
      kSCRIPT,
      kLIGHT,
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

    void
    setGameObj(amGameObject* _obj);

    virtual void 
    onAddComp();

    virtual void 
    onRemoveComp();

    virtual void 
    onMoveComp();

    bool m_hasRenderableResource;
    amResource* m_resourceComponent;
    amGameObject* m_obj;
    amComponentType::E m_type;
  };
}
