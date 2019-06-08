#include "amComponent.h"

namespace amEngineSDK {
  amComponent::amComponent() {}

  amComponent::~amComponent() {}

  amResource * 
  amComponent::getResource() {
    return m_resourceComponent;
  }
}
