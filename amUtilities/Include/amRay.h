/******************************************
 * @file amRay.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a ray in 3D space
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
namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amRay
  {
  public:
    amRay();
    ~amRay();

    amRay
    (const amRay& other);

    amRay
    (const amVector3& dir, const amVector3& pos);

    amRay
    operator=(const amRay& other);

    amRay 
    operator+(const amRay& other) const;

    amRay 
    operator-(const amRay& other) const;

    amRay 
    operator*(const amRay& other) const;

    amRay 
    operator/(const amRay& other) const;

    amRay& 
    operator+=(const amRay& other);

    amRay& 
    operator-=(const amRay& other);

    amRay& 
    operator*=(const amRay& other);

    amRay& 
    operator/=(const amRay& other);

    bool
    intersects(const amRay& other) const;

    amVector3 m_pos;
    amVector3 m_dir;
  };
}
