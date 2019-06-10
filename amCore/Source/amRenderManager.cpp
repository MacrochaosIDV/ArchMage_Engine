#include "amRenderManager.h"
#include "amGraphicsAPI.h"

namespace amEngineSDK {
  amRenderManager::amRenderManager() {
    
  }

  amRenderManager::~amRenderManager() {}

  int32 
  amRenderManager::render() {
    m_api->ClearRenderTarget();

    // Get geometry to draw
    Vector<amResource*> objsCam = m_currScene->getAllResourcesInCam(m_currCam);
    uint32 objsCamSize = objsCam.size();
    // Render all objs in cam
    // TODO: upgrade to have this render in stages accounting for textures with tranparencies
    for (uint32 i = 0; i < objsCamSize; ++i) {
      m_api->Draw(objsCam[i], ,);
    }
    

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
