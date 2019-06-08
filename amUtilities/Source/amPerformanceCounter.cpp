#include "amPrerequisitesUtilities.h"
#include "amPerformanceCounter.h"
#include <iostream>
#include <windows.h>

namespace amEngineSDK {

  void 
  amPerformanceCounter::startCounterNano() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";
      m_PCFreq = static_cast<double>((li.QuadPart) * 0.000000001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  void 
  amPerformanceCounter::startCounterMicro() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";
    m_PCFreq = static_cast<double>((li.QuadPart) * 0.000001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  void 
  amPerformanceCounter::startCounterMili() {
    LARGE_INTEGER li;

    if (!QueryPerformanceFrequency(&li))
      //std::cout << "QueryPerformanceFrequency failed!\n";

      m_PCFreq = static_cast<double>((li.QuadPart) * 0.001);

    QueryPerformanceCounter(&li);
    m_counterVal = li.QuadPart;
  }

  double 
  amPerformanceCounter::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return static_cast<double>((li.QuadPart - m_counterVal) / m_PCFreq);
  }
}
