#include "amVector2.h"

namespace amEngineSDK {
  amVector2::amVector2() {
    x = 0; y = 0;
  }
  amVector2::~amVector2() {}

  amVector2 & amVector2::operator=(const amVector2 & other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  amVector2 & amVector2::operator+=(const amVector2 & other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  amVector2 & amVector2::operator-=(const amVector2 & other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  amVector2 & amVector2::operator*=(const amVector2 & other) {
    x *= other.x;
    y *= other.y;
    return *this;
  }

  amVector2 amVector2::operator*(const float & f) {
    amVector2 res = *this;
    res.x *= f;
    res.y *= f;
    return res;
  }

  amVector2 & amVector2::operator*=(const float & f) {
    x *= f;
    y *= f;
    return *this;
  }

  amVector2 amVector2::operator/(const float & f) const {
    amVector2 res = *this;
    res.x /= f;
    res.y /= f;
    return res;
  }

  amVector2 amVector2::operator-(const amVector2 & other) const {
    amVector2 res = *this;
    res.x -= other.x;
    res.y -= other.y;
    return res;
  }

  amVector2 amVector2::operator+(const amVector2 & other) const {
    amVector2 res = *this;
    res.x += other.x;
    res.y += other.y;
    return res;
  }

  amVector2 amVector2::operator*(const amVector2 & other) const {
    amVector2 res = *this;
    res.x *= other.x;
    res.y *= other.y;
    return res;
  }

  void amVector2::normalize() {
    float mag = 0;
    mag = (x * x) + (y * y);
    mag = sqrt(mag);
    x /= mag; y /= mag;
  }

  amVector2 amVector2::getNormalized() {
    float mag = 0;
    amVector2 res;
    mag = res.x * res.x + res.y * res.y;
    mag = sqrt(mag);
    res *= mag;
    return res;
  }

  float amVector2::Mag() {
    return sqrt((x * x) + (y * y));
  }

  float
  amVector2::dotNormalized(amVector2 & ProjectedOn) {
    // calculate dot of vectors
    // dive by product of magnitudes
    // res = cos(theta) of the first vector's mag projected on vector 2
    float dot = (x*ProjectedOn.x + y*ProjectedOn.y);
    float magmag = Mag() * ProjectedOn.Mag();
    return dot / magmag;
  }
}


