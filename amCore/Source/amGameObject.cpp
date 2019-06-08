#include "amGameObject.h"
#include "amTransform.h"
#include "amVector3.h"

namespace amEngineSDK {
  amGameObject::amGameObject(amSceneNode* _node) {
    m_node = _node;
  }

  amGameObject::~amGameObject() {}

  amVector3 
  amGameObject::getPosition() {
    return m_transform.m_transform.getPosition();
  }

  amComponent * 
  amGameObject::addComponent(amComponent * _comp) {
    if (_comp->m_type == amComponentType::E::kRESOURCE) {
      m_hasResourceComponent = true;
      m_resourceComponent = _comp;
    }
      
    m_vecComponents.push_back(_comp);
    return _comp;
  }

  amResource * 
  amGameObject::getResourceInComp() {
    if (m_resourceComponent) {
      return m_resourceComponent->getResource();
    }
    return nullptr;
  }

}
