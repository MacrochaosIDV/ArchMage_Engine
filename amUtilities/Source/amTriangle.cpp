/******************************************
 * @file amTriangle.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the triangle
 *
 * @note
******************************************/
#include "amTriangle.h"

namespace amEngineSDK {
  amTriangle::amTriangle() {}


  amTriangle::~amTriangle() {}

  amEngineSDK::amTriangle::amTriangle(const amTriangle& other) {
    m_v0 = other.m_v0;
    m_v1 = other.m_v1;
    m_v2 = other.m_v2;
  }

  amTriangle & amEngineSDK::amTriangle::operator=(const amTriangle & other) {
    m_v0 = other.m_v0;
    m_v1 = other.m_v1;
    m_v2 = other.m_v2;
    return *this;
  }

  amTriangle amEngineSDK::amTriangle::operator+(const amTriangle & other) const {
    amTriangle res;
    res.m_v0 = m_v0 + other.m_v0;
    res.m_v1 = m_v1 + other.m_v1;
    res.m_v2 = m_v2 + other.m_v2;
    return res;
  }

  amTriangle amEngineSDK::amTriangle::operator-(const amTriangle & other) const {
    amTriangle res;
    res.m_v0 = m_v0 - other.m_v0;
    res.m_v1 = m_v1 - other.m_v1;
    res.m_v2 = m_v2 - other.m_v2;
    return res;
  }

  amTriangle amEngineSDK::amTriangle::operator*(const amTriangle & other) const {
    amTriangle res;
    res.m_v0 = m_v0 * other.m_v0;
    res.m_v1 = m_v1 * other.m_v1;
    res.m_v2 = m_v2 * other.m_v2;
    return res;
  }

  amTriangle amEngineSDK::amTriangle::operator/(const amTriangle & other) const {
    amTriangle res;
    res.m_v0 = m_v0 / other.m_v0;
    res.m_v1 = m_v1 / other.m_v1;
    res.m_v2 = m_v2 / other.m_v2;
    return res;
  }

  amTriangle & amEngineSDK::amTriangle::operator+=(const amTriangle & other) {
    m_v0 += other.m_v0;
    m_v1 += other.m_v1;
    m_v2 += other.m_v2;
    return *this;
  }

  amTriangle & amEngineSDK::amTriangle::operator-=(const amTriangle & other) {
    m_v0 -= other.m_v0;
    m_v1 -= other.m_v1;
    m_v2 -= other.m_v2;
    return *this;
  }

  amTriangle & amEngineSDK::amTriangle::operator*=(const amTriangle & other) {
    m_v0 *= other.m_v0;
    m_v1 *= other.m_v1;
    m_v2 *= other.m_v2;
    return *this;
  }

  amTriangle & amEngineSDK::amTriangle::operator/=(const amTriangle & other) {
    m_v0 /= other.m_v0;
    m_v1 /= other.m_v1;
    m_v2 /= other.m_v2;
    return *this;
  }

}


