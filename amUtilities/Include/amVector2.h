#pragma once
#include "amMath.h"
namespace amEngineSDK {
  class amVector2
  {
  public:
    amVector2();
    ~amVector2();

    amVector2& operator = (const amVector2 & other);
    amVector2& operator +=(const amVector2 & other);
    amVector2 operator *(const float & f);
    amVector2& operator *=(const float & f);
    amVector2 operator /(const float & f);
    amVector2 operator -(const amVector2 & other);
    amVector2 operator +(const amVector2 & other);
    void Normalize();
    amVector2 getNormalized();
    float Mag();
    float DotNormalized(amVector2 & ProjectedOn);

    float x;
    float y;
  };
}


