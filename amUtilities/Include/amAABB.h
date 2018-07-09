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
  class amAABB
  {
  public:
    amAABB();
    ~amAABB();

    /***********************
    *  @brief Copy constructor
    ***********************/
    amAABB
    (const amAABB& other);

    /***********************
    *  @brief Make this box a copy of the given box
    ***********************/
    amAABB& 
    operator=(const amAABB& other);

    /***********************
    *  @brief Initializes the box
    ***********************/
    void 
    init();

    /***********************
    *  @brief Adds a point/vector to the box´s volume
    ***********************/
    void
    add(const amVector3& vec);

    /***********************
    *  @brief 
    ***********************/
    amAABB
    setToTransformedBox();

    amVector3 m_pMin;
    amVector3 m_pMax;
  };
}


