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
  namespace amDXFormats {
    enum E
    {
      kFORMAT_UNKNOWN = 0,
      kFORMAT_R32G32B32A32_TYPELESS,
      kFORMAT_R32G32B32A32_FLOAT,
      kFORMAT_R32G32B32A32_UINT,
      kFORMAT_R32G32B32A32_SINT,
      kFORMAT_R32G32B32_TYPELESS,
      kFORMAT_R32G32B32_FLOAT,
      kFORMAT_R32G32B32_UINT,
      kFORMAT_R32G32B32_SINT,
      kFORMAT_R16G16B16A16_TYPELESS,
      kFORMAT_R16G16B16A16_FLOAT,
      kFORMAT_R16G16B16A16_UNORM,
      kFORMAT_R16G16B16A16_UINT,
      kFORMAT_R16G16B16A16_SNORM,
      kFORMAT_R16G16B16A16_SINT,
      kFORMAT_R32G32_TYPELESS,
      kFORMAT_R32G32_FLOAT,
      kFORMAT_R32G32_UINT,
      kFORMAT_R32G32_SINT,
      kFORMAT_R32G8X24_TYPELESS,
      kFORMAT_D32_FLOAT_S8X24_UINT,
      kFORMAT_R32_FLOAT_X8X24_TYPELESS,
      kFORMAT_X32_TYPELESS_G8X24_UINT,
      kFORMAT_R10G10B10A2_TYPELESS,
      kFORMAT_R10G10B10A2_UNORM,
      kFORMAT_R10G10B10A2_UINT,
      kFORMAT_R11G11B10_FLOAT,
      kFORMAT_R8G8B8A8_TYPELESS,
      kFORMAT_R8G8B8A8_UNORM,
      kFORMAT_R8G8B8A8_UNORM_SRGB,
      kFORMAT_R8G8B8A8_UINT,
      kFORMAT_R8G8B8A8_SNORM,
      kFORMAT_R8G8B8A8_SINT,
      kFORMAT_R16G16_TYPELESS,
      kFORMAT_R16G16_FLOAT,
      kFORMAT_R16G16_UNORM,
      kFORMAT_R16G16_UINT,
      kFORMAT_R16G16_SNORM,
      kFORMAT_R16G16_SINT,
      kFORMAT_R32_TYPELESS,
      kFORMAT_D32_FLOAT,
      kFORMAT_R32_FLOAT,
      kFORMAT_R32_UINT,
      kFORMAT_R32_SINT,
      kFORMAT_R24G8_TYPELESS,
      kFORMAT_D24_UNORM_S8_UINT,
      kFORMAT_R24_UNORM_X8_TYPELESS,
      kFORMAT_X24_TYPELESS_G8_UINT,
      kFORMAT_R8G8_TYPELESS,
      kFORMAT_R8G8_UNORM,
      kFORMAT_R8G8_UINT,
      kFORMAT_R8G8_SNORM,
      kFORMAT_R8G8_SINT,
      kFORMAT_R16_TYPELESS,
      kFORMAT_R16_FLOAT,
      kFORMAT_D16_UNORM,
      kFORMAT_R16_UNORM,
      kFORMAT_R16_UINT,
      kFORMAT_R16_SNORM,
      kFORMAT_R16_SINT,
      kFORMAT_R8_TYPELESS,
      kFORMAT_R8_UNORM,
      kFORMAT_R8_UINT,
      kFORMAT_R8_SNORM,
      kFORMAT_R8_SINT,
      kFORMAT_A8_UNORM,
      kFORMAT_R1_UNORM,
      kFORMAT_R9G9B9E5_SHAREDEXP,
      kFORMAT_R8G8_B8G8_UNORM,
      kFORMAT_G8R8_G8B8_UNORM,
      kFORMAT_BC1_TYPELESS,
      kFORMAT_BC1_UNORM,
      kFORMAT_BC1_UNORM_SRGB,
      kFORMAT_BC2_TYPELESS,
      kFORMAT_BC2_UNORM,
      kFORMAT_BC2_UNORM_SRGB,
      kFORMAT_BC3_TYPELESS,
      kFORMAT_BC3_UNORM,
      kFORMAT_BC3_UNORM_SRGB,
      kFORMAT_BC4_TYPELESS,
      kFORMAT_BC4_UNORM,
      kFORMAT_BC4_SNORM,
      kFORMAT_BC5_TYPELESS,
      kFORMAT_BC5_UNORM,
      kFORMAT_BC5_SNORM,
      kFORMAT_B5G6R5_UNORM,
      kFORMAT_B5G5R5A1_UNORM,
      kFORMAT_B8G8R8A8_UNORM,
      kFORMAT_B8G8R8X8_UNORM,
      kFORMAT_R10G10B10_XR_BIAS_A2_UNORM,
      kFORMAT_B8G8R8A8_TYPELESS,
      kFORMAT_B8G8R8A8_UNORM_SRGB,
      kFORMAT_B8G8R8X8_TYPELESS,
      kFORMAT_B8G8R8X8_UNORM_SRGB,
      kFORMAT_BC6H_TYPELESS,
      kFORMAT_BC6H_UF16,
      kFORMAT_BC6H_SF16,
      kFORMAT_BC7_TYPELESS,
      kFORMAT_BC7_UNORM,
      kFORMAT_BC7_UNORM_SRGB,
      kFORMAT_AYUV,
      kFORMAT_Y410,
      kFORMAT_Y416,
      kFORMAT_NV12,
      kFORMAT_P010,
      kFORMAT_P016,
      kFORMAT_420_OPAQUE,
      kFORMAT_YUY2,
      kFORMAT_Y210,
      kFORMAT_Y216,
      kFORMAT_NV11,
      kFORMAT_AI44,
      kFORMAT_IA44,
      kFORMAT_P8,
      kFORMAT_A8P8,
      kFORMAT_B4G4R4A4_UNORM,
      kFORMAT_P208,
      kFORMAT_V208,
      kFORMAT_V408,
      kFORMAT_FORCE_UINT,
      kCOUNT
    };
  }
  namespace amDXSRV_Types {
    enum E
    {
      kSRV_UNKNOWN = 0,
      kSRV_BUFFER = 1,
      kSRV_TEXTURE1D = 2,
      kSRV_TEXTURE1DARRAY = 3,
      kSRV_TEXTURE2D = 4,
      kSRV_TEXTURE2DARRAY = 5,
      kSRV_TEXTURE2DMS = 6,
      kSRV_TEXTURE2DMSARRAY = 7,
      kSRV_TEXTURE3D = 8,
      kSRV_TEXTURECUBE = 9,
      kSRV_TEXTURECUBEARRAY = 10,
      kSRV_BUFFEREX = 11,
      kCOUNT
    };
  }
}
