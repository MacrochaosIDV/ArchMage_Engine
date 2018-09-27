/******************************************
 * @file amTriangle.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 3D triangle 
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
  class amTriangle
  {
  public:
    amTriangle();
    ~amTriangle();

    amTriangle(const amTriangle& other);

    amTriangle& operator=(const amTriangle& other);

    amTriangle 
    operator+(const amTriangle& other) const;
    amTriangle 
    operator-(const amTriangle& other) const;
    amTriangle 
    operator*(const amTriangle& other) const;
    amTriangle 
    operator/(const amTriangle& other) const;

    amTriangle& 
    operator+=(const amTriangle& other);
    amTriangle& 
    operator-=(const amTriangle& other);
    amTriangle& 
    operator*=(const amTriangle& other);
    amTriangle& 
    operator/=(const amTriangle& other);

    amVector3 m_v0;
    amVector3 m_v1;
    amVector3 m_v2;
  };
}


