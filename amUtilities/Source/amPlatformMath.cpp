/******************************************
 * @file amPlatformMath.cpp
 * @date 2018/09/20
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements collisions between all 3D shapes & sets constants
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
  
    const float amPlatformMath::HALFPI = std::tanf(1.0f) * 2.0f;
    const float amPlatformMath::PI = std::tanf(1.0f) * 4.0f;
    const float amPlatformMath::TWOPI = std::tanf(1.0f) * 8.0f;
    const float amPlatformMath::RAD2DEG = 180.0f / PI;
    const float amPlatformMath::DEG2RAD = PI / 180.0f;
                                
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
    amPlatformMath::intersects(const amVector3 &vec, const amFrustrum &f) {
      if ((vec | f.m_planes[FRUSTRUM_PLANES::NEAR]) < 0)
        if ((vec | f.m_planes[FRUSTRUM_PLANES::FAR]) < 0)
          if ((vec | f.m_planes[FRUSTRUM_PLANES::RIGHT]) < 0)
            if ((vec | f.m_planes[FRUSTRUM_PLANES::LEFT]) < 0)
              if ((vec | f.m_planes[FRUSTRUM_PLANES::TOP]) < 0)
                if ((vec | f.m_planes[FRUSTRUM_PLANES::BOTTOM]) < 0)
                  return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amCapsule &c) {
      c;
      vec;
      return false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amTriangle &t) {
      if (intersects(vec, *new amPlane(t))) {
        float anglSum = ((vec - t.m_v0) % (vec - t.m_v1)) +
                        ((vec - t.m_v0) % (vec - t.m_v1)) +
                        ((vec - t.m_v0) % (vec - t.m_v2));
        if(anglSum == TWOPI - 0.001f || anglSum == TWOPI + 0.001f)
            return true;
          return false;
      }
      return false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amSphere &s) {
      return ((vec - s.m_center).Mag() < s.m_radius) ? true : false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amOOBB &o) {
      o;
      vec;
      return false;
    }

    bool
    amPlatformMath::intersects(const amVector3 & vec, const amAABB &a) {
      if (vec.x >= a.m_pMin.x && vec.y >= a.m_pMin.y && vec.z >= a.m_pMin.z)
        if (vec.x <= a.m_pMax.x && vec.y <= a.m_pMax.y && vec.z <= a.m_pMax.z)
          return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amPlane &p) {
      return((vec | p) <= -0.0001f || (vec | p) >= 0.0001) ? true : false;
    }

    bool
    amPlatformMath::intersects(const amVector3 &vec, const amRay &r) {
      return((vec - r.m_pos).getNormalized() == r.m_dir.getNormalized()) ? true : false;
    }

    /***********************
    *
    *  Frustrum collisions
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amCapsule &c) {
      f;
      c;
      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amTriangle &t) {
      if (intersects(t.m_v0, f)) {
        return true;
      }
      if (intersects(t.m_v1, f)) {
        return true;
      }
      if (intersects(t.m_v2, f)) {
        return true;
      }
      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amSphere &s) {
      if (intersects(s.m_center, f)) {
        return true;
      }
      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amOOBB &o) {
      f;
      o;
      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amAABB &a) {
      if (intersects(a.m_pMin, f)) 
        return true;
      if (intersects(a.m_pMax, f)) 
        return true;
      if (intersects(amVector3(a.m_pMin.x, a.m_pMin.y, a.m_pMax.z), f)) 
        return true;
      if (intersects(amVector3(a.m_pMin.x, a.m_pMax.y, a.m_pMax.z), f)) 
        return true;
      if (intersects(amVector3(a.m_pMax.x, a.m_pMin.y, a.m_pMax.z), f)) 
        return true;
      if (intersects(amVector3(a.m_pMax.x, a.m_pMax.y, a.m_pMin.z), f)) 
        return true;  
      if (intersects(amVector3(a.m_pMin.x, a.m_pMax.y, a.m_pMin.z), f)) 
        return true;
      if (intersects(amVector3(a.m_pMax.x, a.m_pMax.y, a.m_pMin.z), f)) 
        return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amPlane &p) {
      for (auto& plane : f.m_planes) {
        if (plane.intersects(p)) {
          return true;
        }
      }

      return false;
    }

    bool
    amPlatformMath::intersects(const amFrustrum &f, const amRay &r) {
      if (intersects(r.m_pos, f))
        return true;
      return false;
    }

    /***********************
    *
    *  Capsule collisions
    *
    ***********************/
    bool
    amPlatformMath::intersects(const amCapsule &c, const amTriangle &t) {
      c;
      t;
      return false;
    }

    bool
    amPlatformMath::intersects(const amCapsule &c, const amSphere &s) {
      c;
      s;
      return false;
    }

    bool
    amPlatformMath::intersects(const amCapsule &c, const amOOBB &o) {
      c;
      o;
      return false;
    }

    bool
    amPlatformMath::intersects(const amCapsule &c, const amAABB &a) {
      c;
      a;
      return false;
    }

    bool
    amPlatformMath::intersects(const amCapsule &c, const amPlane &p) {
      c;
      p;
      return false;
    }

    bool
    amPlatformMath::intersects(const amCapsule &c, const amRay &r) {
      c;
      r;
      return false;
    }

    /***********************
    *
    *  Triangle collisions
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amTriangle &t, const amSphere &s) {
      if (intersects(t.m_v0, s))
        return true;
      if (intersects(t.m_v1, s))
        return true;
      if (intersects(t.m_v2, s))
        return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amTriangle &t, const amOOBB &o) {
      t; 
      o;
      return false;
    }

    bool
    amPlatformMath::intersects(const amTriangle &t, const amAABB &a) {
      if (intersects(t.m_v0, a))
        return true;
      if (intersects(t.m_v1, a))
        return true;
      if (intersects(t.m_v2, a))
        return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amTriangle &t, const amPlane &p) {
      t;
      p;
      return false;
    }

    bool
    amPlatformMath::intersects(const amTriangle &t, const amRay &r) {
      t;
      r;
      return false;
    }

    /***********************
    *
    *  Sphere collisions
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amSphere &s, const amOOBB &o) {
      s;
      o;
      return false;
    }

    bool
    amPlatformMath::intersects(const amSphere &s, const amAABB &a) {
      if (intersects(s.m_center, a))
        return true;
      return false;
    }

    bool
    amPlatformMath::intersects(const amSphere &s, const amPlane &p) {
      return ((s.m_center | p) <= (s.m_radius)) ? true : false;
    }

    bool
    amPlatformMath::intersects(const amSphere &s, const amRay &r) {
      s;
      r;
      return false;
    }

    /***********************
    *
    *  OOBB collisions
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amOOBB &o, const amAABB &a) {
      o;
      a;
      return false;
    }

    bool
    amPlatformMath::intersects(const amOOBB &o, const amPlane &p) {
      o;
      p;
      return false;
    }

    bool
    amPlatformMath::intersects(const amOOBB &o, const amRay &r) {
      o;
      r;
      return false;
    }

    /***********************
    *
    *  AABB collisions
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amAABB &a, const amPlane &p) {
      a;
      p;
      return false;
    }

    bool
    amPlatformMath::intersects(const amAABB &a, const amRay &r) {
      a;
      r;
      return false;
    }

    /***********************
    *
    *  Plane <---> Ray collision
    *
    ***********************/

    bool
    amPlatformMath::intersects(const amPlane &p, const amRay &r, float dist) {
      if ((r.m_dir | p) == 0.f)
        return false;
      /***********************
      *
      *  TODO: calculate dist
      *
      ***********************/
      dist;
      return true;
    }

    bool
    amPlatformMath::intersects(const amPlane &p, const amRay &r) {
      return ((r.m_dir | p) <= 0.f) ? false : true;
    }
}
