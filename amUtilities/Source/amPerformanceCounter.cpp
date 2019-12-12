#include "amPrerequisitesUtilities.h"
#include "amPerformanceCounter.h"
#include <iostream>

#ifdef AM_PLATFORM_WIN32
#include <windows.h>
#endif // AM_PLATFORM_WIN32


namespace amEngineSDK {
  amPerformanceCounter::amPerformanceCounter(const uint32 _refreshRateMul) {
    m_refreshRate = _refreshRateMul;
    m_counterVal = 0;
  }

  void 
  amPerformanceCounter::setRefreshRate(uint32 _refreshRateMul) {
    m_refreshRate = _refreshRateMul;
    m_counterVal = 0;
  }

  void
  amPerformanceCounter::startCounterNano() {
#ifdef AM_PLATFORM_WIN32
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li)) {
      //std::cout << "QueryPerformanceFrequency failed!\n";
    }
    m_refreshRate = static_cast<double>((li.QuadPart) * 0.000000001);
    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
#endif // AM_PLATFORM_WIN32
  }

  void 
  amPerformanceCounter::startCounterMicro() {
#ifdef AM_PLATFORM_WIN32
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li)) {
      //std::cout << "QueryPerformanceFrequency failed!\n";
    }
    m_refreshRate = static_cast<double>((li.QuadPart) * 0.000001);
    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
#endif // AM_PLATFORM_WIN32
  }

  void 
  amPerformanceCounter::startCounterMili() {
#ifdef AM_PLATFORM_WIN32
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li)) {
      //std::cout << "QueryPerformanceFrequency failed!\n";
    }
    m_refreshRate = static_cast<double>((li.QuadPart) * 0.001);
    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
#endif // AM_PLATFORM_WIN32
  }

  void 
  amPerformanceCounter::resetCounter() {
    m_counterVal = 0;
  }

  double 
  amPerformanceCounter::getCounter() {
#ifdef AM_PLATFORM_WIN32
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return static_cast<double>((li.QuadPart - m_counterVal) * m_refreshRate);
#endif // AM_PLATFORM_WIN32
  }
}
