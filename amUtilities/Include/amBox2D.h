/*****************************************************************************/
/**
 * @file    amBox2D.h
 * @author  Andrés Sumano (andressumano@hotmail.com)
 * @date    2018/6/22
 * @brief   Implements a rectangular 2D Box.
 *
 * Implements a rectangular 2D Box.
 *
 * @bug     No known bugs.
 */
/*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
/*****************************************************************************/
#include "amPrerequisitesUtilities.h"
#include "amVector2.h"

namespace amEngineSDK {
  class amBox2D
  {
   public:
    amBox2D();
    ~amBox2D();


    /**
     *  @brief Make box be the same as the given box
     */
    amBox2D& 
    operator =(const amBox2D& other);

    /***********************
    *  @brief Moves the center point by the given vector
    ***********************/
    amBox2D& 
    operator +(const amVector2& vec);

    /***********************
    *  @brief Returns the sums all components of both boxes
    ***********************/
    amBox2D 
    operator +(const amBox2D& box);

    /***********************
    *  @brief Returns a box with the difference of all components of both boxes
    ***********************/
    amBox2D 
    operator -(const amBox2D& box);

    /***********************
    *  @brief Returns product of all components of both boxes
    ***********************/
    amBox2D 
    operator *(const amBox2D& box);

    /***********************
    *  @brief Division not implemented because of danger of /0
    ***********************/
    //amBox2D operator/(const amBox2D& box);

    /***********************
    *  @brief Returns a modified box with the sum of the boxes
    ***********************/
    amBox2D& 
    operator +=(const amBox2D& box);
    /***********************
    *  @brief Returns a modified box with the difference of the boxes
    ***********************/
    amBox2D& 
    operator -=(const amBox2D& box);
    /***********************
    *  @brief Returns a modified box with the product of the boxes
    ***********************/
    amBox2D& 
    operator *=(const amBox2D& box);

    /***********************
    *  @brief Division not implemented because of danger of /0
    ***********************/
    //amBox2D& 
    //operator/=(const amBox2D& box);

    /***********************
    *  @brief Calculates if a vector is inside the box
    ***********************/
    bool 
    isInside(const amVector2 & vec);

    /***********************
    *  @brief Scales h & w by a scalar, keeps aspect ratio
    ***********************/
    void 
    scale(const float& scale);

    /***********************
    *  @brief Move the box's center to the position given by the vector
    ***********************/
    void 
    moveTo(const amVector2& newPos);

    /***********************
    *  @brief Flips h & w values
    ***********************/
    void 
    flip();

    amVector2 m_center;
    float h;
    float w;
  };
}


