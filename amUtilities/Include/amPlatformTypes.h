/******************************************
 * @file amPlatformTypes.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Defines the engine specific types
 *
 * @note
******************************************/
#pragma once
/******************************************************************************/
/**
*  Includes
*/
/******************************************************************************/
#include <cstdint>
#include <cstddef>
#include <string>
#include "amPlatformDefines.h"

#if AM_PLATFORM == AM_PLATFORM_PS4
#  include <scebase.h> //Sony computer entertainment base
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
  *
  *  @brief 128 bits var type
  *
  ******************************************************************************/
  MS_ALIGN(16) class QWord 
  {
   public:

    QWord() : m_lower(0), m_upper(0) {}

    explicit QWord(bool from)   : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint8 from)  : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int8 from)   : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int16 from)  : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int32 from)  : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint64 from) : m_lower(from),                      m_upper(0) {}
    explicit QWord(int64 from)  : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(float from)  : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(double from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}

    /***********************
    *  @brief The cast operator for casting/truncating to 64 bits.
    *  @returns The lower 64 bits of the value
    ***********************/
    operator int64() const { return static_cast<uint64>(m_lower); }

  public:
    uint64 m_lower; // The lower 64 bits of the 128 bit integer
    int64 m_upper; // The upper 64 bits of the 128 bit integer


  }GCC_ALIGN(16);
  
  using int128 = QWord; // signed 128 bit integer
  using uint128 = QWord; // signed 128 bit integer

  /******************************************************************************
  **
  *  Character types
  *
  ******************************************************************************/

#if AM_COMPILER == AM_COMPILER_MSVC || AM_COMPILER == AM_COMPILER_PS4
  using WCHAR = wchar_t; // Wide char(used by Visual Studio)
#else
  using WCHAR = unsigned short; // Wide char(used by any other compiler)
#endif
  using ANSICHAR = char;  // Ansi character type
  using UNICHAR = WCHAR;  // Unicode character Type

  /**
  ************************
  *
  *  String type
  *
  ************************
  */
  using String = std::string;

  /******************************************************************************
  **
  *  Memory byte type
  *
  ******************************************************************************/

  using BYTE_T = uint8;

  /***********************
  **
  *  NULL types
  *
  ***********************/
  using TYPE_OF_NULL = int32;

  /******************************************************************************/
  /**
  *  SIZE_T is an architecture dependent data type
  */
  /******************************************************************************/
  using SIZE_T = size_t;
}
