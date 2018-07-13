#include "amPlane.h"

namespace amEngineSDK {
  amPlane::amPlane() {}

  amPlane::~amPlane() {}

  amPlane::amPlane(const amPlane & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    d = other.d;
  }

  amPlane::amPlane(const amVector3 & vertex0, const amVector3 & vertex1, const amVector3 & vertex2) {}

  amPlane & amPlane::operator=(const amPlane & other) {
    // TODO: insert return statement here
  }

  amPlane amPlane::operator+(const amPlane & other) {
    amPlane pl = *this;
    pl.x += other.x;
    pl.y += other.y;
    pl.z += other.z;
    pl.d += other.d;
    return pl;
  }

  amPlane amPlane::operator-(const amPlane & other) {
    amPlane pl = *this;
    pl.x -= other.x;
    pl.y -= other.y;
    pl.z -= other.z;
    pl.d -= other.d;
    return pl;
  }

  amPlane amPlane::operator*(const amPlane & other) {
    amPlane pl = *this;
    pl.x *= other.x;
    pl.y *= other.y;
    pl.z *= other.z;
    pl.d *= other.d;
    return pl;
  }

  amPlane amPlane::operator/(const amPlane & other) {
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

  int8 amPlane::whichSide(const amVector3 & vec) {
    return int8();
  }

  float amPlane::distanceTo(const amVector3 & vec) {
    amVector3 point;
    return (point - vec).Mag();
  }

}


