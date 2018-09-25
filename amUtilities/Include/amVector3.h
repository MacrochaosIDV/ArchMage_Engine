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
    *  @brief Operator * multiplies the vector components
    ***********************/
    amVector3 
    operator*(const amVector3& other) const;

    /***********************
    *  @brief Operator * multiplies the vector components
    ***********************/
    amVector3 
    operator/(const amVector3& other) const;

    /***********************
    *  @brief Operator == checks for vectors being the same
    ***********************/
    bool 
    operator ==(const amVector3 & other) const;

    /***********************
    *  @brief Does the cross product & returns it
    ***********************/
    amVector3 
    operator ^(const amVector3 & other) const;

    /***********************
    *  @brief Operator for Dot product
    ***********************/
    float
    operator |(const amVector3 & other) const;
    /***********************
    *  @brief 
    ***********************/
    amVector3& 
    operator -=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3& 
    operator +=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3&
    operator *=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3&
    operator /=(const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3& 
    operator *=(const float & f);

    /***********************
    *  @brief 
    ***********************/
    amVector3& 
    operator = (const amVector3 & other);

    /***********************
    *  @brief 
    ***********************/
    amVector3 
    operator *(const float & f) const;

    /***********************
    *  @brief 
    ***********************/
    amVector3 
    operator /(const float & f) const;

    /***********************
    *  @brief 
    ***********************/
    amVector3 
    operator -(const amVector3 & other) const;

    /***********************
    *  @brief 
    ***********************/
    amVector3 
    operator +(const amVector3 & other) const;

    /***********************
    *  @brief Normalizes this vector to be of unit length
    ***********************/
    void 
    Normalize();

    /***********************
    *  @brief Return the normalizes version of this vector without modifying it
    ***********************/
    amVector3 
    getNormalized() const;

    /***********************
    *  @brief Returns the Magnitude of this vector
    ***********************/
    float 
    Mag() const;

    /***********************
    *  @brief Returns the value of the Dot product of this vector projected on the other
    ***********************/
    float 
    DotNormalized(const amVector3 & ProjectedOn) const;

    /***********************
    *  @brief Return a vector perpendicular to this and the other vector
    ***********************/
    amVector3 
    cross3(const amVector3 & other) const;

    /***********************
    *  @brief Checks if all the components in this vector are exactly 0
    ***********************/
    bool 
    isZero() const;

    float
    getDeterminant(const amVector3 & other) const;

    float x; 
    float y; 
    float z;
  };
}

