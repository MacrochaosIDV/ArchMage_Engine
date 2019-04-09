#include "amRenderManager.h"


namespace amEngineSDK {
  amRenderManager::amRenderManager() {}

  amRenderManager::~amRenderManager() {}
  void amRenderManager::render() {}

  void amRenderManager::setpManagers(amResourceManager * _rm, amCameraManager * _cm) {
    m_camManager = _cm;
    m_resourceManager = _rm;
  }

  Vector<amResource*> amRenderManager::getResourcesOnCam(amCamera* _cam) {
    _cam;
    return Vector<amResource*>();
  }
}

