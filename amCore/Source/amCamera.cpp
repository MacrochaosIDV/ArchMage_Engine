#include "amCamera.h"
//#include "amFrustrum.h"

namespace amEngineSDK {

  amCamera::~amCamera() {}

  amCamera & amCamera::operator=(const amCamera & other) {
    // m_dirty = true;
    m_front = other.m_front;
    m_right = other.m_right;
    m_up = other.m_up;
    m_position = other.m_position;

    m_fov = other.m_fov;
    m_near = other.m_near;
    m_far = other.m_far;

    //m_clipSpace = other.m_clipSpace;
    m_matView = other.m_matView;
    return *this;
  }

  amCamera::amCamera() {}

  amCamera::amCamera(const amVector3& Pos, const amVector3& Dir, const amVector3& Up) {
    m_position = Pos;
    m_front = Dir;
    m_up = Up;
    m_right = m_front ^ m_up;
  }

  amCamera::amCamera(const amCamera & other) {
    m_dirty = true;
    m_front = other.m_front;
    m_right = other.m_right;
    m_up = other.m_up;
    m_position = other.m_position;

    m_fov = other.m_fov;
    m_near = other.m_near;
    m_far = other.m_far;

    //m_clipSpace = other.m_clipSpace;
    m_matView = other.m_matView;
  }

  void amCamera::movePoint(const amVector3& newPos, const amVector3& front, const amVector3& up) {
    m_position = newPos;
    m_front = front;
    m_up = up;
    m_right = m_front ^ m_up;
    m_dirty = true;
  }

  void amCamera::moveFront(float defaz) {
    m_position += m_front * defaz;
    m_dirty = true;
  }
  void amCamera::moveRight(float defaz) {
    m_position += m_right * defaz;
    m_dirty = true;
  }
  void amCamera::moveUp(float defaz) {
    m_position += m_up * defaz;
    m_dirty = true;
  }

  void amCamera::rotate(amVector3 axis, float angle) {
    m_dirty = true;
    angle;
  }

  void amCamera::orbit(amVector3 target, amVector3 angles) {
    m_dirty = true;
    angles;
  }

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
    m_dirty = true;
  }

  void amCamera::update() {
    if (m_dirty)
      m_matView = getViewMatrix();

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


