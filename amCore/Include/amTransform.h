#pragma once
#include "amPrerequisitesCore.h"
#include "amComponent.h"

namespace amEngineSDK {
  class amVector3;
  class amGameObject;

  class AM_CORE_EXPORT amTransform : public amComponent
  {
  public:
    amTransform();
    ~amTransform();

    amGameObject* m_obj;
    amTransform* m_parentTransform;
    amTransform* m_childTransform;
    amVector3 m_position;
    amVector3 m_rotation;
    amVector3 m_scale;
    bool b_globalTransform;
    //amMatrix4x4 m_transform;
  };
}
