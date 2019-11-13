/******************************************
 * @file amVector4.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the vector4
 *
 * @note
******************************************/
#include "amVector3.h"
#include "amVector4.h"
#include "amColor.h"

namespace amEngineSDK {

  amVector4::amVector4() {}

  amVector4::~amVector4() {}

  const amVector4
  amVector4::UP = amVector4(FORCE_INIT_VECTOR4::kUP);

  const amVector4
  amVector4::ZERO = amVector4(FORCE_INIT_VECTOR4::kZERO);

  const amVector4
  amVector4::RIGHT = amVector4(FORCE_INIT_VECTOR4::kRIGHT);

  const amVector4
  amVector4::FRONT = amVector4(FORCE_INIT_VECTOR4::kFRONT);

  const amVector4 
  amVector4::ONE = amVector4(FORCE_INIT_VECTOR4::kONE);

  const amVector4 
  amVector4::RED = amVector4(FORCE_INIT_VECTOR4::kRED);

  const amVector4 
  amVector4::GREEN = amVector4(FORCE_INIT_VECTOR4::KGREEN);

  const amVector4 
  amVector4::BLUE = amVector4(FORCE_INIT_VECTOR4::kBLUE);

  const amVector4 
  amVector4::YELLOW = amVector4(FORCE_INIT_VECTOR4::kYELLOW);

  const amVector4 
  amVector4::CYAN = amVector4(FORCE_INIT_VECTOR4::kCYAN);

  const amVector4 
  amVector4::MAGENTA = amVector4(FORCE_INIT_VECTOR4::kMAGENTA);

  const amVector4 
  amVector4::WHITE = amVector4(FORCE_INIT_VECTOR4::kWHITE);

  const amVector4 
  amVector4::BLACK = amVector4(FORCE_INIT_VECTOR4::kBLACK);

  amVector4::amVector4(const uint32 val) {
    memset(this, 0, sizeof(amVector4));
    if (val == FORCE_INIT_VECTOR4::kUP) {
      y = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kRIGHT) {
      x = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kFRONT) {
      z = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kONE) {
      x = y = z = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kRED) {
      x = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::KGREEN) {
      y = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kBLUE) {
      z = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kYELLOW) {
      x = y = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kCYAN) {
      y = z = w = 1;
    }
    if (val == FORCE_INIT_VECTOR4::kMAGENTA) {
      x = z = w = 1;
    }
  }

  amVector4::amVector4(const float& xx, const float& yy, const float& zz, const float& ww) {
    x = xx;
    y = yy;
    z = zz;
    w = ww;
  }

  amVector4::amVector4(const amVector4& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
  }

  amVector4& 
  amEngineSDK::amVector4::operator=(const amVector4& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
  }

  amVector4& 
  amVector4::operator-=(const amVector4& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }

  amVector4& 
  amVector4::operator+=(const amVector4& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  amVector4 
  amVector4::operator*(const float& f) const {
    amVector4 res = *this;
    res.x *= f;
    res.y *= f;
    res.z *= f;
    res.w *= f;
    return res;
  }

  amVector4& 
  amVector4::operator*=(const float& f) {
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
  }

  amVector4 
  amVector4::operator/(const float& f) const {
    amVector4 res = *this;
    res.x /= f;
    res.y /= f;
    res.z /= f;
    res.w /= f;
    return res;
  }

  amVector4 
  amVector4::operator-(const amVector4& other) const {
    amVector4 res = *this;
    res.x -= other.x;
    res.y -= other.y;
    res.z -= other.z;
    res.w -= other.w;
    return res;
  }

  amVector4 
  amVector4::operator+(const amVector4& other)  const {
    amVector4 res = *this;
    res.x += other.x;
    res.y += other.y;
    res.z += other.z;
    res.w += other.w;
    return res;
  }

  void 
  amVector4::Normalize() {
    float mag = 0;
    mag = (x * x) + (y * y) + (z * z) + (w * w);
    mag = sqrt(mag);
    x /= mag; y /= mag;
  }

  amVector4 
  amVector4::getNormalized() {
    float mag = 0;
    amVector4 res;
    mag = (res.x * res.x) + (res.y * res.y) + (res.z * res.z) + (res.w * res.w);
    mag = sqrt(mag);
    res *= mag;
    return res;
  }

  float 
  amVector4::Mag() {
    return sqrt((x * x) + (y * y) + (z * z) + (w * w));
  }

  float 
  amVector4::DotNormalized(amVector4& ProjectedOn) {
    // calculate dot of vectors
    // dive by product of magnitudes
    // res = cos(theta) of the first vector's mag projected on vector 2
    float dot = (x*ProjectedOn.x + y * ProjectedOn.y);
    float magmag = Mag() * ProjectedOn.Mag();
    return dot / magmag;
  }

  bool 
  amVector4::isZero() {
    if (x == 0 && y == 0 && z == 0 && w == 0)
      return true;
    return false;
  }

  amVector4 
  amVector4::cross3(const amVector4& vec) {
    amVector4 res;
    res.x = y * vec.z;
    res.y = x * vec.z;
    res.z = x * vec.y;
    return res;
  }

  amColor 
  amVector4::color(const bool _normalized) {
    if (_normalized) {
      return amColor(amMath::min(x / 255, 255.0f),
                     amMath::min(y / 255, 255.0f),
                     amMath::min(z / 255, 255.0f),
                     amMath::min(w, 255.0f));
    }
    return amColor(amMath::min(x, 255.0f),
                   amMath::min(y, 255.0f),
                   amMath::min(z, 255.0f),
                   amMath::min(w, 255.0f));
    
  }
  /*const float* amVector4::getVecArr() {
    float res[4] = {x,y,z,w};
    return res;
  }*/
}
