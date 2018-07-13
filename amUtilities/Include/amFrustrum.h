/***********************
*  @brief 
***********************/
#pragma once
/***********************
*
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"
#include "amVector3.h"

namespace amEngineSDK {
  class amFrustrum
  {
  public:
    amFrustrum();
    ~amFrustrum();

    amFrustrum(const amFrustrum& other);

    amFrustrum& operator=(const amFrustrum& other);

    amFrustrum operator+(const amFrustrum& other);
    amFrustrum operator-(const amFrustrum& other);
    amFrustrum operator*(const amFrustrum& other);
    amFrustrum operator/(const amFrustrum& other);

    amFrustrum& operator+=(const amFrustrum& other);
    amFrustrum& operator-=(const amFrustrum& other);
    amFrustrum& operator*=(const amFrustrum& other);
    amFrustrum& operator/=(const amFrustrum& other);

    void init();
  };
}


