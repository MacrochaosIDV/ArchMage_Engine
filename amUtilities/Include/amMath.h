/*doxygen comment here*/
#pragma once
/***********************
*
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"

#if AM_PLATFORM == AM_PLATFORM_WIN32
#include "amWinMath.h"
#elif AM_PLATFORM == AM_PLATFORM_PS4
#include "amPlatformMath.h"
#elif AM_PLATFORM == AM_PLATFORM_OSX
#include "amPlatformMath.h"
#else
#include "amPlatformMath.h"
#endif

namespace amEngineSDK {
#if AM_PLATFORM == AM_PLATFORM_WIN32
  using amMath = amWinMath;
#elif AM_PLATFORM == AM_PLATFORM_PS4
  using amMath = amPLatformMath;
#elif AM_PLATFORM == AM_PLATFORM_OSX
  using amMath = amPLatformMath;
#else
  using amMath = amPLatformMath;
#endif
}


