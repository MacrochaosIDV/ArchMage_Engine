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
      ZERO,
      ONE
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


    /***********************
    *  @brief Initializes the matrix as the identity matrix
    ***********************/
    void 
    initIdentity();

    /***********************
    *  @brief Translates this matrix by the given amount in RADIANS (Right handed rotations)
    ***********************/
    amMatrix4x4 
    Translation_RH(float dx, float dy, float dz);

    /***********************
    *  @brief Translates this matrix by the given amount in RADIANS (Left handed rotations)
    ***********************/
    amMatrix4x4 
    Translation_LH(float dx, float dy, float dz);

    amMatrix4x4 
    Scaling(float sx, float sy, float sz);

    /*********************************************************************
    *
    *
    *  Matrix Rotations 
    *
    *
    *********************************************************************/

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the X axis (Right handed rotations)
    ***********************/
    amMatrix4x4 
    RotationX_RH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Y axis (Right handed rotations)
    ***********************/
    amMatrix4x4 
    RotationY_RH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Z axis (Right handed rotations)
    ***********************/
    amMatrix4x4 
    RotationZ_RH(const float& theta);


    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the X axis (Left handed rotations)
    ***********************/
    amMatrix4x4 
    RotationX_LH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Y axis (Left handed rotations)
    ***********************/
    amMatrix4x4 
    RotationY_LH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Z axis (Left handed rotations)
    ***********************/
    amMatrix4x4 
    RotationZ_LH(const float& theta);

    amMatrix4x4 
    perspectiveFOVLH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar);

    amMatrix4x4 
    perspectiveFOVRH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar);

    /***********************
    *  @brief Return the transposed of this matrix
    ***********************/
    amMatrix4x4 
    transposed();

    /***********************
    *  @brief Transposes this matrix
    ***********************/
    //void 
    //Transpose();


    amMatrix4x4 
    Fast_Inverse(amMatrix4x4& M);

    /**
    ************************
    *  @brief Returns the inverse of this matrix
    ************************
    */
    amMatrix4x4 
    inverse();

    /**
    ************************
    *  @brief Inverts this matrix
    ************************
    */
    void invert();

    
    amMatrix4x4 
    lookAt_RH(amVector4& EyePos, amVector4& Target, amVector4& Up);

    amMatrix4x4
    lookAt_LH(amVector4& EyePos, amVector4& Target, amVector4& Up);

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
