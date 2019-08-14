#include "amPrerequisitesUtilities.h"
#include "amPerformanceCounter.h"
#include <iostream>
#include <windows.h>

namespace amEngineSDK {
  amPerformanceCounter::amPerformanceCounter(const uint32 _refreshRate) {
    m_refreshRate = _refreshRate;
    m_counterVal = 0;
  }

  void 
  amPerformanceCounter::setRefreshRate(uint32 _refreshRate) {
    m_refreshRate = _refreshRate;
    m_counterVal = 0;
  }

  void
  amPerformanceCounter::startCounterNano() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";
      m_refreshRate = static_cast<double>((li.QuadPart) * 0.000000001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  void 
  amPerformanceCounter::startCounterMicro() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";
      m_refreshRate = static_cast<double>((li.QuadPart) * 0.000001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  void 
  amPerformanceCounter::startCounterMili() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";

      m_refreshRate = static_cast<double>((li.QuadPart) * 0.001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  double 
  amPerformanceCounter::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return static_cast<double>((li.QuadPart - m_counterVal) / m_refreshRate);
  }
}
