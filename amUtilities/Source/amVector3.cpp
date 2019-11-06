/******************************************
 * @file amVector3.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the vector3
 *
 * @note
******************************************/
#include "amVector3.h"
#include "amMath.h"

namespace amEngineSDK {

  amVector3::amVector3() {
    x = 0; y = 0; z = 0;
  }

  amVector3::~amVector3() {}

  const amVector3 
  amVector3::Front = amVector3(VECTOR_INIT::kVECTOR_FRONT);

  const amVector3 
  amVector3::Right = amVector3(VECTOR_INIT::kVECTOR_RIGHT);

  const amVector3 
  amVector3::Up = amVector3(VECTOR_INIT::kVECTOR_UP);

  const amVector3 
  amVector3::Zero = amVector3(VECTOR_INIT::kVECTOR_ZERO);

  const amVector3 
  amVector3::One = amVector3(VECTOR_INIT::kVECTOR_ONE);

  amVector3::amVector3(int32 val) {
    memset(this, 0, sizeof(amVector3));
    if (val == VECTOR_INIT::kVECTOR_FRONT) {
      z = 1.0f;
    }

    else if (val == VECTOR_INIT::kVECTOR_RIGHT) {
      x = 1.0f;
    }

    else if (val == VECTOR_INIT::kVECTOR_UP) {
      y = 1.0f;
    }

    else if (val == VECTOR_INIT::kVECTOR_ONE) {
      x = y =  z = 1.0f;
    }
  }

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

  float 
  amVector3::operator%(const amVector3 & other) const{
    return amMath::aCos(((*this) | other) / ((*this).Mag() * other.Mag()));
  }

  amVector3 
  amVector3::operator*(const amVector3 & other) const {
    amVector3 res = *this;
    res.x *= other.x;
    res.y *= other.y;
    res.z *= other.z;
    return res;
  }

  amVector3 
  amVector3::operator/(const amVector3 & other) const {
    amVector3 res = *this;
    res.x /= other.x;
    res.y /= other.y;
    res.z /= other.z;
    return res;
  }

  bool 
  amVector3::operator==(const amVector3 & other) const {
    return(x == other.x && y == other.y && z == other.z) ? true : false;
  }

  amVector3 
  amVector3::operator^(const amVector3 & other)  const {
    amVector3 res;
    //res.x = y * other.z;
    //res.y = z * other.x;
    //res.z = x * other.y;
    res.x = z * other.y;
    res.y = x * other.z;
    res.z = y * other.x;
    return res;
  }

  amVector3& 
  amVector3::operator=(const amVector3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  float 
  amVector3::operator|(const amVector3 & other) const {
    return (x * other.x + y * other.y, + z * other.z);
  }

  amVector3& 
  amVector3::operator-=(const amVector3 & other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  amVector3& 
  amVector3::operator+=(const amVector3 & other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  amVector3& 
  amVector3::operator*=(const amVector3 & other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
  }

  amVector3& 
  amVector3::operator/=(const amVector3 & other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
  }

  amVector3 
  amVector3::operator*(const float & f)  const {
    amVector3 res = *this;
    res.x *= f;
    res.y *= f;
    res.z *= f;
    return res;
  }

  amVector3& 
  amEngineSDK::amVector3::operator*=(const float & f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
  }

  amVector3 
  amVector3::operator/(const float & f)  const {
    amVector3 res = *this;
    res.x /= f;
    res.y /= f;
    res.z /= f;
    return res;
  }

  amVector3 
  amVector3::operator-(const amVector3 & other)  const {
    amVector3 res = *this;
    res.x -= other.x;
    res.y -= other.y;
    res.z -= other.z;
    return res;
  }

  amVector3 
  amVector3::operator+(const amVector3 & other)  const {
    amVector3 res = *this;
    res.x += other.x;
    res.y += other.y;
    res.z += other.z;
    return res;
  }

  void 
  amVector3::Normalize() {
    float mag = 0;
    mag = Mag();
    x /= mag; y /= mag; z /= mag;
  }

  amVector3 
  amVector3::getNormalized()  const {
    amVector3 res= *this;
    res.Normalize();
    return res;
  }

  float 
  amVector3::Mag() const {
    return amMath::sqrt((x * x) + (y * y) + (z * z));
  }

  float 
  amVector3::DotNormalized(const amVector3 & ProjectedOn)  const {
    // calculate dot of vectors
    // dive by product of magnitudes
    // res = cos(theta) of the first vector's mag projected on vector 2
    float dot = (x*ProjectedOn.x + y * ProjectedOn.y);
    float magmag = Mag() * ProjectedOn.Mag();
    return dot / magmag;
  }

  amVector3 
  amVector3::cross3(const amVector3 & other) const {
    amVector3 res = *this ^ other;
    return res;
  }

  bool 
  amVector3::isZero()  const {
    return (x == 0 && y == 0 && z == 0);
  }

  float 
  amVector3::getDeterminant(const amVector3 & other) const {
    return (((amMath::tan(z / x) * (amMath::sqrt(z * x))) * other.y) - 
           (((amMath::tan(other.z / other.x) * (amMath::sqrt(other.z * other.x)) * y))));

  }
}
