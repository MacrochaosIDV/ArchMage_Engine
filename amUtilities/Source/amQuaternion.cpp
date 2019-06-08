/******************************************
 * @file amQuaternion.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the quaternion
 *
 *
 * @note
******************************************/
#include "amQuaternion.h"
#include "amMath.h"

namespace amEngineSDK {
  amQuaternion::amQuaternion() {}

  amQuaternion::~amQuaternion() {}

  amQuaternion::amQuaternion(const float& _x, const float _y, const float _z, const float _w) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
  }

  amQuaternion::amQuaternion(const amQuaternion & quat) {
    x = quat.x;
    y = quat.y;
    z = quat.z;
    w = quat.w;
  }

  amQuaternion 
  amQuaternion::operator*(const amQuaternion& other) {
    amQuaternion res;
    res.w = ((w * other.w) - (x * other.x) - (y  * other.y) - (z * other.z));
    res.x = ((w * other.x) + (x * other.w) + (z * other.y) - (y * other.z));
    res.y = ((w * other.y) + (y * other.w) + (x * other.z) - (z * other.x));
    res.z = ((w * other.z) + (z * other.w) + (y * other.x) - (x * other.y));
    return res;
  }

  amQuaternion & 
  amQuaternion::operator*=(const amQuaternion & other) {
    *this = *this * other;
    return *this;
  }

  amQuaternion 
  amEngineSDK::amQuaternion::operator*(const float & f) {
    amQuaternion q = *this;;
    q.w *= f;
    q.x *= f;
    q.y *= f;
    q.z *= f;
    return q;
  }

  float 
  amEngineSDK::amQuaternion::quatDot(const amQuaternion& projectedOn) {
    return (w*projectedOn.w + x * projectedOn.x + y * projectedOn.y
            + z * projectedOn.z);
  }

  amQuaternion 
  amQuaternion::sLerp(amQuaternion& other, float& t) {
    /*amVector3 dif = other.m_vec - m_vec;
    if (dif.isZero())
      return *this;
    dif *= f;
    dif = (dif - (m_vec - m_vec)).getNormalized();
    return *new amQuaternion(dif, w);*/
    if (t <= 0.0f) return *this;
    if (t >= 1.0f) return other;
      float cosOmega = quatDot(other);
    float q1w = other.w;
    float q1x = other.x;
    float q1y = other.y;
    float q1z = other.z;
    if (cosOmega < 0.0f) {
      q1w = -q1w;
      q1x = -q1x;
      q1y = -q1y;
      q1z = -q1z;
      cosOmega = -cosOmega;
    }
    assert(cosOmega < 1.1f);
    float k0, k1;
    if (cosOmega > 0.9999f) {
      k0 = 1.0f-t;
      k1 = t;
    }
    else {
      float sinOmega = sqrt(1.0f - cosOmega * cosOmega);
      float omega = atan2(sinOmega, cosOmega);
      float oneOverSinOmega = 1.0f / sinOmega;
      k0 = sin((1.0f - t) * omega) * oneOverSinOmega;
      k1 = sin(t * omega) * oneOverSinOmega;
    }
    amQuaternion res;
    res.x = k0 * x + k1 * q1x;
    res.y = k0 * y + k1 * q1y;
    res.z = k0 * z + k1 * q1z;
    res.w = k0 * w + k1 * q1w;
    return res;
  }

  amQuaternion & 
  amQuaternion::quatPow(float & exp) {
    if (amMath::abs(w) > 0.9999f) {
      return *this;
    }
    float alpha = acos(w);
    float newAlpha = alpha * exp;
    w = cos(newAlpha);
    float mult = sin(newAlpha) / sin(alpha);
    x *= mult;
    y *= mult;
    z *= mult;
    return *this;
  }
  
  void 
  amQuaternion::rotateAroundX(const float & theta) {
    w = cos(theta*0.5f);
    x = sin(theta*0.5f);
    y = 0;
    z = 0;
  }

  void 
  amQuaternion::rotateAroundY(const float & theta) {
    w = cos(theta*0.5f);
    x = 0;
    y = sin(theta*0.5f);
    z = 0;
  }

  void 
  amQuaternion::rotateAroundZ(const float & theta) {
    w = cos(theta*0.5f);
    x = 0;
    y = sin(theta*0.5f);
    z = 0;
  }

  void 
  amQuaternion::rotateAroundAxis(const amVector3 & axis, const float & theta) {
    w = cos(theta*0.5f);
    float sinHalfTheta = sin(theta*0.5f);
    x = axis.x * sinHalfTheta;
    y = axis.y * sinHalfTheta;
    z = axis.z * sinHalfTheta;
  }

  void 
  amQuaternion::quatNormalize() {}

  float 
  amQuaternion::quatMag() {
    return 0.0f;
  }

  amVector3 
  amQuaternion::getQuatVector() {
    return amVector3();
  }

}
