#include "amGameObject.h"
#include "amTransform.h"
#include "amVector3.h"

namespace amEngineSDK {
  amGameObject::amGameObject(amSceneNode* _node) {
    m_node = _node;
  }

  amGameObject::~amGameObject() {}

  amVector3 amGameObject::getPosition() {
    return m_transform.m_transform.getPosition();
  }

}


