#include "amFrustrum.h"

namespace amEngineSDK {
  amFrustrum::amFrustrum() {
  
  }

  amFrustrum::~amFrustrum() {
  
  }
  amFrustrum::amFrustrum(const amFrustrum & other) {
    m_far    = other.m_far;
    m_near   = other.m_near;
    m_right  = other.m_right;
    m_left   = other.m_left;
    m_top    = other.m_top;
    m_bottom = other.m_bottom;
  }

  /*amFrustrum::amFrustrum(const amVector3 & topRightBack,
                         const amVector3 & topRightFront,
                         const amVector3 & topLefttBack,
                         const amVector3 & topLeftFront,
                         const amVector3 & bottomRightBack,
                         const amVector3 & bottomRightFront,
                         const amVector3 & bottomLefttBack,
                         const amVector3 & bottomLeftFront) {
    m_far(topLeftFront, topRightFront, bottomRightFront);
    m_near(topLefttBack, topRightBack, bottomRightBack);
    m_right(topRightBack, topRightFront, bottomRightBack);
    m_left(topLeftFront, topLefttBack, bottomLeftFront);
    m_top(topRightFront, topLeftFront, topRightBack);
    m_bottom(bottomLeftFront, bottomRightFront, bottomRightBack);
  }*/

  amFrustrum::amFrustrum(const amMatrix4x4 & VP) {
  
  }

  amFrustrum & amFrustrum::operator=(const amFrustrum & other) {
    m_far    = other.m_far;
    m_near   = other.m_near;
    m_right  = other.m_right;
    m_left   = other.m_left;
    m_top    = other.m_top;
    m_bottom = other.m_bottom;
    return *this;
  }
  amFrustrum amFrustrum::operator+(const amFrustrum & other) {
    amFrustrum res;
    res.m_far    += other.m_far;
    res.m_near   += other.m_near;
    res.m_right  += other.m_right;
    res.m_left   += other.m_left;
    res.m_top    += other.m_top;
    res.m_bottom += other.m_bottom;
    return res;
  }
  amFrustrum amFrustrum::operator-(const amFrustrum & other) {
    amFrustrum res;
    res.m_far    -= other.m_far;
    res.m_near   -= other.m_near;
    res.m_right  -= other.m_right;
    res.m_left   -= other.m_left;
    res.m_top    -= other.m_top;
    res.m_bottom -= other.m_bottom;
    return res;
  }
  amFrustrum amFrustrum::operator*(const amFrustrum & other) {
    amFrustrum res;
    res.m_far    *= other.m_far;
    res.m_near   *= other.m_near;
    res.m_right  *= other.m_right;
    res.m_left   *= other.m_left;
    res.m_top    *= other.m_top;
    res.m_bottom *= other.m_bottom;
    return res;
  }
  amFrustrum amFrustrum::operator/(const amFrustrum & other) {
    amFrustrum res;
    res.m_far    /= other.m_far;
    res.m_near   /= other.m_near;
    res.m_right  /= other.m_right;
    res.m_left   /= other.m_left;
    res.m_top    /= other.m_top;
    res.m_bottom /= other.m_bottom;
    return res;
  }
  amFrustrum & amFrustrum::operator+=(const amFrustrum & other) {
    m_far    += other.m_far;
    m_near   += other.m_near;
    m_right  += other.m_right;
    m_left   += other.m_left;
    m_top    += other.m_top;
    m_bottom += other.m_bottom;
    return *this;
  }
  amFrustrum & amFrustrum::operator-=(const amFrustrum & other) {
    m_far    -= other.m_far;
    m_near   -= other.m_near;
    m_right  -= other.m_right;
    m_left   -= other.m_left;
    m_top    -= other.m_top;
    m_bottom -= other.m_bottom;
    return *this;
  }
  amFrustrum & amFrustrum::operator*=(const amFrustrum & other) {
    m_far    *= other.m_far;
    m_near   *= other.m_near;
    m_right  *= other.m_right;
    m_left   *= other.m_left;
    m_top    *= other.m_top;
    m_bottom *= other.m_bottom;
    return *this;
  }
  amFrustrum & amFrustrum::operator/=(const amFrustrum & other) {
    m_far    /= other.m_far;
    m_near   /= other.m_near;
    m_right  /= other.m_right;
    m_left   /= other.m_left;
    m_top    /= other.m_top;
    m_bottom /= other.m_bottom;
    return *this;
  }
  bool amFrustrum::intersects(const amFrustrum & other) {
    return false;
  }
  /*void amFrustrum::init() {
    m_far.init();
    m_near.init();
    m_right.init();
    m_left.init();
    m_top.init();
    m_bottom.init();
  }*/
}


