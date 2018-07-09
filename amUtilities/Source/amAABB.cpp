#include "amAABB.h"


namespace amEngineSDK {
  amAABB::amAABB() {}


  amAABB::~amAABB() {}

  amEngineSDK::amAABB::amAABB(const amAABB & other) {
    m_pMax = other.m_pMax;
    m_pMin = other.m_pMin;
  }

  amAABB & amEngineSDK::amAABB::operator=(const amAABB & other) {
    m_pMax = other.m_pMax;
    m_pMin = other.m_pMin;
    return *this;
  }

  void amEngineSDK::amAABB::init() {
    m_pMax.init();
    m_pMin.init();
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
}


