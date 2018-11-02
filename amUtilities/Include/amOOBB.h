/******************************************
 * @file amOOBB.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements an Object oriented bounded box
 *
 *
 * @note
******************************************/
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


