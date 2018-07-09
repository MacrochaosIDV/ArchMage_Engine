#include "amVector3.h"

namespace amEngineSDK {

  amVector3::amVector3() {
    x = 0; y = 0; z = 0;
  }

  amVector3::~amVector3() {}

  amVector3::amVector3(const float & xx, const float & yy, const float & zz) {
    x = xx;
    y = yy;
    z = zz;
  }

  amVector3::amVector3(const amVector3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
  }

  amVector3 & amEngineSDK::amVector3::operator=(const amVector3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  amVector3 & amVector3::operator-=(const amVector3 & other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  amVector3 & amEngineSDK::amVector3::operator+=(const amVector3 & other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  amVector3 amEngineSDK::amVector3::operator*(const float & f) {
    amVector3 res = *this;
    res.x *= f;
    res.y *= f;
    res.z *= f;
    return res;
  }

  amVector3 & amEngineSDK::amVector3::operator*=(const float & f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
  }

  amVector3 amEngineSDK::amVector3::operator/(const float & f) {
    amVector3 res = *this;
    res.x /= f;
    res.y /= f;
    res.z /= f;
    return res;
  }

  amVector3 amEngineSDK::amVector3::operator-(const amVector3 & other) {
    amVector3 res = *this;
    res.x -= other.x;
    res.y -= other.y;
    res.z -= other.z;
    return res;
  }

  amVector3 amEngineSDK::amVector3::operator+(const amVector3 & other) {
    amVector3 res = *this;
    res.x += other.x;
    res.y += other.y;
    res.z += other.z;
    return res;
  }

  void amEngineSDK::amVector3::Normalize() {
    float mag = 0;
    mag = (x * x) + (y * y) + (z * z);
    mag = sqrt(mag);
    x /= mag; y /= mag;
  }

  void amVector3::init() {
    x = y = z = 0;
  }

  amVector3 amEngineSDK::amVector3::getNormalized() {
    float mag = 0;
    amVector3 res;
    mag = (res.x * res.x) + (res.y * res.y) + (res.z * res.z);
    mag = sqrt(mag);
    res *= mag;
    return res;
  }

  float amEngineSDK::amVector3::Mag() {
    return sqrt((x * x) + (y * y) + (z * z));
  }

  float amEngineSDK::amVector3::DotNormalized(amVector3 & ProjectedOn) {
    // calculate dot of vectors
    // dive by product of magnitudes
    // res = cos(theta) of the first vector's mag projected on vector 2
    float dot = (x*ProjectedOn.x + y * ProjectedOn.y);
    float magmag = Mag() * ProjectedOn.Mag();
    return dot / magmag;
  }
  amVector3 amVector3::cross3(const amVector3 & other) {
    amVector3 res;
    res.x = y * other.z;
    res.y = x * other.z;
    res.z = x * other.y;
    return res;
  }
  bool amVector3::isZero() {
    if (x == 0 && y == 0 && z == 0)
      return true;
    return false;
  }
}


