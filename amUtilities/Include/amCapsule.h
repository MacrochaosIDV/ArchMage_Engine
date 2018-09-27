/******************************************
 * @file amCapsule.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 3d capsule
 *
 *
 * @note Not yet implemented
******************************************/
#pragma once
/***********************
*
*  Includes
*
***********************/
#include "amVector3.h"

namespace amEngineSDK {
  class amCapsule
  {
  public:
    amCapsule();
    ~amCapsule();
    
    /***********************
    *  @brief Copy constructor
    ***********************/
    amCapsule(const amCapsule& other);


    /***********************
    *  @brief Makes this capsule a copy of the other capsule
    ***********************/
    amCapsule& operator=(const amCapsule& other);

    /***********************
    *  @brief Returns a capsule with its height & radius added
    ***********************/
    amCapsule operator+(const amCapsule& other);

    /***********************
    *  @brief Returns a capsule with its height & radius subtracted
    ***********************/
    amCapsule operator-(const amCapsule& other);

    /***********************
    *  @brief Returns a capsule with its height & radius multiplied
    ***********************/
    amCapsule operator*(const amCapsule& other);

    /***********************
    *  @brief Returns a capsule with its height & radius divided
    ***********************/
    amCapsule operator/(const amCapsule& other);
    
    /***********************
    *  @brief Adds the height & radius of the other capsule to this capsule
    ***********************/
    amCapsule& operator+=(const amCapsule& other);

    /***********************
    *  @brief Subtracts the height & radius of the other capsule to this capsule
    ***********************/
    amCapsule& operator-=(const amCapsule& other);

    /***********************
    *  @brief Multiplies the height & radius of the other capsule to this capsule
    ***********************/
    amCapsule& operator*=(const amCapsule& other);

    /***********************
    *  @brief Divides the height & radius of the other capsule to this capsule
    ***********************/
    amCapsule& operator/=(const amCapsule& other);

    /***********************
    *  @brief Initializes all components to 0s
    ***********************/


    amVector3 m_center;
    float m_radius;
    float m_height;

  };
}


