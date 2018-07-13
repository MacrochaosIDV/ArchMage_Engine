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
  class amBox
  {
  public:
    amBox();
    ~amBox();

    amBox(const amBox& other);

    amBox& operator=(const amBox& other);

    amBox operator+(const amBox& other);
    amBox operator-(const amBox& other);
    amBox operator*(const amBox& other);
    amBox operator/(const amBox& other);

    amBox& operator+=(const amBox& other);
    amBox& operator-=(const amBox& other);
    amBox& operator*=(const amBox& other);
    amBox& operator/=(const amBox& other);

    void init();
  };
}


