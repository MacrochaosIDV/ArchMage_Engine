#include "amAABB.h"


namespace amEngineSDK {
  amAABB::amAABB() {}


  amAABB::~amAABB() {}

    amAABB::amAABB(const amAABB & other) {
    m_pMax = other.m_pMax;
    m_pMin = other.m_pMin;
  }

  amAABB & amEngineSDK::amAABB::operator=(const amAABB & other) {
    m_pMax = other.m_pMax;
    m_pMin = other.m_pMin;
    return *this;
  }

  amAABB amAABB::operator+(const amAABB & other) {
    return amAABB();
  }

  amAABB amAABB::operator-(const amAABB & other) {
    return amAABB();
  }

  amAABB amAABB::operator*(const amAABB & other) {
    return amAABB();
  }

  amAABB amAABB::operator/(const amAABB & other) {
    return amAABB();
  }

  amAABB & amAABB::operator+=(const amAABB & other) {
    return *this;
  }

  amAABB & amAABB::operator-=(const amAABB & other) {
    return *this;
  }

  amAABB & amAABB::operator*=(const amAABB & other) {
    return *this;
  }

  amAABB & amAABB::operator/=(const amAABB & other) {
    return *this;
  }

  void amEngineSDK::amAABB::add(const amVector3 & vec) {
    if (vec.x < m_pMin.x)
      m_pMin.x = vec.x;

    if (vec.x > m_pMax.x)
      m_pMax.x = vec.x;

    if (vec.y < m_pMin.x)
      m_pMin.y = vec.y;

    if (vec.y > m_pMax.x)
      m_pMax.y = vec.y;

    if (vec.z < m_pMin.x)
      m_pMin.z = vec.z;

    if (vec.z > m_pMax.x)
      m_pMax.z = vec.z;
  }

  bool amAABB::intersects(const amVector3 & vec) const {
    return amPLatformMath::intersects(vec, *this);
  }

  bool amAABB::intersects(const amAABB & other) {
    /***********************
    *  Calculate the other points o the other box the test them onto this box
    ***********************/
    amVector3 Mxmymz = *new amVector3(other.m_pMax.x, other.m_pMin.y, other.m_pMin.z);
    amVector3 mxmyMz = *new amVector3(other.m_pMin.x, other.m_pMin.y, other.m_pMax.z);
    amVector3 MxmyMz = *new amVector3(other.m_pMax.x, other.m_pMin.y, other.m_pMax.z);

    amVector3 mxMyMz = *new amVector3(other.m_pMin.x, other.m_pMax.y, other.m_pMax.z);
    amVector3 MxMymz = *new amVector3(other.m_pMax.x, other.m_pMax.y, other.m_pMin.z);
    amVector3 mxMymz = *new amVector3(other.m_pMin.x, other.m_pMax.y, other.m_pMin.z);

    if (intersects(other.m_pMin))
      return true;
    if (intersects(other.m_pMax))
      return true;
    if (intersects(Mxmymz))
      return true;
    if (intersects(mxmyMz))
      return true;
    if (intersects(MxmyMz))
      return true;
    if (intersects(mxMyMz))
      return true;
    if (intersects(MxMymz))
      return true;
    if (intersects(mxMymz))
      return true;

    /***********************
    *  Then calculate of the points of this box and test them against the other box
    ***********************/
    Mxmymz = *new amVector3(m_pMax.x, m_pMin.y, m_pMin.z);
    mxmyMz = *new amVector3(m_pMin.x, m_pMin.y, m_pMax.z);
    MxmyMz = *new amVector3(m_pMax.x, m_pMin.y, m_pMax.z);

    mxMyMz = *new amVector3(m_pMin.x, m_pMax.y, m_pMax.z);
    MxMymz = *new amVector3(m_pMax.x, m_pMax.y, m_pMin.z);
    mxMymz = *new amVector3(m_pMin.x, m_pMax.y, m_pMin.z);
    if (other.intersects(m_pMin))
      return true;
    if (other.intersects(m_pMax))
      return true;
    if (other.intersects(Mxmymz))
      return true;
    if (other.intersects(mxmyMz))
      return true;
    if (other.intersects(MxmyMz))
      return true;
    if (other.intersects(mxMyMz))
      return true;
    if (other.intersects(MxMymz))
      return true;
    if (other.intersects(mxMymz))
      return true;

    /***********************
    *THEN calculate the inner AABB and test it against both AABBs
    ***********************/
    amVector3 third_pMin = *new amVector3(other.m_pMin.x, m_pMin.y, m_pMin.z);
    amVector3 third_pMax = *new amVector3(other.m_pMax.x, m_pMax.y, m_pMax.z);

    Mxmymz = *new amVector3(third_pMax.x, third_pMin.y, third_pMin.z);
    mxmyMz = *new amVector3(third_pMin.x, third_pMin.y, third_pMax.z);
    MxmyMz = *new amVector3(third_pMax.x, third_pMin.y, third_pMax.z);

    mxMyMz = *new amVector3(third_pMin.x, third_pMax.y, third_pMax.z);
    MxMymz = *new amVector3(third_pMax.x, third_pMax.y, third_pMin.z);
    mxMymz = *new amVector3(third_pMin.x, third_pMax.y, third_pMin.z);

    if (intersects(third_pMin))
      return true;
    if (intersects(third_pMax))
      return true;
    if (intersects(Mxmymz))
      return true;
    if (intersects(mxmyMz))
      return true;
    if (intersects(MxmyMz))
      return true;
    if (intersects(mxMyMz))
      return true;
    if (intersects(MxMymz))
      return true;
    if (intersects(mxMymz))
      return true;

    return false;
  }
  
  

  amAABB amAABB::setToTransformedBox() {
    return amAABB();
  }
}


