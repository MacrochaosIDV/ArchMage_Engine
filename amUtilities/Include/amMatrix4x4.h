/******************************************
 * @file amMatrix4x4.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 4x4 matrix
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
#include "amVector4.h"
#include "amMath.h"

namespace amEngineSDK {
  namespace FORCE_INIT {
    enum E
    {
      kZERO,
      kONE
    };
  }

  class AM_UTILITIES_EXPORT amMatrix4x4
  {
  public:
    amMatrix4x4();
    ~amMatrix4x4();

    static const amMatrix4x4 IDENTITY;
    static const amMatrix4x4 ZERO;

    /***********************
    *  @brief Copy constructor
    ***********************/
    amMatrix4x4(const amMatrix4x4& other);

    /***********************
    *  @brief Constructs the matrix with all values = val
    ***********************/
    amMatrix4x4(int32 val);

    /***********************
    *  @brief Constructs the matrix by individual params
    ***********************/
    amMatrix4x4(const float _m00, const float _m01, const float _m02, const float _m03,
                const float _m10, const float _m11, const float _m12, const float _m13,
                const float _m20, const float _m21, const float _m22, const float _m23,
                const float _m30, const float _m31, const float _m32, const float _m33);

    /***********************
    *  @brief Returns a multiplied matrix by the given scalar
    ***********************/
    amMatrix4x4 
    operator*(const float& f);

    /***********************
    *  @brief Makes this Matrix a copy of the given Matrix
    ***********************/
    amMatrix4x4& 
    operator=(const amMatrix4x4& other);

    /***********************
    *  @brief Returns a Matrix multiplied by the other
    ***********************/
    amMatrix4x4 
    operator*(const amMatrix4x4& other);

    /***********************
    *  @brief Orients/Rotates a vector using this matrix
    ***********************/
    amVector4 
    operator*(amVector4& V);


    amMatrix4x4&
    operator*=(const amMatrix4x4& other);

    /***********************
    *  @brief Initializes the matrix as the identity matrix
    ***********************/
    void 
    initIdentity();

    /***********************
    *  @brief Translates this matrix by the given amount in RADIANS (Left handed rotations)
    ***********************/
    amMatrix4x4& 
    translate(const float dx, const  float dy, const  float dz);

    /**
    ************************
    *  @brief Returns the matrix scaled by sx, sy, sz
    ************************
    */
    amMatrix4x4 
    scale(const float sx, const  float sy, const  float sz);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the X axis (Left handed rotations)
    ***********************/
    amMatrix4x4&
    rotateX(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Y axis (Left handed rotations)
    ***********************/
    amMatrix4x4&
    rotateY(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Z axis (Left handed rotations)
    ***********************/
    amMatrix4x4& 
    rotateZ(const float& theta);

    /**
    ************************
    *  @ brief Rotates this matrix by the given amount in RADIANS on the axis (Left handed rotations)
    ************************
    */
    amMatrix4x4&
    rotateAxis(const amVector3& axis, const  float ang);


    amMatrix4x4&
    setViewProjection(const float& FOV, const float& ratio, const float& zNear, const float& zFar);

    /***********************
    *  @brief Return the transposed of this matrix
    ***********************/
    amMatrix4x4& 
    transpose();

    amMatrix4x4
    transposed();


    amMatrix4x4
    lookAt(const amVector3& EyePos, const  amVector3& Target, const  amVector3& Up);

    /**
    ************************
    *  @brief Returns the inverse of this matrix
    ************************
    */
    amMatrix4x4 
    inverse();

    
    amMatrix4x4&
    fastInverse();

    /**
    ************************
    *  @brief Inverts this matrix
    ************************
    */
    amMatrix4x4& 
    invert();

    /**
    ************************
    *  @brief Extracts & returns the position of this matrix
    ************************
    */
    amVector3 
    getPosition();

    union {
      struct
      {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
      }_m;
      float m[4][4];
      amVector4 vec[4];
      float fvec[16];
    };
  };
}
