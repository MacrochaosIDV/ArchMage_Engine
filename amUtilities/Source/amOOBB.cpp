/******************************************
 * @file amOOBB.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the OOBB
 *
 *
 * @note
******************************************/
#include "amOOBB.h"


namespace amEngineSDK {
  amOOBB::amOOBB() {}

  amOOBB::~amOOBB() {}

  amOOBB::amOOBB(const amOOBB & other) {
    other;
  }


  amOOBB & amOOBB::operator=(const amOOBB & other) {
    other;
    return *this;
  }

  amOOBB amOOBB::operator+(const amOOBB & other) {
    other;
    return amOOBB();
  }

  amOOBB amOOBB::operator-(const amOOBB & other) {
    other;
    return amOOBB();
  }

  amOOBB amOOBB::operator*(const amOOBB & other) {
    other;
    return amOOBB();
  }

  amOOBB amOOBB::operator/(const amOOBB & other) {
    other;
    return amOOBB();
  }

  amOOBB & amOOBB::operator+=(const amOOBB & other) {
    other;
    return *this;
  }

  amOOBB & amOOBB::operator-=(const amOOBB & other) {
    other;
    return *this;
  }

  amOOBB & amOOBB::operator*=(const amOOBB & other) {
    other;
    return *this;
  }

  amOOBB & amOOBB::operator/=(const amOOBB & other) {
    other;
    return *this;
  }
}

