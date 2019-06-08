#include "amRenderManager.h"
#include "amGraphicsAPI.h"

namespace amEngineSDK {
  amRenderManager::amRenderManager() {}

  amRenderManager::~amRenderManager() {}

  int32 
  amRenderManager::render() {
    //TODO: add to Render() so that it accesses the data to render from inside itself or change Render() so it accepts the data to render
    m_api->ClearRenderTarget();



    m_api->Present();
    return 0;
  }

  void 
  amRenderManager::setScene(int32 _index) {
    if (_index < m_scenes.size()) {
      m_currScene = m_scenes[_index];
    }
  }

  void 
  amRenderManager::setpManagers(amResourceManager * _rm, amCameraManager * _cm) {
    m_camManager = _cm;
    m_resourceManager = _rm;
  }

  Vector<amResource*> 
  amRenderManager::getResourcesOnCam(amCamera* _cam) {
    return m_currScene->getAllResourcesInCam(_cam);
  }

  void 
  amRenderManager::addScene(amSceneGraph * _scn) {
    m_scenes.push_back(_scn);
  }

}
