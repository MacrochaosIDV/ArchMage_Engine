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
#include "amVector3.h"

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
    (const amVector3& vertex0, const amVector3& vertex1, const amVector3& vertex2);

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

    int8 whichSide(const amVector3& vec);


    float distanceTo(const amVector3& vec);

    float d;
};
}


