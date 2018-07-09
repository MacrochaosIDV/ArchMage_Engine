#include "amQuaternion.h"

namespace amEngineSDK {
  amQuaternion::amQuaternion() {}


  amQuaternion::~amQuaternion() {}

  amQuaternion::amQuaternion(const amVector3 & vec, const float _w) {
    m_vec = vec;
    w = _w;
  }

  amQuaternion::amQuaternion(const amQuaternion & quat) {
    m_vec = quat.m_vec;
    w = quat.w;
  }

  amQuaternion amQuaternion::operator*(const amQuaternion& other) {
    amQuaternion res;
    res.w = ((w * other.w) - (m_vec.x * other.m_vec.x) - (m_vec.y  * other.y) - (m_vec.z * other.z));
    res.m_vec.x = ((w * other.m_vec.x) + (m_vec.x * other.w) + (m_vec.z * other.m_vec.y) - (m_vec.y * other.m_vec.z));
    res.m_vec.y = ((w * other.m_vec.y) + (m_vec.y * other.w) + (m_vec.x * other.m_vec.z) - (m_vec.z * other.m_vec.x));
    res.m_vec.z = ((w * other.m_vec.z) + (m_vec.z * other.w) + (m_vec.y * other.m_vec.x) - (m_vec.x * other.m_vec.y));
    return res;
  }

  amQuaternion & amQuaternion::operator*=(const amQuaternion & other) {
    *this = *this * other;
    return *this;
  }

  amQuaternion amEngineSDK::amQuaternion::operator*(const float & f) {
    amQuaternion q = *this;;
    q.w *= f;
    q.m_vec.i *= f;
    q.m_vec.j *= f;
    q.m_vec.k *= f;
    return q;
  }

  float amEngineSDK::amQuaternion::quatDot(const amQuaternion& projectedOn) {
    return (w*projectedOn.w + m_vec.x * projectedOn.m_vec.x + m_vec.y * projectedOn.m_vec.y
            + m_vec.z * projectedOn.m_vec.z);
  }
  amQuaternion amQuaternion::sLerp(amQuaternion& other, float& t) {
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
    float q1x = other.m_vec.x;
    float q1y = other.m_vec.y;
    float q1z = other.m_vec.z;
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
    res.m_vec.x = k0 * m_vec.x + k1 * q1x;
    res.m_vec.y = k0 * m_vec.y + k1 * q1y;
    res.m_vec.z = k0 * m_vec.z + k1 * q1z;
    res.w = k0 * w + k1 * q1w;
    return res;
  }
  amQuaternion & amQuaternion::quatPow(float & exp) {
    if (fabs(w) > .9999f) {
      return *this;
    }
    float alpha = acos(w);
    float newAlpha = alpha * exp;
    w = cos(newAlpha);
    float mult = sin(newAlpha) / sin(alpha);
    m_vec.x *= mult;
    m_vec.y *= mult;
    m_vec.z *= mult;
  }
  void amQuaternion::init() {
    w = m_vec.x = m_vec.y = m_vec.z = 0;
  }
  void amQuaternion::initIdentity() {
    w = 1;
    m_vec.init();
  }
  void amQuaternion::rotateAroundX(const float & theta) {
    w = cos(theta*0.5);
    m_vec.i = sin(theta*0.5);
    m_vec.j = 0;
    m_vec.k = 0;
  }
  void amQuaternion::rotateAroundY(const float & theta) {
    w = cos(theta*0.5);
    m_vec.i = 0;
    m_vec.j = sin(theta*0.5);
    m_vec.k = 0;
  }
  void amQuaternion::rotateAroundZ(const float & theta) {
    w = cos(theta*0.5);
    m_vec.i = 0;
    m_vec.j = sin(theta*0.5);
    m_vec.k = 0;
  }
  void amQuaternion::rotateAroundAxis(const amVector3 & axis, const float & theta) {
    w = cos(theta*0.5);
    float sinHalfTheta = sin(theta*0.5);
    m_vec.i = axis.x * sinHalfTheta;
    m_vec.j = axis.y * sinHalfTheta;
    m_vec.k = axis.z * sinHalfTheta;
  }
}


