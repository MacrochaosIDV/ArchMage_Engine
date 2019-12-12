#include "amComponent.h"
#include "amGameObject.h"

namespace amEngineSDK {
  amComponent::amComponent() {}

  amComponent::~amComponent() {}

  amResource* 
  amComponent::getResource() {
    if (m_resourceComponent)
      return m_resourceComponent;
    return nullptr;
  }

  void 
  amComponent::setGameObj(amGameObject* _obj) {
    m_obj = _obj;
    _obj->addComponent(this);
  }

  void
  amComponent::onAddComp() {
  
  }

  void
  amComponent::onRemoveComp() {
  
  }

  void 
  amComponent::onMoveComp() {
  
  }
}
