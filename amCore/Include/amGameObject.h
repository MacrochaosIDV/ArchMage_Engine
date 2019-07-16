#pragma once
#include "amPrerequisitesCore.h"
#include "amTransform.h"

namespace amEngineSDK {
  class amSceneNode;
  class amVector3;
  class amResource;
  class amMaterial;

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

    amMaterial*
    getMat();

    Vector<amMaterial*>
    getAllMats();

    bool m_hasResourceComponent;
    uint32 m_nMaterials;
    amComponent* m_resourceComponent;
    amSceneNode* m_pNode;
    amTransform m_transform;
    Vector<amComponent*> m_vecComponents;
    amMaterial* m_pCompMat;
    Vector<amMaterial*> m_vecpCompMats;
  };
}
