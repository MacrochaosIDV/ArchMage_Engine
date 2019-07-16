#include "amSceneManager.h"
#include "amSceneGraph.h"
#include "amSceneNode.h"

namespace amEngineSDK {
  amSceneManager::amSceneManager() {}

  amSceneManager::~amSceneManager() {}

  void
  amSceneManager::setScene(uint32 _index) {
    if (_index < m_scenes.size()) {
      m_currScene = m_scenes[_index];
      if (m_currScene->m_pRoot)
        m_sceneRoot = m_currScene->m_pRoot;
    }
  }

  void amSceneManager::setScene(amSceneGraph * _scn) {
    m_currScene = _scn;
    if (m_currScene->m_pRoot)
      m_sceneRoot = m_currScene->m_pRoot;
  }

  void
  amSceneManager::addScene(amSceneGraph * _scn) {
    m_scenes.push_back(_scn);
  }

  void 
  amSceneManager::addNode(amSceneNode* _parentNode, amGameObject* _obj) {
    if (!_parentNode)
      m_currScene->m_pRoot->addEmpty();
    else if (_parentNode && _obj)
      _parentNode->addChild(_obj);
    else
      _parentNode->addChild(_parentNode);
  }

  void amSceneManager::concatScene(amSceneNode * _scn) {
    m_currScene->m_pRoot->addChildren(_scn->getAllChildren());
  }

  void amSceneManager::concatScene(const Vector<amSceneNode*>& _scnV) {
    uint32 size = static_cast<uint32>(_scnV.size());
    for (uint32 i = 0; i < size; ++i) {
      m_currScene->m_pRoot->addChildren(_scnV[i]->getAllChildren());
    }
  }
}
