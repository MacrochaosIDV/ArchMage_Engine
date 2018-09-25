/***********************
*  @brief 
***********************/
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
    operator+(const amFrustrum& other);
    amFrustrum 
    operator-(const amFrustrum& other);
    amFrustrum 
    operator*(const amFrustrum& other);
    amFrustrum 
    operator/(const amFrustrum& other);

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

    /******************************************
    *
    * @brief Checks for intersects with a capsule
    *
    * @param the capsule
    *
    * @returns true if is intersecting with the capsule
    *
    ******************************************/
    bool
    intersects(const amCapsule& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with a triangle
    *
    * @param the triangle
    *
    * @returns true if is intersecting with the triangle
    *
    ******************************************/
    bool
    intersects(const amTriangle& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with a sphere
    *
    * @param the sphere
    *
    * @returns true if is intersecting with the sphere
    *
    ******************************************/
    bool 
    intersects(const amSphere& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with an OOBB
    *
    * @param the OOBB
    *
    * @returns true if is intersecting with the OOBB
    *
    ******************************************/
    bool
    intersects(const amOOBB& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with an AABB
    *
    * @param the AABB
    *
    * @returns true if is intersecting with the AABB
    *
    ******************************************/
    bool
    intersects(const amAABB& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with a plane
    *
    * @param the plane
    *
    * @returns true if is intersecting with the plane
    *
    ******************************************/
    bool
    intersects(const amPlane& other) {
      return amMath::intersects(*this, other);
    }

    /******************************************
    *
    * @brief Checks for intersects with a ray
    *
    * @param the ray
    *
    * @returns true if is intersecting with the ray
    *
    ******************************************/
    bool
    intersects(const amRay& other) {
      return amMath::intersects(*this, other);
    }
    
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
    intersects(const amVector3& vec) {
      return amMath::intersects(vec, *this);
    }
    
    amPlane m_far;
    amPlane m_near;
    amPlane m_top;
    amPlane m_bottom;
    amPlane m_right;
    amPlane m_left;
  };
}


