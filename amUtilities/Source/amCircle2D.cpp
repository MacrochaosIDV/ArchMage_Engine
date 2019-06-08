#include "amCircle2D.h"

namespace amEngineSDK {
  amCircle2D 
  amCircle2D::operator+(amCircle2D & cir) const {
    amCircle2D c = *this;
    c.r += cir.r;
    c.m_center += cir.m_center;
    return c;
  }

  amCircle2D 
  amCircle2D::operator-(amCircle2D & cir) const {
    amCircle2D c = *this;
    c.r -= cir.r;
    c.m_center -= cir.m_center;
    return c;
  }

  amCircle2D 
  amCircle2D::operator*(amCircle2D & cir) const {
    amCircle2D c = *this;
    c.r *= cir.r;
    c.m_center *= cir.m_center;
    return c;
  }

  amCircle2D & 
  amCircle2D::operator=(amCircle2D & cir) {
    r = cir.r;
    m_center = cir.m_center;
    return *this;
  }

  amCircle2D & 
  amCircle2D::operator+=(amCircle2D & cir) {
    r += cir.r;
    m_center += cir.m_center;
    return *this;
  }

  amCircle2D & 
  amCircle2D::operator-=(amCircle2D & cir) {
    r -= cir.r;
    m_center -= cir.m_center;
    return *this;
  }

  amCircle2D & 
  amCircle2D::operator*=(amCircle2D & cir) {
    r *= cir.r;
    m_center *= cir.m_center; 
    return *this;
  }

  amCircle2D&
  amCircle2D::operator+=(amVector2 & vec) {
    m_center += vec;
    return *this;
  }

  bool 
  amCircle2D::isInside(const amVector2 & vec) {    
    if ( (vec - m_center).Mag() >= r) {
      return true;
    }

    return false;
  }

  void 
  amCircle2D::scale(const float& f) {
    r *= f;
  }

  void
  amCircle2D::moveTo(const amVector2& newPos) {
    m_center = newPos;
  }
}
