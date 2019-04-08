#include "amCameraManager.h"
#include "amCamera.h"

namespace amEngineSDK {
  amCameraManager::amCameraManager() {}

  amCameraManager::~amCameraManager() {}
  amMatrix4x4 amCameraManager::getViewMatrix() {
    return m_activeCam->getViewMatrix();
  }
  void amCameraManager::camTransition(amCamera * A, amCamera * B, float time) {
    A;
    B;
    time;
  }
}

