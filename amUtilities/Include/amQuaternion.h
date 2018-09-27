/******************************************
 * @file amQuaternion.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a Quaternion
 *
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
#include "amVector3.h"

namespace amEngineSDK {
  class amQuaternion
  {
  public:
    amQuaternion();
    ~amQuaternion();

    /***********************
    *  @brief Copy constructor from another quaternion
    ***********************/
    amQuaternion
    (const amQuaternion& quat);;

    /***********************
    *  @brief Operator* returns conatenated quats and thier rotations
    ***********************/
    amQuaternion 
    operator*(const amQuaternion& other);

    /***********************
    *  @brief Ope *= does Ope* to this quat
    ***********************/
    amQuaternion&
    operator*=(const amQuaternion& other);

    /***********************
    *  @brief Constructor from vector and w value
    ***********************/
    amQuaternion
    (const float& _x, const float _y, const float _z, const float _w);

   
    /***********************
    *  @brief Returns a quat with all its components multiplied by f
    ***********************/
    amQuaternion 
    operator *(const float & f);

    /***********************
    *  @brief Returns the dot product of this quat projected onto the given quat
    ***********************/
    float 
    quatDot(const amQuaternion& projectedOn);

    /***********************
    *  @brief Interpolates two quat rotations by f
    ***********************/
    amQuaternion 
    sLerp(amQuaternion& other, float& t);

    /***********************
    *  @brief Exponetializes this quat by the given value of exp
    ***********************/
    amQuaternion&
    quatPow(float& exp);

    /***********************
    *  @brief Initializes the quaternion on 0s
    ***********************/
    void init();

    /***********************
    *  @brief Initializes the quaternion as identity
    ***********************/
    void initIdentity();

    /***********************
    *  @brief Rotates the quaternion around the X axis
    ***********************/
    void rotateAroundX(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Y axis
    ***********************/
    void rotateAroundY(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Z axis
    ***********************/
    void rotateAroundZ(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Given axis
    ***********************/
    void rotateAroundAxis(const amVector3 &axis, const float& theta);

    /***********************
    *  @brief Normalizes this quat
    ***********************/
    void 
    quatNormalize();

    /***********************
    *  @brief Returns the magnitude of this quat
    ***********************/
    float 
    quatMag();

    amVector3 
    getQuatVector();

    
    float x;
    float y;
    float z;
    float w;

  };
}


