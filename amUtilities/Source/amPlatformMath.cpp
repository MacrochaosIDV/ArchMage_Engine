/******************************************
 * @file amPlatformMath.cpp
 * @date 2018/09/20
 *
 * @author Andrés Sumano Hernandez
 * Contact: user@company.com
 *
 * @brief 
 *
 * TODO: long description
 *
 * @note
******************************************/
#include "amPlatformMath.h"

#include "amAABB.h"
#include "amCapsule.h"
#include "amFrustrum.h"
#include "amOOBB.h"
#include "amPlane.h"
#include "amRay.h"
#include "amSphere.h"
#include "amTriangle.h"
#include "amVector3.h"

namespace amEngineSDK {
  
    //static const float PI;      // = std::tan(1) * 4;
    //static const float HALFPI;  // = std::tan(1) * 2;
    //static const float TWOPI;   // = std::tan(1) * 8;
    //static const float RAD2DEG; // = 57.29577951;
    //static const float DEG2RAD; // = 0.017453292519;
    const float amPLatformMath::HALFPI = std::tanf(1.0f) * 2.0f;
    const float amPLatformMath::PI = std::tanf(1.0f) * 4.0f;
    const float amPLatformMath::TWOPI = std::tanf(1.0f) * 8.0f;
    const float amPLatformMath::RAD2DEG = 180.0f / PI;
    const float amPLatformMath::DEG2RAD = PI / 180.0f;
                                
    ////* Implementations *////

    
    /***********************
    *
    *  Collisions
    *
    ***********************/

    /***********************
    *
    *  Vector3 collisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amFrustrum &f) {
      if ((vec | f.m_near) < 0)
        if ((vec | f.m_far) < 0)
          if ((vec | f.m_right) < 0)
            if ((vec | f.m_left) < 0)
              if ((vec | f.m_top) < 0)
                if ((vec | f.m_bottom) < 0)
                  return true;
      return false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amCapsule &c) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amTriangle &t) {
      if (intersects(vec, *new amPlane(t))) {
        //if sum of angles == 2PI true
            return true;
          return false;
      }
      return false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amSphere &s) {
      return ((vec - s.m_center).Mag() < s.m_radius) ? true : false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amOOBB &o) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amVector3 & vec, const amAABB &a) {
      if (vec.x >= a.m_pMin.x && vec.y >= a.m_pMin.y && vec.z >= a.m_pMin.z)
        if (vec.x <= a.m_pMax.x && vec.y <= a.m_pMax.y && vec.z <= a.m_pMax.z)
          return true;
      return false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amPlane &p) {
      return((vec | p) <= -0.0001f || (vec | p) >= 0.0001) ? true : false;
    }

    bool
    amPLatformMath::intersects(const amVector3 &vec, const amRay &r) {
      return((vec - r.m_pos).getNormalized() == r.m_dir.getNormalized()) ? true : false;
    }

    /***********************
    *
    *  Frustrum collisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amCapsule &c) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amTriangle &t) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amSphere &s) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amOOBB &o) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amAABB &a) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amPlane &p) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amFrustrum &f, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  Capsule collisions
    *
    ***********************/
    bool
    amPLatformMath::intersects(const amCapsule &c, const amTriangle &t) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amCapsule &c, const amSphere &s) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amCapsule &c, const amOOBB &o) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amCapsule &c, const amAABB &a) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amCapsule &c, const amPlane &p) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amCapsule &c, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  Triangle coliisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amTriangle &t, const amSphere &s) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amTriangle &t, const amOOBB &o) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amTriangle &t, const amAABB &a) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amTriangle &t, const amPlane &p) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amTriangle &t, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  Sphere collisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amSphere &s, const amOOBB &o) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amSphere &s, const amAABB &a) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amSphere &s, const amPlane &p) {
      return ((s.m_center | p) <= (s.m_radius)) ? true : false;
    }

    bool
    amPLatformMath::intersects(const amSphere &s, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  OOBB collisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amOOBB &o, const amAABB &a) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amOOBB &o, const amPlane &p) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amOOBB &o, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  AABB collisions
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amAABB &a, const amPlane &p) {
      return false;
    }

    bool
    amPLatformMath::intersects(const amAABB &a, const amRay &r) {
      return false;
    }

    /***********************
    *
    *  Plane <---> Ray collision
    *
    ***********************/

    bool
    amPLatformMath::intersects(const amPlane &p, const amRay &r, float dist) {
      if ((r.m_dir | p) == 0.f)
        return false;
      /***********************
      *
      *  TODO: calculate dist
      *
      ***********************/
      return true;
    }

    bool
    amPLatformMath::intersects(const amPlane &p, const amRay &r) {
      return ((r.m_dir | p) <= 0.f) ? false : true;
    }
}