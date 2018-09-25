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
  class amOOBB
  {
  public:
    amOOBB();
    ~amOOBB();

    amOOBB(const amOOBB& other);

    amOOBB& operator=(const amOOBB& other);

    amOOBB operator+(const amOOBB& other);
    amOOBB operator-(const amOOBB& other);
    amOOBB operator*(const amOOBB& other);
    amOOBB operator/(const amOOBB& other);

    amOOBB& operator+=(const amOOBB& other);
    amOOBB& operator-=(const amOOBB& other);
    amOOBB& operator*=(const amOOBB& other);
    amOOBB& operator/=(const amOOBB& other);
  };
}


