/******************************************
 * @file amWinMath.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Includes Windows specific optimizations 
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
#include "amPLatformMath.h"

namespace amEngineSDK {
  struct amWinMath : public amPLatformMath {
    //using  = amMath::sqrt;
  };
}
