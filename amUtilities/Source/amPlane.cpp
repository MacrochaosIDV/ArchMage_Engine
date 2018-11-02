/******************************************
 * @file amPlane.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the plane
 *
 *
 * @note
******************************************/
#include "amPlane.h"

namespace amEngineSDK {
  // ax + by + cz + d = 0
  amPlane::amPlane() {}

  amPlane::~amPlane() {}

  amPlane::amPlane(const amPlane & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    d = other.d;
  }

  amPlane::amPlane(const amVector3 & a, const amVector3 & b, const amVector3 & c) {
    (amVector3)(*this)= ((a - b) ^ (a - c)).getNormalized();
    d = a | (amVector3)(*this);
  }

  amPlane::amPlane(const amTriangle& t) {
    (*this) = *new amPlane(t.m_v0, t.m_v1, t.m_v2);
  }

  amPlane & amPlane::operator=(const amPlane & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    d = other.d;
    return *this;
  }

  amPlane amPlane::operator+(const amPlane & other) const {
    amPlane pl = *this;
    pl.x += other.x;
    pl.y += other.y;
    pl.z += other.z;
    pl.d += other.d;
    return pl;
  }

  amPlane amPlane::operator-(const amPlane & other) const {
    amPlane pl = *this;
    pl.x -= other.x;
    pl.y -= other.y;
    pl.z -= other.z;
    pl.d -= other.d;
    return pl;
  }

  amPlane amPlane::operator*(const amPlane & other) const {
    amPlane pl = *this;
    pl.x *= other.x;
    pl.y *= other.y;
    pl.z *= other.z;
    pl.d *= other.d;
    return pl;
  }

  amPlane amPlane::operator/(const amPlane & other) const {
    amPlane pl = *this;
    pl.x /= other.x;
    pl.y /= other.y;
    pl.z /= other.z;
    pl.d /= other.d;
    return pl;
  }

  amPlane & amPlane::operator+=(const amPlane & other) {
    x += other.x;
    y += other.y;
    z += other.z;
    d += other.d;
    return *this;
  }

  amPlane & amPlane::operator-=(const amPlane & other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    d -= other.d;
    return *this;
  }

  amPlane & amPlane::operator*=(const amPlane & other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    d *= other.d;
    return *this;
  }

  amPlane & amPlane::operator/=(const amPlane & other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    d /= other.d;
    return *this;
  }

  PLANE_TEST::E amPlane::whichSide(const amVector3 & vec) {
    vec;
    return PLANE_TEST::ON_PLANE;
  }

  float amPlane::distanceTo(const amVector3 & vec) {
    amVector3 point;
    return (point - vec).Mag();
  }

  bool amPlane::intersects(const amPlane & other) const {
    if (*this == other) {
      if (d == other.d) {
        return true;
      }
      return false;
    }
    return true;
  }

}


