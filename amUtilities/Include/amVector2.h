/*****************************************************************************/
/**
* @file    amBox2D.h
* @author  Andrés Sumano (andressumano@hotmail.com)
* @date    2018/6/22
* @brief   Implements a 2D Vector.
*
* Implements a 2D Vector.
*
* @bug     No known bugs.
*/
/*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
* Includes
*/
/*****************************************************************************/
#include "amPrerequisitesUtilities.h"
#include "amMath.h"

namespace amEngineSDK {
  class amVector2
  {
  public:
    amVector2();
    ~amVector2();

    /***********************
    *  @brief Make this vector the same as the given vector
    ***********************/
    amVector2& 
    operator = (const amVector2 & other);
    
    /***********************
    *  @brief Returns the difference between this and the given vector
    ***********************/
    amVector2 
    operator-(const amVector2& other) const;

    /***********************
    *  @brief Returns the sum of this and the given vector
    ***********************/
    amVector2 
    operator +(const amVector2 & other) const;

    /***********************
    *  @brief Returns the product of this and the given vector
    ***********************/
    amVector2 
    operator *(const amVector2 & other) const;

    /***********************
    *  @brief Sums the vectors
    ***********************/
    amVector2& 
    operator +=(const amVector2 & other);

    /***********************
    *  @brief Subtracts the given vector from this
    ***********************/
    amVector2& 
    operator -=(const amVector2 & other);

    /***********************
    *  @brief Multiplies this vector by the given vector
    ***********************/
    amVector2&
    operator *=(const amVector2 & other);

    /***********************
    *  @brief Multiplies this vector by f
    ***********************/
    amVector2& 
    operator *=(const float & f);

    /***********************
    *  @brief Returns a vector multiplied by f
    ***********************/
    amVector2 
    operator *(const float & f);

    /***********************
    *  @brief Returns a vector divided by f
    ***********************/
    amVector2 
    operator /(const float & f)const;

    /***********************
    *  @brief Makes the vector unit length
    ***********************/
    void 
    normalize();

    /***********************
    *  @brief Returns the would be unit length vector of this vector
    ***********************/
    amVector2 
    getNormalized();

    /***********************
    *  @brief Returns the length of this vector
    ***********************/
    float 
    Mag();

    /***********************
    *  @brief Returns the projection of this vector onto the given vector
    ***********************/
    float 
      dotNormalized(amVector2 & ProjectedOn);

    float x;
    float y;
  };
}


