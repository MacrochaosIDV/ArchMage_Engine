#include "amSphere.h"
#include "amMath.h"


namespace amEngineSDK {
  amSphere::amSphere() {}

  amSphere::~amSphere() {}

  amSphere::amSphere(const amSphere & other) {
    m_center = other.m_center;
    m_radius = other.m_radius;
  }

  amSphere::amSphere(const amVector3 & vec, const float & radius) {
    m_center = vec; m_radius = radius;
  }

  amSphere& amSphere::operator=(const amSphere & other) {
    m_center = other.m_center; 
    m_radius = other.m_radius;
    return *this;
  }

  amSphere amSphere::operator+(const amSphere & other) const {
    amSphere res = *this;
    res.m_center += other.m_center;
    res.m_radius += other.m_radius;
    return res;
  }

  amSphere amSphere::operator-(const amSphere & other) const {
    amSphere res = *this;
    res.m_center -= other.m_center;
    res.m_radius -= other.m_radius;
    return res;
  }

  amSphere amSphere::operator*(const amSphere & other) const {
    amSphere res = *this;
    res.m_center *= other.m_center;
    res.m_radius *= other.m_radius;
    return res;
  }

  amSphere amSphere::operator/(const amSphere & other)const {
    amSphere res = *this;
    res.m_center /= other.m_center;
    res.m_radius /= other.m_radius;
    return res;
  }

  amSphere & amSphere::operator+=(const amSphere & other) {
    m_center += other.m_center;
    m_radius += other.m_radius;
    return *this;
  }

  amSphere & amSphere::operator-=(const amSphere & other) {
    m_center -= other.m_center;
    m_radius -= other.m_radius;
    return *this;
  }

  amSphere & amSphere::operator*=(const amSphere & other) {
    m_center *= other.m_center;
    m_radius *= other.m_radius;
    return *this;
  }

  amSphere & amSphere::operator/=(const amSphere & other) {
    m_center /= other.m_center;
    m_radius /= other.m_radius;
    return *this;
  }

  bool amSphere::intersects(const amVector3 & vec) const{
    return amMath::intersects(vec, *this);
  }

  bool amSphere::intersects(const amSphere & other) const {
    return ((other.m_center - m_center).Mag() <= (m_radius + other.m_radius)) ? true : false;
  }
}

