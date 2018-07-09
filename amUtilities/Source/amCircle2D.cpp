#include "amCircle2D.h"

namespace amEngineSDK {
  amCircle2D::amCircle2D() {}
  amCircle2D::~amCircle2D() {}

  amCircle2D amCircle2D::operator+(amCircle2D & cir) {
    amCircle2D c = *this;
    c.r += cir.r;
    c.m_center += cir.m_center;
    return c;
  }

  amCircle2D amCircle2D::operator-(amCircle2D & cir) {
    amCircle2D c = *this;
    c.r -= cir.r;
    c.m_center -= cir.m_center;
    return c;
  }

  amCircle2D amCircle2D::operator*(amCircle2D & cir) {
    amCircle2D c = *this;
    c.r *= cir.r;
    c.m_center *= cir.m_center;
    return c;
  }

  amCircle2D & amCircle2D::operator=(amCircle2D & cir) {
    r = cir.r;
    m_center = cir.m_center;
    return *this;
  }

  amCircle2D & amCircle2D::operator+=(amCircle2D & cir) {
    r += cir.r;
    m_center += cir.m_center;
    return *this;
  }

  amCircle2D & amCircle2D::operator-=(amCircle2D & cir) {
    r -= cir.r;
    m_center -= cir.m_center;
    return *this;
  }

  amCircle2D & amCircle2D::operator*=(amCircle2D & cir) {
    r *= cir.r;
    m_center *= cir.m_center; 
    return *this;
  }

  amCircle2D & amCircle2D::operator+=(amVector2 & vec) {
    m_center += vec;
    return *this;
  }

  void amCircle2D::init() {
    r = 0;
    m_center.init();
  }

  bool amCircle2D::isInside(const amVector2 & vec) {
    amVector2 copyVec = vec;
    if ((copyVec - m_center).Mag() >= r * r)
      return true;
    return false;
  }

  void amCircle2D::shrink(const float & f) {
    r -= f;
  }

  void amCircle2D::expand(const float & f) {
    r += f;
  }

  void amCircle2D::moveTo(const amVector2 & newPos) {
    m_center = newPos;
  }
}


