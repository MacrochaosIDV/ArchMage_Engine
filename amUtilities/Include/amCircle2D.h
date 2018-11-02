/*****************************************************************************/
/**
 * @file    amBox2D.h
 * @author  Andrés Sumano (andressumano@hotmail.com)
 * @date    2018/6/25
 * @brief   Implements a 2D Circle.
 *
 * Implements a 2D Circle.
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
  class amCircle2D final
  {
   public:
    amCircle2D() = default;
    ~amCircle2D() = default;

    /***********************
    *  @brief 
    ***********************/
    amCircle2D 
    operator + (amCircle2D& cir)const;

    /***********************
    *  @brief
    ***********************/
    amCircle2D 
    operator - (amCircle2D& cir)const;

    /***********************
    *  @brief
    ***********************/
    amCircle2D 
    operator * (amCircle2D& cir)const;


    /***********************
    *  @brief Make circle be the same as the given circle
    ***********************/
    amCircle2D&
    operator = (amCircle2D& cir);

    /***********************
    *  @brief
    ***********************/
    amCircle2D& 
    operator += (amCircle2D& cir);

    /***********************
    *  @brief
    ***********************/
    amCircle2D& 
    operator -= (amCircle2D& cir);

    /***********************
    *  @brief
    ***********************/
    amCircle2D& 
    operator *= (amCircle2D& cir);


    /***********************
    *  @brief Moves the center point by the given vector
    ***********************/
    amCircle2D&
    operator += (amVector2& vec);

    /***********************
    *  @brief Calculates if a vector is inside the circle
    ***********************/
    bool
    isInside(const amVector2 & vec);

    /***********************
    *  @brief Expands the radius by f
    ***********************/
    void
    scale(const float& f);

    /***********************
    *  @brief Move the circle's center to the position given by the vector
    ***********************/
    void
    moveTo(const amVector2& newPos);

  private:
    amVector2 m_center;
    float r;
  };
}
