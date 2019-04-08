#pragma once
#include <OISInputManager.h>

#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    if defined(AM_STATIC_LIB)
#      define AM_INPUTMANAGER_EXPORT
#    else
#      if defined(AM_INPUTMANAGER_EXPORTS)
#        define AM_INPUTMANAGER_EXPORT __declspec( dllexport )
#      else
#        define AM_INPUTMANAGER_EXPORT __declspec( dllimport )
#      endif
#    endif
#  else // Any other compiler
#    if defined(AM_STATIC_LIB)
#      define AM_INPUTMANAGER_EXPORT
#    else
#      if defined(AM_INPUTMANAGER_EXPORTS)
#        define AM_INPUTMANAGER_EXPORT __attribute__( (dllexport) )
#      else
#        define AM_INPUTMANAGER_EXPORT __attribute__( (dllimport) )
#      endif
#    endif
#  endif
#  define AM_INPUTMANAGER_HIDDEN
#else //Linux / Mac settings
#  define AM_INPUTMANAGER_EXPORT __attribute__ ((visibility("default")))
#  define AM_INPUTMANAGER_HIDDEN __attribute__ ((visibility("hidden")))
#endif 
// DLL export for plug-ins
#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    define AM_PLUGIN_EXPORT __declspec(dllexport)
#  else
#    define AM_PLUGIN_EXPORT __attribute__(dllexport)
#  endif
#  define AM_INPUTMANAGER_HIDDEN
#else //Linux / Mac settings
#  define AM_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

