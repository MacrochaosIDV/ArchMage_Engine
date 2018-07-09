/******************************************************************************
**
* @file    amVector4.h
* @author  Andrés Sumano (andressumano@hotmail.com)
* @date    2018/6/28
* @brief   Implements a 4D vector.
*
* Implements a 4D vector.
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
#include "amVector3.h"

namespace amEngineSDK {
  class amVector4
  {
  public:
    amVector4();
    ~amVector4();

    /***********************
    *  @brief Constructor from 3 float values
    ***********************/
    amVector4
    (const float& xx, const float& yy, const float& zz, const float & ww);

    /***********************
    *  @brief Copy constructor from another Vector4
    ***********************/
    amVector4
    (const amVector4& other);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator -=(const amVector4 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator +=(const amVector4 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator *=(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator = (const amVector4 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator *(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator /(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator -(const amVector4 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator +(const amVector4 & other);

    /***********************
    *  @brief Normalizes this vector to be of unit length
    ***********************/
    void 
    Normalize();

    /***********************
    *  @brief Initializes the vector on 0s
    ***********************/
    void
    init();

    /***********************
    *  @brief Return the normalizes version of this vector without modifying it
    ***********************/
    amVector4 
    getNormalized();

    /***********************
    *  @brief Returns the Magnitude of this vector
    ***********************/
    float 
    Mag();

    /***********************
    *  @brief Returns the value of the Dot product of this vector projected on the other
    ***********************/
    float 
    DotNormalized(amVector4 & ProjectedOn);

    /***********************
    *  @brief Checks if all the components in this vector are exactly 0
    ***********************/
    bool 
    isZero();

    /***********************
    *  @brief 
    ***********************/
    amVector4
    cross3(const amVector4& vec);
    /*
    float x;
    float y;
    float z;
    float w;*/
    union 
    {
      struct { float x; float y; float z; float w; };// _vec;
      struct { float r; float g; float b; float a; };// _color;
      struct { float _w; float i; float j; float k; };// _quat;
      float v[4];
    };
    
  };
}

