#include "amCapsule.h"


namespace amEngineSDK {
  amCapsule::amCapsule() {

  }

  amCapsule::~amCapsule() {

  }

  amCapsule::amCapsule(const amCapsule & other) {
    m_center = other.m_center;
    m_radius = other.m_radius;
    m_height = other.m_height;
  }

  amCapsule & amCapsule::operator=(const amCapsule & other) {
    m_center = other.m_center;
    m_radius = other.m_radius;
    m_height = other.m_height;
    return *this;
  }

  amCapsule amCapsule::operator+(const amCapsule & other) {
    amCapsule cp;
    cp.m_height += other.m_height;
    cp.m_radius += other.m_radius;
    return cp;
  }

  amCapsule amCapsule::operator-(const amCapsule & other) {
    amCapsule cp;
    cp.m_height -= other.m_height;
    cp.m_radius -= other.m_radius;
    return cp;
  }

  amCapsule amCapsule::operator*(const amCapsule & other) {
    amCapsule cp;
    cp.m_height *= other.m_height;
    cp.m_radius *= other.m_radius;
    return cp;
  }

  amCapsule amCapsule::operator/(const amCapsule & other) {
    amCapsule cp;
    cp.m_height /= other.m_height;
    cp.m_radius /= other.m_radius;
    return cp;
  }

  amCapsule & amCapsule::operator+=(const amCapsule & other) {
    m_height += other.m_height;
    m_radius += other.m_radius;
    return *this;
  }

  amCapsule & amCapsule::operator-=(const amCapsule & other) {
    m_height -= other.m_height;
    m_radius -= other.m_radius;
    return *this;
  }

  amCapsule & amCapsule::operator*=(const amCapsule & other) {
    m_height *= other.m_height;
    m_radius *= other.m_radius;
    return *this;
  }

  amCapsule & amCapsule::operator/=(const amCapsule & other) {
    m_height /= other.m_height;
    m_radius /= other.m_radius;
    return *this;
  }

  void amCapsule::init() {
    m_center.init();
    m_height = m_radius = 0;
  }


}

