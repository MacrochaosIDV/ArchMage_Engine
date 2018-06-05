#pragma once
/******************************************************************************/
/**
*  Includes
*/
/******************************************************************************/
#include <cstdint>
#include "amPlatformDefines.h"

#if AM_PLATFORM == AM_PLATFORM_PS4
#  include <scebase.h>
#endif

namespace amEngineSDK {
  using std::uint8_t;
  using std::uint16_t;
  using std::uint32_t;
  using std::uint64_t;

  using std::int8_t;
  using std::int16_t;
  using std::int32_t;
  using std::int64_t;

  /******************************************************************************/
  /**
  *  Basic unsigned types
  */
  /******************************************************************************/

  using uint8 = uint8_t;
  using uint16 = uint16_t;
  using uint32 = uint32_t;
  using uint64 = uint64_t;

  /******************************************************************************/
  /**
  *  Basic signed types
  */
  /******************************************************************************/

  using int8 = int8_t;
  using int16 = int16_t;
  using int32 = int32_t;
  using int64 = int64_t;

  /******************************************************************************/
  /**
  *  @Class QWord
  */
  /******************************************************************************/

  /******************************************************************************/
  /**
  *  Character types
  */
  /******************************************************************************/

#if AM_COMPILER == AM_COMPILER_MSVC || AM_COMPILER == AM_COMPILER_PS4
  using WCHAR = wchar_t;
#else
  using WCHAR = unsigned short;
#endif
  using ANSICHAR = char;  // Ansi character type
  using UNICHAR = WCHAR;  // Unicode character Type

  /******************************************************************************/
  /**
  *  Memory byte type
  */
  /******************************************************************************/

  using BYTE_T = uint8;

  /******************************************************************************/
  /**
  *  SIZE_T is an architecture dependant datat type
  */
  /******************************************************************************/
  using SIZE_T = size_t;
}
