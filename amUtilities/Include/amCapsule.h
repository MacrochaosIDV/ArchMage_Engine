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
    void init();

    amVector3 m_center;
    float m_radius;
    float m_height;

  };
}


