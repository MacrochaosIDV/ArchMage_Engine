/******************************************************************************/
/**
 * @file amPlatformDefines.h
 *
 *
 *
 */
/******************************************************************************/
#pragma once

/******************************************************************************/
/**
* Initial platform/compiler related stuff to set
*/
/******************************************************************************/

#define AM_PLATFORM_WIN32    1   //Windows platform
#define AM_PLATFORM_LINUX    2   //Linux platform
#define AM_PLATFORM_PS4      3   //PlayStation 4 platform
#define AM_PLATFORM_ANDROID  4   //Android platform
#define AM_PLATFORM_OSX      5   //OSX platform

#define AM_COMPILER_MSVC      1   //Visual studio compiler
#define AM_COMPILER_GNUC      2   //GCC compiler
#define AM_COMPILER_INTEL     3   //Intel compiler
#define AM_COMPILER_CLANG     4   //Clang compiler

#define AM_ARCHITECTURE_x86_32   1   //Intel x86 32 bits
#define AM_ARCHITECTURE_x86_64   2   //Intel x86 64 bits

#define AM_ENDIAN_LITTLE   1   // Little Endian
#define AM_ENDIAN_BIG      2   // Big Endian

// Define actual endian type( little for windows, Linux, apple and PS4
#define AM_ENDIAN AM_ENDIAN_LITTLE

#define AM_VERSION_MAYOR   0   // Engine version mayor value
#define AM_VERSION_MINOR   4   // Engine version minor value
#define AM_VERSION_PATCH   0   // Engine version patch value
#define AM_EDITOR_BUILD    1   // This is an editor build

// Define if on crash we want to report warnings on unknown symbols
#define AM_DEBUG_DETAILED_SYMBOLS 1

/******************************************************************************/
/**
* Compiler type and version
*/
/******************************************************************************/

#if defined(__clang__)
#   define AM_COMPILER AM_COMPILER_CLANG
#   define AM_COMP_VER __clang_version__
#   define AM_THREADLOCAL __thread
#   define AM_STDCALL __attribute__((stdcall))
#   define AM_CDECL __attribute__((cdecl))
#   define AM_FALLTHROUGH [[clang::fallthrough]]
#elif defined(__GNUC__) //Check after Clang, as Clang defines this too
#   define AM_COMPILER AM_COMPILER_GNUC
#   define AM_COMP_VER (((__GNUC__)*100) + (__GNUC_MINOR__ * 10) + + __GNUC_PATCHLEVEL__)
#   define AM_THREADLOCAL __thread
#   define AM_STDCALL __attribute__((stdcall))
#   define AM_CDECL __attribute__((cdecl))
#   define AM_FALLTHROUGH __attirbute__((fallthrough))
#elif defined(__INETL_COMPILER)
#   define AM_COMPILER AM_COMPILER_INTEL
#   define AM_COMP_VER __INETL_COMPILER
//#   define AM_THREADLOCAL __thread
#   define AM_STDCALL __stdcall
#   define AM_CDECL __cdecl
#   define AM_FALLTHROUGH
/**
 *  AM_THREADLOCAL define is down below because Intel compiler defines it
 *  differently based on platform
 */
// Check after clang and intel, we could be building with either wit VS
#elif defined(_MSC_VER)
#   define AM_COMPILER AM_COMPILER_MSVC
#   define AM_COMP_VER _MSC_VER
#   define AM_THREADLOCAL __declspec(thread)
#   define AM_STDCALL __stdcall
#   define AM_CDECL __cdecl
#   define AM_FALLTHROUGH
#   undef __PRETTY_FUNCTION__
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
// No known compiler found, send the error to the output(if any)
#pragma error "No known compiler"
#endif
/******************************************************************************/
/**
* See if we can use __forceinline for if we need to use __inline instead
*/
/******************************************************************************/
#if AM_COMPILER == AM_COMPILER_MSVC     // If we are compiling with Visual Studio
#  if AM_COMP_VER >= 1200               // If we are on VisualStudio 6 or higher
#    define FORCEINLINE __forceinline   // Set __forceinline
#    ifndef RESTRICT
#      define RESTRICT __restrict
#    endif
#  endif
#elif defined(__MINGW32__)              // If we are on a Unix type system
#  if !defined(FORCEINLINE)
#    define FORCEINLINE __inline        //Set __inline
#    ifndef RESTRICT
#      define RESTRICT                  //No alias hint
#    endif
#  endif
#else                                   // Any other compiler
#  define FORCEINLINE __inline          //Set __inline
#  ifndef RESTRICT
#    define RESTRICT __restrict         //No alias hint
#  endif
#endif
/******************************************************************************/
/**
*  Finds the current platform
*/
/******************************************************************************/
#if defined(__WIN32__) | defined(_WIN32)       //If it's a Windows platform
#  define AM_PLATFORM AM_PLATFORM_WIN32
#elif defined(__APPLE_CC__)                    //It's an Apple platform
#  define AM_PLATFORM AM_PLATFORM_OSX
#elif defined(__ORBIS__)                       //It's a PlayStation 4
#  define AM_PLATFORM AM_PLATFORM_PS4
#else                                          //Will consider it as a Linux platform
#  define AM_PLATFORM AM_PLATFORM_LINUX
#endif

/******************************************************************************/
/**
*  Finds the architecture type
*/
/******************************************************************************/

#if defined(__x86_64__) || defined(_M_X64)
#  define AM_ARCH_TYPE AM_ARCHITECTURE_x86_64   // This is a x64 compile
#else
#  define AM_ARCH_TYPE AM_ARCHITECTURE_x86_32   // This is a x86 compile
#endif 

/******************************************************************************/
/**
*  Memory Alignment macros
*/
/******************************************************************************/

#if AM_COMPILER == AM_COMPILER_MSVC
#  define MS_ALIGN(n) __declspec(align(n))
#  ifndef GCC_PACK
#    define GCC_PACK(n)
#  endif
#  ifndef GCC_ALIGN
#    define GCC_ALIGN(n)
#  endif
#elif ( AM_COMPILER == AM_COMPILER_GNUC && AM_PLATFORM == AM_PLATFORM_PS4 )
#  define MS_ALIGN(n)
#  define GCC_PACK(n)
#  define GCC_ALIGN(n) __attribute__( (__aligned__(n)))
#else
#  define MS_ALIGN(n)
#  define GCC_PACK(n) __attribute__( (packed, aligned(n)) )
#  define GCC_ALIGN(n) __attribute__( (aligned(n)) )
#endif

/******************************************************************************/
/**
*  For throw override( deprecated on c++11 but VS doesn't have handle noexcept
*/
/******************************************************************************/

#if AM_COMPILER == AM_COMPILER_MSVC
#  define _NOEXCEPT noexcept
#elif AM_COMPILER == AM_COMPILER_INTEL
#  define _NOEXCEPT noexcept
#elif AM_COMPILER == AM_COMPILER_GNUC
#  define _NOEXCEPT noexcept
#else
#  define _NOEXCEPT
#endif

/******************************************************************************/
/**
*  Library export specifics
*/
/******************************************************************************/

#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    if defined(AM_STATIC_LIB)
#      define AM_UTILITIES_EXPORT
#    else
#      if defined(AM_UTILITIES_EXPORTS)
#        define AM_UTILITIES_EXPORT __declspec( dllexport )
#      else
#        define AM_UTILITIES_EXPORT __declspec( dllimport )
#      endif
#    endif
#  else // Any other compiler
#    if defined(AM_STATIC_LIB)
#      define AM_UTILITIES_EXPORT
#    else
#      if defined(AM_UTILITIES_EXPORTS)
#        define AM_UTILITIES_EXPORT __attribute__( (dllexport) )
#      else
#        define AM_UTILITIES_EXPORT __attribute__( (dllimport) )
#      endif
#    endif
#  endif
#  define AM_UTILITIES_HIDDEN
#else //Linux / Mac settings
#  define AM_UTILITIES_EXPORT __attribute__ ((visibility("default")))
#  define AM_UTILITIES_HIDDEN __attribute__ ((visibility("hidden")))
#endif 
// DLL export for plug-ins
#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if AM_COMPILER == AM_COMPILER_MSVC
#    define AM_PLUGIN_EXPORT __declspec(dllexport)
#  else
#    define AM_PLUGIN_EXPORT __attribute__(dllexport)
#  endif
#  define AM_UTILITIES_HIDDEN
#else //Linux / Mac settings
#  define AM_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

/******************************************************************************/
/**
*  Windows specific settings
*/
/******************************************************************************/

// Win32 compilers use _DEBUG for specifying debug builds. For MinGW, we set DEBUG
#if AM_PLATFORM == AM_PLATFORM_WIN32
#  if defined(_DEBUG) || defined(DEBUG)
#    define AM_DEBUG_MODE 1
#  else
#    define AM_DEBUG_MODE 0
#  endif
#  if AM_COMPILER == AM_COMPILER_INTEL
#    define AM_TREADLOCAL __declspec(thread)
#  endif
#endif //AM_PLATFORM == AM_PLATFORM_WIN32

/******************************************************************************/
/**
*  Linux / Mac specific settings
*/
/******************************************************************************/

#if AM_PLATFORM == AM_PLATFORM_LINUX || AM_PLATFORM == AM_PLATFORM_OSX
#  define stricmp strcasecmp
// if we are on debug build
#  if defined(_DEBUG) || defined(DEBUG)
#    define AM_DEBUG_MODE 1
#  else
#    define AM_DEBUG_MODE 0
#  endif
#  if AM_COMPILER == AM_COMPILER_INTEL
#    define AM_TREADLOCAL __thread
#  endif
#endif //AM_PLATFORM == AM_PLATFORM_LINUX || AM_PLATFORM == AM_PLATFORM_OSX

/******************************************************************************/
/**
*  PS4 specific settings
*/
/******************************************************************************/

#if AM_PLATFORM == AM_PLATFORM_PS4
#  define stricmp strcasecmp
// if we are on debug build
#  if defined(_DEBUG) || defined(DEBUG)
#    define AM_DEBUG_MODE 1
#  else
#    define AM_DEBUG_MODE 0
#  endif
#endif // AM_PLATFORM == AM_PLATFORM_PS4

/******************************************************************************/
/**
*  Definition of debug macros
*/
/******************************************************************************/

#if AM_DEBUG_MODE
#  define AM_DEBUG_ONLY(x) x
#  define AM_ASSERT(x) assert(x)
#else
#  define AM_DEBUG_ONLY(x)
#  define AM_ASSERT(x)
#endif

/******************************************************************************/
/**
*  Disable some compiler warnings
*/
/******************************************************************************/

// if compiling with Visual Studio
#if AM_COMPILER == AM_COMPILER_MSVC

/**
*  TODO: This is not deactivated anywhere, therefore it applies to to any file
*  that includes this header...
*/
//Secure version aren't multi platform, so we won't be using them
#  define _CRT_SECURE_NO_WARNINGS
//#  define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING
/*
*  Disable: "<type> needs to have DLL interface to be used
*/
#pragma warning (disable: 4251)

//Disable 'X' function call with parameters that may be unsafe
#pragma warning (disable: 4996)
/*
*  Disable: decorated name l
*/
#pragma warning (disable: 4503)

#endif


/******************************************************************************/
/**
*   Standard Libraries defines
*/
/******************************************************************************/

