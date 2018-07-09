#include "amBox2D.h"

namespace amEngineSDK {
  amBox2D::amBox2D() {}


  amBox2D::~amBox2D() {}

  amBox2D & amBox2D::operator=(const amBox2D & other) {
    m_center = other.m_center;
    w = other.w;
    h = other.h;
  }

  amBox2D & amEngineSDK::amBox2D::operator+(const amVector2 & vec) {
    m_center += vec;
    return *this;
  }
  amBox2D amBox2D::operator+(const amBox2D & box) {
    amBox2D b = *this;
    b.m_center = m_center + box.m_center;
    b.h = h + box.h;
    b.w = w + box.w;
    return b;
  }
  amBox2D amBox2D::operator-(const amBox2D & box) {
    amBox2D b = *this;
    b.m_center = m_center - box.m_center;
    b.h = h - box.h;
    b.w = w - box.w;
    return b;
  }
  amBox2D amBox2D::operator*(const amBox2D & box) {
    amBox2D b = *this;
    b.m_center = m_center * box.m_center;
    b.h = h * box.h;
    b.w = w * box.w;
    return b;
  }
  amBox2D & amBox2D::operator+=(const amBox2D & box) {
    m_center += box.m_center;
    h += box.h;
    w += box.w;
    return *this;
  }
  amBox2D & amBox2D::operator-=(const amBox2D & box) {
    m_center -= box.m_center;
    h -= box.h;
    w -= box.w;
    return *this;
  }
  amBox2D & amBox2D::operator*=(const amBox2D & box) {
    m_center *= box.m_center;
    h *= box.h;
    w *= box.w;
    return *this;
  }
  void amBox2D::init() {
    m_center.init();
    w = h = 0;
  }
  bool amBox2D::isInside(const amVector2 & vec) {
    //TODO
    return false;
  }
  void amBox2D::shrink(const float & f) {
    h += f;
    w += f;
  }
  void amBox2D::expand(const float & f) {
    h -= f;
    w -= f;
  }
  void amBox2D::expandShrinkRatio(const float & scale) {
    h *= scale;
    w *= scale;
  }
  void amBox2D::moveTo(const amVector2 & newPos) {
    m_center = newPos;
  }
  void amBox2D::flip() {
    float tmp = h;
    h = w;
    w = tmp;
  }
}
