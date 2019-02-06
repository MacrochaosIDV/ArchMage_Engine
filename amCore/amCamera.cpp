#include "amCamera.h"

namespace amEngineSDK {

  amCamera::amCamera(amVector3 Pos, amVector3 Dir, amVector3 Up) {}

  amCamera::~amCamera() {}

  void amCamera::moveFront(float defaz) {
    m_position += m_front * defaz;
  }
  void amCamera::moveRight(float defaz) {
    m_position += m_right * defaz;
  }
  void amCamera::moveUp(float defaz) {
    m_position += m_up * defaz;
  }

  void amCamera::rotate(amVector3 axis, float angle) {}

  void amCamera::orbit(amVector3 target, amVector3 angles) {}

  void amCamera::yaw(float angle) {
    rotate(m_up, angle);
  }

  void amCamera::pitch(float angle) {
    rotate(m_right, angle);
  }

  void amCamera::roll(float angle) {
    rotate(m_front, angle);
  }

  void amCamera::setPos(amVector3 newPos) {
    m_position = newPos;
  }

  amMatrix4x4 amCamera::getViewMatrix() {
    if (m_dirty) {
      m_matView = {m_right.x,           m_up.x,            m_front.x,             0,
                   m_right.y,           m_up.y,            m_front.y,             0,
                   m_right.z,           m_up.z,            m_front.z,             1,
                   m_right | m_position, m_up | m_position, m_front | m_position, 0};
      return m_matView;
    }
    return m_matView;
  }
}


