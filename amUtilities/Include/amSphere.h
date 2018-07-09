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
    *  @brief Makes this sphere a copy of the given sphere
    ***********************/
    amSphere& operator=(const amSphere& other);

    /***********************
    *  @brief 
    ***********************/

    float m_radius;
    amVector3 m_center;
  };
}


