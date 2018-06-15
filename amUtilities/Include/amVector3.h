#pragma once
#include "amMath.h"
namespace amEngineSDK {
  class amVector3
  {
  public:
    amVector3();
    ~amVector3();

    amVector3& operator = (const amVector3 & other);
    amVector3& operator +=(const amVector3 & other);
    amVector3 operator *(const float & f);
    amVector3& operator *=(const float & f);
    amVector3 operator /(const float & f);
    amVector3 operator -(const amVector3 & other);
    amVector3 operator +(const amVector3 & other);
    void Normalize();
    amVector3 getNormalized();
    float Mag();
    float DotNormalized(amVector3 & ProjectedOn);

    float x;
    float y;
    float z;
  };
}

