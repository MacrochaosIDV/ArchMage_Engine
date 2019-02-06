#include "amCameraManager.h"


namespace amEngineSDK {
  amCameraManager::amCameraManager() {}

  amCameraManager::~amCameraManager() {}
  amMatrix4x4 amCameraManager::getViewMatrix() {
    return m_activeCam->getViewMatrix();
  }
  void amCameraManager::camTransition(amCamera * A, amCamera * B, float time) {}
}

