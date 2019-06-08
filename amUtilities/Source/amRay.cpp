/******************************************
 * @file amRay.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the ray
 *
 *
 * @note
******************************************/
#include "amRay.h"

namespace amEngineSDK {
  amRay::amRay() {}

  amRay::~amRay() {}

  amRay::amRay(const amRay & other) {
    m_dir = other.m_dir;
    m_pos = other.m_pos;
  }

  amRay::amRay(const amVector3 & dir, const amVector3 & pos) {
    m_dir = dir;
    m_pos = pos;
  }

  amRay 
  amRay::operator=(const amRay & other) {
    m_dir = other.m_dir;
    m_pos = other.m_pos;
    return *this;
  }

  amRay 
  amRay::operator+(const amRay & other) const {
    amRay res = *this;
    res.m_pos += other.m_pos;
    res.m_dir += other.m_dir;
    return res;
  }

  amRay 
  amRay::operator-(const amRay & other) const {
    amRay res = *this;
    res.m_pos -= other.m_pos;
    res.m_dir -= other.m_dir;
    return res;
  }

  amRay 
  amRay::operator*(const amRay & other) const {
    amRay res = *this;
    res.m_pos *= other.m_pos;
    res.m_dir *= other.m_dir;
    return res;
  }

  amRay 
  amRay::operator/(const amRay & other) const {
    amRay res = *this;
    res.m_pos /= other.m_pos;
    res.m_dir /= other.m_dir;
    return res;
  }

  amRay & 
  amRay::operator+=(const amRay & other) {
    m_pos += other.m_pos;
    m_dir += other.m_dir;
    return *this;
  }

  amRay & 
  amRay::operator-=(const amRay & other) {
    m_pos -= other.m_pos;
    m_dir -= other.m_dir;
    return *this;
  }

  amRay & 
  amRay::operator*=(const amRay & other) {
    m_pos *= other.m_pos;
    m_dir *= other.m_dir;
    return *this;
  }

  amRay & 
  amRay::operator/=(const amRay & other) {
    m_pos /= other.m_pos;
    m_dir /= other.m_dir;
    return *this;
  }

  bool 
  amRay::intersects(const amRay & other) const {
    other;
    return false;
  }
}
