#pragma once
#include "amPrerequisitesCore.h"
#include "amTransform.h"

namespace amEngineSDK {
  class amSceneNode;
  class amVector3;

  class amGameObject
  {
  public:
    amGameObject(amSceneNode* _node);
    ~amGameObject();

    amVector3 
    getPosition();

    amSceneNode* m_node;
    amTransform m_transform;
  };
}


