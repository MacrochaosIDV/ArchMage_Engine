#pragma once

#include "amPrerequisitesCore.h"
#include "amMatrix4x4.h"
#include "amFrustrum.h"


namespace amEngineSDK {
  //class amFrustrum;

  class AM_CORE_EXPORT amCamera
  {
  public:
    amCamera();
    amCamera(const amVector3& Pos, const amVector3& Target, const amVector3& Up);
    amCamera(const amVector3& Pos, 
             const amVector3& Target, 
             const amVector3& Up, 
             const float _near, 
             const float _far, 
             const float _fov);
    amCamera(const amCamera& other);
    ~amCamera();

    amCamera&
    operator=(const amCamera& other);

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
    float m_fov;
    float m_near;
    float m_far;
    amVector3 m_position;
    amVector3 m_up;
    amVector3 m_front;
    amVector3 m_right;
    amFrustrum m_clipSpace;
    amMatrix4x4 m_mat;
  };
}
