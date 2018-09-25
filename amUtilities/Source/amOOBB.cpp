#include "amOOBB.h"


namespace amEngineSDK {
  amOOBB::amOOBB() {}

  amOOBB::~amOOBB() {}

  amOOBB::amOOBB(const amOOBB & other) {}


  amOOBB & amOOBB::operator=(const amOOBB & other) {
    return *this;
  }

  amOOBB amOOBB::operator+(const amOOBB & other) {
    return amOOBB();
  }

  amOOBB amOOBB::operator-(const amOOBB & other) {
    return amOOBB();
  }

  amOOBB amOOBB::operator*(const amOOBB & other) {
    return amOOBB();
  }

  amOOBB amOOBB::operator/(const amOOBB & other) {
    return amOOBB();
  }

  amOOBB & amOOBB::operator+=(const amOOBB & other) {
    return *this;
  }

  amOOBB & amOOBB::operator-=(const amOOBB & other) {
    return *this;
  }

  amOOBB & amOOBB::operator*=(const amOOBB & other) {
    return *this;
  }

  amOOBB & amOOBB::operator/=(const amOOBB & other) {
    return *this;
  }
}

