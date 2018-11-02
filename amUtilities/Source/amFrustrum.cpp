/******************************************
 * @file amFrustrum.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the frustrum
 *
 *
 * @note Currently out-of-date operators
******************************************/
#include "amFrustrum.h"

namespace amEngineSDK {
  amFrustrum::amFrustrum() {
  
  }

  amFrustrum::~amFrustrum() {
  
  }
  amFrustrum::amFrustrum(const amFrustrum & other) {
    for (int32 i = 0; i < FRUSTRUM_PLANES::COUNT; ++i) {
      m_planes[i] = other.m_planes[i];
    }
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
    VP;
  }

  amFrustrum & amFrustrum::operator=(const amFrustrum & other) {
    for (int32 i = 0; i < FRUSTRUM_PLANES::COUNT; ++i) {
      m_planes[i] = other.m_planes[i];
    }
    return *this;
  }
  amFrustrum amFrustrum::operator+(const amFrustrum & other) const {
    amFrustrum res;
    res.m_planes[FRUSTRUM_PLANES::FAR] = m_planes[FRUSTRUM_PLANES::FAR]       + other.m_planes[FRUSTRUM_PLANES::FAR];
    res.m_planes[FRUSTRUM_PLANES::NEAR] = m_planes[FRUSTRUM_PLANES::NEAR]     + other.m_planes[FRUSTRUM_PLANES::NEAR];
    res.m_planes[FRUSTRUM_PLANES::RIGHT] = m_planes[FRUSTRUM_PLANES::RIGHT]   + other.m_planes[FRUSTRUM_PLANES::RIGHT];
    res.m_planes[FRUSTRUM_PLANES::LEFT] = m_planes[FRUSTRUM_PLANES::LEFT]     + other.m_planes[FRUSTRUM_PLANES::LEFT];
    res.m_planes[FRUSTRUM_PLANES::TOP] = m_planes[FRUSTRUM_PLANES::TOP]       + other.m_planes[FRUSTRUM_PLANES::TOP];
    res.m_planes[FRUSTRUM_PLANES::BOTTOM] = m_planes[FRUSTRUM_PLANES::BOTTOM] + other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return res;
  }
  amFrustrum amFrustrum::operator-(const amFrustrum & other) const {
    amFrustrum res;
    res.m_planes[FRUSTRUM_PLANES::FAR] = m_planes[FRUSTRUM_PLANES::FAR]       - other.m_planes[FRUSTRUM_PLANES::FAR];
    res.m_planes[FRUSTRUM_PLANES::NEAR] = m_planes[FRUSTRUM_PLANES::NEAR]     - other.m_planes[FRUSTRUM_PLANES::NEAR];
    res.m_planes[FRUSTRUM_PLANES::RIGHT] = m_planes[FRUSTRUM_PLANES::RIGHT]   - other.m_planes[FRUSTRUM_PLANES::RIGHT];
    res.m_planes[FRUSTRUM_PLANES::LEFT] = m_planes[FRUSTRUM_PLANES::LEFT]     - other.m_planes[FRUSTRUM_PLANES::LEFT];
    res.m_planes[FRUSTRUM_PLANES::TOP] = m_planes[FRUSTRUM_PLANES::TOP]       - other.m_planes[FRUSTRUM_PLANES::TOP];
    res.m_planes[FRUSTRUM_PLANES::BOTTOM] = m_planes[FRUSTRUM_PLANES::BOTTOM] - other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return res;
  }
  amFrustrum amFrustrum::operator*(const amFrustrum & other) const {
    amFrustrum res;
    res.m_planes[FRUSTRUM_PLANES::FAR]    *= other.m_planes[FRUSTRUM_PLANES::FAR];
    res.m_planes[FRUSTRUM_PLANES::NEAR]   *= other.m_planes[FRUSTRUM_PLANES::NEAR];
    res.m_planes[FRUSTRUM_PLANES::RIGHT]  *= other.m_planes[FRUSTRUM_PLANES::RIGHT];
    res.m_planes[FRUSTRUM_PLANES::LEFT]   *= other.m_planes[FRUSTRUM_PLANES::LEFT];
    res.m_planes[FRUSTRUM_PLANES::TOP]    *= other.m_planes[FRUSTRUM_PLANES::TOP];
    res.m_planes[FRUSTRUM_PLANES::BOTTOM] *= other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return res;
  }
  amFrustrum amFrustrum::operator/(const amFrustrum & other) const {
    amFrustrum res;
    res.m_planes[FRUSTRUM_PLANES::FAR]    /= other.m_planes[FRUSTRUM_PLANES::FAR];
    res.m_planes[FRUSTRUM_PLANES::NEAR]   /= other.m_planes[FRUSTRUM_PLANES::NEAR];
    res.m_planes[FRUSTRUM_PLANES::RIGHT]  /= other.m_planes[FRUSTRUM_PLANES::RIGHT];
    res.m_planes[FRUSTRUM_PLANES::LEFT]   /= other.m_planes[FRUSTRUM_PLANES::LEFT];
    res.m_planes[FRUSTRUM_PLANES::TOP]    /= other.m_planes[FRUSTRUM_PLANES::TOP];
    res.m_planes[FRUSTRUM_PLANES::BOTTOM] /= other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return res;
  }
  amFrustrum & amFrustrum::operator+=(const amFrustrum & other) {
    m_planes[FRUSTRUM_PLANES::FAR]    += other.m_planes[FRUSTRUM_PLANES::FAR];
    m_planes[FRUSTRUM_PLANES::NEAR]   += other.m_planes[FRUSTRUM_PLANES::NEAR];
    m_planes[FRUSTRUM_PLANES::RIGHT]  += other.m_planes[FRUSTRUM_PLANES::RIGHT];
    m_planes[FRUSTRUM_PLANES::LEFT]   += other.m_planes[FRUSTRUM_PLANES::LEFT];
    m_planes[FRUSTRUM_PLANES::TOP]    += other.m_planes[FRUSTRUM_PLANES::TOP];
    m_planes[FRUSTRUM_PLANES::BOTTOM] += other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return *this;
  }
  amFrustrum & amFrustrum::operator-=(const amFrustrum & other) {
    m_planes[FRUSTRUM_PLANES::FAR]    -= other.m_planes[FRUSTRUM_PLANES::FAR];
    m_planes[FRUSTRUM_PLANES::NEAR]   -= other.m_planes[FRUSTRUM_PLANES::NEAR];
    m_planes[FRUSTRUM_PLANES::RIGHT]  -= other.m_planes[FRUSTRUM_PLANES::RIGHT];
    m_planes[FRUSTRUM_PLANES::LEFT]   -= other.m_planes[FRUSTRUM_PLANES::LEFT];
    m_planes[FRUSTRUM_PLANES::TOP]    -= other.m_planes[FRUSTRUM_PLANES::TOP];
    m_planes[FRUSTRUM_PLANES::BOTTOM] -= other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return *this;
  }
  amFrustrum & amFrustrum::operator*=(const amFrustrum & other) {
    m_planes[FRUSTRUM_PLANES::FAR]    *= other.m_planes[FRUSTRUM_PLANES::FAR];
    m_planes[FRUSTRUM_PLANES::NEAR]   *= other.m_planes[FRUSTRUM_PLANES::NEAR];
    m_planes[FRUSTRUM_PLANES::RIGHT]  *= other.m_planes[FRUSTRUM_PLANES::RIGHT];
    m_planes[FRUSTRUM_PLANES::LEFT]   *= other.m_planes[FRUSTRUM_PLANES::LEFT];
    m_planes[FRUSTRUM_PLANES::TOP]    *= other.m_planes[FRUSTRUM_PLANES::TOP];
    m_planes[FRUSTRUM_PLANES::BOTTOM] *= other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return *this;
  }
  amFrustrum & amFrustrum::operator/=(const amFrustrum & other) {
    m_planes[FRUSTRUM_PLANES::FAR]    /= other.m_planes[FRUSTRUM_PLANES::FAR];
    m_planes[FRUSTRUM_PLANES::NEAR]   /= other.m_planes[FRUSTRUM_PLANES::NEAR];
    m_planes[FRUSTRUM_PLANES::RIGHT]  /= other.m_planes[FRUSTRUM_PLANES::RIGHT];
    m_planes[FRUSTRUM_PLANES::LEFT]   /= other.m_planes[FRUSTRUM_PLANES::LEFT];
    m_planes[FRUSTRUM_PLANES::TOP]    /= other.m_planes[FRUSTRUM_PLANES::TOP];
    m_planes[FRUSTRUM_PLANES::BOTTOM] /= other.m_planes[FRUSTRUM_PLANES::BOTTOM];
    return *this;
  }
  bool amFrustrum::intersects(const amFrustrum & other) {
    other;
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


