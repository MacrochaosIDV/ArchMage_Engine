/******************************************
 * @file amFrustrum.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 3D Frustrum
 *
 * TODO: long description
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
#include "amPlane.h"
#include "amMath.h"


namespace amEngineSDK {
  namespace FRUSTRUM_PLANES {
    enum E {
      NEAR,
      FAR,
      LEFT,
      RIGHT,
      TOP,
      BOTTOM,
      COUNT
    };
  }

  class amFrustrum
  {
  public:
    amFrustrum();
    ~amFrustrum();

    /***********************
    *  @brief Copy constructor
    ***********************/
    amFrustrum(const amFrustrum& other);

    /***********************
    *  @brief Initializes from a view projection matrix
    ***********************/
    amFrustrum(const amMatrix4x4& VP);

   
    amFrustrum& 
    operator=(const amFrustrum& other);

    amFrustrum 
    operator+(const amFrustrum& other)const;
    amFrustrum 
    operator-(const amFrustrum& other)const;
    amFrustrum 
    operator*(const amFrustrum& other)const;
    amFrustrum 
    operator/(const amFrustrum& other)const;

    amFrustrum& 
    operator+=(const amFrustrum& other);
    amFrustrum& 
    operator-=(const amFrustrum& other);
    amFrustrum& 
    operator*=(const amFrustrum& other);
    amFrustrum& 
    operator/=(const amFrustrum& other);

    /******************************************
     * 
     * @brief Checks for intersects with another frustrum
     *
     * @param the other frustrum
     *
     * @returns true if is intersecting with the other frustrum
     *
    ******************************************/
    bool
    intersects(const amFrustrum& other);
    
    amPlane m_planes[FRUSTRUM_PLANES::COUNT];
  };
}


