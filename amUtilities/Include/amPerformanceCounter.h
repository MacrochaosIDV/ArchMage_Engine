#pragma once
namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amPerformanceCounter
  {
  public:
    amPerformanceCounter() = default;
    ~amPerformanceCounter() = default;

    void 
    startCounterNano();

    void 
    startCounterMicro();

    void 
    startCounterMili();

    double 
    getCounter();

    double m_PCFreq = 0.0;
    int64 m_counterVal = 0;
  };
}


