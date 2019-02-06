/**
***********************************************
 * @file amPrerequisitesCore.h
 * @date 2018/12/04
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a 
***********************************************
*/
#pragma once
#include <amPrerequisitesUtilities.h>

/**
************************
*  Defines
************************
*/

#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    if defined(AM_STATIC_LIB)
#      define AM_CORE_EXPORT
#    else
#      if defined(AM_CORE_EXPORTS)
#        define AM_CORE_EXPORT __declspec( dllexport )
#      else
#        define AM_CORE_EXPORT __declspec( dllimport )
#      endif
#    endif
#  else // Any other compiler
#    if defined(AM_STATIC_LIB)
#      define AM_CORE_EXPORT
#    else
#      if defined(AM_CORE_EXPORTS)
#        define AM_CORE_EXPORT __attribute__( (dllexport) )
#      else
#        define AM_CORE_EXPORT __attribute__( (dllimport) )
#      endif
#    endif
#  endif
#  define AM_CORE_HIDDEN
#else //Linux / Mac settings
#  define AM_CORE_EXPORT __attribute__ ((visibility("default")))
#  define AM_CORE_HIDDEN __attribute__ ((visibility("hidden")))
#endif 
// DLL export for plug-ins
#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    define AM_PLUGIN_EXPORT __declspec(dllexport)
#  else
#    define AM_PLUGIN_EXPORT __attribute__(dllexport)
#  endif
#  define AM_CORE_HIDDEN
#else //Linux / Mac settings
#  define AM_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

#if AM_PLATFORM == AM_PLATFORM_WIN32
// Windows Header Files:
  #include <windows.h>

// C RunTime Header Files
  #include <stdlib.h>
  #include <malloc.h>
  #include <memory.h>
  #include <tchar.h>
#elif AM_PLATFORM == AM_PLATFORM_LINUX

#elif AM_PLATFORM == AM_PLATFORM_PS4

#elif AM_PLATFORM == AM_PLATFORM_ANDROID

#else

#endif