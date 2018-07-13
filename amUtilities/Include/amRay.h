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
  class amRay
  {
  public:
    amRay();
    ~amRay();

    amRay(const amRay& other);

    amRay& operator=(const amRay& other);

    amRay operator+(const amRay& other);
    amRay operator-(const amRay& other);
    amRay operator*(const amRay& other);
    amRay operator/(const amRay& other);

    amRay& operator+=(const amRay& other);
    amRay& operator-=(const amRay& other);
    amRay& operator*=(const amRay& other);
    amRay& operator/=(const amRay& other);

    void init();
  };
}


