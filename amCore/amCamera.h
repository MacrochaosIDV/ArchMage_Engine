#pragma once
#include "amPrerequisitesCore.h"
#include <amVector3.h>
#include <amMatrix4x4.h>

namespace amEngineSDK {
  class AM_CORE_EXPORT amCamera
  {
  public:
    amCamera() = default;
    amCamera(amVector3 Pos, amVector3 Target, amVector3 Up);
    ~amCamera();

    void moveFront(float defaz);

    void moveRight(float defaz);

    void moveUp(float defaz);
      
    void rotate(amVector3 axis, float angle);

    void orbit(amVector3 target, amVector3 angles);

    void yaw(float angle);

    void pitch(float angle);

    void roll(float angle);

    void setPos(amVector3 newPos);

    amMatrix4x4 getViewMatrix();

    bool m_dirty;
    amVector3 m_position;
    amVector3 m_up;
    amVector3 m_front;
    amVector3 m_right;
    amMatrix4x4 m_matView;
  };
}


