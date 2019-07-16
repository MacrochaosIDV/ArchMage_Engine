#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amSceneGraph;
  class amSceneNode;
  class amGameObject;

  class amSceneManager
  {
  public:
    amSceneManager();
    ~amSceneManager();

    void 
    setScene(uint32 _index);

    void
    setScene(amSceneGraph * _scn);

    void
    addScene(amSceneGraph* _scn);

    void 
    addNode(amSceneNode* _parentNode = nullptr, amGameObject* _obj = nullptr);

    void 
    concatScene(amSceneNode* _scn);

    void
    concatScene(const Vector<amSceneNode*>& _scnV);

    Vector<amSceneGraph*> m_scenes;
    amSceneGraph* m_currScene;
    amSceneNode* m_sceneRoot;
  };
}
