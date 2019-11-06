/******************************************
 * @file amVector4.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 4D vector
 *
 * @note
******************************************/
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
  namespace FORCE_INIT_VECTOR4 {
    enum E
    {
      kZERO = 0,
      kFRONT,
      kUP,
      kRIGHT,
      kCOUNT
    };
  }

  class AM_UTILITIES_EXPORT amVector4
  {
  public:
    amVector4();
    ~amVector4();

    static const amVector4 ZERO;
    static const amVector4 FRONT;
    static const amVector4 UP;
    static const amVector4 RIGHT;

    /**
    ************************
    *  @brief Constructor for firectional constants
    ************************
    */
    amVector4
    (const uint32 val);

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
    operator -=(const amVector4& other);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator +=(const amVector4& other);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator *=(const float& f);

    /***********************
    *  @brief 
    ***********************/
    amVector4&
    operator = (const amVector4& other);

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator *(const float& f) const;

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator /(const float& f) const;

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator -(const amVector4& other) const;

    /***********************
    *  @brief 
    ***********************/
    amVector4
    operator +(const amVector4& other) const;

    /***********************
    *  @brief Normalizes this vector to be of unit length
    ***********************/
    void 
    Normalize();

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
    DotNormalized(amVector4& ProjectedOn);

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

    /*const float*
    getVecArr();*/
    
    float x;
    float y;
    float z;
    float w;
  };
}
