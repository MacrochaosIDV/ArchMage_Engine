#pragma once
namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amPerformanceCounter
  {
  public:
    amPerformanceCounter() = default;
    amPerformanceCounter(const uint32 _refreshRate);
    ~amPerformanceCounter() = default;

    void 
    setRefreshRate(uint32 _refreshRate);

    void 
    startCounterNano();

    void 
    startCounterMicro();

    void 
    startCounterMili();

    double 
    getCounter();

    double m_refreshRate;
    uint64 m_counterVal;
  };
}
