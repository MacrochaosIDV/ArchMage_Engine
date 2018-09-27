/******************************************
 * @file amMatix4x4.h
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

  class amMatix4x4
  {
  public:
    amMatix4x4();
    ~amMatix4x4();

    static const amMatix4x4 IDENTITY;
    static const amMatix4x4 ZERO;

    /***********************
    *  @brief Copy constructor
    ***********************/
    amMatix4x4(amMatix4x4& other);

    /***********************
    *  @brief Constructs the matrix with all values = val
    ***********************/
    amMatix4x4(int32 val);

    /***********************
    *  @brief Returns a multiplied matrix by the gives scalar
    ***********************/
    amMatix4x4 operator*(const float& f);

    /***********************
    *  @brief Makes this Matrix a copy of the given Matrix
    ***********************/
    amMatix4x4& operator=(const amMatix4x4& other);

    /***********************
    *  @brief Returns a Matrix multiplied by the other
    ***********************/
    amMatix4x4 operator*(const amMatix4x4& other);

    /***********************
    *  @brief Orients/Rotates a vector using this matrix
    ***********************/
    amVector4 operator*(amVector4& V);


    /***********************
    *  @brief Initializes the matrix as the identity matrix
    ***********************/
    void initIdentity();

    /***********************
    *  @brief Translates this matrix by the given amount in RADIANS (Right handed rotations)
    ***********************/
    amMatix4x4 Translation_RH(float dx, float dy, float dz);

    /***********************
    *  @brief Translates this matrix by the given amount in RADIANS (Left handed rotations)
    ***********************/
    amMatix4x4 Translation_LH(float dx, float dy, float dz);

    amMatix4x4 Scaling(float sx, float sy, float sz);

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
    amMatix4x4 RotationX_RH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Y axis (Right handed rotations)
    ***********************/
    amMatix4x4 RotationY_RH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Z axis (Right handed rotations)
    ***********************/
    amMatix4x4 RotationZ_RH(const float& theta);


    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the X axis (Left handed rotations)
    ***********************/
    amMatix4x4 RotationX_LH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Y axis (Left handed rotations)
    ***********************/
    amMatix4x4 RotationY_LH(const float& theta);

    /***********************
    *  @brief Rotates this matrix by the given amount in RADIANS on the Z axis (Left handed rotations)
    ***********************/
    amMatix4x4 RotationZ_LH(const float& theta);

    amMatix4x4 perspectiveFOVLH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar);
    amMatix4x4 perspectiveFOVRH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar);

    /***********************
    *  @brief Return the transposed of this matrix
    ***********************/
    amMatix4x4 Transposed();

    /***********************
    *  @brief Transposes this matrix
    ***********************/
    //void 
    //Transpose();


    amMatix4x4 Fast_Inverse(amMatix4x4& M);

    //float Inverse(amMatix4x4 & M, amMatix4x4 & R);

    void foo() {
      //_m.m00
    }

    
    amMatix4x4 lookAt_RH(amVector4& EyePos, amVector4& Target, amVector4& Up);
    amMatix4x4 lookAt_LH(amVector4& EyePos, amVector4& Target, amVector4& Up);

    union
    {
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


