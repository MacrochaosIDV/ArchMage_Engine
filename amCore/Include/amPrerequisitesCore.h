/**
***********************************************
 * @file amPrerequisitesCore.h
 * @date 2018/12/04
 *
 * @author Andr�s Sumano
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
  //#include <stdlib.h>
  //#include <malloc.h>
  //#include <memory.h>
  //#include <tchar.h>
#elif AM_PLATFORM == AM_PLATFORM_LINUX

#elif AM_PLATFORM == AM_PLATFORM_PS4

#elif AM_PLATFORM == AM_PLATFORM_ANDROID

#else

#endif

namespace amEngineSDK {

  /**
  ************************
  *  Pre-defined paths to default textures
  ************************
  */
#define AM_MISSING_TEX "Resources/Textures/defaultTexture.png"
#define AM_BRDF_LUT_TEX "Resources/Textures/ibl_brdf_lut.png"
#define AM_NORMALS_TEX "Resources/Textures/defaultNormals.png"
#define AM_BLACK_TEX "Resources/Textures/pureBlack.png"
#define AM_GREY_TEX "Resources/Textures/midGrey.png"
#define AM_WHITE_TEX "Resources/Textures/pureWhite.png"

  namespace amResourceBindFlags {
    enum E
    {
      kBIND_VERTEX_BUFFER                 = 0x1L,
      kBIND_INDEX_BUFFER                  = 0x2L,
      kBIND_CONSTANT_BUFFER               = 0x4L,
      kBIND_SHADER_RESOURCE               = 0x8L,
      kBIND_STREAM_OUTPUT                 = 0x10L,
      kBIND_RENDER_TARGET                 = 0x20L,
      kBIND_DEPTH_STENCIL                 = 0x40L,
      kBIND_UNORDERED_ACCESS              = 0x80L,
      kBIND_DECODER                       = 0x200L,
      kBIND_VIDEO_ENCODER                 = 0x400L,
      kBIND_RENDER_T_SHADER_R = kBIND_SHADER_RESOURCE | kBIND_RENDER_TARGET,
      kCOUNT
    };
  }
  namespace amSRV_Types {
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
  namespace amFormats {
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
  namespace amPrimitiveTopology {
    enum E
    {
      kPRIMITIVE_TOPOLOGY_UNDEFINED = 0,
      kPRIMITIVE_TOPOLOGY_POINTLIST = 1,
      kPRIMITIVE_TOPOLOGY_LINELIST = 2,
      kPRIMITIVE_TOPOLOGY_LINESTRIP = 3,
      kPRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,
      kPRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
      kPRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10,
      kPRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11,
      kPRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12,
      kPRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13,
      kPRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33,
      kPRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34,
      kPRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35,
      kPRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36,
      kPRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37,
      kPRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38,
      kPRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39,
      kPRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40,
      kPRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41,
      kPRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42,
      kPRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43,
      kPRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44,
      kPRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45,
      kPRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46,
      kPRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47,
      kPRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48,
      kPRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49,
      kPRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50,
      kPRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51,
      kPRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52,
      kPRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53,
      kPRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54,
      kPRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55,
      kPRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56,
      kPRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57,
      kPRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58,
      kPRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59,
      kPRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60,
      kPRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61,
      kPRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62,
      kPRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63,
      kPRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64,
      kCOUNT
    };
  }
  namespace amShaderType {
    enum E
    {
      kUNKNOWN = 0,
      kVERTEX,
      kPIXEL,
      kGEOMETRY,
      kCOMPUTE,
      kCOUNT
    };
  }
  namespace amShaderInputLayout {
    enum E
    {
      kGBUFFER = 0,
      kDEFFERRED,
      kCOUNT
    };
  }
  namespace amUsageFlags {
    enum E
    {
      kDEFAULT = 0,
      kIMMUTABLE,
      kDYNAMIC,
      kSTAGING,
      kCOUNT
    };
  }
  namespace amClearFlags {
    enum E
    {
      kCLEAR_DEPTH   = 0x1L,
      kCLEAR_STENCIL = 0x2L
    };
  }
  namespace amMeshLoadFlags {
    enum E
    {
      kNO_FLAG         = 0x1L,
      kNO_MATS         = 0x2L,
      kNO_TEX          = 0x4L,
      kCALC_BINORMALS  = 0x8L,
      kCALC_TANGENTS   = 0x10L,
      kFIRST_MESH_ONLY = 0x20L,
      kCOMBINE_MESHES  = 0x40L,
      kCOUNT
    };
  };
  namespace amConstants {
    enum E
    {
      kFPS30 = 30,
      kFPS60 = 60,
      kFPS75 = 75,
      kFPS90 = 90,
      kCOUNT
    };
  }
}
