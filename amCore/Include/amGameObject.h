#pragma once
#include "amPrerequisitesCore.h"
#include "amTransform.h"

namespace amEngineSDK {
  class amSceneNode;
  class amVector3;
  class amResource;

  class amGameObject
  {
  public:
    amGameObject(amSceneNode* _node);
    ~amGameObject();

    amVector3 
    getPosition();

    amComponent*
    addComponent(amComponent* _comp);

    amResource* 
    getResourceInComp();

    bool m_hasResourceComponent;
    amComponent* m_resourceComponent;
    amSceneNode* m_node;
    amTransform m_transform;
    Vector<amComponent*> m_vecComponents;
  };
}
