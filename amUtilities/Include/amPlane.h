/******************************************
 * @file amPlane.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 3D plane
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
#include "amTriangle.h"

namespace amEngineSDK{
  class amPlane : public amVector3 {
  public:
    amPlane();
    ~amPlane();

    /***********************
    *  @brief Copy constructor
    ***********************/
    amPlane
    (const amPlane& other);

    /***********************
    *  @brief Constructs a plane from 3 points/vectors in space
    ***********************/
    amPlane
    (const amVector3& a, const amVector3& b, const amVector3& c);

    /***********************
    *  @brief Constructor from a triangle
    ***********************/
    amPlane
    (const amTriangle& t);

    /***********************
    *  @brief Copies the other plane data onto this one
    ***********************/
    amPlane& 
    operator=(const amPlane& other);


    /***********************
    *  @brief 
    ***********************/
    amPlane
    operator+(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane
    operator-(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane
    operator*(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane
    operator/(const amPlane& other);


    /***********************
    *  @brief 
    ***********************/
    amPlane&
    operator+=(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane&
    operator-=(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane&
    operator*=(const amPlane& other);

    /***********************
    *  @brief 
    ***********************/
    amPlane&
    operator/=(const amPlane& other);

    /***********************
    *  @brief  Returns <0 if point in under the plane, >0 if above or 0 if on the plane
    ***********************/
    int8 whichSide(const amVector3& vec);

    /***********************
    *  @brief Returns distance to plane from given point
    ***********************/
    float distanceTo(const amVector3& vec);

    /******************************************
     * 
     * @brief Intersection check with another plane
     *
     * @param the other plane
     *
     * @returns true if the planes intersect
     *
    ******************************************/
    bool
    intersects(const amPlane& other) const;

    float d;
};
}


