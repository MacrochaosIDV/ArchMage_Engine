/******************************************************************************
**
* @file    amVector3.h
* @author  Andrés Sumano (andressumano@hotmail.com)
* @date    2018/6/28
* @brief   Implements a 3D vector.
*
* Implements a 3D vector.
*
* @bug     No known bugs.
*
******************************************************************************/
#pragma once
/***********************
**
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"
#include "amMath.h"

namespace amEngineSDK {
  class amVector3
  {
  public:
    amVector3();
    ~amVector3();

    /***********************
    *  @brief Constructor from 3 float values
    ***********************/
    amVector3(const float& xx, const float& yy, const float& zz);

    /***********************
    *  @brief Copy constructor from another Vector3
    ***********************/
    amVector3(const amVector3& other);

    /***********************
    *  @brief 
    ***********************/
    amVector3& operator -=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3& operator +=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3& operator *=(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector3& operator = (const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3 operator *(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector3 operator /(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector3 operator -(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3 operator +(const amVector3 & other);

    /***********************
    *  @brief Normalizes this vector to be of unit length
    ***********************/
    void Normalize();

    /***********************
    *  @brief Initializes the vector on 0s
    ***********************/
    void 
    init();

    /***********************
    *  @brief Return the normalizes version of this vector without modifying it
    ***********************/
    amVector3 getNormalized();

    /***********************
    *  @brief Returns the Magnitude of this vector
    ***********************/
    float Mag();

    /***********************
    *  @brief Returns the value od the Dot product of this vector projected on the other
    ***********************/
    float DotNormalized(amVector3 & ProjectedOn);

    /***********************
    *  @brief Return a vector perpendicular to this and the other vector
    ***********************/
    amVector3 cross3(const amVector3 & other);

    /***********************
    *  @brief Checks if all the components in this vector are exactly 0
    ***********************/
    bool isZero();

    /*float x; 
    float y; 
    float z;*/
    union {
      struct { float x; float y; float z; };
      struct { float r; float g; float b; };
      struct { float i; float j; float k; };
    };// _m;
  };
}

