/**
***********************************************
 * @file amDXPreReqs.h
 * @date 2018/10/31
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief 
 *
 * TODO: long description
 *
 * @note
***********************************************
*/
#pragma once

/**
************************
*  Includes
************************
*/

#include <amPrerequisitesUtilities.h>
//#include <D3DX11async.h>
#include <windows.h>
#include <winnt.h>
#include <DXGI.h>
#include <D3Dcommon.h>
#include <d3d11.h>
#include <d3dcompiler.h>
//#include <xnamath.h>

/**
************************
*  Defines
************************
*/

#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    if defined(AM_STATIC_LIB)
#      define AM_GRAPHICSDX_EXPORT
#    else
#      if defined(AM_GRAPHICSDX_EXPORTS)
#        define AM_GRAPHICSDX_EXPORT __declspec( dllexport )
#      else
#        define AM_GRAPHICSDX_EXPORT __declspec( dllimport )
#      endif
#    endif
#  else // Any other compiler
#    if defined(AM_STATIC_LIB)
#      define AM_GRAPHICSDX_EXPORT
#    else
#      if defined(AM_GRAPHICSDX_EXPORTS)
#        define AM_GRAPHICSDX_EXPORT __attribute__( (dllexport) )
#      else
#        define AM_GRAPHICSDX_EXPORT __attribute__( (dllimport) )
#      endif
#    endif
#  endif
#  define AM_GRAPHICSDX_HIDDEN
#else //Linux / Mac settings
#  define AM_GRAPHICSDX_EXPORT __attribute__ ((visibility("default")))
#  define AM_GRAPHICSDX_HIDDEN __attribute__ ((visibility("hidden")))
#endif 
// DLL export for plug-ins
#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    define AM_PLUGIN_EXPORT __declspec(dllexport)
#  else
#    define AM_PLUGIN_EXPORT __attribute__(dllexport)
#  endif
#  define AM_GRAPHICSDX_HIDDEN
#else //Linux / Mac settings
#  define AM_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif



namespace amEngineSDK {

}