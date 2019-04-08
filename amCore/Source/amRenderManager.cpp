#include "amRenderManager.h"


namespace amEngineSDK {
  amRenderManager::amRenderManager() {}

  amRenderManager::~amRenderManager() {}
  void amRenderManager::render() {}
  Vector<amResource*> amRenderManager::getResourcesOnCam(amCamera* _cam) {
    _cam;
    return Vector<amResource*>();
  }
}

