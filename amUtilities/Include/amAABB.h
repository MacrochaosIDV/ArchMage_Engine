/******************************************
 * @file amAABB.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 3D Axis Aligned Bounding Box
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
#include "amVector3.h"
#include "amMath.h"

namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amAABB
  {
   public:
    amAABB();
    ~amAABB();

    /***********************
    *  @brief Copy constructor
    ***********************/
    amAABB(const amAABB& other);

    /***********************
    *  @brief Make this box a copy of the given box
    ***********************/
    amAABB& 
    operator=(const amAABB& other);

    amAABB
    operator+(const amAABB& other) const;

    amAABB
    operator-(const amAABB& other) const;
    
    amAABB
    operator*(const amAABB& other) const;
    
    amAABB
    operator/(const amAABB& other) const;

    amAABB&
    operator+=(const amAABB& other);
    
    amAABB&
    operator-=(const amAABB& other);
    
    amAABB&
    operator*=(const amAABB& other);
    
    amAABB&
    operator/=(const amAABB& other);

    /***********************
    *  @brief Adds a point/vector to the box volume
    ***********************/
    void
    add(const amVector3& vec);


    /******************************************
    *
    * @brief Checks for intersects with another AABB
    *
    * @param the other AABB
    *
    * @returns true if is intersecting with the other AABB
    *
    ******************************************/
    bool
    intersects(const amAABB& other);

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


    /***********************
    *  @brief 
    ***********************/
    amAABB
    setToTransformedBox();

    /*property MxMymz {
      return amVector3(m_pMax.x, m_pMax.y, m_pMin.z);
    }*/

   public:
    amVector3 m_pMin;
    amVector3 m_pMax;
  };
}
