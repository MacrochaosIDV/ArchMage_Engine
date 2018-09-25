#pragma once
/***********************
*  @brief 
***********************/

/***********************
*
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"
#include "amVector3.h"
namespace amEngineSDK {
  class amSphere
  {
  public:
    amSphere();
    ~amSphere();

    /***********************
    *  @brief Copy constructor
    ***********************/
    amSphere(const amSphere& other);

    /***********************
    *  @brief Copy constructor
    ***********************/
    amSphere(const amVector3& vec, const float& radius);

    /***********************
    *  @brief Makes this sphere a copy of the given sphere
    ***********************/
    amSphere& operator=(const amSphere& other);

    amSphere operator+(const amSphere& other) const;
    amSphere operator-(const amSphere& other) const;
    amSphere operator*(const amSphere& other) const;
    amSphere operator/(const amSphere& other) const;

    amSphere& operator+=(const amSphere& other);
    amSphere& operator-=(const amSphere& other);
    amSphere& operator*=(const amSphere& other);
    amSphere& operator/=(const amSphere& other);

    /******************************************
    *
    * @brief Checks for intersects with another capsule
    *
    * @param the other capsule
    *
    * @returns true if is intersecting with the other capsule
    *
    ******************************************/
    bool
    intersects(const amSphere& other) const;

    /******************************************
    *
    * @brief Checks for intersects with a vector
    *
    * @param the vector
    *
    * @returns true if is intersecting with the vector
    *
    ******************************************/
    bool
    intersects(const amVector3& vec) const;

    float m_radius;
    amVector3 m_center;
  };
}


