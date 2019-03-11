#pragma once
#include "amPrerequisitesCore.h"
#include <amVector3.h>
#include <amMatrix4x4.h>

namespace amEngineSDK {
  class AM_CORE_EXPORT amCamera
  {
  public:
    amCamera();
    amCamera(const amVector3& Pos, const amVector3& Target, const amVector3& Up);
    ~amCamera();

    void 
    movePoint(const amVector3& newPos, const amVector3& front, const amVector3& up);

    void 
    moveFront(float defaz);

    void 
    moveRight(float defaz);

    void 
    moveUp(float defaz);
      
    void 
    rotate(amVector3 axis, float angle);

    void 
    orbit(amVector3 target, amVector3 angles);

    void 
    yaw(float angle);

    void 
    pitch(float angle);

    void 
    roll(float angle);

    void 
    setPos(amVector3 newPos);

    void 
    update();

    amMatrix4x4 
    getViewMatrix();

    bool m_dirty;
    amVector3 m_position;
    amVector3 m_up;
    amVector3 m_front;
    amVector3 m_right;
    amMatrix4x4 m_matView;
  };
}


