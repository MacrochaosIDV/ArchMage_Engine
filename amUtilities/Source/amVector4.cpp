#include "amVector3.h"

namespace amEngineSDK {

  amVector4::amVector4() {}

  amVector4::~amVector4() {}

  amVector4::amVector4(const float & xx, const float & yy, const float & zz, const float & ww) {
    x = xx;
    y = yy;
    z = zz;
    w = ww;
  }

  amVector4::amVector4(const amVector4 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
  }

  amVector4 & amEngineSDK::amVector4::operator=(const amVector4 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
  }
  amVector4 & amVector4::operator-=(const amVector4 & other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }

  amVector4 & amEngineSDK::amVector4::operator+=(const amVector4 & other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  amVector4 amEngineSDK::amVector4::operator*(const float & f) {
    amVector4 res = *this;
    res.x *= f;
    res.y *= f;
    res.z *= f;
    res.w *= f;
    return res;
  }

  amVector4 & amEngineSDK::amVector4::operator*=(const float & f) {
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
  }

  amVector4 amEngineSDK::amVector4::operator/(const float & f) {
    amVector4 res = *this;
    res.x /= f;
    res.y /= f;
    res.z /= f;
    res.w /= f;
    return res;
  }

  amVector4 amEngineSDK::amVector4::operator-(const amVector4 & other) {
    amVector4 res = *this;
    res.x -= other.x;
    res.y -= other.y;
    res.z -= other.z;
    res.w -= other.w;
    return res;
  }

  amVector4 amEngineSDK::amVector4::operator+(const amVector4 & other) {
    amVector4 res = *this;
    res.x += other.x;
    res.y += other.y;
    res.z += other.z;
    res.w += other.w;
    return res;
  }

  void amEngineSDK::amVector4::Normalize() {
    float mag = 0;
    mag = (x * x) + (y * y) + (z * z) + (w * w);
    mag = sqrt(mag);
    x /= mag; y /= mag;
  }

  void amVector4::init() {
    x = y = z = w = 0;
  }

  amVector4 amEngineSDK::amVector4::getNormalized() {
    float mag = 0;
    amVector4 res;
    mag = (res.x * res.x) + (res.y * res.y) + (res.z * res.z) + (res.w * res.w);
    mag = sqrt(mag);
    res *= mag;
    return res;
  }

  float amEngineSDK::amVector4::Mag() {
    return sqrt((x * x) + (y * y) + (z * z) + (w * w));
  }

  float amEngineSDK::amVector4::DotNormalized(amVector4 & ProjectedOn) {
    // calculate dot of vectors
    // dive by product of magnitudes
    // res = cos(theta) of the first vector's mag projected on vector 2
    float dot = (x*ProjectedOn.x + y * ProjectedOn.y);
    float magmag = Mag() * ProjectedOn.Mag();
    return dot / magmag;
  }

  bool amVector4::isZero() {
    if (x == 0 && y == 0 && z == 0 && w == 0)
      return true;
    return false;
  }

  amVector4 amVector4::cross3(const amVector4 & vec) {
    amVector4 res;
    res.x = y * vec.z;
    res.y = x * vec.z;
    res.z = x * vec.y;
    return res;
  }
}


