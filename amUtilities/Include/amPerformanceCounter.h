#pragma once
namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amPerformanceCounter
  {
  public:
    amPerformanceCounter() = default;
    amPerformanceCounter(const uint32 _refreshRateMul);
    ~amPerformanceCounter() = default;

    void 
    setRefreshRate(uint32 _refreshRateMul);

    void 
    startCounterNano();

    void 
    startCounterMicro();

    void 
    startCounterMili();

    void 
    resetCounter();

    double 
    getCounter();

    double m_refreshRate;
    uint64 m_counterVal;
  };
}
